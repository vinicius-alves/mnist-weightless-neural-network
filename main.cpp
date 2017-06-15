#include <iostream>
#include <string>
#include <vector>
#include <wann/WiSARD.hpp>
#include "binarize.cpp"
#include "label_reader.cpp"
#include "look_files.cpp"

using namespace wann;
using namespace std;

typedef unsigned short unshort;


int main(){

	const unshort training_lines = 60000;
	const unshort test_lines = 10000;
	const int retinaLength = 784;
	const int numBitsAddr = 10;

	vector<vector<int>> input_x;
	vector<vector<int>> testing_x;
	vector<string> training_labels;
	vector<string> test_labels;
	vector<string> result;
	unshort counter;

	vector<string> training_files = lookFiles("data/training_data");

	for (vector<string>::iterator training_file = training_files.begin() ; training_file != training_files.end(); ++training_file){	

	  	input_x = binarize_file("data/training_data/"+(*training_file), training_lines);

	    training_labels = getLabels("data/training_labels/train-labels.idx1-ubyte",training_lines);

	    testing_x = binarize_file("data/test_data/"+ (*training_file).substr(0,13)+"test.txt", test_lines);

	    test_labels = getLabels("data/test_labels/t10k-labels.idx1-ubyte",test_lines);
	    

		WiSARD *w = new WiSARD(retinaLength, numBitsAddr);

		w->fit(input_x, training_labels);

		result = w->predict(testing_x);


		counter = 0;

		for (unshort i = 0; i < test_lines; i++){

			if(result[i]==test_labels[i]) counter++;
		}
		cout<<"Threshold :"<<(*training_file).substr(0,3)<<". Acuracia: "<<counter*1.0/test_lines<<endl;

		delete w;

	}

	//cout<< training_files[0].substr(0,13)<<endl;




	return 0;
}
