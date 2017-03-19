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


std::unordered_map <int, std::vector<int>> ReadGraphFromFile(const std::string& filepath)
{
	std::unordered_map <int, std::vector<int>> graph;
	std::ifstream inputFile(filepath);
	std::string line;
	for (int node = 1; std::getline(inputFile, line); node++)
	{
		std::istringstream iss(line, std::istringstream::in);
		std::string adjacentNode;
		iss >> adjacentNode;
		auto adjacentNodes = std::vector<int>();
		while (iss >> adjacentNode)
		{
			auto i = std::stoi(adjacentNode);
			adjacentNodes.push_back(i);
		}
		graph.insert(std::make_pair(node, adjacentNodes));
	}
	return graph;
}