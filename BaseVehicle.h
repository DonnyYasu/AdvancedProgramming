#pragma once  //Only allows a library to be declared once

//Typical libraries expected to be used, so we included them
#include <iostream>
#include <dos.h>
#include <string>
#include <sstream>

using namespace std;	//This is specifying a specific section of the library files, standard C/C++


//Similar to creating an array, but does the kind of the opposite:
// Enum assigns numbers like 0, 1, 2, etc to the words within the squiggly braces.
//  THe computer sees the number as a value, but we can use the words that have meaning to us.
//  For example, when I enter your grades I assign them to students by name, but the computer is
//  actually storing the grades along with your student ID.
static enum audio { RADIO, SINGLECD, MULTICD, SATELLITE, MP3 };

//*****************************************************************************
//Quick note for your weapon options in your Player class.
//Player Enum: Weapon: NONE, SWORD, BOW, CROSSBOW, AXE, MACE, STAFF, WAND
//*****************************************************************************


//Class for the basic characteristics of a 
class BaseVehicle
{

	public:

		//Public properties can be accessed directly from anywhere that implement this class
		//So these variables are not super secure.  (similar to my wallet in the hallway)
		string Model;
		int Year;
		int MinSpeed;
		int MaxSpeed;
		int CurrSpeed;
	
		//Constructor: function that runs automatically when an instance of the class is created (object)
		BaseVehicle::BaseVehicle();					//default constructor (no params)
		BaseVehicle::BaseVehicle(audio tSterio);	//Overloaded constructor runs when audio param is sent


		//Function/method to change the speed to value sent to function
		string SetSpeed(int newSpeed);
		string Accelerate(int speedIncr);
		string Decelerate(int speedDecr);

		//*** Notice the keyword VIRTUAL...This means the children classes can override this function
		virtual void PrintStats();

		//Declaring new functions to Set and Get the Make of the car.
		string BaseVehicle::SetMake(string strMake);
		string BaseVehicle::GetMake();

		// Private protects values from outside programs, unless using SET/GET
		//THis is similar to keeping my wallet in my pocket and students asking to borrow/repay money
	private:
		string Make;	//Made this private first to test its GET and GET
		audio Sterio;	//This is a private property to store one of our preset audio system types
		
		//In the instance of your Player class' Wepaon enumeration, it would be declared similar to:
		//weapon myWeapon;
};