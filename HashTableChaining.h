#ifndef HASH_TABLE_CHAINING_H
#define HASH_TABLE_CHAINING_H

#include "HashTableBase.h"

class HashTableChaining :
	public HashTableBase
{
public:
	// <will>
	// Constructor
	HashTableChaining(int numberOfBuckets);
	
	// <will>
	// Destructor
	virtual ~HashTableChaining(void);

	// <will>
	// Inserts a key into the hash table. Returns true if insertion
	// succeeded; false otherwise.
	bool insertKey(int key);
};

#endif
