/**
*   @file main.cc
*   @brief This program counts the characters/lines of a text file (Or Athens/Ohio University if no filename is given)
*   @author Grant Madden
*/

#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>

using namespace std;

/**
*   @file main.cc
*   @fn countChar
*   @brief This function counts how many characters there are in a string
*   @param input String to be counted
**/
int countChar(string input);

/**
*   @file main.cc
*   @fn countLine
*   @brief This function counts how many lines there are in a string
*   @param input String to be counted
**/
int countLine(string input);

/**
*   @file main.cc
*   @fn main
*   @brief Runs the program, which counts the characters/lines of a text file (Or Athens/Ohio University if no filename is given)
**/

int main(int argc, char* argv[]){ 
  fstream inStream;
  string param;
  char fileChar;

  if(argc == 1){
    cout << countChar("Athens") << " Characters" << endl;
    cout << countLine("Ohio University") << " Lines" << endl;
  }
  else {
    string file = argv[1];
    inStream.open(file);
    if(inStream.fail()){
      cout << "File Error." << endl;
      exit(EXIT_FAILURE);
    }
    
    inStream.get(fileChar);
    while(!inStream.eof()){
      param += fileChar;
      inStream.get(fileChar);
    }

    cout << countLine(param) << " Lines" << endl;
    cout << countChar(param) << " Characters" << endl;

    inStream.close();
  }

  return 0;
}

int countChar(string pName){
    return pName.size();
}

int countLine(string pName){
  int count = 0;
  for(int i = 0; i < pName.size(); i++){
    if(pName[i] == '\n')
      count++;
  }
  return count + 1;     
}
