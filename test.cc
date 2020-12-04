#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std; 

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

TEST_CASE(){
    string a = "";
    string b = "1";
    string c = "12345";
    REQUIRE( countChar(a) == 0 );
    REQUIRE( countChar(b) == 1 );
    REQUIRE( countChar(c) == 5 );
}

