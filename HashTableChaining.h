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

  //<alex>
  // Overrides the base printTable() since the structure of our table
  // is a little different here
  void printTable();

private:

	//<alex>
	// Added vecBuckets to accommodate the vector<vector<int>> chaining case.
	vector<vector<int> >* vecBuckets;
};

#endif
