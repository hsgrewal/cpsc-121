// Harkishan Grewal
// harkishangrewal@csu.fullerton.edu
// This program designs and tests a Car class.
// April 25, 2015
// Due April 28, 2015

#include<iostream>
#include<string>

using namespace std;

class Car{
private:
	int year;
	string make;
	int speed;
public:
	Car(int newYear, string newMake){
		year = newYear;
		make = newMake;
		speed = 0;
	}
	int getYear(){
		return year;
	}
	string getMake(){
		return make;
	}
	int getSpeed(){
		return speed;
	}
	int accelerate(){
		// Make sure speed is not < 0 before operation.
		if (speed > -1){
			speed += 5;
			return speed;
		}
		else
			return -1;
	}
	int brake(){
		// Make sure speed will not be < 0 by operation.
		if (speed > 4){
			speed -= 5;
			return speed;
		}
		else
			return -1;
	}
};

int main(){
	// declare car object.
	Car car1(1992, "Toyota Camry");

	// display data.
	cout << "Year: " << car1.getYear() << "\nMake: " << car1.getMake()
		<< "\nCurrent speed: " << car1.getSpeed() << endl << endl;

	// call accelerate function 5 times and display speed.
	for (int i = 0; i < 5; i++){
		cout << i + 1 << " call of accelerate function.\n";
		car1.accelerate();
		cout << "Current speed: " << car1.getSpeed() << endl << endl;
	}
	
	// call brake function 5 times and display speed.
	for (int i = 0; i < 5; i++){
		cout << i + 1 << " call of brake function.\n";
		car1.brake();
		cout << "Current speed: " << car1.getSpeed() << endl << endl;
	}

	// Return 0 to the operating system.
	return 0;
}