//#include "stdafx.h"
#include "HashTableBase.h"

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// <will>
// Base class constructor. Instantiates the buckets vector<int> and 
// bucketsFilledFlags vector<bool>. 
//
// <alex>
// Added the vectorFlag to allow the constructor to construct the traditional
// vector<int> buckets or the chaining cases' vector<vector<int>> buckets.
HashTableBase::HashTableBase(int numberOfBuckets, bool vectorFlag)
{
	this->numberOfBuckets = numberOfBuckets;
	this->entries = 0;

    // <alex>
    // Decides between the traditional vector<int> buckets or the 
    // chaining cases' vector<vector<int>> buckets based on vectorFlags.
    if(vectorFlag){
    	vecBuckets = new vector<vector<int> >(numberOfBuckets);
    }
    else{
	    buckets = new vector<int>(numberOfBuckets);
	}
	
	bucketsFilledFlags = new vector<bool>(numberOfBuckets);
}



// <will>
// Base class desctructor. Deletes the buckets vector<int> and the
// bucketsFilledFlags vector<bool>.
HashTableBase::~HashTableBase(void)
{
	delete buckets;
	buckets = 0;

	delete bucketsFilledFlags;
	bucketsFilledFlags = 0;
}

// <will>
// Prints the table. This method should be overwritten if seprate chaining is used
// since the buckets vector<int> is not used in this case.
void HashTableBase::printTable()
{
	for (int ii = 0; ii < numberOfBuckets; ii++)
	{
		// <will>
		// print out the bucket number
		cout << setw(6) << ii << " - ";

		// <will>
		// print out the bucket value if possible
		if ((*bucketsFilledFlags)[ii])
		{
			cout << (*buckets)[ii] << endl;
		}
		else
		{
			cout << "---" << endl;
		}
	}
}

// <will>
// Gets the current load ratio for the hash table
double HashTableBase::getLoadRatio()
{
	return static_cast<double>(entries) / numberOfBuckets;
}

// <will>
// Returns the hash value for a given key.
int HashTableBase::getHashForKey(int key)
{
	// <will>
	// this prevents weird results if the key is negative
	while (key < 0)
	{
		key += numberOfBuckets;
	}
    cout << key << " % " << numberOfBuckets << " = " << key%numberOfBuckets << endl;
	return key % numberOfBuckets;
}
