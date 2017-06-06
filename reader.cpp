#include <iostream>
#include <fstream>
#include <stdexcept>
#include <bitset>
using namespace std;

typedef unsigned short unshort;


int main(){
  ifstream labels;
  labels.open("t10k-labels.idx1-ubyte", ios::binary);
  if (labels.is_open()){
        char c[4];
        unshort counter =0;
        int number;
        while (counter<20) {
          counter++;
          for(unshort i=0; i<4; i++) labels.get(c[i]);
          //16777216 = 2^(24),65536 = 2^(16),256 = 2^(8)
          number = 16777216*int(c[0])+65536*int(c[1])+256*int(c[2])+int(c[3]);  
          if (labels) {
            bitset<32> num_binary(number);
            cout << "Line " << counter << ". Read a "<< number <<", binary is " << num_binary << endl;
          }
        }

    labels.close();
  } else{
    throw invalid_argument( "File not found!" );
  }


    return 0;
}
