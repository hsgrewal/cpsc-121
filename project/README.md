# Final Project

## Harkishan Singh Grewal

CPSC-121 - Programming Concepts
March 20, 2015
Written in C++

## Simple Blackjack Game
The project is a C++ application of a simple blackjack game. The subsections
below describe the following:
  1. Card and Ticket Number
  2. Point System
  3. Stage of Game
  4. Dealer and Player
  5. Constant

### Card and Ticket Number
This C++ program shuffles 4 decks of standard 52 cards. A standard deck of 52
cards has 4 suits: spade, heart, diamond and club. Each suit contains 13
cards: Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, and King. For the
purposes of this program, it is assumed that Ace is 0, Jack is 10, Queen is
11, and King is 12. In the other words, a number is assigned to each face card
and making the 13 cards: 0 (Ace), 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 (Jack),
11 (Queen), and 12 (King). The decks are numbered as 0, 1, 2, and 3 for the
first, second, third and fourth deck respectively. The suits (spade, heart,
diamond, and club) are numbered as 0, 1, 2, and 3 respectively. Each card
from the four decks is associated with an unique ticket number. For the first
deck, the 13 spades from Ace to King have ticket numbers 0, 1, 2, 3, 4, ...
11, and 12 respectively. The 13 hearts from Ace to King in the first deck have
ticket numbers 13, 14, 15, ... 24, and 25 respectively. The 13 diamonds from
Ace to King in the first deck have ticket numbers 26, 27, 28, ... 37, and 38.
The 13 clubs from Ace to King in the first deck have ticket numbers 39, 40,
41, ... 50, and 51. For the 52 cards in the second deck, the numbering
continues from the first deck. The 13 spades from Ace to King in the second
deck have ticket numbers 52, 53, 54, ... 63, and 64. The rest of cards in the
remaining decks are numbered in the same manner. Using the ticket number
enables the program to identify the deck number, suit, and the real card
number. For example, 12 is the king of spade from the first deck, 60 is the
number 9 of spade from the second deck and 200 is the number 6 of club from
the fourth deck.

In terms of implementation, the program uses 1D array to hold all the ticket
numbers. Since there are 208 cards in 4 decks, the integer array of 208
elements can hold the ticket numbers from 0 to 207, as the numbering scheme
described above.

### Point System
The point system specifies the points associated with each card regardless
its suit. This is used when counting the total points of a given hand or
combination of cards. The total points is the summation of points associated
with each card. The point system is given below. For example, if the player
has the hand: 3 of Spade, 4 of Club and 5 of heart, then the player has a
total of 12 points. For another example, the player has Ace of Club and Queen
of Heart at hand. The player would have 11 or 21 points.

**Point System Associated with Each Card**
| Card  |  Point  |
|:-----:|:-------:|
| Ace   | 1 or 11 |
|  2    |    2    |
|  3    |    3    |
|  4    |    4    |
|  5    |    5    |
|  6    |    6    |
|  7    |    7    |
|  8    |    8    |
|  9    |    9    |
|  10   |    10   |
| Jack  |    10   |
| Queen |    10   |
| King  |    10   |

### Stage of Game
The simple blackjack game has the following stages from the start to end of game:

  * Stage 1
    The stage 1 initializes the environment of each game. The game environment
    includes 4 decks of cards, players, and dealer. Players can be friends
    while the game creator is the dealer. Or the program can randomly pick one
    person as the dealer. The environment setup is described below:
    1. The four decks of cards are created and shuffled
    2. The information of 7 players are read from the file
    3. The information of 7 dealers are read from the file
    4. The number of players in one game depends on how many players would
      like to join the game. Once the number of players is specified in the
      beginning of the game, no additional player can join until the next
      game. Once the player join the game, they will stay until the end of
      game.
    5. Once the number of players are set, the program randomly selects the
      players from the player list
    6. A dealer is randomly selected from the dealer list

  * Stage 2
    The dealer initializes the game by dealing cards to each player. The way
    to deal cards in the first round is specified below:
    1. The dealer deals two cards to each player. For example, the dealer
      deals first two cards to the first player, and next two cards to the
      second player until every player gets their first two cards. Please note
      that the order of players to received their two cards depends on how
      players were randomly selected from the player list.
    2. After every player has two cards, the dealer deals one card to
      him/her-self.

  * Stage 3
    The dealer starts to deal cards to each player and lastly him/her-self.
    1. Before dealing a card to each player, the dealer will ask the player
      the following question:
        - Hit?
        - Pass?
    2. If the player chooses “Hit”, the dealer will deal one card to the
      player. This process continues until the same player chooses “Pass” or
      the player exceeds 21 (bust).
    3. Once the dealer finishes dealing cards to one player, he/she will move
      onto the next player.
    4. The dealer finishes dealing cards to all players based on the one of
      the following conditions:
        - All players pass.
        - Some players bust while the rest pass.
    5. After the dealer finishes handling all players, he/she will start to
      deal cards to him/her-self until one of the following conditions:
        - The dealer exceeds 17 points.
        - The dealer passes.
    6. After the dealer finishes dealing cards to him/her-self, the stage is
      terminated.

  * Stage 4
    It is time to count the points for each player and dealer using the point
    system outlined above.

  * Stage 5
    The dealer (casino) starts to pay or collect the money.
    1. As long as a player busts (even if the dealer busts), the dealer
      collects a 10-dollar chip from the player.
    2. If a player and the dealer do not bust and the player has fewer points
      than the dealer, the dealer collects a 10-dollar chip from the player.
    3. If a player does not bust but the dealer busts, the dealer pays a
      10-dollar chip to the player.
    4. If a player and the dealer do not bust and the player has more points
      than the dealer, the dealer pays a 10-dollar chip to the player.
    5. If a player and the dealer do not bust and the player and dealer have
      the same number of points, no transaction occurs.

### Dealer and Player
In the player file, ”player.txt”, the first column is ID, second column is
first name, and third column is the number of 10-dollar chips, owned by a
player. In the dealer file, ”dealer.txt”, the first column is ID, second
column is casino name, and the third column is the number of 10-dollar chips
in a casino’s bank. The set of ticket numbers and player’s or dealer’s status
will be updated while playing the blackjack. A dealer and player have the
following data members in a C++ struct.
  * ID: identification number.
  * Name: first name.
  * Chip: the number of 10-dollar chip.
  * Ticket number: a set of ticket numbers possessed at the current game.
  * Status (isWithdrawn): If the player has over 21 points, the player busts
    and is withdrawn from the game. Or he/she can continue playing the game.

Here is the C++ struct to represent both dealer and players:
```cpp
struct person {
  int id;
  std::string first_name;
  int ticket_number[18];
  bool isWithdrawn;
};
```

### Constants
The constants are listed below:
  1. The number of decks is 4.
  2. The number of suits is 4.
  3. The number of cards is 13.
  4. The number of swaps is 1000.
  5. Each chip has a value of 10 dollars.
