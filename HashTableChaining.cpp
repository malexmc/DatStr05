//#include "stdafx.h"
#include "HashTableChaining.h"
#include <iomanip>
#include <iostream>
// <will>
// Constructor
HashTableChaining::HashTableChaining(int numberOfBuckets)
	: HashTableBase(numberOfBuckets)
{
  	vecBuckets = new vector<vector<int> >(numberOfBuckets);
}

// <will>
// Destructor
HashTableChaining::~HashTableChaining(void)
{
  delete vecBuckets;
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
        HashTableBase::totalComparisons++;
	if ((*vecBuckets)[bucketNumber].size() == 0){
            
	    //cout << "Pingas" << endl;
	    (*vecBuckets)[bucketNumber].push_back(key);
      //cout << "Pushed Back" << endl;
      entries++;
      return true;
	}
	
	else{
	  for( unsigned int ii = 0; ii < (*vecBuckets)[bucketNumber].size(); ii++){
      HashTableBase::totalComparisons++;
      if((*vecBuckets)[bucketNumber][ii] == key){
        return false;
      }
    }
    (*vecBuckets)[bucketNumber].push_back(key);
    entries++;
    return true;
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

  //<alex>
  // Overrides the base printTable() since the structure of our table
  // is a little different here
  void HashTableChaining::printTable(){
	  for (int ii = 0; ii < numberOfBuckets; ii++)
	  {
		  // <will>
		  // print out the bucket number
		  cout << setw(6) << ii << " - ";

      //<alex>
      // if the bucket is empty, print that.
      if((*vecBuckets)[ii].size() == 0){
        cout << "(Empty)" << endl;
      }

      //<alex>
      //otherwise, loop through the bucket vector and print its elements.
      else{
        for(unsigned int jj = 0; jj < (*vecBuckets)[ii].size(); jj++){
          if(jj == (*vecBuckets)[ii].size() - 1  ){
            cout << (*vecBuckets)[ii][jj] << endl;
          }
          else{
            cout << (*vecBuckets)[ii][jj] << ", ";
          }
        }
      }

      /*

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
      */
	  }
  }
