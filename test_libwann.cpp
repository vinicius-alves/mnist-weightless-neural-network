#include <wann/WiSARD.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace wann;
using namespace std;

// compile with clang++ -Wall test_libwann.cpp -o test -std=c++11 -lwann
// import and other stuffs

int main(){

	vector<vector<int>> input_X= {
		{1,0,1,1,1,0},
		{0,1,1,0,0,1},
		{0,0,0,1,1,1}
	};
	vector<string> input_y = {"a","b","c"};

	vector<vector<int>> testing_X = {
		{0,0,1,1,1,1},
		{1,0,1,1,0,0}
	};

	// load data into input_X, input_y and testing_X


	int retinaLength = 2;
	int numBitsAddr = 2;

	WiSARD *w = new WiSARD(retinaLength, numBitsAddr);

	w->fit(input_X, input_y);

	vector<string> result = w->predict(testing_X);

	vector<unordered_map<string, float>> results = w->predictProba(testing_X);


  	for( const auto& n : results[1] ) {
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }

	delete w;

	return 0;

}