/*
 * This program verifies answers to the pointer exercise.
 *
 * Harkishan Singh Grewal
 * March 8, 2015
 * Due March 10, 2015
 */

#include<iostream>
using namespace std;

int main()
{
  // Given variables and values.
  int a = 40;
  int b = 4;
  int c = 30;
  int d = 19;
  int e = 18;
  int f = 20;

  // Declare pointers.
  int *t = &d;
  int *z = &e;
  int *u = &f;
  int **r = &z;
  int **s = &z;
  int **y = &z;
  int ***p = &y;
  int ***q = &y;

  int **v;
  int *w;

  // Print out the values of variables.
  cout << "The variables values before assignment statements:\n"
    << "a= " << a << "\nb= " << b << "\nc= " << c << "\nd= " << d
    << "\ne= " << e << "\nf= " << f << endl << endl;

  // Assignment statements.
  t = **p;
  b = ***q;
  *t = c;
  v = r;
  w = *s;
  a = **v;
  *u = *w;


  // Print out final values of given variables.
  cout << "The variables values after assignment statements:\n"
    << "a= " << a << "\nb= " << b << "\nc= " << c << "\nd= " << d
    << "\ne= " << e << "\nf= " << f << endl << endl;

  return 0;
}
