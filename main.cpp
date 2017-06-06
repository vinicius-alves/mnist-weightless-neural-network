#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

typedef unsigned short unshort;

void binarize_line(stringstream &threshold_line_stream, bool arr[][784]){
		const char second_delimiter =',';
		string threshold_line_caractere;
		threshold_line_stream.clear();	
		for(unshort j =0; j<784; j++){
			getline(threshold_line_stream, threshold_line_caractere, second_delimiter);
			arr[0][j]=threshold_line_caractere==" 0" || threshold_line_caractere=="0"?false:true;	
		}

		for(unshort k =0; k<784; k++){
			if(k%28==0) cout<<endl;
			if(arr[0][k]){ cout<<"#";}
			else if (!arr[0][k]){cout<<" ";}
		}

		cout<<endl;
}

void binarize_file(ifstream &file, bool arr[][784]){
	stringstream threshold_stream;
	stringstream threshold_line_stream;
	threshold_stream << file.rdbuf();
	const char first_delimiter ='\n';
	string threshold_line;


	for(unshort i =0; i<10; i++){
		getline(threshold_stream, threshold_line, first_delimiter);
		threshold_line_stream.str(threshold_line);
		//cout<<"line: "<< threshold_line<<endl;
		binarize_line(threshold_line_stream, arr);
	}
 
}


int main(){
  ifstream myfile;
  myfile.open("teste.txt");
  if (myfile.is_open()){
  	bool arr[10][784];
  	binarize_file(myfile, arr);

    //getline (myfile,line);
   // getline (myfile,line);
   // cout << line << '\n';
    myfile.close();
  } else{
  	throw invalid_argument( "File not found!" );
  }


	return 0;
}
