#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#define PIXElS_PER_LINE 28
#define DIMENSION 28*28 

using namespace std;

typedef unsigned short unshort;

void binarize_line(stringstream &threshold_line_stream, bool arr[][DIMENSION]){
		const char second_delimiter =',';
		string threshold_line_caractere;
		threshold_line_stream.clear();	
		for(unshort j =0; j<DIMENSION; j++){
			getline(threshold_line_stream, threshold_line_caractere, second_delimiter);
			arr[0][j]=threshold_line_caractere==" 0" || threshold_line_caractere=="0"?false:true;	
		}

		// uncomment to see data
		/*for(unshort k =0; k<DIMENSION; k++){
			if(k%PIXElS_PER_LINE==0) cout<<endl;
			if(arr[0][k]){ cout<<"#";}
			else if (!arr[0][k]){cout<<" ";}
		}
		cout<<endl;*/
				
}

void binarize_file(const char * path, bool arr[][DIMENSION], const unshort lines){
	ifstream file;
 	file.open(path);
 	if (file.is_open()){
		stringstream threshold_stream;
		stringstream threshold_line_stream;
		threshold_stream << file.rdbuf();
		const char first_delimiter ='\n';
		string threshold_line;

		for(unshort i =0; i<lines; i++){
			getline(threshold_stream, threshold_line, first_delimiter);
			threshold_line_stream.str(threshold_line);
			binarize_line(threshold_line_stream, arr);
		}
 	} else{
  		throw invalid_argument( "File not found!" );
  	}
}

//with vectors <int>

vector <int> binarize_line(stringstream &threshold_line_stream){

		vector<int> arr(DIMENSION);
		const char second_delimiter =',';
		string threshold_line_caractere;
		threshold_line_stream.clear();	
		for(unshort j =0; j<DIMENSION; j++){
			getline(threshold_line_stream, threshold_line_caractere, second_delimiter);
			arr[j]=threshold_line_caractere==" 0" || threshold_line_caractere=="0"?false:true;	
		}

		return arr;
				
}

vector<vector <int>> binarize_file(const string path, const unshort &lines){

	char path_file[25];
	ifstream file;
 	vector<vector <int>> arr(lines);
	strcpy(path_file, path.c_str());
 	file.open(path_file);
 	if (file.is_open()){
		stringstream threshold_stream;
		stringstream threshold_line_stream;
		threshold_stream << file.rdbuf();
		const char first_delimiter ='\n';
		string threshold_line;

		for(unshort i =0; i<lines; i++){
			getline(threshold_stream, threshold_line, first_delimiter);
			threshold_line_stream.str(threshold_line);
			arr[i] = binarize_line(threshold_line_stream);
		}
		return arr;
 	} else{
  		throw invalid_argument( "File \'"+path+"\' not found!" );
  	}
  	return arr;
}