/*
 * This program calculates the BMI of each student based on a database of
 * students. Then, it determines the weight status of each student.
 *
 * Harkishan Singh Grewal
 * February 9, 2015
 * Due February 14, 2015
 */

#include<iostream>
#include<string>
using namespace std;

// Declare function prototypes
int searchName(string, int, string name[]);
double bmiCalculator(double, double);
void weightStatus(double);

int main()
{
  // Declare constants.
  const int SIZE = 3;

  // Declare the arrays.
  string name[SIZE] = { "bender", "leela", "fry" };
  double height[SIZE] = { 75.4, 70.8, 65.0 };
  double weight[SIZE] = { 200.2, 140.7, 100.9 };

  // Declare variables.
  string targetName;
  int index;
  double bmi;

  // Ask user for a target name.
  cout << "Enter name to be searched: ";
  cin >> targetName;

  // Get the index corresponding to the name.
  index = searchName(targetName, SIZE, name);

  // Check if name is valid.
  while (index < 0)
  {
    // Ask user for another target name.
    cout << "\nInvalid name! Enter new name to be searched: ";
    cin >> targetName;

    // Get the index corresponding to the name.
    index = searchName(targetName, SIZE, name);
  }

  // Get bmi from function.
  bmi = bmiCalculator(height[index], weight[index]);

  // Print out the bmi of the student.
  cout << "\nBMI: " << bmi << endl;

  // Call weightStatus function to determine weight status.
  weightStatus(bmi);

  // Return 0 to the operating system.
  return 0;
}

/************************************************
 *                searchName                    *
 * This function searches for a match to the    *
 * target name.                                 *
 * Inputs:                                      *
 *  targetName (string) name given by user      *
 *  SIZE (int) the size of array                *
 *  name (array of string type)                 *
 * Return:                                      *
 *  index (int)                                 *
 ************************************************/
int searchName(string targetName, int SIZE, string name[])
{
  // Delcare searchName variables.
  int index = -1; // Default value if name is not found.

  // For loop to search for targetName.
  for (int i = 0; i < SIZE; i++)
  {
    if (name[i] == targetName)
    {
      index = i;
      break; // Break loop if targetName is found.
    }
  }

  // Return index.
  return index;
}

/************************************************
 *                bmiCalculator                 *
 * This function calculates the BMI.            *
 * Inputs:                                      *
 *  height (double)	of the student              *
 *  weight (double)	of the student              *
 * Return:                                      *
 *  bmi (double)                                *
 ************************************************/
double bmiCalculator(double height, double weight)
{
  // Compute and return the BMI
  return weight * (703 / (height * height));
}

/************************************************
 *                weightStatus                  *
 * This function determines and prints weight   *
 * status.                                      *
 * Inputs:                                      *
 *  BMI (double)                                *
 * Return:                                      *
 *  Nothing.                                    *
 ************************************************/
void weightStatus(double bmi)
{
  // Determine the weight status.
  if (bmi < 18.5)
  {
    cout << "The student is underweight.\n\n";
  }
  else if (bmi>25)
  {
    cout << "The student is overweight.\n\n";
  }
  else
  {
    cout << "The student is at optimal weight.\n\n";
  }
}
