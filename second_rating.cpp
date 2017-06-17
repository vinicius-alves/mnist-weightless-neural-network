#include <iostream>
#include <string>
#include <vector>
#include <wann/WiSARD.hpp>
#include "libs/binarize.cpp"
#include "libs/label_reader.cpp"
#include "libs/look_files.cpp"
#include "libs/writer.cpp"
#include "libs/prefix.cpp"

#define TRAINING_LINES 60000
#define TEST_LINES 10000
#define NUM_BITS_ADDRESS_INIT_VALUE 30
#define NUM_BITS_ADDRESS_END_VALUE 40

using namespace wann;
using namespace std;

//Treino variando NumBitsAddress e threshold
//to compile: clang++ second_rating.cpp -o second -std=c++11 -lwann

typedef unsigned short unshort;


int main(){

	WiSARD *w;
	const int retinaLength = 784;

	vector<vector<int>> input_x;
	vector<vector<int>> testing_x;
	vector<string> training_labels;
	vector<string> test_labels;
	vector<string> result;
	string contents = "";
	string name_file_training;
	string name_file_test;
	unshort counter;
	float acuracy;

	vector<string> training_files = lookFiles("data/training_data");

	training_labels = getLabels("data/training_labels/train-labels.idx1-ubyte",TRAINING_LINES);

	test_labels = getLabels("data/test_labels/t10k-labels.idx1-ubyte",TEST_LINES);

	for (vector<string>::iterator training_file = training_files.begin() ; training_file != training_files.end(); ++training_file){

		name_file_training = (*training_file);
		name_file_test     = getPrefix(*training_file) + "_thresholdtest.txt";
		
	  	input_x = binarize_file("data/training_data/"+ name_file_training, TRAINING_LINES);

	    testing_x = binarize_file("data/test_data/"+ name_file_test, TEST_LINES);
 
	    for(int numBitsAddr = NUM_BITS_ADDRESS_INIT_VALUE; numBitsAddr<NUM_BITS_ADDRESS_END_VALUE+1; numBitsAddr++){

	    	w = new WiSARD(retinaLength, numBitsAddr);

			w->fit(input_x, training_labels);

			result = w->predict(testing_x);

			delete w;

			counter = 0;
			for (unshort i = 0; i < TEST_LINES; i++){

				if(result[i]==test_labels[i]) counter++;
			}

			acuracy = counter*1.0/TEST_LINES;

			contents += getPrefix(*training_file) +" "+ to_string(numBitsAddr)+ " "+ to_string(acuracy)+ "\n";

			cout<<"Threshold: "<<getPrefix(*training_file) <<". NumBitsAddr: "<< numBitsAddr <<". Acuracia: "<< acuracy <<endl;

		}

	}

	save_contents(contents);

	return 0;
}
