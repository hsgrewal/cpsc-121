/*
 * This program asks the user for height and weight to calculate Body
 * Mass Index(BMI) and determine weight condition. It, then, displays BMI
 * and weight condition.
 *
 * Harkishan Singh Grewal
 * January 23, 2015.
 * Due January 30, 2015.
 */

#include <iostream>

using namespace std;

int main()
{
  // Declare variables.
  double weight;
  double height;
  double bmi;

  // Ask user to enter weight in pounds and store it into a variable.
  cout << "Enter weight (in pounds): ";
  cin >> weight;
  while (weight < 0) // Validate input.
  {
    cout << "ERROR! Invalid input! Enter weight (in pounds): ";
    cin >> weight;
  }

  // Ask user to enter height in inches and store it into a variable.
  cout << "Enter height (in inches): ";
  cin >> height;
  while (height < 0) // Validate input.
  {
    cout << "ERROR! Invalid input! Enter height (in inches): ";
    cin >> height;
 }

  // Calculate BMI.
  bmi = weight*(703 / (height*height));

  // Determine weight condition based of BMI and display results.
  if (bmi < 18.5)
  {
    cout << "\nBMI: " << bmi << " ----- underweight\n\n";
  }
  else if (bmi>25)
  {
    cout << "\nBMI: " << bmi << " ----- overweight\n\n";
  }
  else
  {
    cout << "\nBMI: " << bmi << " ----- optimal weight\n\n";
  }

  // Return 0 to main function.
  return 0;
}
