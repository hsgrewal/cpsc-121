/*
 * This program analyzes movie data to determine which movie production
 * is the most cost-effective domestically and globally.
 *
 * Harkishan Singh Grewal
 * April 16, 2015
 * Due April 22, 2015
 */

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// Declare constants.
const int NUM_MOVIES = 103;

struct Movie
{
  string name;
  double budget;
  double domesticGross;
  double globalGross;
};

int main()
{
  // Declare main variables.
  Movie movies[NUM_MOVIES];
  ifstream inputFile;
  int index = 0;

  // Open file.
  inputFile.open("movie_data.txt");

  // Import data from the file into array.
  for (int i = 0; i < NUM_MOVIES; i++)
  {
    if (inputFile.is_open()) // Check if file is open.
    {
      inputFile >> movies[i].name;
      inputFile >> movies[i].budget;
      inputFile >> movies[i].domesticGross;
      inputFile >> movies[i].globalGross;
    }
    else
    {
      cout << "Error opening file.\n";
      break;
    }
  }

  // Close file.
  inputFile.close();

  // Find the index of the movie with most domestic cost-effectivenss.
  for (int i = 0; i < NUM_MOVIES; i++)
  {
    if ((movies[i].domesticGross / movies[i].budget)>
      (movies[index].domesticGross / movies[index].budget))
    {
      index = i;
    }
  }

  // Display the most cost-effective movie production domestically.
  cout << "The most cost-effective domestic movie production was: "
    << fixed << movies[index].name << "\n   Production budget: $"
    << movies[index].budget << "\n   Domestic gross: $"
    << movies[index].domesticGross << "\n   Global gross: $"
    << movies[index].globalGross << "\n   Cost-effectiveness: "
    << movies[index].domesticGross / movies[index].budget << endl;

  // Reset index to 0.
  index = 0;

  // Find the index of the movie with most global cost-effectivenss.
  for (int i = 0; i < NUM_MOVIES; i++)
  {
    if ((movies[i].globalGross / movies[i].budget)>
      (movies[index].globalGross / movies[index].budget))
    {
      index = i;
    }
  }

  // Display the most cost-effective movie production globally.
  cout << "\nThe most cost-effective global movie production was: "
    << movies[index].name << "\n   Production budget: $"
    << movies[index].budget << "\n   Domestic gross: $"
    << movies[index].domesticGross << "\n   Global gross: $"
    << movies[index].globalGross << "\n   Cost-effectiveness: "
    << movies[index].globalGross / movies[index].budget << endl << endl;

  // Return 0 to the operating system.
  return 0;
}
