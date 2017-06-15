#include <string>

string getPrefix(string &name){

	unshort k = 0;
	for(char& character : name) {
	    if(character=='_'){
	    	return name.substr(0,k);
	    }
	    k++;
	}
	return name;
}