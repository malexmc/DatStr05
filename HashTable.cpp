// HashTable.cpp : Defines the entry point for the console application.
//

#include "HashTableBase.h"
#include "HashTableLinProbe.h"
#include "HashTableDoubleHash.h"
#include "HashTableQuadratic.h"
#include "HashTableChaining.h"

#include <iostream>
#include <limits>
#include <stdlib.h>
#include <time.h>

double getDoubleFromUser(double lowerBound, double higherBound);
int getIntegerFromUser();

vector<int>* getRandomlyGeneratedVector(unsigned int length)
{
	vector<int>* newVector = new vector<int>();
	for (unsigned int ii = 0; ii < length; ii++)
	{
		// <will>
		// Generate numbers that are in the range [-2 * length, 2 * length)
		newVector->push_back((rand() % (length * 4)) - length * 2);
	}
	return newVector;
}

int main(int argc, char* argv[])
{
    srand(static_cast<unsigned int>(time(NULL)));
    int totalBuckets = 811;
    vector<int>* randomNumbers = getRandomlyGeneratedVector( totalBuckets );
    for( int collisionResolutionScheme = 1; collisionResolutionScheme <= 4; collisionResolutionScheme++){
    for( double maxLoadRatio = .1; maxLoadRatio <= .86; maxLoadRatio+=.05)
    {
        
	// <will>
	// get the collision resolution scheme
	//cout << "Select the collision resolution scheme:" << endl;
	//cout << " 1: Linear Probing (Single Hashing)" << endl;
	//cout << " 2: Linear Probing (Double Hashing)" << endl;
	//cout << " 3: Quadratic Probing" << endl;
	//cout << " 4: Seprate Chaining" << endl;
	//cout << " :";

	// <will>
	// get the input
	//int collisionResolutionScheme = 0;
	//cin >> collisionResolutionScheme;
	//if (cin.fail() || collisionResolutionScheme < 1 || collisionResolutionScheme > 4)
	//{
	//	return 1;
	//}

	// <will>
	// get the max load ratio
	//cout << endl << "Enter the max load ratio (0 to 1):" << endl;
	//double maxLoadRatio = getDoubleFromUser(0.0, 1.0);

	// <will>
	// create the hash table
	//int numberOfBuckets = 1009;
	
	// <alex>
	// Make our hash table pointer then decide what hash table to create
	// based on the user input
	HashTableBase* hashTable;
	switch(collisionResolutionScheme){
	    case 1: hashTable = new HashTableLinProbe(totalBuckets);
	            break;
	    case 2: hashTable = new HashTableDoubleHash(totalBuckets);
	            break;
	    case 3: hashTable = new HashTableQuadratic(totalBuckets);
	            break;
	    case 4: hashTable = new HashTableChaining(totalBuckets);
                break;
	}
	
	//HashTableBase* hashTable = new HashTableLinProbe(numberOfBuckets);

	// <will>
	// have user fill hash table
	//cout << endl << "Enter the numbers one at a time into the hash table:" << endl;
        int i = 0;
	while (hashTable->getLoadRatio() < maxLoadRatio)
	{
		//int newKey = getIntegerFromUser();
		bool insertSuccess = hashTable->insertKey(randomNumbers->at(i));
		if (!insertSuccess)
		{
			//cout << "**"<< randomNumbers->at(i) << " could not be inserted as it is a duplicate entry." 
			      //  << endl;
		}
                i++;
	}

	// <will>
	// test the hash table
	/*srand((unsigned int)time((time_t)0));
	while (hashTable->getLoadRatio() < maxLoadRatio)
	{
		int newKey = rand();
		bool insertSuccess = hashTable->insertKey(newKey);
		if (!insertSuccess)
		{
			cout << insertSuccess << " could not be inserted as it is a duplicate entry." << endl;
		}
	}*/

	/*int testValues[] = { 5, 5 + 23, 23, 0, 5 };
	int len = 5;

	for (int ii = 0; ii < len; ii++)
	{
		if (!hashTable->insertKey(testValues[ii]))
		{
			cout << testValues[ii] << " could not be inserted as it is a duplicate entry." << endl;
		}
	}*/

	// <will>
	// print out the hash table to verify
	//hashTable->printTable();
        double totalInsertions = totalBuckets*hashTable->getLoadRatio();
        double avgComparisons = HashTableBase::totalComparisons/totalInsertions;
        cout << "Load Ratio: " << maxLoadRatio << " Average Comparisons: " << avgComparisons << endl;

	//return 0;
        string response;
        
        
        HashTableBase::totalComparisons = 0;
}     
    cout << "^^^^^Method: " << collisionResolutionScheme << endl << endl;
    }
}


// <will>
// Gets a double value from the user
double getDoubleFromUser(double lowerBound, double higherBound)
{
	double response = 0;
	cout << " :";
	cin >> response;
	while (cin.fail() || response < lowerBound || response > higherBound)
	{
		cout << "Please enter an floating point number from " << lowerBound << " to " << higherBound << "." << endl << " :";
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cin >> response;
	}
	return response;
}

// <will>
// Gets an integer value from the user
int getIntegerFromUser()
{
	int response = 0;
	cout << " :";
	cin >> response;
	while (cin.fail())
	{
		cout << "Please enter an integer." << endl << " :";
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cin >> response;
	}
	return response;
}

