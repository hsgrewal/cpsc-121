/*
 * This program classifies 10 random numbers between 0-100 into 3 groups.
 *
 * Harkishan Singh Grewal
 * February 3,2015
 * Due February 6, 2015
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  // Declare and intialize constants.
  const int SIZE = 10;

  // Declare 3 arrays to hold values for each group.
  int group1[SIZE]; // For values 0-33.
  int group2[SIZE]; // For values 34-66.
  int group3[SIZE]; // For values 67-100.

  // Declare variables.
  int randNum;
  int g1Counter = 0; // Count number of elements entered in group1 array.
  int g2Counter = 0; // Count number of elements entered in group2 array.
  int g3Counter = 0; // Count number of elements entered in group3 array.

  // Give current time as seed for rand function.
  srand(time(NULL));

  // Get 10 random numbers and classify them.
  for (int i = 0; i < SIZE; i++)
  {
    randNum = rand() % 101;
    if (randNum < 34)
    {
      group1[g1Counter] = randNum;
      g1Counter++;
    }
    else if (randNum < 67)
    {
      group2[g2Counter] = randNum;
      g2Counter++;
    }
    else
    {
      group3[g3Counter] = randNum;
      g3Counter++;
    }
  }

  // Print out numbers in group1.
  cout << "The Numbers in Group 1 (0-33) are: ";
  for (int i = 0; i < g1Counter; i++)
  {
    if (i == g1Counter - 1) // For last index of array.
    {
      cout << group1[i] << ".\n";
    }
    else
    {
      cout << group1[i] << ", ";
    }
  }

  // Print out numbers in group2.
  cout << "The Numbers in Group 2 (34-66) are: ";
  for (int i = 0; i < g2Counter; i++)
  {
    if (i == g2Counter - 1) // For last index of array.
    {
      cout << group2[i] << ".\n";
    }
    else
    {
      cout << group2[i] << ", ";
    }
  }

  // Print out numbers in group3.
  cout << "The Numbers in Group 3 (67-100) are: ";
  for (int i = 0; i < g3Counter; i++)
  {
    if (i == g3Counter - 1) // For last index of array.
    {
      cout << group3[i] << ".\n\n";
    }
    else
    {
      cout << group3[i] << ", ";
    }
  }

  return 0;
}
