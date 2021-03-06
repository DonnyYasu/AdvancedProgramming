#include <iostream>
#include <dos.h>
#include <string>
#include <sstream>
#include "BaseVehicle.h";	//Connects us with variable & function declarations

using namespace std;		//only use Standard C/C++ sections of libraries

//Defining the constructor (automatically runs when we create an instance)
BaseVehicle::BaseVehicle()
{
	//Initialize values within the instance.
	Make = "";
	Model = "";
	Year = 1970;
	MaxSpeed = 100;
	MinSpeed = 0;
	CurrSpeed = 0;
	Sterio = audio::RADIO;
}

BaseVehicle::BaseVehicle(audio tSterio)
{
	//Initialize values within the instance.
	Make = "";
	Model = "";
	Year = 1970;
	MaxSpeed = 100;
	MinSpeed = 0;
	CurrSpeed = 0;
	Sterio = tSterio;	//Note that we have a second/alternative constructor with incoming audio
}






//Function to set a new speed directly
//When we write code to set a value, we can compare the incoming value with our requirements
// If the incoming value passes, great...store it.  Else, do not store it and return error msg
string BaseVehicle::SetSpeed(int newSpeed)
{
	//Declare and Initialize response string 
	string strResponse = "OK";

	//If the speed is between 0 and 120 mph, we are good...store it.  Else, no storing & give error msg
	if (newSpeed >= 0 && newSpeed <= 120)
	{	
		CurrSpeed = newSpeed;
	}
	else
	{
		strResponse = "ERROR: Sorry, the Speed must be between 0 and 120";
	}

	//Return msg (Could be OK or Error)
	return strResponse;
}


//Function to increase the current speed by a particular value
string BaseVehicle::Accelerate(int speedIncr)
{
	/* 
	****************************************************************************
	Original code.  Worked, but has limitations or can cause problems....Why?
	****************************************************************************
	string strResponse = "OK";
	CurrSpeed += speedIncr;
	return strResponse;
	****************************************************************************
	*/

	//Version that is more More protective of the data 
	string strResponse = "OK";
	int newSpeed = CurrSpeed + speedIncr;

	if (newSpeed >= MinSpeed && newSpeed <= MaxSpeed)
	{
		CurrSpeed += newSpeed;
	}
	else
	{
		strResponse = "ERROR: Sorry, but speeds can only be set between 0 and 120 mph";
	}
	
	return strResponse;
}


//Function to decrease the current speed by a particular value
string BaseVehicle::Decelerate(int speedDecr)
{
	string strResponse = "OK";
	int newSpeed = CurrSpeed - speedDecr;

	if (newSpeed >= MinSpeed && newSpeed <= MaxSpeed)
	{
		CurrSpeed += newSpeed;
	}
	else
	{
		strResponse = "ERROR: Sorry, but speeds can only be set between 0 and 120 mph";
	}

	return strResponse;
}


//Function to change the Make to whatever string was sent to this function
string BaseVehicle::SetMake(string strMake)
{
	Make = strMake;	//Set the Make to whatever was sent in (no?'s asked)
	//What could we do to make sure they did not name the make 'PoopeyPants' ?
	return "OK";
}


//Function to get a COPY of the VALUE stored in "Make" variable
//In many cases, they GET just returns a copy...BUT there would be a problem if this were private
// information like someone's social security # or salary.  In those cases, we may need to check
// criteria like user authority/access level to keep data safe from prying eyes.
string BaseVehicle::GetMake()
{
	return Make;
}


//Method/Function that the outside world can call to get a list of the car's stats
void BaseVehicle::PrintStats()
{
	cout << "Make: " + Make + "\n";		//Basic stuff
	cout << "Model: " + Model + "\n";
	cout << "Year: " << Year << "\n";
	cout << "Audio Option (NUMERIC): " << Sterio << "\n";

	string strAudio = "";				//How we can print text instead of numeric values
	if (Sterio == audio::RADIO)
	{
		strAudio = "RADIO";
	}
	else if (Sterio == audio::MP3)
	{
		strAudio = "MP3 Player";
	}
	else
	{
		strAudio = "NONE";
	}

	cout << "Audio Option (STRING): " << strAudio << "\n";


}

