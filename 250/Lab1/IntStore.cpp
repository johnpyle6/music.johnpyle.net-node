/** @file Lab1c.cpp */
#include "IntStore.h"

using namespace std;

/** Constructor */
IntStore::IntStore() : intStore()
{
   numValues = 0;
}


/** Private */
int IntStore::getLargest()
{
   int max = 0;
   for (int i=0; i < numValues; i++)
      if (intStore[i] > max)
         max = intStore[i];
         
   return max;
}

int IntStore::getSmallest()
{
   int min = intStore[0];
   for (int i=0; i < numValues; i++)
      if (intStore[i] < min)
         min = intStore[i];
         
   return min;
}

int IntStore::getAvg()
{
   int total = 0;
   for (int i=0; i < numValues; i++)
      total += intStore[i];
         
   return total/numValues;
}



/** Public */
bool IntStore::setNumber(int value)
{
   bool success = true;
   if (numValues < 10)
   {  intStore[numValues] = value;
      numValues++;
   }
   else
   {  success = false;
   }
   
   return success;
}
   
bool IntStore::clear()
{
   numValues = 0;
}
   
bool IntStore::displayNumbers()
{
   if (numValues == 0)
      cout << "No numbers to display" << endl;
   else
   {  
      cout << "The numbers are: ";
      for (int i=0; i < numValues - 1; i++)
         cout << intStore[i] << ", ";
      
      cout << intStore[numValues - 1] << "." << endl;
   }
}
   
void IntStore::getStats(int &largest, int &smallest, int &avg)
{
   if (numValues > 0)
   {  largest = getLargest();
      smallest = getSmallest();
      avg = getAvg();
   }
    
}


