#ifndef HASH_TABLE_DOUBLE_HASH_H
#define HASH_TABLE_DOUBLE_HASH_H

#include "HashTableBase.h"

class HashTableDoubleHash :
	public HashTableBase
{
public:
	// <will>
	// Constructor
	HashTableDoubleHash(int numberOfBuckets);
	
	// <will>
	// Destructor
	virtual ~HashTableDoubleHash(void){};

	// <will>
	// Inserts a key into the hash table. Returns true if insertion
	// succeeded; false otherwise.
	bool insertKey(int key);
	
protected:
    // <alex>
    // Returns the double hashed value for a given key.
    int getDoubleHashForKey(int key);
};
#endif
