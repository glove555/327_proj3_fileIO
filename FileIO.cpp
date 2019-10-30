/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;
//trys to open filename, and return its contents in contents
//it will strip out only \n's (char return\line feed)
//returns:
//SUCCESS all worked, contents string contains all in the file
//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const std::string &filename,
		std::string &contents) {
	//open file
	ifstream myfile;
	std::string line = "";
	myfile.open(filename.c_str());
	if (!myfile.is_open()) {
		contents.clear();
		return COULD_NOT_OPEN_FILE_TO_READ;
	}
	else {
		while (getline(myfile, line)) {
			//strip chars here and return getline contents?
			contents += line;
		}
	}
	return SUCCESS;
}
//trys to open filename, and serialize  myEntryVector contents to it
//returns:
//SUCCESS all worked, filename contains myEntryVector strings
//COULD_NOT_OPEN_FILE_TO_WRITE
int KP_FileIO::writeVectortoFile(const std::string filename,
		std::vector<std::string> &myEntryVector) {
	ofstream myfile;
	myfile.open(filename.c_str());
	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}
	string mydata;
	for (int i = 0; i < (signed) myEntryVector.size(); ++i) {
		mydata = (myEntryVector[i]);
		myfile << mydata << endl;
	}
	return SUCCESS;
}
