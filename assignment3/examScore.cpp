/*
 * This program askes the user fo a student name and computes the average
 * of 5 test score for that student.
 *
 * Harkishan Singh Grewal
 * February 9, 2015
 * Due February 14, 2015
 */

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

// Declare constants.
const int NUM_STUDENTS = 3;
const int NUM_EXAMS = 5; // columns of 2D array.

// Declare function prototypes.
int searchName(string, int, string name[]);
void assignScores(int, int examScores[][NUM_EXAMS]);
double calculateAverage(int, int examScores[]);

int main()
{
  // Declare the arrays.
  string name[NUM_STUDENTS] = { "bender", "leela", "fry" };
  int examScores[NUM_STUDENTS][NUM_EXAMS] = { {}, {} };

  // Declare variables.
  string targetName;
  int index; // row of 2D array.
  double average;

  // Call assignScores function to intialize 2D array.
  assignScores(NUM_STUDENTS, examScores);

  // Ask user for a target name.
  cout << "Enter name to be searched: ";
  cin >> targetName;

  // Get the index corresponding to the name.
  index = searchName(targetName, NUM_STUDENTS, name);

  // Check if name is valid.
  while (index < 0)
  {
    // Ask user for another target name.
    cout << "\nInvalid name! Enter new name to be searched: ";
    cin >> targetName;

    // Get the index corresponding to the name.
    index = searchName(targetName, NUM_STUDENTS, name);
  }

  // Get average of the student's score.
  average = calculateAverage(NUM_EXAMS, examScores[index]);

  // Print out results
  cout << endl << targetName << " scored ";
  for (int i = 0; i < NUM_EXAMS; i++) // To get test scores.
  {
    if (i == NUM_EXAMS - 1)
    {
      cout << examScores[index][i];
    }
    else
    {
      cout << examScores[index][i] << ", ";
    }
  }
  cout << " with an average of " << average << endl << endl;

  // Return 0 to OS.
  return 0;
}

/************************************************
 *                assignScores                  *
 * This function assign randoms scores to a 2D  *
 * array.                                       *
 * Inputs:                                      *
 *  NUM_STUDENTS (int) is number of             *
 *  students (rows of 2D array)                 *
 *  examScores (2D array of int type)           *
 * Return:                                      *
 *  Nothing.                                    *
 * Side-Effect: Array reintialized everytime    *
 * function is called.                          *
 ************************************************/
void assignScores(int NUM_STUDENTS, int examScores[][NUM_EXAMS])
{
  // Use current time as seed for rand function.
  srand(time(NULL));

  // For loop to assing random values.
  for (int row = 0; row < NUM_STUDENTS; row++)
  {
    for (int col = 0; col < NUM_EXAMS; col++)
    {
      // Assign value to array.
      examScores[row][col] = rand() % 11;
    }
  }
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
 *  index (int) of the targetName               *
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
 *              calculateAverage                *
 * This function calculates the average of all  *
 * scores in a column of 2D array.              *
 * Inputs:                                      *
 *  NUM_EXAMS (int) is the number of test       *
 *  scores.                                     *
 *  examScores (array of int type)              *
 * Return:                                      *
 *  average (double) of the scores              *
 ************************************************/
double calculateAverage(int NUM_EXAMS, int examScores[])
{
  // Declare calculateAverage variables.
  double sum = 0; // Sum of all scores (of the student);

  // For loop to access each score.
  for (int i = 0; i < NUM_EXAMS; i++)
  {
    // Sum all the scores in the column.
    sum += examScores[i];
  }

  // Calculate and return average.
  return sum / NUM_EXAMS;
}
