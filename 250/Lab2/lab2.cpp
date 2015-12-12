/** @file */

#include <iostream>
#include <string>
#include <list>
#include <cstdlib>      // Library that EXIT_SUCCESS constant
#include <cstring>
#include <fstream>

using namespace std;


void printStars(int numStars = 8)
{
   if (numStars > 0)
   {  cout << "*";
      printStars(numStars -1);
   }
}

int reverseWords(list<char*> words)
{
//   char *word = words.back();
//   cout << word;
//   words.pop_back();
   
//   if (words.size() > 0)
//      reverseWords(words);   
   
   return 0;
}


list<char*> getWordList()
{
   string wordList;
   list<char*> words;
   char *word;
   char *tempChar;
   
   cout << "Enter list of words to display backwards:" << endl;
   cin.get(tempChar, 1, ' ');
   
   
   while ( !cin.eof() )
   {  words.push_back( tempChar );
      cin.get(tempChar, 1, ' ');
   }
   
   /*
   while ( !cin.eof() )
   {  
      if (tempChar == ' ')
      {  words.push_back(word);
         word = tempChar;
      }else
         word += tempChar;
         
      cin.get(tempChar);
   }
      
   /*   
   char *cstr = const_cast<char*>( wordList.c_str() ); 
   char *pch;
   

   pch = strtok (cstr," ");
    
   while (pch != NULL)
   {  words.push_back(pch);
      pch = strtok (NULL, " ");
   }
   */
   return words;
   
}

int main(){
/*
   int stars = 0;
   cout << "How many stars should I display? ";
   cin >> stars;
   cout << endl;
   printStars(stars);
   
   while (stars != 0)
   {  cout << endl << "Enter another number to print or 0 to quit ";
      cin >> stars;
      cout << endl;
      printStars(stars);
   }
   
   cout << "Bye!" << endl;
*/


   list<char*> words = getWordList();
   reverseWords(words);
   
}

/*
string getWordList()
{
   string wordList;
   char tempChar;
   cout << "Enter list of words to display backwards:" << endl;
   cin.get(tempChar);
   
   while ( !cin.eof() )
   {  wordList += tempChar;
      cin.get(tempChar);
   }
       
   
   char *pch;
   
   list<char*> words;
   pch = strtok (cstr," ");
    
   while (pch != NULL)
   {  words.push_back(pch);
      pch = strtok (NULL, " ");
   }
}
*/