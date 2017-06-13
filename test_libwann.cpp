#include <wann/WiSARD.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace wann;

// compile with g++ test_libwann.cpp -o test -std=c++11 -lwann
// import and other stuffs

int main(){

std::vector<std::vector<int>> input_X;
std::vector<std::string> input_y;
std::vector<std::vector<int>> testing_X;

// load data into input_X, input_y and testing_X


int retinaLength = 10;
int numBitsAddr = 16;

WiSARD *w = new WiSARD(retinaLength, numBitsAddr);

//w->fit(input_X, input_y);

//vector<string> result = w->predict(testing_X);

return 0;

}