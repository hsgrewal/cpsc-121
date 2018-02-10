/*
 * This program allows the user to calculate the area of various shapes based
 * on input and choice.
 *
 * Harkishan Singh Grewal
 * February 9, 2015
 * Due February 14, 2015
 */

#include<iostream>
using namespace std;

// Declare function prototypes.
void displayMenu();
double areaOfTriangle(double, double);
double areaOfRectangle(double, double);
double areaOfCircle(double);

int main()
{
  // Declare main variables.
  int choice;
  double base;
  double height;
  double width;
  double length;
  double radius;

  // Call displayMenu function to give options.
  displayMenu();
  cin >> choice;

  // Call area functions depending on choice.
  if (choice == 1) // For area of triangle.
  {
    // Get base and height of triangle from user.
    cout << "\nEnter base of triangle: ";
    cin >> base;
    cout << "Enter height of triangle: ";
    cin >> height;

    // Print out the area.
    cout << "\nThe triangle of base " << base << " and height " << height
      << " has an area of " << areaOfTriangle(base, height) << ".\n\n";
  }
  else if (choice == 2)
  {
    // Get width and length of rectangle from user.
    cout << "\nEnter width of rectangle: ";
    cin >> width;
    cout << "Enter length of rectangle: ";
    cin >> length;

    // Print out the area.
    cout << "\nThe rectangle of width " << width << " and length " << length
      << " has an area of " << areaOfRectangle(width, length) << ".\n\n";
  }
  else if (choice == 3)
  {
    // Get radius of the circle from user.
    cout << "\nEnter radius of circle: ";
    cin >> radius;

    // Print out the area.
    cout << "\nThe circle of radius " << radius << " has an area of "
      << areaOfCircle(radius) << ".\n\n";
  }
  else
  {
    // Print nothing. Default option for user to quit the program.
  }

  // Return 0 to operating system.
  return 0;
}

/************************************************
 *                 displayMenu                  *
 * This function prints out the menu.           *
 * Inputs:                                      *
 *  None.                                       *
 * Return:                                      *
 *  Nothing.                                    *
 ************************************************/
void displayMenu()
{
  cout << "Welcome to Area Calculator! Choose a shape to calculate"
    << "the area.\n\n   1. Triangle\n   2. Rectangle\n   3. Circle\n"
    << "   4. Quit\n\n";
}

/************************************************
 *                 areaOfTriangle               *
 * This function calculates the area of a       *
 * triangle.                                    *
 * Inputs:                                      *
 *  base (double) of triange                    *
 *  height (double)	of triangle                 *
 * Return:                                      *
 *  areaOfTriangle (double) of the triangle     *
 ************************************************/
double areaOfTriangle(double base, double height)
{
  // Compute and return the area of a triangle.
  return 0.5 * base * height;
}

/************************************************
 *                areaOfRectangle               *
 * This function calculates the area of a       *
 * rectangle.                                   *
 * Inputs:                                      *
 *  width (double) of rectangle                 *
 *  length (double) of rectangle                *
 * Return:                                      *
 *  areaOfRectangle (double)                    *
 ************************************************/
double areaOfRectangle(double width, double length)
{
  // Compute and return the area of a rectangle.
  return width * length;
}

/************************************************
 *                areaOfCircle                  *
 * This function calculates the area of a       *
 * circle.                                      *
 * Inputs:                                      *
 *  radius (double)                             *
 * Return:                                      *
 *  areaOfCircle (double)                       *
 ************************************************/
double areaOfCircle(double radius)
{
  // Declar constants.
  const double PI = 3.14159;

  // Compute and return the area of a circle.
  return PI*radius*radius;
}
