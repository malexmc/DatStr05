//#include "stdafx.h"
#include "HashTableDoubleHash.h"
#include <iostream>

// <will>
// Constructor
HashTableDoubleHash::HashTableDoubleHash(int numberOfBuckets)
	: HashTableBase(numberOfBuckets)
{
}


// <will>
// Inserts a key into the hash table. Returns true if insertion
// succeeded; false otherwise.
bool HashTableDoubleHash::insertKey(int key)
{
	// <will>
	// get the bucket number for the key
	int bucketNumber = getDoubleHashForKey(key);

	// <will>
	// starting at the bucket number, keep iterating through the hash until we
	// find an empty space
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

	// <will>
	// If we got here, the hash table is full. This shouldn't ever happen if the calling
	// code is checking our load ratio.
	return false;
}


// <alex>
// Returns the double hashed value for a given key.
int HashTableDoubleHash::getDoubleHashForKey(int key)
{
	// <will>
	// this prevents weird results if the key is negative
	while (key < 0)
	{
		key += numberOfBuckets;
	}

    int firstKey = key % numberOfBuckets;
    
    // <alex>
    // provides a second hash given that the number of buckets is larger than zero
    if (numberOfBuckets > 0){
        int q = (numberOfBuckets/2) + 1;
        return q-(firstKey % q);
    }
    
	return firstKey;
};
