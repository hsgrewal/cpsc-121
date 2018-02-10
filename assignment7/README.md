# Assignment 7

## Harkishan Singh Grewal

CPSC-121 - Programming Concepts
April 22, 2015
Written in C++

## Programming Assignment

### Car Class
This C++ program implements a class named Car in C++ that has the following
member variables:
  1. year - An int that holds the car’s model year
  2. make - A string object that holds the make of car
  3. speed - An int that holds the car’s current speed

Additionally, the class has the following member functions:
  1. Constructor - Constructor accepts the car’s year and make as arguments
    and assign these values to the object’s year and make member variables.
    The constructor initializes the speed member variable to 0
  2. Accessors or Getters - Appropriate accessors or getters allow values to
    be retrieved from an object’s year, make and speed member variables
  3. accelerate - accelerate function adds 5 to the speed member variable each
    time it’s called
  4. brake - brake function subtracts 5 from the speed member variable each
    time it is called

The program does the following:
  1. The program creates a Car object
  2. The program calls the accelerate function 5 times. After each call to
    the accelerate function, the program gets the current speed of the car
    and displays it
  3. The program calls the brake function 5 times. After each call to the
    break function, the program gets the current speed of car and displays it

### Dealer, Player, and Card Shuffler Class
This C++ program simulates a card distribution scheme among Dealer, Player,
and Card Shuffler in a game of Black Jack using Object Oriented Programming
(OOP).

The lists of minimal responsibilities for a Dealer, Player, and Card Shuffler
Class are given below:
  **Card Shuffler**
    1. A card shuffler shuffles the N decks of cards, where N is defined by
      the user
    2. A card shuffler distributes a different card to the dealer every-time
  **Dealer**
    1. A dealer has a name
    2. A dealer retrieves a card from the shuffler
    3. A dealer distributes the card to the player
  **Player**
    1. A player has a name
    2. A player retrieves a card from the dealer
    3. A player displays all the cards in their hands
