/*
 * This program optimizes the deminsions of a cylindrical can by minimizing
 * cost and finding optimal radius and height.
 *
 * Harkishan Singh Grewal
 * February 3, 2015
 * Due February 6, 2015
 */

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
  // Declare constants.
  const double PI = 3.14159;
  const double UNIT_PRICE = 0.002;
  const double VOLUME = 330;

  // Declare variables.
  double radius = 1.0;
  double optRadius;
  double height;
  double optHeight;
  double surfaceArea;
  double cost = 0;
  double minCost=0; // Arbitary high cost assigned.
  double temp = 5;

  // Find which radius gives lowest cost.
  for (int i = 0; i < 10; i++)
  {
    // Rewrite volume formula to get height in terms of radius.
    height = (VOLUME / (PI*radius*radius));
    surfaceArea = 2 * PI*radius*radius + 2 * PI*radius*height;
    cost = UNIT_PRICE*surfaceArea;
    cout << "cost:" << cost << "\ntemp-cost:" << (cost<temp) << "\nradius:"
      << radius << endl;

    // Find lowest cost.
    if (cost<temp)
    {
      minCost = cost; // Update minCost to a lower cost is found.
      optHeight = height; // Keep track of radius corresponding to a lower cost.
      optRadius = radius; // Keep track of height corresponding to a lower cost.
      radius += (radius / ((i + .25)*(i + .25)));
    }
    else
    {
      radius =radius/2;
    }
    temp = cost;
    cout << "temp: " << temp << endl;
  }

  // Display results.
  cout << "Optimal radius: " << setprecision(4) << fixed << optRadius
    << " (cm)\n";
  cout << "Optimal height: " << optHeight << " (cm)\n";
  cout << "Minimal cost: $" << minCost << endl << endl;

  return 0;
}
