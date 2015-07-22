#ifndef HASH_TABLE_LIN_PROBE_H
#define HASH_TABLE_LIN_PROBE_H

#include "HashTableBase.h"

class HashTableLinProbe :
	public HashTableBase
{
public:
	// <will>
	// Constructor
	HashTableLinProbe(int numberOfBuckets);
	
	// <will>
	// Destructor
	virtual ~HashTableLinProbe(void);

	// <will>
	// Inserts a key into the hash table. Returns true if insertion
	// succeeded; false otherwise.
	bool insertKey(int key);
};

#endif