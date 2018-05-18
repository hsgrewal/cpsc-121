/*
 * This program takes two inputs (points) from the user and displays
 * the equation of the straight line passing through both points.
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
  double xCord1;
  double yCord1;
  double xCord2;
  double yCord2;
  double slope;
  double yIntercept;

  // Welcome user to program and describe what it does.
  cout << "Welcome! Enter coordinates of two points to find \nthe equation of "
    << "a straight line between those points.\n\n";

  // Ask user to input two points and store the input.
  cout << "Enter the x coordinate of the first point: ";
  cin >> xCord1; // x-coordinate of point 1.
  cout << "Enter the y coordinate of the first point: ";
  cin >> yCord1; // y-coordinate of point 1.
  cout << "Enter the x coordinate of the second point: ";
  cin >> xCord2; // x-coordinate of point 2.
  cout << "Enter the y coordinate of the second point: ";
  cin >> yCord2; // y-coordinate of point 2.

  // Calculate slope of line between given points.
  slope = (yCord2 - yCord1) / (xCord2 - xCord1);

  // Calculate yIntercept of the line.
  yIntercept = yCord2 - (slope*xCord2);

  // Display the line equation.
  cout << "\nEquation of the line is: y = " << slope << "x + " << yIntercept
    << endl << endl;

  // Return 0 to main function.
  return 0;
}
