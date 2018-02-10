# Assignment 4

## Harkishan Singh Grewal

CPSC-121 - Programming Concepts
March 2, 2015
Written in C++

**Note:** Include client_info.txt file in the folder.

## Programming Assignment

### Expense Manager
This C++ program performs the basic functions of an expense manager. The basic
functions are listed below:
  1. Search a client’s identification number
  2. Display the client’s information including ID, last name, all the monthly
    expenses and current balance
  3. Compute the average of monthly expense for the client
  4. Find the maximum monthly expense for the client
  5. Determine if the client’s account will be over-budget on the next purchase

Here are possible usages of an Expense Manager. When the user would like to
read client information, the program asks the user for the client ID and
display the client information. When the user would like to know the average
expense of a client, the program asks the user the client ID and display the
corresponding average of monthly expense. When the user would like to know if
the next purchase would cause the client’s account over budget, the program
would ask for the client’s ID and the cost of next purchase and then, display
a proper message. Or the user can just quit the program. The information of 50
clients is given in the text file, “client info.txt”. Each row in the table
contains the following client information. There are 50 rows, one for each
client.
  1. Identification number (column 1)
  2. Last name (column 2)
  3. 6 monthly expenses in dollars (column 3, 4, 5, 6, 7, and 8)
  4. Current balance in dollars (column 9)


The program does the following:
  1. The program is a menu-driven
  2. The number of clients is 50
  3. The number of monthly expenses is 6
  4. All the IDs are stored in an 1D array
  5. All the last names are stored in an 1D array
  6. All the monthly expenses and current balances for 50 clients are stored
    in a 2D array, where each row has 6 monthly expense plus one current
    balance.
  7. Search the client’s ID
    *int searchId(int id[], int nId, int targetId);*
      - Parameter: an array of IDs, number of IDs to be searched and the
        target ID
      - Return value: the array index of target ID
  8. Display the client’s information
    *void displayInformation(int id, std::string lastName, double expense[],
      int nExpense, double currentBalance);*
      - Parameter: id, last name, monthly expenses, number of expenses to be
        displayed and current balance
      - Return value: none
  9. Compute the average of monthly expenses for the client
    *double computeAverageExpense(double expense[], int nExpense);*
      - Parameter: an 1D array of monthly expense for the client and the
        number of expense wished to be computed for the average
      - Return value: average monthly expense
  10. Find the maximum monthly expense for the client
    *double findMaxExpense(double expense[], int nExpense);*
      - Parameter: an 1D array of monthly expense for the client and the
        number of expense wished to be searched for the max expense
      - Return value: max expense
  11. Determine if the client’s account will be over-budget for the next
    purchase
    *bool isOverBudget(double currentBalance, double nextPurchaseCost);*
      - Parameter: the current balance and the cost of next purchase
      - Return value: When the account is over budget or the current balance
        is less than the cost of next purchase, the function returns true.
        Otherwise, the function returns false.

### Pointer Exercise
Assuming all the variables are integer and all pointers are typed appropriately. Please show the final values of the variables, a, b, c, d, e and f, after executing the following assignments from the top to bottom sequentially. The assignment statements are shown below:
  > t = \**p;
  > b = \***q;
  > ∗t = c;
  > v = r;
  > w = \*s;
  > a = \**v;
  > \*u = ∗w;

The variables a, b, c, d, e and f are initialized with 40, 5,
30, 19, 18 and 20 respectively.
