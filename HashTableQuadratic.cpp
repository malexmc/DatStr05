//#include "stdafx.h"
#include "HashTableQuadratic.h"
#include <iostream>

// <will>
// Constructor
HashTableQuadratic::HashTableQuadratic(int numberOfBuckets)
	: HashTableBase(numberOfBuckets)
{
}


// <will>
// Inserts a key into the hash table. Returns true if insertion
// succeeded; false otherwise.
bool HashTableQuadratic::insertKey(int key)
{
	// <will>
	// get the bucket number for the key
	int bucketNumber = getHashForKey(key);

	// <will>
	// starting at the bucket number, keep iterating through the hash until we
	// find an empty space
	for (int ii = 0; ii < numberOfBuckets; ii++)
	{
	    //<alex>
	    // The quadratic "ii*ii" replaces the linear "ii" to make the
	    // probing quadratic.
		int bucket = ( (ii*ii) + bucketNumber) % numberOfBuckets;

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

	// <will>
	// If we got here, the hash table is full. This shouldn't ever happen if the calling
	// code is checking our load ratio.
	return false;
}

