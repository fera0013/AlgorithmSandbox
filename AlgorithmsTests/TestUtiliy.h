#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
#include <istream>
#include <iostream>

std::vector<int> ReadVectorFromFile(const std::string& filepath);
std::unordered_map <int, std::vector<int>> ReadGraphFromFile(const std::string& filepath);
