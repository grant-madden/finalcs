#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>

using namespace std;

int countChar(string input);
int countLine(string input);

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
