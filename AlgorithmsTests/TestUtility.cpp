#pragma once
#include "stdafx.h"
#include "TestUtiliy.h"

std::vector<int> ReadVectorFromFile(const std::string& filepath)
{
	std::vector<int> v;
	std::ifstream inputFile(filepath);
	// test file open   
	if (inputFile) {
		int value;

		// read the elements in the file into a vector  
		while (inputFile >> value) {
			v.push_back(value);
		}
	}
	return v;
};