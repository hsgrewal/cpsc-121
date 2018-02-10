/*
 * This program asks user to enter a point and determines the loaction of
 * the plane.
 *
 * Harkishan Singh Grewal
 * January 24, 2015
 * Due January 30, 2015
 */

#include<iostream>

using namespace std;

int main()
{
  // Declare variables
  int xCord;
  int yCord;

  // Ask the user to enter the coordinates of the point.
  cout << "Enter the x coordinate of the point: ";
  cin >> xCord;
  cout << "Enter the y coordinate of the point: ";
  cin >> yCord;

  // Determine the loaction of the point and display result.
  if (xCord > 0 && yCord > 0)
  {
    cout << "\nThe point (" << xCord << "," << yCord << ") is in"
      << "Quadrant I.\n\n";
  }
  else if (xCord < 0 && yCord > 0)
  {
    cout << "\nThe point (" << xCord << "," << yCord << ") is in"
      << "Quadrant II.\n\n";
  }
  else if (xCord < 0 && yCord < 0)
  {
    cout << "\nThe point (" << xCord << "," << yCord << ") is in"
      << "Quadrant III.\n\n";
  }
  else if (xCord > 0 && yCord < 0)
  {
    cout << "\nThe point (" << xCord << "," << yCord << ") is in"
      << "Quadrant IV.\n\n";
  }
  else if (xCord == 0 && yCord == 0)
  {
    cout << "\nThe point (" << xCord << "," << yCord << ") is at"
      << "the Origin.\n\n";
  }
  else if (xCord > 0 && yCord == 0)
  {
    cout << "\nThe point (" << xCord << "," << yCord << ") is on"
      << "positive X-axis.\n\n";
  }
  else if (xCord < 0 && yCord == 0)
  {
    cout << "\nThe point (" << xCord << "," << yCord << ") is on"
      << "negative X-axis.\n\n";
  }
  else if (xCord == 0 && yCord > 0)
  {
    cout << "\nThe point (" << xCord << "," << yCord << ") is on"
      << "positive Y-axis.\n\n";
  }
  else if (xCord == 0 && yCord < 0)
  {
    cout << "\nThe point (" << xCord << "," << yCord << ") is on"
      << "negative Y-axis.\n\n";
  }
  else
  {
    cout << "\nThe point (" << xCord << "," << yCord << ") is undefined.\n\n";
  }

  // Return 0 to the main function.
  return 0;
}
