#include "Guppy.hpp"
#include <cmath>

int Guppy::foodForUpgrade, Guppy::timeForCoin, Guppy::speed, Guppy::price;
std::vector<Animation> Guppy::animList;

Guppy::Guppy(const int & x, const int & y, Aquarium & aquarium, double now) : AquariumObject(Position(x, y), aquarium), Fish(Fish::Type::GUPPY) {
    amountOfFood = 0;
    Fish::animFrame = 0;
    Fish::animMode = 0;
    aquarium.gold -= Guppy::price;
    stage = 0;
    Fish::timeStamp = now;
    timeSinceLastCoin = now;
    Fish::timeEat = now;
    AquariumObject::timeSpawned = now;
    hungry = false;
    right = false;
}

int Guppy::getStage() const {
    return Fish::stage;
}

Position Guppy::getPosition() const {
    return AquariumObject::position;
}

bool Guppy::eat(double now) {
    Food * food = findNearestFood();
    if (hungry && food != NULL && position.distanceFrom(food->getPosition()) <= 20) {
        printf("Closing in to eat\n");
        aquarium.foods.remove(food);
        amountOfFood++;
        return true;
    } else if (hungry && food != NULL && position.distanceFrom(food->getPosition()) <= 60) {
        Fish::animMode = 1 + 3 * Fish::hungry + 6 * right + 12 * stage;
        Fish::timeStamp = now;
    }
    return false;
}

void Guppy::update(double now, double secSinceLast) {
    if (Fish::alive) {
        if (Fish::animMode % 3 == 1 && Fish::animFrame == 9) {
            Fish::animMode = 0 + 3 * hungry + 6 * right + 12 * stage; 
            Fish::animFrame = 0;
            Fish::timeStamp = now;
        }
        else if (right && (Fish::animMode % 6) % 3 == 2 && Fish::animFrame == 9) {
            Fish::animMode = 0 + 3 * hungry + 6 * right + 12 * stage;
            Fish::animFrame = 0;
            Fish::timeStamp = now;
        }
        else if (!right && (Fish::animMode % 6) % 3 == 2) {
            Fish::animFrame = 9 - (fmod((now - Fish::timeStamp) * 50, 60)) / 6; 

            if (Fish::animFrame == 0) {
                Fish::animMode = 0 + 3 * hungry + 6 * right + 12 * stage;
                Fish::animFrame = 0;
                Fish::timeStamp = now;            
            }
        }
        else {
            Fish::animFrame = (fmod((now - Fish::timeStamp) * 50, 60)) / 6;
        }
        move(secSinceLast);
        if (eat(now)) {
            Fish::timeEat = now;
            Fish::timeHungry = Fish::timeEat + timeUntilHungry;
            Fish::hungry = false;
            Fish::animMode = animMode % 3 + 3 * hungry + 6 * right + 12 * stage;
        }
        if (hungry && now - timeHungry >= timeUntilDead) {
            Fish::alive = false;
            Fish::animMode = 48 + 2 * stage + right;
            Fish::animFrame = 0;
            Fish::timeStamp = now;
        }
        else if (!hungry && now - timeEat >= timeUntilHungry) {
            Fish::timeHungry = now;
            Fish::hungry = true;
            Fish::animMode = animMode % 3 + 3 * hungry + 6 * right + 12 * stage;
        }
        if (!right && (direction <= 90 || direction >= 270)) {
            Fish::animMode = 2 + 3 * hungry + 6 * right + 12 * stage;
            if (right) {
                Fish::animFrame = 9;
            }
            Fish::timeStamp = now;
            right = true;
        }
        else if (right && (direction >= 90 && direction <= 270)) {
            Fish::animMode = 2 + 3 * hungry + 6 * right + 12 * stage;
            if (right) {
                Fish::animFrame = 9;
            }
            Fish::timeStamp = now;
            right = false;
        }
        if (now - timeSinceLastCoin >= timeForCoin) {
            produceCoin(now);
            timeSinceLastCoin = now;
        }
        upgrade();
    } 
    else {
        if (Fish::animFrame == 9) {
            Fish::destroy = true;
        }
        else {
            position.y += secSinceLast * 30;
            Fish::animFrame = (fmod((now - Fish::timeStamp) * 50, 60)) / 6;        
        }
    }
}

int Guppy::getStage() {
    return stage;
}

void Guppy::produceCoin(double now) {
    SilverCoin * coin = new SilverCoin(position.x, position.y, aquarium, now, 40 * (stage + 1));
    aquarium.coins.add(coin);        
}

void Guppy::upgrade() {
    if (amountOfFood >= Guppy::foodForUpgrade && stage < 3) {
        amountOfFood = 0;
        stage++;
    }
}

Food * Guppy::findNearestFood() {
    Food * nearestFood = NULL;
    double minDistance = 9999;
    for (int i = 0; i < aquarium.foods.length(); i++) {
        Food * food = aquarium.foods[i];
        if (position.distanceFrom(food->getPosition()) < minDistance) {
            minDistance = position.distanceFrom(food->getPosition());
            nearestFood = food;
        }
    }
    return nearestFood;
}

void Guppy::move(double secSinceLast) {
    if (moveDuration < 0) {
        std::uniform_real_distribution<double> durDistribution(1, 5);
        moveDuration = durDistribution(generator);
        std::uniform_real_distribution<double> distribution(0, 360);
        direction = distribution(generator);        
    }
    else {
        moveDuration -= secSinceLast;
    }
    if (hungry && findNearestFood() != NULL) {
        Food * nearestFood = findNearestFood();
        int deltaX, deltaY;
        deltaX = nearestFood->getPosition().x - position.x;
        deltaY = nearestFood->getPosition().y - position.y;
        // TODO calculate the degree to point into direction of food   
        direction = atan2(deltaY, deltaX) * 180 / (PI);
    } 
    else {
        double newX, newY;
        newX = position.x + cos(direction * PI / 180.0) * secSinceLast * speed;
        newY = position.y + sin(direction * PI / 180.0) * secSinceLast * speed;

        if (newX >= SCREEN_WIDTH - 40) {
            std::uniform_real_distribution<double> distribution(0, 180);
            direction = 90 + distribution(generator);
        }
        else if (newX <= 40) {
            std::uniform_real_distribution<double> distribution(0, 180);
            direction = 270 + distribution(generator);
        }
        else if (newY <= 40) {
            std::uniform_real_distribution<double> distribution(0, 180);
            direction = 0 + distribution(generator);            
        }
        else if (newY >= SCREEN_HEIGHT - 40) {
            std::uniform_real_distribution<double> distribution(0, 180);
            direction = 180 + distribution(generator);               
        }
    }
    position.x += cos(direction * PI / 180.0) * secSinceLast * speed;
    position.y += sin(direction * PI / 180.0) * secSinceLast * speed;
}

Animation Guppy::getAnim(int index) {
    return Guppy::animList.at(index);
}
