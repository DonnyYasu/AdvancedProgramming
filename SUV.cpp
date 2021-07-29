#pragma once  //Only allows a library to be declared once

//Typical libraries expected to be used, so we included them
#include <iostream>
#include <dos.h>
#include <string>
#include <sstream>

#include "SUV.h";	//Connects us with SUV variable & function declarations
//** Why do we not need to include BaseVehicle.h here?  **

using namespace std;	//This is specifying a specific section of the library files, standard C/C++


//Default Constructor Definition
// Notice the ":BaseVehicle".  This is calling the Parent's default constructor first.
// THen we run code within the brackets, initializing two package and 4WD
SUV::SUV() :BaseVehicle()
{
	towPkg = false;
	FWD = true;
}

// Overloaded constructor receiving a specified Audio component
//  THink of this like buying a car, but paying extra to only upgrade the stereo.
//  If SUV receives an audio component, we call the Parent's constructor that takes care of that
// for us already....Why code it again, if not needed.
//  Afterwards, the code in the braces are run and initializes the additional SUV properties.
SUV::SUV(audio tAudio) :BaseVehicle(tAudio)
{
	towPkg = false;
	FWD = true;
}

//********************************************************************************
//Accessors & Mutators
//********************************************************************************

string SUV::SetTowPkg(bool tTowPkg)
{
	towPkg = tTowPkg;		//No validation to keep simple at this point
	return "OK";			//Feedback mechanism for potential issues
}

bool SUV::GetTowPkg()
{
	return towPkg;			//Share a copy of the towPkg's current value/setting
}

string SUV::SetFWD(bool tFWD)
{
	FWD = tFWD;				//No validation to keep simple at this point
	return "OK";			//Feedback mechanism for potential issues
}

bool SUV::GetFWD()
{
	return FWD;			//Share a copy of the FWD's current value/setting
}


