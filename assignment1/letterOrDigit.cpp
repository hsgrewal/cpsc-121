/*
 * This program takes in a character from the user and clasifies the character
 * and displays the result.
 *
 * Harkishan Singh Grewal
 * January 24, 2015
 * Due January 30, 2915
 */

#include <iostream>
using namespace std;

int main()
{
  // Declare variables.
  char inputCh;

  // Ask user to enter a character and store it into a variable.
  cout << "Enter a character to be classified: ";
  cin >> inputCh;

  // Classify the character and print out the result.
  if (isdigit(inputCh))
  {
    cout << "\nThe character '" << inputCh << "' is a digit.\n\n";
  }
  else if (isupper(inputCh))
  {
    cout << "\nThe character '" << inputCh << "' is an uppercase letter.\n\n";
  }
  else if (islower(inputCh))
  {
    cout << "\nThe character '" << inputCh << "' is a lowercase letter.\n\n";
  }
  else
  {
    cout << "\nThe character '" << inputCh << "' is neither a letter"
      << "nor digit.\n\n";
  }

  // Return 0 to the main function.
  return 0;
}
