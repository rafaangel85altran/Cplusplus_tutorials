//============================================================================
// Name        : classes.cpp
// Author      : jrangel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * 1.  The ZooAnimal class definition below is missing a prototype for
the Create function.  It should have parameters so that a character
string and three integer values (in that order) can be provided when
it is called for a ZooAnimal object.  Like the Destroy function, it
should have return type void.  Write an appropriate prototype for the
ZooAnimal Create function.

   class ZooAnimal
   {
    private:
      char *name;
      int cageNumber;
      int weightDate;
      int weight;
    public:
      void Destroy (); // destroy function
      char* reptName ();
      int daysSinceLastWeighed (int today);
   };
 *
 * */


#include <iostream>
#include <string>
using namespace std;

class ZooAnimal
   {
    private:
      string name = "None";				//char name has a deference operator
      int cageNumber;
      int weightDate;
      int weight;
    public:
      void Create (string, int, int, int);				//Prototype function of Create, that has 1 char and 3 integers
      void Destroy (); 									// destroy function
      string reptName ();
      int daysSinceLastWeighed (int today);

   };

void ZooAnimal::Destroy() {
	name = "";
}

void ZooAnimal::Create(string a, int b, int c, int d) {	//Member function declaration
	name = a;
	cageNumber = b;
	weightDate = c;
	weight = d;
}

string ZooAnimal::reptName() {
	return name;
}

int ZooAnimal::daysSinceLastWeighed (int today)
	{
		 int startday, thisday;
		 thisday = today/100*30 + today - today/100*100;
		 startday = weightDate/100*30 + weightDate - weightDate/100*100;
		 if (thisday < startday)
			 thisday += 360;
		 return (thisday-startday);
	}

int main() {
	cout << "Exercices from https://www.cs.purdue.edu/homes/bxd/CandC++/" << endl; // prints Exercices from https://www.cs.purdue.edu/homes/bxd/CandC++/

	ZooAnimal crocodrile;			//Create an object Crocodrile

	crocodrile.Create("Johny", 20, 34, 56);

	cout << "This animal is called " << crocodrile.reptName() << " and there is " << crocodrile.daysSinceLastWeighed(100) << " days since last weight" << endl;

	crocodrile.Destroy();

	return 0;
}
