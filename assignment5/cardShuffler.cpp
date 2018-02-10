/*
 * This program shuffles 4 decks of playing cards and deals a certain number
 * of cards. It then displays information about those dealt cards.
 *
 * Harkishan Singh Grewal
 * March 15, 2015
 * Due March 17, 2015
 */

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

// Delcare constants.
const int NUM_DECKS = 4;
const int NUM_SUITS = 4;
const int NUM_CARDS = 13;
const int NUM_SWAPS = 1000;

// Declare function prototypes.
int swap(int* element1, int* element2);
int shuffle(int card[], int nSwap);
int determineCardInformation(int tickerNumber, int*deck, int* suit,
  int* cardNumber);
void displayCardInformation(int ticketNumber, int deck, int suit,
  int cardNumber);

int main()
{
  // Delcare main variables.
  int ticketNumbers[NUM_CARDS*NUM_DECKS*NUM_SUITS];
  int deck;
  int suit;
  int cardNumber;
  int numDeal;

  // Populate the ticketNumbers array.
  for (int i = 0; i < NUM_CARDS*NUM_DECKS*NUM_SUITS; i++)
    ticketNumbers[i] = i;

  // Shuffle the cards.
  shuffle(ticketNumbers, NUM_SWAPS);

  // Ask user for number of cards to deal.
  cout << "How many cards should be dealt: ";
  cin >> numDeal;

  // Validate the input.
  while (numDeal<0 || numDeal>208)
  {
    cout << "ERROR! How many cards should be dealt: ";
    cin >> numDeal;
  }

  cout << endl; // For display.

  // Loop to process the number of cards requested.
  for (int i = 0; i < numDeal; i++)
  {
    // Determine the infomation of the card.
    determineCardInformation(ticketNumbers[i], &deck, &suit, &cardNumber);

    // Display the information.
    cout << "Card " << i + 1;
    displayCardInformation(ticketNumbers[i], deck, suit, cardNumber);
  }

  // Return 0 to the operating system.
  return 0;
}

/****************************************************************
 *                          swap                                *
 * This function switch the values of two elements.             *
 * Parameter: element1 - integer pointer to an array element.   *
 *  element2 - integer pointer to an array element.             *
 * Return: element1 - the new value of the first array element. *
 ****************************************************************/
int swap(int* element1, int* element2)
{
  int temp = *element1; // Save first element into temp variable.
  *element1 = *element2;
  *element2 = temp;

  // Return the new first element.
  return *element1;
}

/****************************************************************
 *                          shuffle                             *
 * This function shuffle the elements of an integer array by    *
 * swaping random elements of the array.                        *
 * Parameter: ticket - an integer array.                        *
 *  nSwap - number of times to swap elements.                   *
 * Return: ticket[0] - first element of the shuffled array.     *
 ****************************************************************/
int shuffle(int ticket[], int nSwap)
{
  // Declare local variables.
  int card1;
  int card2;

  // USe current time as seed for rand function.
  srand(time(NULL));

  // Swap two random cards with each other.
  for (int i = 0; i < NUM_SWAPS; i++)
  {
    // Pick two random cards.
    card1 = rand() % (NUM_CARDS*NUM_SUITS*NUM_DECKS);
    card2 = rand() % (NUM_CARDS*NUM_SUITS*NUM_DECKS);

    // If the two cards are diffent, swap them.
    if (card1 != card2)
    {
      swap(ticket[card1], ticket[card2]);
    }
  }

  // Return the first card after shuffling.
  return ticket[0];
}

/****************************************************************
 *                  determineCardInformation                    *
 * This function determines the deck, suit, and number of a     *
 * card based on its ticket number.                             *
 * Parameter: ticketNumber - ticket number of a card.           *
 *  deck - integer pointer to the deck.                         *
 *  suit - integer pointer to the suit.                         *
 *  cardNumber - integer pointer to the card number.            *
 * Return: cardNumber - the real value of the card.             *
 ****************************************************************/
int determineCardInformation(int ticketNumber, int*deck, int* suit,
  int* cardNumber)
{
  /* Deck is the quotient of ticketNumber divided by number of cards in
  each deck.*/
  *deck = ticketNumber / (NUM_SUITS*NUM_CARDS);
  /* Suit is the remainder of ticketNumber divided by number of cards in
  each suit.*/
  *suit = (ticketNumber % (NUM_SUITS*NUM_CARDS)) / NUM_CARDS;
  *cardNumber = (ticketNumber % (NUM_SUITS*NUM_CARDS)) % NUM_CARDS;

  // Return the real value of the card.
  return *cardNumber;
}

/****************************************************************
 *                  displayCardInformation                      *
 * This function displays the deck, suit, and number of a card  *
 * based on its ticket number.                                  *
 * Parameter: ticketNumber - ticket number of a card.           *
 *  deck - the deck of the card.                                *
 *  suit - the suit of the card.                                *
 *  cardNumber - the card number of the card.                   *
 * Return: Nothing.                                             *
 ****************************************************************/
void displayCardInformation(int ticketNumber, int deck, int suit,
  int cardNumber)
{
  // Display ticket number.
  cout << " (Ticket Number " << ticketNumber << ") is the ";

  // Display card number.
  switch (cardNumber)
  {
    case 0: cout << "Ace of ";
    break;
    case 10: cout << "Jack of ";
    break;
    case 11: cout << "Queen of ";
    break;
    case 12: cout << "King of ";
    break;
    default: cout << cardNumber + 1 << " of "; // For cards 2 through 10.
  }

  // Display Suit.
  switch (suit)
  {
    case 0: cout << "Spade from deck ";
    break;
    case 1: cout << "Heart from deck ";
    break;
    case 2: cout << "Diamond from deck ";
    break;
    case 3: cout << "Club from deck ";
    break;
    default: cout << "ERROR!\n\n";
  }

  // Display deck number.
  cout << deck + 1 << ".\n\n";
}
