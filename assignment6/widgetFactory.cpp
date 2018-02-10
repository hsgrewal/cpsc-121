/*
 * This program calculates the time needed to manufacture a given number
 * of widgets provided by the user.
 *
 * Harkishan Singh Grewal
 * April 16, 2015
 * Due April 22, 2015
 */

#include<iostream>

using namespace std;

class WidgetFactory{
private:
  int widgets;
  double time; // in hours.
public:
  int getWidgets(){
    return widgets;
  }
  int setWidgets(int numWidgets){
    widgets = numWidgets;
    return widgets;
  }
  double findTime(){
    time = getWidgets() / 10.0; // 10 because 10 widgets per hour.
    return time;
  }
};

int main(){
  // Declare main variables
  int numWidgets;
  WidgetFactory order;

  // Ask user to enter the number of widgets to be manufactured.
  cout << "Enter number of widgets to be manufactured: ";
  cin >> numWidgets;
  while (numWidgets < 0)
  {
    cout << "ERROR! Enter number of widgets to be manufactured: ";
    cin >> numWidgets;
  }

  // Set widgets to the user's input.
  order.setWidgets(numWidgets);

  // Display time.
  cout << "\nThe manufacturing time is " << order.findTime() << " hours ("
    // 16 because 2 8-hour shifts per day.
    << order.findTime() / 16.0 << " days).\n\n";

  // Return 0 to the operating system.
  return 0;
}
