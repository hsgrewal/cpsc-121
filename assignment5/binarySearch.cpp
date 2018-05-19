/*
 * This program uses heap memory abd binary search to find a target integer
 * from an array of integers.
 *
 * Harkishan Singh Grewal
 * March 15, 2015
 * Due March 17,2015
 */

#include<iostream>
#include<fstream>
using namespace std;

// Declare function prototypes.
int* initalizeArray(int nRead);
int binarySearch(int key, const int* start, const int* end);

int main()
{
  // Declare main variables.
  int nInts;
  int targetInt;
  int* numbers; // pointer to number array.
  int index;

  // Aske user for the number of integers to read.
  cout << "Enter the number of integers to search: ";
  cin >> nInts;

  // Validate input.
  while (nInts <= 0 || nInts > 1000)
  {
    cout << "ERROR! Invalid input! Enter the number of integers to search: ";
    cin >> nInts;
  }

  // Intialize the array with the first nRead integers.
  numbers = initalizeArray(nInts);

  // Ask user for the integer to be searched.
  cout << "\nEnter the integer to be searched: ";
  cin >> targetInt;

  index = binarySearch(targetInt, numbers, numbers + nInts);

  // Display result.
  if (index < 0)
  {
    cout << "\nThe integer '" << targetInt << "' is not present in the "
      << "list.\n\n";
  }
  else
  {
    cout << "\nThe integer '" << targetInt << "' is " << index + 1
      << " element in the list.\n\n";
  }

  // Free the memory.
  delete[] numbers;
  numbers = 0;

  // Return 0 to operating system.
  return 0;
}

/************************************************************
 *                  *initalizeArray                         *
 * This funtion intilizes an array with certain number of   *
 * of integers from a file and returns the memory address   *
 * of the first element of the array.                       *
 *                                                          *
 * Parameter: nRead -  the number of elements to read.      *
 * Return: numArray - a pointer to heap memory address of   *
 *  the array.                                              *
 ************************************************************/
int* initalizeArray(int nRead)
{
  // Declare variables.
  ifstream inputFile;

  int* numArray; // Array to hold numbers.

  // Allocate heap memory to the array.
  numArray = new int[nRead];

  // Open file.
  inputFile.open("number_list.txt");

  // Check if file opened.
  if (inputFile)
  {
    // Read numbers from file into the array.
    for (int i = 0; i < nRead; i++)
    {
      inputFile >> numArray[i];
    }

    // Close file after array is initialized.
    inputFile.close();
  }
  else
  {
    cout << "Error opening the file.\n";
  }

  // Return a pointer to the start of array
  return numArray;
}

/************************************************************
 *                  binarySearch                            *
 * This funtion uses binaray search to find a given         *
 * integer in an interger array. It does this by comparing  *
 * the given integer with the value of the middle of array. *
 * If the middle element is equal to key, then the index    *
 * of middle element is returned. If the value of middle    *
 * element is greater than the key, the second half of the  *
 * is ignored and the search begins again. if the value is  *
 * less than key, then the first half of array is ignored.  *
 * If no value matches the key, the -1 is returned.         *
 *                                                          *
 * Parameter: key -  the integer to be found.               *
 *  start - the memory address of the start of array        *
 *  end - the memory address of end of the array            *
 * Return: index - index of the key in the array.           *
 ************************************************************/
int binarySearch(int key, const int* start, const int* end)
{
  int index = -1; // Default value of index.
  const int* mid = start + (end - start) / 2; // Pointer to middle of array.
  const int* ogStart = start; // Save orginal Start memory address.

  // Loop to find index of key.
  while (start <= end)
  {
    if (key == *mid)
    {
      index = mid - ogStart; // Update index.
      return index; // Return index.
    }
    else if (key < *mid)
      end = mid - 1; // Ignore the second half of array.
    else
      start = mid + 1; // Ignore first half of array.

    // Find memory address of the middle of the remaining array.
    mid = start + (end - start) / 2;
  }

  // Return index of -1 if the key is not found.
  return index;
}
