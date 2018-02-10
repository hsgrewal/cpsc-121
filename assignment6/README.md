# Assignment 6

## Harkishan Singh Grewal

CPSC-121 - Programming Concepts
April 11, 2015
Written in C++

**Note:** Include "movie_data.txt" file in the folder.

## Programming Assignment

### Analysis of Movie Data
This C++ program determines which movie production is the most cost-effective
domestically and globally based on the provided movie data. A gross profit is
in US dollars. One way to measure the cost effectiveness is to take the ratio
between the gross profit and production budget. For example, if the profit is
2000 USD and the production budget is 200 USD, then, the cost effectiveness
is 2000.0/200.0 = 10.0.

The movie data are stored in a text file, where each field is separated by a
whitespace. Each movie record has four fields: movie name, production budget,
domestic gross and worldwide gross. There are 103 records in total. An array
of C++ structure is used to build the movie database from the file. The struct
is provided below:
  > struct Movie {
  >   std::string name;
  >   double budget;
  >   double domestic_gross;
  >   double global_gross;
  > };

### Widget Factory
This C++ program designs a class for a widget manufacturing plant. Assuming
that 10 widgets may be produced each hour, the class object will calculate
how many days it will take to produce any number of widgets. The plant has
two 8-hour shift per day.

The program asks the user for the number of widgets that have been ordered
and then displays the number of days it will take to produce them.
