#pragma once  //Only allows a library to be declared once

//Typical libraries expected to be used, so we included them
#include <iostream>
#include <dos.h>
#include <string>
#include <sstream>

#include "Truck.h";	//Connects us with SUV variable & function declarations
//** Why do we not need to include BaseVehicle.h here?  **

using namespace std;	//This is specifying a specific section of the library files, standard C/C++


						//Default Constructor Definition
						// Notice the ":BaseVehicle".  This is calling the Parent's default constructor first.
						// THen we run code within the brackets, initializing two package and 4WD
Truck::Truck() :BaseVehicle()
{
	manualTransmission = true;
	FWD = true;
	LEDlight = true;
	dumpBed = true;
}

// Overloaded constructor receiving a specified Audio component
//  THink of this like buying a car, but paying extra to only upgrade the stereo.
//  If SUV receives an audio component, we call the Parent's constructor that takes care of that
// for us already....Why code it again, if not needed.
//  Afterwards, the code in the braces are run and initializes the additional SUV properties.
Truck::Truck(audio tAudio) :BaseVehicle(tAudio)
{
	manualTransmission = true;
	FWD = true;
	LEDlight = true;
	dumpBed = true;
}

//********************************************************************************
//Accessors & Mutators
//********************************************************************************

string Truck::SetTowPkg(bool tTowPkg)
{
	towPkg = tTowPkg;		//No validation to keep simple at this point
	return "OK";			//Feedback mechanism for potential issues
}

bool SUV::GetTowPkg()
{
	return towPkg;			//Share a copy of the towPkg's current value/setting
}

string Truck::SetFWD(bool tFWD)
{
	FWD = tFWD;				//No validation to keep simple at this point
	return "OK";			//Feedback mechanism for potential issues
}

bool Truck::GetFWD()
{
	return FWD;			//Share a copy of the FWD's current value/setting
}


