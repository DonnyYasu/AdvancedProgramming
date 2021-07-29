#pragma once  //Only allows a library to be declared once

#include <iostream>
#include <dos.h>
#include <string>
#include <sstream>
#include "BaseVehicle.h";
#include "SUV.h";
using namespace std;




void main()
{
	//Testing out the creation of a BaseVehicle
	//You are declaring the variable and running it's default constructor
	BaseVehicle myCar = BaseVehicle();
	myCar.Year = 2005;
	myCar.SetMake("Mazda");
	myCar.Model = "626";
	myCar.MinSpeed = 0;
	myCar.MaxSpeed = 120;
	myCar.CurrSpeed = 55;  //What happens if we change Current Speed to -2500 ?

	myCar.PrintStats();


							
	string year;          
	ostringstream converter;  
	converter << myCar.Year;  
	year = converter.str(); 


							
	string currSpeed;
	ostringstream converter2;
	converter2 << myCar.CurrSpeed;
	currSpeed = converter2.str();


	myCar.Accelerate(5);
	
	converter2.str("");
	converter2 << myCar.CurrSpeed;
	currSpeed = converter2.str();
	//Concatenate info in order to display it.
	cout << "My " + myCar.GetMake() + " is traveling at " + currSpeed + "mph.";



	myCar.Decelerate(8);

	converter2.str("");
	converter2 << myCar.CurrSpeed;
	currSpeed = converter2.str();
	//Concatenate info in order to display it.
	cout << "My car is traveling at " + currSpeed + "mph.";




	myCar.SetSpeed(200);

	converter2.str("");
	converter2 << myCar.CurrSpeed;
	currSpeed = converter2.str();
	//Concatenate info in order to display it.
	cout << "My car is traveling at " + currSpeed + "mph.";



	//Now let's try an SUV
	//This time, we will declare the SUV object (mySUV) and run the overloaded constructor
	SUV mySUV = SUV(MP3);  //Another way is SUV mySUV(MP3), but what I have is common among langs.
	mySUV.Year = 2010;
	mySUV.SetMake("Honda");
	mySUV.Model = "CRV";
	mySUV.MinSpeed = 0;
	mySUV.MaxSpeed = 150;
	mySUV.CurrSpeed = 25;  //What happens if we change Current Speed to -2500 ?


	mySUV.PrintStats();  //Did you notice anything that you think should have been there?  Different?






	//Display message to ask the user to press enter to continue...leading program to end
	cout << "\n\nPlease press Q then Enter key to end program.\n";
	string junk;
	cin >> junk;
}