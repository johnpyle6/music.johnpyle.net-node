/** Programs to demonstrate knowledge of C++
* @author John Pyle
* @file IntStore.h
*/

#include <iostream>     // Library that defines cout and cin
#include <cstdlib>      // Library that EXIT_SUCCESS constant
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cstring>
#include <fstream>



class IntStore
{

private:
   
   int intStore[10];
   int numValues;
   int currentPosition;   
   
   int getLargest();
   int getSmallest();
   int getAvg();
   
public:

   IntStore();
   
   bool setNumber(int value);
   
   bool clear();
   
   bool displayNumbers(); 
   
   void getStats(int &largest, int &smallest, int &avg);

};


