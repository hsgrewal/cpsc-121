/*
 * This program simulates a simple Blackjack game.
 *
 * Harkishan Singh Grewal
 * April 1, 2015
 * Due April 7, 2015
 */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Delcare constants.
const int NUM_DECKS = 4;
const int NUM_SUITS = 4;
const int NUM_CARDS = 13;
const int NUM_SWAPS = 1000;
const int VALUE_CHIP = 10;

// Declare struct.
struct person{
  int id;
  string name;
  int numChips;
  int cards[18];
  int counter = 0;
  int score = 0;
  bool isWithdrawn = false;
};

// Declare function prototypes.
int swap(int* element1, int* element2);
int shuffle(int card[], int nSwap);
void determineCardInformation(int tickerNumber, int* cardNumber);
void shufflePlayers(person players[], int nSwap);
int determinePoints(int cardNumber, int score);
int determineCardNumber(int ticketNumber);
void displayCard(int cardNumber);

int main(){
  // Delcare main variables.
  int deck[NUM_CARDS*NUM_DECKS*NUM_SUITS];
  int numPlayers;
  ifstream inputFile;
  person players[7]; // Declare array of players.
  person dealers[7]; // Declare array of players.
  person dealer;
  string hitOrPass;
  string playAgain = "yes";

  // Populate the ticketNumbers array.
  for (int i = 0; i < NUM_CARDS*NUM_DECKS*NUM_SUITS; i++)
    deck[i] = i;

  cout << "Welcome to BLACKJACK!\n";
  do{
    int deckIndex = 0;
    // Stage 1.
    // Shuffle the cards.
    shuffle(deck, NUM_SWAPS);

    // Get the number of players.
    cout << "\nEnter number of players: ";
    cin >> numPlayers;
    while (numPlayers<0 || numPlayers>7){ // validate user input.
      cout << "Enter number of players: ";
      cin >> numPlayers;
    }

    // Open file.
    inputFile.open("player.txt");

    // Check if file opened.
    if (inputFile){
      // Read numbers from file into the array.
      for (int i = 0; i < 7; i++){
        inputFile >> players[i].id;
        inputFile >> players[i].name;
        inputFile >> players[i].numChips;
      }

      // Close file after array is initialized.
      inputFile.close();
    }
    else
      cout << "Error opening the file.\n";

    // Shuffle players.
    shufflePlayers(players, NUM_SWAPS);

    // Display player information.
    for (int i = 0; i < numPlayers; i++){
      cout << "\nPlayer " << i + 1 << ":\n"
        << "   Id: " << players[i].id << endl
        << "   Name: " << players[i].name << endl
        << "   Chips: " << players[i].numChips << " ($"
        << players[i].numChips*VALUE_CHIP << ")\n";
    }

    // Open file.
    inputFile.open("dealer.txt");

    // Check if file opened.
    if (inputFile){
      // Read numbers from file into the array.
      for (int i = 0; i < 7; i++){
        inputFile >> dealers[i].id;
        inputFile >> dealers[i].name;
        inputFile >> dealers[i].numChips;
      }

      // Close file after array is initialized.
      inputFile.close();
    }
    else
      cout << "Error opening the file.\n";

    // select a random dealer for the game.
    dealer = dealers[rand() % 7];

    // Display dealer information.
    cout << "\nDealer:\n"<< "   Id: " << dealer.id << endl
      << "   Name: " << dealer.name << endl
      << "   Chips: " << dealer.numChips << " ($"
      << dealer.numChips*VALUE_CHIP << ")\n";

    // Stage 2.
    // deal 2 cards to each player.
    while (deckIndex < numPlayers * 2){
      for (int j = 0; j < numPlayers; j++){
        for (int k = 0; k < 2; k++){ // 2 cards
          // get the card number of the given card in the deck.
          players[j].cards[players[j].counter] =
            determineCardNumber(deck[deckIndex]);
          // get the update the score with the points of dealt card.
          players[j].score +=
          determinePoints(players[j].cards[players[j].counter],
            players[j].score);
          // update indexes.
          deckIndex++;
          players[j].counter++;
        }
      }

      // get the card number of the given card in the deck.
      dealer.cards[dealer.counter] = determineCardNumber(deck[deckIndex]);
      // get the update the score with the points of dealt card.
      dealer.score += determinePoints(dealer.cards[dealer.counter],
        dealer.score);
      // update indexes.
      deckIndex++;
      dealer.counter++;
    }

    // Stage 3.
    for (int j = 0; j < numPlayers; j++){
      // display the cards that the player already has.
      cout << "\nPlayer " << j + 1 << ":\n   Cards: ";
      for (int i = 0; i < players[j].counter; i++){
        if (i == players[j].counter - 1){
          displayCard(players[j].cards[i]);
          cout << endl;
        }
        else{
          displayCard(players[j].cards[i]);
          cout << ", ";
        }
      }
      // display user score.
      cout << "   Score: " << players[j].score << endl;
      if (players[j].score < 21){
        do{
          // ask the player to hit or stay.
          cout << "   Hit or Pass? ";
          cin >> hitOrPass;

          // update player info if player withdrew.
          if (hitOrPass == "pass")
            players[j].isWithdrawn = true;
          else{
            // deal another card to the player.
            players[j].cards[players[j].counter] =
              determineCardNumber(deck[deckIndex]);
            // update player's score.
            players[j].score +=
              determinePoints(players[j].cards[players[j].counter],
                players[j].score);
            // udate indexes.
            deckIndex++;
            players[j].counter++;

            // display p;ayer's cards and score.
            cout << "   Cards: ";
            for (int i = 0; i < players[j].counter; i++){
              if (i == players[j].counter - 1){
                displayCard(players[j].cards[i]);
                cout << endl;
              }
              else{
                displayCard(players[j].cards[i]);
                cout << ", ";
              }
            }
            cout<< "   Score: " << players[j].score << endl;

            // check if player busted.
            if (players[j].score >= 21)
              players[j].isWithdrawn = true;
            }
        } while (players[j].isWithdrawn == false);
      }
    }

    // display dealer's cards and score.
    cout << "\nDealer:\n   Cards: ";
    for (int i = 0; i < dealer.counter; i++){
      if (i == dealer.counter - 1){
        displayCard(dealer.cards[i]);
        cout << endl;
      }
      else{
        displayCard(dealer.cards[i]);
        cout << ", ";
      }
    }
    cout << "   Score: " << dealer.score << endl;
    if (dealer.score < 21){
      do{
        // deal one card to the dealer.
        dealer.cards[dealer.counter] = determineCardNumber(deck[deckIndex]);
        // update dealer's score.
        dealer.score += determinePoints(dealer.cards[dealer.counter],
          dealer.score);
        // update indexes.
        deckIndex++;
        dealer.counter++;

        // display dealer's cards and score.
        cout << "   Cards: ";
        for (int i = 0; i < dealer.counter; i++){
          if (i == dealer.counter - 1){
            displayCard(dealer.cards[i]);
            cout << endl;
          }
          else{
            displayCard(dealer.cards[i]);
            cout << ", ";
          }
        }
        cout << "   Score: " << dealer.score << endl;

        // check if dealer is over 16.
        if (dealer.score >= 17)
          dealer.isWithdrawn = true;
      } while (dealer.isWithdrawn == false);
    }

    // Stage 5.
    // display the results of the game.
    for (int j = 0; j < numPlayers; j++){
      if (players[j].score>21){ // player busts.
        cout << "\nPlayer " << j + 1 << " BUSTED! Dealer wins!\n";
        players[j].numChips -= 1;
        dealer.numChips += 1;
      }
      else if (dealer.score > 21){ // dealer busts.
        cout << "\nPlayer " << j + 1 << " wins! Dealer BUSTED!\n";
        dealer.numChips -= 1;
        players[j].numChips += 1;
      }
      else if (players[j].score < dealer.score){ // dealer has higher score.
        cout << "\nPlayer " << j + 1 << " lost. Dealer wins!\n";
        players[j].numChips -= 1;
        dealer.numChips += 1;
      }
      else if (players[j].score > dealer.score){ // player has higer score.
        cout << "\nPlayer " << j + 1 << " wins! Dealer lost.\n";
        dealer.numChips -= 1;
        players[j].numChips += 1;
      }
      else{ // dealer and player have same score.
        cout << "\nPlayer " << j + 1 << " and Dealer push.\n";
      }
    }

    // display final number of chips.
    cout << "\nFinal Score:\n";
    for (int i = 0; i < numPlayers; i++){
      cout << "\n Player " << i + 1 << ":\n"
        << "   Chips: " << players[i].numChips << " ($"
        << players[i].numChips*VALUE_CHIP << ")\n";
    }
    cout << "\n Dealer:\n" << "   Chips: " << dealer.numChips << " ($"
      << dealer.numChips*VALUE_CHIP << ")\n";

    // ask user whether to play again.
    cout << "\nPlay again? (yes/no): ";
    cin >> playAgain;
  } while (playAgain == "yes");

  // Return 0 to the operating system.
  return 0;
}

