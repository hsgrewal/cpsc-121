/*
 * This program shifts a series of 10 random numbers to the left.
 *
 * Harkishan Singh Grewal
 * February 3, 2015
 * Due February 6, 2015
 */

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
  // Declare and intialize constants.
  const int SIZE = 10;

  // Delcare a temporary variable.
  int temp;

  // Declare array for random numbers.
  int randNums[SIZE];

  // Use current time as seed for rand function.
  srand(time(NULL));

  // Generate random numbers and store them into array. Print stored numbers.
  cout << "Before the circular-left-shift operation: ";
  for (int i = 0; i < SIZE; i++)
  {
    if (i == SIZE - 1) // For last index of array.
    {
      randNums[i] = rand() % 101;
      cout << randNums[i] << ".\n";
    }
    else
    {
      randNums[i] = rand() % 101;
      cout << randNums[i] << ", ";
    }
  }

  // Shift random numbers in the array to left by 1 position.
  cout << "After the circular-left-shift operation: ";
  for (int i = 0; i < SIZE; i++)
  {
    if (i == 0)
    {
      // Store first element of array into temp for later use.
      temp = randNums[i];
      // Store second element of array into first.
      randNums[i] = randNums[i + 1];
      cout << randNums[i] << ", ";
    }
    else if (i == SIZE - 1) // Assign temp to last element and print it.
    {
      randNums[i] = temp;
      cout << randNums[i] << ".\n\n";
    }
    else // Shift elements left by 1.
    {
      randNums[i] = randNums[i + 1];
      cout << randNums[i] << ", ";
    }
  }

  return 0;
}
