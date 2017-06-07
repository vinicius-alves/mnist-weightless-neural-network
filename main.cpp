#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "binarize.cpp"
#include "label_reader.cpp"

using namespace std;

typedef unsigned short unshort;


int main(){
  ifstream myfile;
  myfile.open("data/training_data/teste.txt");
  if (myfile.is_open()){
  	bool arr[10][784];
  	binarize_file(myfile, arr, 10);

    //getline (myfile,line);
   // getline (myfile,line);
   // cout << line << '\n';
    myfile.close();
  } else{
  	throw invalid_argument( "File not found!" );
  }


	return 0;
}
