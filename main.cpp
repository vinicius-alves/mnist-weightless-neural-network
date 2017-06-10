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

    unshort arr2[20];
    getLabels("data/training_labels/train-labels.idx1-ubyte",arr2,20);
    
    myfile.close();
  } else{
  	throw invalid_argument( "File not found!" );
  }


	return 0;
}
