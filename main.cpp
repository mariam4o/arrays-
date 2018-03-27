 #include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
int main()
{

//create two arrays
const int ARRAY_SIZE = 200; //array size of 100 elements
int nbrOfTrips[ARRAY_SIZE]; //array declaration of 100 elements
int counter; //For loop counter variable

double totalCost[ARRAY_SIZE]; //array declaration for cost of trips


ifstream fileIn; //create file object
ofstream fileSave; //create new output file
fileIn.open("TripInput.txt"); //read in file

//Variables
int tripNbr = 0;
double fuelCost = 0;
double fuelTotal = 0;
double wasteDisp = 0;
double misCost = 0;
double finalCost = 0.0;

cout<<"Welcome to Joe Snuffy Space Travel Company"<<endl;
cout<<endl;
cout<<"Trip No"<<setw(10)<<"Fuel"<<setw(10)<<"Waste"<<setw(10)<<"Misc"<<setw(15)
	<<"Discount Fuel"<<setw(15)<<"Final Cost"<<endl;

if(fileIn.fail())//test to see if file opened
{
	cout<<"File did not open."<<endl;
}
while(fileIn>>tripNbr>>fuelCost>>wasteDisp>>misCost) //while loop to read in data from file
{
	fuelTotal = fuelCost - (fuelCost * .10);
	finalCost = fuelTotal + wasteDisp + misCost;
	cout<<tripNbr<<setprecision(2)<<fixed<<setw(14)<<fuelCost<<setw(10)<<wasteDisp
		<<setw(10)<<misCost<<setw(15)<<fuelTotal<<setw(15)<<finalCost<<endl;

	for(counter = 0; counter < ARRAY_SIZE; counter++) //loop to write data into array
	{
		nbrOfTrips[counter] = counter; // array 1
		totalCost[counter] = counter; // array 2
	}

	fileSave.open("TripCost.txt"); //open output file

	for(counter = 0; counter < ARRAY_SIZE; counter++) //use for loop to output to file
	{
		fileSave << nbrOfTrips[counter]<<totalCost[counter]<<endl;
	}
	fileSave.close();
}
system("Pause");
return 0;
}
