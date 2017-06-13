#include <iostream>
#include <dirent.h>
#include <vector>
#include <string>
using namespace std;

void lookFiles(const char * path, vector<string> &files){

	DIR *dir;
	struct dirent *ent;
	string name_file;
	if ((dir = opendir (path)) != NULL) {
	  while ((ent = readdir (dir)) != NULL) {
	  	name_file = ent->d_name;
	  	if(name_file!="." && name_file!=".."){
	  		files.push_back(name_file);
	  	}
	  }
	  closedir (dir);
	} else {
		cout<<"could not open directory"<<endl;
	}
}


int main(){
	
	vector<string> files;

	lookFiles("./data", files);

	return 0;
}