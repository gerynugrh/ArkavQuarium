#include "Guppy.hpp"
#include <cmath>

int Guppy::foodForUpgrade, Guppy::timeForCoin, Guppy::speed;
std::vector<Animation> Guppy::animList;

Guppy::Guppy(const int & x, const int & y, Aquarium & aquarium, double now) : AquariumObject(Position(x, y), aquarium), Fish(Fish::Type::GUPPY) {
    amountOfFood = 0;
    Fish::animFrame = 0;
    Fish::animMode = 0;
    AquariumObject::timeSpawned = now;
}

int Guppy::getStage() const {
    return stage;
}

Position Guppy::getPosition() const {
    return AquariumObject::position;
}

bool Guppy::eat(Food * food) {
    aquarium.foods.remove(food);
    amountOfFood++;
}

void Guppy::update(double now, double secSinceLast) {
    printf("%lf\n", AquariumObject::timeSpawned);
    Fish::animFrame = (fmod((now - AquariumObject::timeSpawned) * 50, 60)) / 6;
    move(secSinceLast);
}

Coin * Guppy::produceCoin() {

}

void Guppy::upgrade() {
    if (amountOfFood >= Guppy::foodForUpgrade) {
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
        std::uniform_real_distribution<double> durDistribution(0.5, 5);
        moveDuration = durDistribution(generator);
        std::uniform_real_distribution<double> distribution(0, 360);
        direction = distribution(generator);        
    }
    else {
        moveDuration -= secSinceLast;
    }
    if (findNearestFood() != NULL) {
        Food * nearestFood = findNearestFood();
        int deltaX, deltaY;
        deltaX = nearestFood->getPosition().x - position.x;
        deltaY = nearestFood->getPosition().y - position.y;
        // TODO calculate the degree to point into direction of food   
        direction = atan2(deltaY, deltaX) * 180 / (2 * PI);
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
        
        position.x += cos(direction * PI / 180.0) * secSinceLast * speed;
        position.y += sin(direction * PI / 180.0) * secSinceLast * speed;
    }
}

Animation Guppy::getAnim(int index) {
    return Guppy::animList.at(index);
}
