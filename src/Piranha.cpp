#include "Piranha.hpp"
#include "Helper.hpp"

std::vector<Animation> Piranha::animList;
int Piranha::speed;

Piranha::Piranha(const int& x, const int& y, Aquarium& aquarium, double now) : AquariumObject(Position(x, y), aquarium), Fish(Fish::Type::PIRANHA) {
    Fish::animFrame = 0;
    Fish::animMode = 0;
    AquariumObject::timeSpawned = now;
    Fish::timeEat = now;
}

Position Piranha::getPosition() const {
    return position;
}

void Piranha::update(double now, double secSinceLast) {
    if (Fish::animMode % 3 == 1 && Fish::animFrame == 9) {
        Fish::animMode = 0 + 3 * hungry; 
        Fish::animFrame = 0;
        AquariumObject::timeSpawned = now;
    }
    printf("%lf\n", AquariumObject::timeSpawned);
    Fish::animFrame = (fmod((now - AquariumObject::timeSpawned) * 50, 60)) / 6;
    move(secSinceLast);
    if (eat()) {
        Fish::timeEat = now;
        Fish::hungry = false;
        Fish::animMode = animMode + 3 * hungry;
    }
    if (hungry && now - timeHungry >= timeUntilDead) {
        Fish::alive = false;
    }
    else if (!hungry && now - timeEat >= timeUntilHungry) {
        Fish::timeHungry = now;
        Fish::hungry = true;
        Fish::animMode = animMode + 3 * hungry;
    }
}

Animation Piranha::getAnim(int index) {
    return Piranha::animList.at(index);
}

int Piranha::getStage() const {
    return Fish::stage;
}

void Piranha::upgrade() {

}

Fish * Piranha::findNearestFood() {
    Fish * nearestFood = NULL;
    double minDistance = 9999;
    for (int i = 0; i < aquarium.fishes.length(); i++) {
        Fish * food = aquarium.fishes[i];
        if (aquarium.fishes[i]->getType() == Fish::Type::GUPPY && 
            position.distanceFrom(food->getPosition()) < minDistance) {
            minDistance = position.distanceFrom(food->getPosition());
            nearestFood = food;
        }
    }
    return nearestFood;
}

void Piranha::move(double secSinceLast) {
    if (moveDuration < 0) {
        std::uniform_real_distribution<double> durDistribution(0.5, 5);
        moveDuration = durDistribution(generator);
        std::uniform_real_distribution<double> distribution(0, 360);
        direction = distribution(generator);        
    }
    else {
        moveDuration -= secSinceLast;
    }
    if (hungry && findNearestFood() != NULL) {
        Fish * nearestFood = findNearestFood();
        int deltaX, deltaY;
        deltaX = nearestFood->getPosition().x - position.x;
        deltaY = nearestFood->getPosition().y - position.y;
        // TODO calculate the degree to point into direction of food
        direction = atan2(deltaY, deltaX) * 180 / (PI);
    } 
    else {
        printf("Degree: %lf\n", cos(direction * PI / 180.0) * secSinceLast * speed);
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

int Piranha::getSpeed() {
    return Piranha::speed;
}

Coin * Piranha::produceCoin() {

}

bool Piranha::eat() {
    Fish * food = findNearestFood();
    if (hungry && food != NULL && position.distanceFrom(food->getPosition()) <= 20) {
        printf("Closing in to eat\n");
        aquarium.fishes.remove(food);
        return true;
    } else if (hungry && food != NULL && position.distanceFrom(food->getPosition()) <= 60) {
        Fish::animMode = 1 + 3 * Fish::hungry;
        Fish::animFrame = 0;
    }
    return false;
}