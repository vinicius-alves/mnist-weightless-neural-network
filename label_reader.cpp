#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <bitset>
using namespace std;

typedef unsigned short unshort;

void lookData(const char * path, const unshort lines){
  ifstream labels;
  labels.open(path, ios::binary);
  if (labels.is_open()){
        char c;
        string prefix;
        int number;
        for(unshort counter =0;counter<lines;counter++) {
          labels.get(c);
          number = int(c);  
          if (labels) {
            bitset<8> num_binary(c);
            prefix = counter<10?"0":"";
            cout << "Line " << prefix << counter << ". Read a "<< number <<", binary is " << num_binary << endl;
          }
        }

    labels.close();
  } else{
    throw invalid_argument( "File not found!" );
  }
}

void getLabels(const char * path, unshort arr[], const unshort lines){
  ifstream labels;
  labels.open(path, ios::binary);
  if (labels.is_open()){
        char c;
        for(unshort counter =0;counter<lines;counter++) {
          labels.get(c);
          if(counter>7) arr[counter-8] = int(c);
        }

    labels.close();
  } else{
    throw invalid_argument( "File not found!" );
  }
}
