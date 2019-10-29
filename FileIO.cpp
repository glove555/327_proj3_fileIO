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
int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	//open file
	ifstream myfile;
	myfile.open(filename);
	if (!myfile.is_open()){
		return COULD_NOT_OPEN_FILE_TO_READ;
		contents.clear();
	}
	std::string line;
	std::string token;
	while (!(myfile.eof())) {
		getline(myfile, line);
		//strip chars here and return getline contents?
		getline(std::cin, contents, '\n');
	}
	return SUCCESS;
}
//trys to open filename, and serialize  myEntryVector contents to it
//returns:
//SUCCESS all worked, filename contains myEntryVector strings
//COULD_NOT_OPEN_FILE_TO_WRITE
int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	//TODO fill in
	return SUCCESS;
}
