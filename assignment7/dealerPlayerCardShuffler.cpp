// Harkishan Grewal
// harkishangrewal@csu.fullerton.edu
// This program implements a card shuffler, dealer and player
// class.
// April 24, 2015
// Due April 28, 2015

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

class CardShuffler{
private:
  int N;
  int index;
  int* cards;
public:
  CardShuffler(){}

  CardShuffler(int newN){
    N = newN;
    index = 0;
    cards = new int[N * 52];
    for (int i = 0; i < N * 52; i++){
      cards[i] = i;
    }
    shuffleCards();
  }

  CardShuffler& operator=(const CardShuffler& rhs) {
    N = rhs.N;
    index = rhs.index;

    // compute the total number of cards.
    int nCard = N * 52;

    // Allocate a memory on heap.
    cards = new int[nCard];

    for (int i = 0; i < nCard; i++) {
      cards[i] = rhs.cards[i];
    }

    // Return the object reference on the left hand side of assignment operator.
    return *this;
  }

  int shuffleCards(){
    srand(time(NULL));

    for (int i = 0; i < 1000; i++) {
      // Get the first index randomly
      int index1 = rand() % (N * 52);

      // Get the second index randomly.
      int index2 = rand() % (N * 52);

      // if the two indices are the same, i need to do another random selections.
      if (index1 == index2) {
        i--;
      }
      else{
        swap(&cards[index1], &cards[index2]);
      }
    }
    return cards[0];
  }

  // swap function
  int swap(int* element1, int* element2){
    int temp = *element1;
    *element1 = *element2;
    *element2 = temp;
    return temp;
  }

  int passCard(){
    index += 1;
    return cards[index - 1];
    //return cards[0];
  }

  ~CardShuffler(){
    delete[] cards;
  }
};

class Dealer{
private:
  string name;
  int card;
  CardShuffler shuffler;

public:
  //Dealer(string newName, CardShuffler shuffler){
  Dealer(int nDeck, string newName) {
    name = newName;

    CardShuffler temp(nDeck);
    shuffler = temp;

    card = shuffler.passCard();
  }

  int setCard(int new_card) {
    card = new_card;
    return card;
  }

  int getCard(){
    return card;
  }
};

class Player{
private:
  string name;
public:
  Player(string newName){
    name = newName;
  }
  int getCard(Dealer& dealer){
    return dealer.getCard();
  }
};

int main(){
  int decks;
  int suit;
  int numPlayers;
  string name;
  int card;

  cout << "Enter number of decks: ";
  cin >> decks;

  CardShuffler shuffler(decks);

  Dealer dealer(decks, "bender");

  // Shuffler is out of scope here.
  cout << "\nEnter number of players: ";
  cin >> numPlayers;

  for (int i = 0; i < numPlayers; i++){
    cout << "\nEnter player " << i + 1 << " name: ";
    cin >> name;

    Player player(name);

    string getCard;

    do{
      // Dealer gets a card from shuffler.
      int new_card = shuffler.passCard();
      dealer.setCard(new_card);

      card = player.getCard(dealer);
      cout << "\nDeck: " << (card / 52) + 1 << " Suit: ";
      suit = (card % 52) / 13;
      if (suit == 0){
        cout << "Spade ";
      }
      else if (suit == 1){
        cout << "Heart ";
      }
      else if (suit == 2){
        cout << "Diamond ";
      }
      else{
        cout << "Club ";
      }

      cout << "Card: " << ((card % 52) % 13) + 1;
      cout << "\nget another card (yes/no): ";
      cin >> getCard;
    } while (getCard == "yes");

    cout << endl;
  }

  // Return 0 to operating system.
  return 0;
}
