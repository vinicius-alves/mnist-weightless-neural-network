// basic file operations
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void save_contents(string content){

  const char * filename = "results.txt"; 

  ofstream contents;
  contents.open (filename);
  contents << content;
  contents.close();

  cout<<"Salvo em ./"<<filename<<endl;

}