/****************************************************************
 *                            swap                              *
 * This function switch the values of two elements.             *
 * Parameter: element1 - integer pointer to an array element.   *
 *  element2 - integer pointer to an array element.             *
 * Return : element1 - the new value of the first array element.*
 ****************************************************************/
int swap(int* element1, int* element2){
  int temp = *element1; // Save first element into temp variable.
  *element1 = *element2;
  *element2 = temp;

  // Return the new first element.
  return *element1;
}

/****************************************************************
 *                            shuffle                           *
 * This function shuffle the elements of an integer array by    *
 * swaping random elements of the array.                        *
 * Parameter: ticket - an integer array.                        *
 *  nSwap - number of times to swap elements.                   *
 * Return: ticket[0] - first element of the shuffled array.     *
 ****************************************************************/
int shuffle(int ticket[], int nSwap){
  // Declare local variables.
  int card1;
  int card2;

  // Use current time as seed for rand function.
  srand(time(NULL));

  // Swap two random cards with each other.
  for (int i = 0; i < NUM_SWAPS; i++){
    // Pick two random cards.
    card1 = rand() % (NUM_CARDS*NUM_SUITS*NUM_DECKS);
    card2 = rand() % (NUM_CARDS*NUM_SUITS*NUM_DECKS);

    // If the two cards are diffent, swap them.
    if (card1 != card2)
      swap(ticket[card1], ticket[card2]);
  }

  // Return the first card after shuffling.
  return ticket[0];
}

