/** Programs to demonstrate knowledge of C++
* @author John PYle
* @file lab1.cpp
*
#include <iostream>     // Library that defines cout and cin
#include <cstdlib>      // Library that EXIT_SUCCESS constant
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool isVowel(char character);

int main(void)
{
	string input;
   int vowels = 0;
   int consonants = 0;
   int others = 0;
   
   cout << "Enter words (quit to end): ";
   
   while (cin >> input && input != "quit")
   {  
      if (!isalpha(input[0]))
         others++;
      else if (isVowel( input[0]))
         vowels++;
      else
         consonants++;
   }

   cout << "Vowels: " << vowels << endl;
   cout << "Consonants: " << consonants << endl;
   cout << "Other: " << others << endl;      
	return EXIT_SUCCESS;
}

bool isVowel(char character)
{
	char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
   bool vowel = false;

   for( unsigned int i = 0; i < sizeof(vowels); i = i + 1 )
   {
      if (character == vowels[i])
         vowel = true;
   } 

	return vowel;
}

*/