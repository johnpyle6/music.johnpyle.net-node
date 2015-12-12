/** Programs to demonstrate knowledge of C++
* @author John Pyle
* @file Lab1b.cpp
*/
#include <iostream>     // Library that defines cout and cin
#include <cstdlib>      // Library that EXIT_SUCCESS constant
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

bool isVowel(char character);
void getStatus(string word, int &vow, int &con, int &oth);
bool processLine(string lineOfWords, int &vow, int &con, int &oth);

/*
int main(void)
{


	string input;
  int con = 0;
  int oth = 0;
  int vow = 0;
   
   const string INPUT_FILE = "myFile.txt";      //name of input file
   ifstream inFile(INPUT_FILE.c_str());         // open the input file
   string inputString;                          // stores lines of data input from the file
   bool quit = false;

   if (!inFile)
      cout << "Error opening file for input: " << INPUT_FILE << endl;
   else
   {
      getline (inFile, inputString); // the prime read
      while (inFile) // while no errors have been encountered
      {
         cout << "The line is: " << inputString << endl;
         quit = processLine(inputString, vow, con, oth);
         if (quit)
         {  cout << "Vowels: "      << vow << endl;
            cout << "Consonants: "  << con << endl;
            cout << "Other: "       << oth << endl << endl; 
            
            con = 0;
            oth = 0;
            vow = 0;
         }
         
         getline (inFile, inputString);
         
      }
   
      inFile.close();
   }
   
        

	return EXIT_SUCCESS;
}
*/
bool isVowel(char character)
{
	char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
   bool vowel = false;

	for( unsigned int i = 0; i < sizeof(vowels); i = i + 1 )
	{
      if (character == vowels[i])
         vowel = true;
   } 
	return vowel;
}

void getStatus(string word, int &vow, int &con, int &oth)
{
   char ch = word[0];
	if ( !isalpha(ch) )
		oth++;
	else if ( isVowel(ch) )
		vow++;
	else
		con++;
}

bool processLine(string lineOfWords, int &vow, int &con, int &oth){
   bool quit = false;
   char *cstr = const_cast<char*>( lineOfWords.c_str() ); 
   char *pch;
   pch = strtok (cstr," ");
    
   while (pch != NULL)
   {
      //cout << ":" << pch << endl;
      
      if ( strcmp(pch, "quit") == 0){
         //cout << "is quit" << endl;
         quit = true;
      
      }else{
         //cout << ":" << pch << endl;
         getStatus(pch, vow, con, oth);
      }
      pch = strtok (NULL, " ");
   }

   return quit;
}