#ifndef BISMUTH
#define BISMUTH

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

namespace bismuth {
	bLoad(string filename) {
		ifstream myfile (filename);
		while ( getline (myfile,line) )
	    {
	    	cout << line << '\n';
	    }
	    myfile.close();
	}
	
	bLoop() {
		
	}
	
	bMoveLeft() {
		
	}
	
	bMoveRight() {
		
	}
	
	bJump() {
		
	}
	
	bFire() {
		
	}
	
	bMoveRight
}

#endif
