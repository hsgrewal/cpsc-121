# Assignment 5

## Harkishan Singh Grewal

CPSC-121 - Programming Concepts
March 10, 2015
Written in C++

**Note:** Include "number_list.txt" file in the folder.

## Programming Assignment

### Binary Search
This C++ program performs the binary search algorithm. Binary search algorithm
finds the position of target value (search key) within a sorted array. For
simplicity, it is assumed that the array has been sorted in an ASCENDING order.
The concept of binary search is to split the sorted array in half and then,
rule out the half of data at each step or iteration. In each step, the search
algorithm compares the search key against the key value in the middle of array.
If the search key matches the key value in the middle of array, then the index
of middle element is returned. If the search key is less than the key value in
the middle of array, then the search algorithm repeats its actions on the left
half of array (left sub-array). Otherwise, the search algorithm repeats its
action on the right half of array (right sub-array).

Here is a possible scenario. When the program starts, it asks the user how many
numbers should be read from the input file. In this assignment, the text file,
“number list.txt”, holds the list of 1000 numbers. If the user enter 50, the
program should read the FIRST 50 numbers into an integer array. After the
numbers are read, the program requests the search key from the user. If the
search key is found, the program should display the found index and value. If
the search key is not found, the program should inform the user as well.

The program does the following:
  1. The program asks the user the number of integers should be read from the
    input file, “number list.txt”
  2. The program asks the user for the search key
  3. The program has a C++ function to initialize the array containing a list
    of integers.
    *int \*initalizeArray(int nRead);*
      - Parameter: nRead - the number of integers read from the input file
      - Return value: The function returns a pointer to the dynamically
        allocated array having the same size as nRead. This array is created on
        the heap
  4. The program has a C++ function to perform the binary search
    *int binarySearch(int key, const int *start, const int *end);*
      - Parameter: key - the search key
      - Parameter: start - a pointer to the constant integer, which is the
          first element of array
      - Parameter: end - a pointer to the constant integer, which is the last
          element of array
      - Return value: If the search key is found, return the corresponding
          index of array element. If the search key is not found, return -1
  5. After reading the input file, the resource is released
  6. After done using the array on heap, the array is deleted
  7. The program displays proper messages

### Card Shuffler
This C++ program shuffles 4 decks of standard 52 cards. A standard deck of 52
cards has 4 suits: spade, heart, diamond and club. Each suit contains 13 cards:
Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, and King. For the purposes of
this program, Ace is 1; Jack is 11, Queen is 12; and King is 13. In the other
words, a number is assigned to each face card, making the 13 cards: 1 (Ace),
2, 3, 4, 5, 6, 7, 8, 9, 10, 11 (Jack), 12 (Queen) and 13 (King). The decks are
numbered as 0, 1, 2, and 3 for the first, second, third, and fourth deck
respectively. The suits (spade, heart, diamond, and club) are numbered as 1,
2, 3, and 4 respectively. Each card from the four decks is associated with an
unique ticket number. For example, for the first deck, the 13 spades from Ace
to King have ticket numbers 0, 1, 2, 3, 4, ... 11, and 12 respectively. The
13 hearts from Ace to King in the first deck have ticket numbers 13, 14, 15,
... 24, and 25 respectively. The 13 diamonds from Ace to King in the first
deck have ticket numbers 26, 27, 28, ... 37, and 38. The 13 clubs from Ace to
King in the first deck have ticket numbers 39, 40, 41, ... 50, and 51. For the
52 cards in the second deck, the numbering continues from the first deck,
following the same pattern. The 13 spades from Ace to King in the second deck
have ticket numbers 52, 53, 54, ... 63, and 64 ...

A 1D array is used to hold all the ticket numbers associated with each card.
Since there are 208 cards in 4 decks, the integer array of 208 elements can
hold the ticket numbers from 0 to 207, using the numbering scheme described
above.

Here is one possible scenario: When the program starts, it shuffles the 4
decks of cards, 208 cards in total, by shuffling an array of ticket numbers.
Then, it asks the user the number of cards that should be dealt from the
dealer. If the user enters 3, then the program should deal the FIRST 3 cards
in the array of shuffled ticket numbers. If the first three cards have the
ticket numbers 12, 60, and 200 respectively, then the program should display
both the ticket number and the card information. For example, 12 is the king
of spade from the first deck, 60 is the number 9 of spade from the second deck
and 200 is the number 6 of club from the fourth deck.

The program does the following:
  1. The number of decks is a constant of 4
  2. The number of suits is a constant of 4
  3. The number of cards is a constant of 13
  4. The number of swaps is a constant of 1000
  5. The program stores each ticket number associated with each card in an 1D
    array. The 1D array has ticket numbers from 0 to 207.
  6. Swap the contents of two array elements
    *int swap(int *element1, int *element2);*
    - Parameter: element1 and element2 are the integer pointers to the two
      array elements. These two array elements are about to be swapped
    - Return value: the value of first element AFTER swapped
  7. Shuffle the 4 decks of cards by shuffling the ticket numbers in an 1D
    array. A single step of shuffling is done by the two operations: first,
    randomly choosing two array element; and second, swap them. The same
    swapping procedure for the specified number of times. Thus, the ticket
    numbers will be in an random order.
    *int shuffle(int card[], int nSwap);*
    - Parameter: card - 1D array of ticket numbers associated with each card
    - Parameter: nSwap - the number of swaps
    - Return value: AFTER shuffling, the function returns the ticket number
      of the first array element
  8. Determine the card information by its ticket number
    *int determineCardInformation(int ticketNumber, int *deck, int *suit,
      int *cardNumber);*
    - Parameter: ticketNumber - the ticket number associated with the card
    - Parameter: deck - the integer pointer to the deck number (from 1 to 4)
    - Parameter: suit - the integer pointer to the suit number (from 1 to 4)
    - Parameter: cardNumber - actual card number (from 1 to 13)
    - Return value: the actual card number instead of ticket number
  9. The program asks the user how many cards to be dealt
  10. The program displays the ticket number and information associated with
    the card(s)
    *void displayCardInformation(int ticketNumber, int deck, int suit,
      int cardNumber);*
    - Parameter: ticketNumber - the ticket number associated with the card
    - Parameter: deck - the deck number
    - Parameter: suit - the suit number
    - Parameter: cardNumber - the actual card number
    - Return value: none.
