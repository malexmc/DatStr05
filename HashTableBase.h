#ifndef HASH_TABLE_BASE_H
#define HASH_TABLE_BASE_H

#include <vector>

using namespace std;

class HashTableBase
{
public:
	// <will>
	// Constructor
	HashTableBase(int numberOfBuckets, bool vectorFlag);

	// <will>
	// Destructor
	virtual ~HashTableBase(void);

	// <will>
	// Inserts a key into the hash table. Returns true if insertion
	// succeeded; false otherwise.
	virtual bool insertKey(int key) = 0;

	// <will>
	// Prints out the hash table.
	virtual void printTable();

	// <will>
	// Gets the current load ratio.
	double getLoadRatio();

protected:
	// <will>
	// Returns the hash for a given key.
	int getHashForKey(int key);

	// <will>
	// The number of buckets and entries.
	int numberOfBuckets;
	int entries;

	// <will>
	// Two parallel vectors. Buckets contains the actual values,
	// and bucketsFilledFlags contains flags that correspond to 
	// each bucket; a true value in bucketsFilledFlags means that
	// the value in buckets is valid.
	vector<int>* buckets;
	vector<bool>* bucketsFilledFlags;
	
	//<alex>
	// Added vecBuckets to accommodate the vector<vector<int>> chaining case.
	vector<vector<int> >* vecBuckets;
};

#endif
