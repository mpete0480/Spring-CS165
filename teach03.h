/**********************************************************************
 * File: ta03.cpp
 * Author: Br. Burton
 *
 * Description: Use this file as a starting point for Team Activity 03.
 *    You do not need to "submit" your code, but rather, answer the
 *    questions in the I-Learn assessment.
 **********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/***********************************************************************
 * Struct: Scripture
 * Description: Holds the reference to a scripture (book, chapter, verse
 ***********************************************************************/
struct Scripture
{
   string book;
   int chapter;
   int startVerse;
   int endVerse;
};

/***********************************************************************
 * Function: display
 * Description: Displays the passed scripture.
 ***********************************************************************/
void display(const Scripture &scripture)
{
   cout << scripture.book << " ";
   cout << scripture.chapter << ":";
   cout << scripture.startVerse;
   if (scripture.endVerse > 0)
      cout << "-" << scripture.endVerse;;
}

/************************************************************************
* Function: getFilename()
* Purpose: to get the filename from the user
*************************************************************************/
string getFilename()
{
   string file;
   cout << "What is the filename: ";
   cin  >> file;
   return file;
}

/************************************************************************
* Function: parseLine()
* Purpose: To parse the line into the scripture structure
*************************************************************************/
void parseLine(string line, Scripture & scripture)
{
  stringstream ss; //place for the string stream
  ss.str(line); // line loaded into ss
  ss >> scripture.book;
  ss >> scripture.chapter; 
  ss >> scripture.startVerse;
  ss >> scripture.endVerse;
  if (ss.fail())
  {
     scripture.endVerse = 0;
     ss.clear();
     ss.ignore(256,'\n');
  }
}
/************************************************************************
* Function: parseFile
* Purpose: Will parse file into a Scripture struct
*************************************************************************/
void parseFile(string file,Scripture scripture)
{
   ifstream fin(file.c_str());
   if (fin.fail()) //check for errors
   {  
      cout << "Unable to open file " << file << endl;
      return;
   }
   
   string line;
   while (getline(fin,line))
   {
      parseLine(line, scripture);
      display(scripture);
      cout << endl;
   }
   
}

/***********************************************************************
 * Function: main
 * Description: The driver for the program.
 ***********************************************************************/
int main()
{
   Scripture scripture;
   string file = getFilename();
   parseFile(file, scripture);// Insert your code here to prompt for the name of a file
   // and pass it to a readFile function


   return 0;
}
