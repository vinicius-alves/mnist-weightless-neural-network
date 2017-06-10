#include <wann/WiSARD.hpp>
#include <iostream>
#include <vector>
#include <string>



// import and other stuffs

int main(){

std::vector<std::vector<int>> input_X;
std::vector<std::string> input_y;
std::vector<std::vector<int>> testing_X;

// load data into input_X, input_y and testing_X


int retinaLength = 10;
int numBitsAddr = 16;

wann::WiSARD *w = new WiSARD(retinaLength, numBitsAddr);

//w->fit(input_X, input_y);

//vector<string> result = w->predict(testing_X);

return 0;

}