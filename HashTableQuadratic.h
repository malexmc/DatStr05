#ifndef HASH_TABLE_Quadratic_H
#define HASH_TABLE_Quadratic_H

#include "HashTableBase.h"

class HashTableQuadratic :
	public HashTableBase
{
public:
	// <will>
	// Constructor
	HashTableQuadratic(int numberOfBuckets);
	
	// <will>
	// Destructor
	virtual ~HashTableQuadratic(void){};

	// <will>
	// Inserts a key into the hash table. Returns true if insertion
	// succeeded; false otherwise.
	bool insertKey(int key);
	
};
#endif
