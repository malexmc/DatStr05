//#include "stdafx.h"
#include "HashTableChaining.h"
#include <iostream>
// <will>
// Constructor
HashTableChaining::HashTableChaining(int numberOfBuckets)
	: HashTableBase(numberOfBuckets, true)
{
}

// <will>
// Destructor
HashTableChaining::~HashTableChaining(void)
{
}

// <will>
// Inserts a key into the hash table. Returns true if insertion
// succeeded; false otherwise.
bool HashTableChaining::insertKey(int key)
{
	// <will>
	// get the bucket number for the key
	int bucketNumber = HashTableBase::getHashForKey(key);

	// <alex>
	// At the bucket number, if the vector is empty ,populate it with 
	// the key. Otherwise, check the vector for the element, then 
	// push_back if not found.
	if ((*vecBuckets)[bucketNumber].size() == 0){
	    cout << "Pingas" << endl;
	    (*vecBuckets)[bucketNumber].push_back(key);
        cout << "Pushed Back" << endl;
	}
	
	else{
	    
	}
	
	/*
	for (int ii = 0; ii < numberOfBuckets; ii++)
	{
		int bucket = (ii + bucketNumber) % numberOfBuckets;

		// <will>
		// if the key at this location is equal to the current key, break out early
		if ((*bucketsFilledFlags)[bucket] && (*buckets)[bucket] == key)
		{
			return false;
		}

		// <will>
		// insert the value here if possible
		if ((*bucketsFilledFlags)[bucket] == false)
		{
			(*bucketsFilledFlags)[bucket] = true;
			(*buckets)[bucket] = key;
			entries++;
			return true;
		}
	}
	*/

	// <will>
	// If we got here, the hash table is full. This shouldn't ever happen if the calling
	// code is checking our load ratio.
	return false;
}
