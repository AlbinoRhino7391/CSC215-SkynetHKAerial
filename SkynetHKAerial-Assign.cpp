// SkynetHKAerial-Assign.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Creator Information:
/*
Name: Eric Phelps
Professor: Juan Rodriguez
Date Completed: 20220203
Project Name: Skynet HK-Aerial
*/

/*
Goal:
create a 8x8 array (creates 64 possible grids for the Enemy to hide)
create a random number generator for a number 1-64 (EnemyLocation)
create a random number generator for a number 1-64 (GridSearch)
create Boolean for if the enemy is found (EnemySpotted)
create a loop to continue "scans" if boolean remains false.
*/


#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;


int main()
{

	srand(static_cast<unsigned int>(time(0)));  //Random Number Generator, sets enemy location for "scan".

	int EnemyLocation = rand() % 64 + 1; //Random number between 1 and 64.
	int GridMax = 64;
	int GridMin = 1;
	int Predictions = 1;
	int ScanLocation = rand() % 64 + 1; //Random number between 1 and 64.

	bool EnemySpotted = false;
	cout << "\n\t\t\t\t\t Welcome to Skynet.\n\n";
	cout << "As our search for John Conner and the resistance has continued,We have developed the newest in A.I UAV. The 'HK-Aerial'.\n\n";
	cout << "\n\t\t\t\t HK-Aerial Software Initalizing...\n\n";
	cout << "\t\tThis new software stragetically places an enemy randomly within an 8x8 Grid.\n";
	cout << "\t\t\tAllowing 1 of 64 random locations to be selected within the grid\n\n";
	cout << "HK-Aerial, Initializing Scans.\n\n";


	//Create the search loop (do) function.
	do
	{
		cout << "\n'HK-Aerial' Sending out Scan # " << Predictions << "\n";


		if (ScanLocation > EnemyLocation)
		{
			cout << "\nThe enemy location is not in Grid # " << ScanLocation << " number too high.\n";
			GridMax = ScanLocation;
			ScanLocation = ((GridMax - GridMin) / 2) + GridMin;
			Predictions++;
		}
		else if (ScanLocation < EnemyLocation)
		{
			cout << "\nThe enemy location is not in Grid # " << ScanLocation << " number too low.\n";
			GridMin = ScanLocation;
			ScanLocation = ((GridMax - GridMin) / 2) + GridMin;
			Predictions++;
		}
		if (ScanLocation == EnemyLocation)
		{
			cout << "\nThe enemy was located in Grid #" << EnemyLocation << "\n";
			cout << "\nEnemy Location Spotted. Only took 'HK-Aerial " << Predictions << " search attempts.\n";
			EnemySpotted = true;
		}

	} while (EnemyLocation != ScanLocation);

	system("pause");
	return(0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
