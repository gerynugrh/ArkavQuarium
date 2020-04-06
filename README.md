# ArkavQuarium

ArkavQuarium is an implementation of InsaniQuarium using C++. It includes code to handle sprite changes to generate animation.

## How to Run

`make all`

## Game
Main controller, has update function that will call each Aquarium object's update function.
| Function          | Description                           |
|-------------------|---------------------------------------|
| void update()     | Call update method in all **objects** |
## Aquarium
Aquarium class serve as the interface between object in the aquarium. Because each object in the aquarium object has a refference to Aquarium class theoritically they can access every instance of object that Aquarium has. 

## AquariumObject
Serve as a parent class for all objects in the Aquarium, with each object have access to all other AquariomObjects using Aquarium interface.

## Fish
Abstract class for all the fish in the Aquarium (currently Guppy and Piranha). As Aquarium class saved list of Fish extending Fish class will not break the main program. Also controls the time until the fish hungry or dead.
| Function                  | Description                                           |
|---------------------------|-------------------------------------------------------|
| void findNearestFood()    | Find nearest food that is suitable for the **Fish**   |
| void produceCoin()        | Instantiate a **coin**                                |
| void move()               | Move according to direction **Fish**                  |
| void eat()                | Eat **Food** in the same position as the **Fish**     |
## Guppy
Normal fish in the Aquarium. Able to eat food objects in the Aquarium, it will also try to steer it's move to the nearest food if it is currenlty hungry. Generate coins after T time.

## Piranha
Carnivore fish in the Aquarium. Able to eat Guppy that lives inside the Aquarium, produce coins after eating Guppy. It will move according to the position of the nearest Guppy in the surrounding, will not eat if it feels full.

## Normal Food
Implementation of Food interface, have normal behaviour, upgrading a fish one stage everytime it gets eaten.

## Food
Interface for all the food class in the Aquarium.

## Coin
Interface for all the coins class in the Aquarium. The purpose of using interface is if someone wanted to add an extension to a coins object they will not need to update main Aquarium function as Aquarium save list of object interface.

## Silver Coin
Implementation of Coin interface, have normal behaviour, increasing the amount of coins the player had by 1.

## Snail
Interface for all the snail in the Aquarium. Serve as a base to add another implementation of Snail.

## Normal Snail
Implementation of Snail interface, have normal behaviour, collection all the nearest coins on the bottom of the aquarium.
| Function                  | Description                                           |
|---------------------------|-------------------------------------------------------|
| void getNearestCoin()     | Find the position of the nearest **coin**             |
## Position
Simple structure to save the position of each aquarium object

## Direction
Simple structure to save the direction of each object, Direction is specified as four booleans, UP, DOWN, RIGHT, LEFT with it having true means that the object is going into that direction.

## LinkedList
Helper class to save all the objects in the Aquarium. Implemented using double linked list