/****************************************************************
 *                            shufflePlayers                    *
 * This function shuffle the elements of a person array by      *
 * swaping random elements of the array.                        *
 * Parameter: players - a person array.                         *
 *  nSwap - number of times to swap elements.                   *
 * Return: Nothing.                                             *
 ****************************************************************/
void shufflePlayers(person players[], int nSwap){
  // Declare local variables.
  int player1;
  int player2;

  // Swap two random players with each other.
  for (int i = 0; i < NUM_SWAPS; i++){
    // Pick two random players.
    player1 = rand() % 7;
    player2 = rand() % 7;

    // If the two players are diffent, swap them.
    if (player1 != player2)
      swap(players[player1], players[player2]);
  }
}

/****************************************************************
 *                        determinePoints                       *
 * This function determines points based on the ticketnumber    *
 * provided.                                                    *
 * Parameter: ticketNumber - the ticketNumber of the card.      *
 *  score - the score of the player so far.                     *
 * Return: the points for that particular card.                 *
 ****************************************************************/
int determinePoints(int cardNumber, int score){
  if (cardNumber == 1){ // for aces.
    if (score + 11 > 21) // check if the player will bust with score of 11.
      return 1;
    else
      return 11;
  }
  else if (cardNumber > 1 && cardNumber < 11) // Number cards.
    return cardNumber;
  else // face cards.
    return 10;
}

/****************************************************************
 *                      determineCardNumber                     *
 * This function determines points based on the ticketnumber    *
 * provided.                                                    *
 * Parameter: ticketNumber - the ticketNumber of the card.      *
 * Return: the cardNumber of the card.                          *
 ****************************************************************/
int determineCardNumber(int ticketNumber){
  return (ticketNumber % (NUM_SUITS*NUM_CARDS)) % NUM_CARDS + 1;
}

/****************************************************************
 *                        displayCard                           *
 * This function displays card info based on cardNumber.        *
 * Parameter: cardNumber - the cardNumber of the card (1-13).   *
 * Return: Nothing.                                             *
 ****************************************************************/
void displayCard(int cardNumber){
  switch (cardNumber){
    case 1: cout << "Ace";
    break;
    case 11: cout << "Jack";
    break;
    case 12: cout << "Queen";
    break;
    case 13: cout << "King";
    break;
    default: cout << cardNumber;
  }
}
