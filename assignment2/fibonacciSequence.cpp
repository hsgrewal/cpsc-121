/*
 * This program prints out the Fibonacci Sequence to the Nth term.
 *
 * Harkishan Singh Grewal
 * February 3, 2015
 * Due February 6, 2015
 */

#include <iostream>

using namespace std;

int main()
{
  // Constant varibales.
  const int F_NUM1 = 0;
  const int F_NUM2 = 1;

  // Variables.
  int currentNum;
  int previousNum = F_NUM2;
  int secondPreviousNum = F_NUM1;
  int numberOfTerms;

  // Get how many terms to display from user.
  cout << "Enter the number of Fibonacci numbers to be displayed: ";
  cin >> numberOfTerms;

  if (numberOfTerms < 1) // For user input 0 or less.
  {
    cout << "\nNo Fibonacci Sequence to be displayed.\n\n";
  }
  else if (numberOfTerms==1) // For first number.
  {
    cout << "\n0.\n\n";
  }
  else if (numberOfTerms == 2) // For first two numbers.
  {
    cout << "\n0, 1.\n\n";
  }
  else // For all other Fibonacci Numbers.
  {
    cout << "\n0, 1, ";

    for (int k = 2; k < numberOfTerms; k++)
    {
      currentNum = previousNum + secondPreviousNum;
      if (k == numberOfTerms - 1) // To print last number requested.
      {
        cout << currentNum << ".\n\n";
      }
      else // To print intermediate numbers.
      {
        cout << currentNum << ", ";
        // Update variables.
        secondPreviousNum = previousNum;
        previousNum = currentNum;
      }
    }
  }
  return 0;
}
