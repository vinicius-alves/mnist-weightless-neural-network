#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "binarize.cpp"
#include "label_reader.cpp"

using namespace std;

typedef unsigned short unshort;


int main(){

  	bool arr[10][784];
  	binarize_file("data/training_data/teste.txt", arr, 10);

    unshort arr2[20];
    getLabels("data/training_labels/train-labels.idx1-ubyte",arr2,20);
    
	return 0;
}
