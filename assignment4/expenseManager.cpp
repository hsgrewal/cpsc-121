/*
 * This program manages the expenses of 50 clients, displayiny their
 * information, monthly expenses, and highest expense.
 *
 * Harkishan Singh Grewal
 * March 7, 2015
 * Due March 10, 2015
 */

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

// Declare global constants.
const int NUM_CLIENTS = 50;
const int NUM_EXPENSES = 6;

// Declare function prototypes.
void displayMenu();
int searchId(int id[], int nId, int targetId);
void displayInformation(int id, string lastName, double expense[],
  int nExpense, double currentBalance);
double computeAverageExpense(double expense[], int nExpense);
double findMaxExpense(double expense[], int nExpense);
bool isOverBudget(double currentBalance, double nextPurchaseCost);

int main()
{
  // Declare main variables.
  int choice;
  ifstream inputFile;
  int id[NUM_CLIENTS];
  string name[NUM_CLIENTS];
  double expense[NUM_CLIENTS][NUM_EXPENSES+1];
  int targetId;
  int index;

  // Print menu.
  displayMenu();
  cin >> choice; // Get user's choice of action.

  // Validate choice.
  while (choice<1 || choice>5)
  {
    cout << "INVALID CHOICE! Enter choice.";
  }

  // Open file.
  inputFile.open("client_info.txt");

  // Check if file opened.
  if (inputFile)
  {
    // Intialize the arrays.
    for (int i = 0; i < NUM_CLIENTS; i++)
    {
      inputFile >> id[i];
      inputFile >> name[i];
      for (int j = 0; j < NUM_EXPENSES + 1; j++)
      {
        inputFile >> expense[i][j];
      }
    }

    // Close the file.
    inputFile.close();

    // Ask user for client ID.
    cout << "\nEnter client ID: ";
    cin >> targetId;

    // Call searchId function to find index.
    index = searchId(id, NUM_CLIENTS, targetId);

    // Validate index.
    while (index < 0)
    {
      // Ask user for client ID.
      cout << "\nERROR! Enter client ID: ";
      cin >> targetId;

      // Call searchId function to find index.
      index = searchId(id, NUM_CLIENTS, targetId);
    }

    if (choice == 1)
    {
      displayInformation(id[index], name[index], expense[index],
        NUM_EXPENSES, expense[index][NUM_EXPENSES]);
    }
    else if (choice == 2)
    {
      cout << "\nThe average monthly expense for the client is $"
        << computeAverageExpense(expense[index], NUM_EXPENSES)
        << endl << endl;
    }
    else if (choice == 3)
    {
      cout << "\nThe highest expense for the client was $"
        << findMaxExpense(expense[index], NUM_EXPENSES)
        << endl << endl;
    }
    else if (choice == 4)
    {
      // Declare local variable.
      double nextPurchase;

      // Asked user for the cost of next purchase.
      cout << "\nEnter the cost of next purchase: ";
      cin >> nextPurchase;

      if (isOverBudget(expense[index][NUM_EXPENSES], nextPurchase))
      {
        cout << "\nThe client's account will be over-budget with the "
          << "next purchase.\n\n";
      }
      else
      {
        cout << "\nThe client's account will not be over-budget with the "
          << "next purchase.\n\n";
      }
    }
    else
    {
      cout << "You have quit the program.";
    }
  }
  else // Print out error message if file failed to open.
  {
    cout << "Error opening the file.\n";
  }
  return 0;
}

/****************************************************
 *                  displayMenu                     *
 * This function displays the menu for the user.    *
 * Parameter: None                                  *
 * Return: Nothing                                  *
 ****************************************************/
void displayMenu()
{
  cout << "Please select an action:\n\n"
    << "    1. Display client's information\n"
    << "    2. Compute average of monthly expenses\n"
    << "    3. Find the maximum monthly expense\n"
    << "    4. Determine if client's account is over budget on next purchase.\n"
    << "    5. Quit\n\n";
}

/****************************************************
 *                  searchId                        *
 * This function finds the index of the client's ID *
 * in the array.                                    *
 * Parameter:                                       *
 *  id, an array of client IDs.                     *
 *  nId - number of IDs.                            *
 *  targetID - the ID to be searched                *
 * Return:                                         *
 *  i - the index of the target ID.                 *
 ****************************************************/
int searchId(int id[NUM_CLIENTS], int nId, int targetId)
{
  for (int i = 0; i < nId; i++)
  {
    if (id[i] == targetId)
    {
      return i;
    }
  }
  return -1;
}

/****************************************************
 *                displayInformation                *
 * This function prints out the information of the  *
 * client specified by the entered ID.              *
 * Parameter:                                       *
 *  id is the id of the client.                     *
 *  lastName is the last name of the client.        *
 *  expense is 1D array of clients monthly expenses.*
 *  nExpense is the number of monthly expenses.     *
 *  currentBalance is the remaining balance for     *
 *    the client.                                   *
 * Return:                                          *
 *  Nothing                                         *
 ****************************************************/
void displayInformation(int id, string lastName, double expense[],
  int nExpense, double currentBalance)
{
  cout << "\nClient ID: " << id << "\nClient Last Name: " << lastName
    << "\nMonthly expenses:";
  for (int i = 0; i < NUM_EXPENSES; i++)
  {
    cout << "\n  $" << expense[i];
  }
  cout << "\nCurrent Balance: $" << currentBalance << endl << endl;
}

/****************************************************
 *              computeAverageExpense               *
 * This function finds average of the client's      *
 * monthly expenses.                                *
 * Parameter:                                       *
 *  expense is a 1D array of client's monthly       *
 *    expenses.                                     *
 *  nExpense is the number of monthly expenses      *
 * Return:                                          *
 *  average of monthly expenses                     *
 ****************************************************/
double computeAverageExpense(double expense[], int nExpense)
{
  double sum = 0;
  for (int i = 0; i < nExpense; i++)
  {
    sum += expense[i];
  }
  return sum / nExpense;
}

/****************************************************
 *                computeAverageExpense             *
 * This function finds average of the client's      *
 * monthly expenses.                                *
 * Parameter:                                       *
 *  expense is a 1D array of client's monthly       *
 *    expenses.                                     *
 *  nExpense is the number of monthly expenses      *
 * Return:                                          *
 *  average of monthly expenses                     *
 ****************************************************/
double findMaxExpense(double expense[], int nExpense)
{
  double maxExpense = 0;
  for (int i = 0; i < nExpense; i++)
  {
    if (expense[i]>maxExpense)
      maxExpense = expense[i];
  }
  return maxExpense;
}

/****************************************************
 *                  isOverBudget                    *
 * This function determines whether the client's    *
 * account will go over-budget with next purchase.  *
 * Parameter:                                       *
 *  currentBalnace is the remainng balance for      *
 *    the client.                                   *
 *  nextPurchaseCost is the cost of the next        *
 *    purchase.                                     *
 * Return:                                          *
 *  true if the client's account goes over-budget.  *
 ****************************************************/
bool isOverBudget(double currentBalance, double nextPurchaseCost)
{
  if (nextPurchaseCost >= currentBalance)
    return true;
  else
    return false;
}
