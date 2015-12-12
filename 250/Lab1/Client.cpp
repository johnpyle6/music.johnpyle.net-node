/** @file */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "IntStore.h"

using namespace std;

void testEmpty(IntStore store);
void test1(IntStore store);
void test2(IntStore store);
void testUserInput(IntStore store);

/* 
TODO: 
- add overflow test for setNumber
- add Constant for max_size
- add "do you have another set of numbers"
- clear the array at the begining of each test
- any other tests to meet the standard of thorough?
- enter a number or quit to give the option of less than 10 entries?

*/



int main(void)
{
   IntStore store0;   
//   testEmpty(store0);

   IntStore store1;   
//   test1(store1);
   
   IntStore store2;   
//   test2(store2);
   
   IntStore store3;   
   testUserInput(store3);
}

void testEmpty(IntStore store)
{
   cout << "------ Begin Test 0: empty --------" << endl;
   
   cout << endl <<  "**** store.displayNumbers ****" << endl;
   store.displayNumbers(); // "No numbers to display"
   
   int largest = 0;
   int smallest = 0;
   int avg = 0;   
   
   cout << endl <<  "**** store.getStats ****" << endl;
   store.getStats(largest, smallest, avg);
     
   cout << "Largest: " << largest << endl;   // 0
   cout << "Smallest: " << smallest << endl; // 0
   cout << "Average: " << avg << endl;       // 0
 
   cout << endl <<  "------ End Test 0 ---------------------" << endl << endl << endl;
  
}

void test1(IntStore store)
{
   cout << "------ Begin Test 1: 10 values --------" << endl;
   
   cout << endl << "**** store.setNumber ****" << endl;
   for (int i = 0; i < 10; i++)
   {  int num = (i + 1) * 10;
      cout << "Adding the value " << num << " at position " << i << endl;
      store.setNumber( num );
   }
   
   cout << endl <<  "**** store.displayNumbers ****" << endl;
   store.displayNumbers(); // The numbers are: 10, 20, 30, 40, 50, 60, 70, 80, 90, 100.

   int largest = 0;
   int smallest = 0;
   int avg = 0;   

   cout << endl <<  "**** store.getStats ****" << endl;
   store.getStats(largest, smallest, avg);
   cout << "Largest: " << largest << endl;   // 100
   cout << "Smallest: " << smallest << endl; // 10
   cout << "Average: " << avg << endl;       // 55
   
   cout << endl <<  "**** store.clear() ****" << endl;
   store.clear();
   store.displayNumbers();
   
   cout << endl <<  "------ End Test 1 ---------------------" << endl << endl << endl;
}


void test2(IntStore store)
{
   cout << endl << "------ Begin Test 2: 5 values --------" << endl;
   
   cout << endl << "**** store.setNumber ****" << endl;
   for (int i = 0; i < 5; i++)
   {  int num = (i + 1) * 5;
      cout << "Adding the value " << num << " at position " << i << endl;
      store.setNumber( num );
   }
   
   cout << endl <<  "**** store.displayNumbers ****" << endl;
   store.displayNumbers(); // The numbers are: 5, 10, 15, 20, 25.

   int largest = 0;
   int smallest = 0;
   int avg = 0;   

   cout << endl <<  "**** store.getStats ****" << endl;
   store.getStats(largest, smallest, avg);
   cout << "Largest: " << largest << endl;   // 25
   cout << "Smallest: " << smallest << endl; // 5
   cout << "Average: " << avg << endl;       // 15
   
   cout << endl <<  "**** store.clear() ****" << endl;
   store.clear();
   store.displayNumbers();
   
   cout << endl <<  "------ End Test 2 ---------------------" << endl << endl << endl;
}

void testUserInput(IntStore store)
{
   cout << endl << "------ Begin User Input Test --------" << endl;
   cout << endl << "**** store.setNumber ****" << endl;
   
   int num;
   bool success;
   
   for (int i = 0; i < 11; i++)
   {  cout << "Enter number " << i + 1 << ": ";
      cin >> num;
      cout << "Adding the value " << num << " at position " << i << endl;
      if (!store.setNumber( num ))
         cout << "\t!!!! ERROR: Store is full. Cannot add value " << num << " to store." << endl;
   }
   
   cout << endl <<  "**** store.displayNumbers ****" << endl;
   store.displayNumbers();

   int largest = 0;
   int smallest = 0;
   int avg = 0;   

   cout << endl <<  "**** store.getStats ****" << endl;
   store.getStats(largest, smallest, avg);
   cout << "Largest: " << largest << endl;   // 25
   cout << "Smallest: " << smallest << endl; // 5
   cout << "Average: " << avg << endl;       // 15
   
   cout << endl <<  "**** store.clear() ****" << endl;
   store.clear();
   store.displayNumbers();
   
   cout << endl <<  "------ End User Input Test  ---------------------" << endl << endl << endl;
}