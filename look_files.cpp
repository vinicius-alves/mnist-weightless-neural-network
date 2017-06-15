#include <iostream>
#include <dirent.h>
#include <vector>
#include <string>
using namespace std;

vector<string> lookFiles(const char * path){

	DIR *dir;
	vector<string> files;
	struct dirent *ent;
	string name_file;
	if ((dir = opendir (path)) != NULL) {
	  while ((ent = readdir (dir)) != NULL) {
	  	name_file = ent->d_name;
	  	if(name_file!="." && name_file!=".."){
	  		files.push_back(name_file);
	  	}
	  }
	  return files;
	  closedir (dir);
	} else {
		cout<<"could not open directory"<<endl;
	}
	return files;
}