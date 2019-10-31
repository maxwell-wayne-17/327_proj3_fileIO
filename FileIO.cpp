/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	contents.clear();

	ifstream file;
	file.open(filename);

	if (!file.is_open()){
		return COULD_NOT_OPEN_FILE_TO_READ;
	}

	string line;
	while (getline(file, line)) {

		stringstream ss(line);

		getline(ss, line);
		contents += line;

		ss.clear();
	}

	file.close();

	return SUCCESS;
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	fstream file;
	file.open(filename, ios_base::out);

	if (!file.is_open()){
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}

	std::vector<std::string>::iterator vectorItr;
	for(vectorItr = myEntryVector.begin();
			vectorItr != myEntryVector.end();
			vectorItr++){
		file << *vectorItr<< endl;
	}

	file.close();

	return SUCCESS;
}


