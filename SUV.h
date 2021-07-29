#pragma once  //Only allows a library to be declared once

//Typical libraries expected to be used, so we included them
#include <iostream>
#include <dos.h>
#include <string>
#include <sstream>

#include "BaseVehicle.h";  // In order to inherit BaseVehicle's abilities, we must include 

using namespace std;	//This is specifying a specific section of the library files, standard C/C++

//SUV is a class that is inheriting all properties (vars) and abilities (methods/funcs) 
// from BaseVehicle.  Either BaseVehicle has to be defined as a public class, or we need 
// to declare it here, to truly inherit the class.
class SUV :public BaseVehicle
{
	//Declare our new properties associated specifically with an SUV
	//Because they are private, they need public Accessors/Mutators to be accessed by code outside SUV
	private:
		bool towPkg;
		bool FWD;

	// Declare the public Constructors and Accessors/Mutators
	public:
		//constructors
		SUV::SUV();			//Default Constructor (no params in parethesis)
		SUV::SUV(audio);	// Overloaded constructor.  This one sets audio if audio option is supplied

		//Accessors & Mutators
		string SetTowPkg(bool tTowPkg);		//Set towing package (if approp)
		bool GetTowPkg();					//Get a copy of towing package value to share

		string SetFWD(bool tFWD);			//Set Four-Wheel Drive (if approp)
		bool GetFWD();						//Get a copy of FWD value to share


};	//notice that the class declaration ends with ";" after the closing squiggly brace