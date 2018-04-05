#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "LinkedList.hpp"
#include "Fish.hpp"
#include "Snail.hpp"
#include "Coin.hpp"
#include "Food.hpp"

class Aquarium {
private:
    int height, width;
    LinkedList<Fish> fishes;
    LinkedList<Snail> snails; 
    LinkedList<Food> foods;
    LinkedList<Coin> coins;

    void addFish(const Fish&);
    void addSnail(const Snail&);
    void addFood(const Food&);
    void addCoin(const Coin&);

    Fish& getFish(int) const;
    Snail& getSnail(int) const;
    Food& getFood(int) const;
    Coin& getCoin(int) const;

    int getAmountOfFish() const;
    int getAmountOfSnail() const;
    int getAmountOfFood() const;
    int getAmountOfCoin() const;
    
public:
    Aquarium();
    Aquarium(const int&, const int&);
};

#endif