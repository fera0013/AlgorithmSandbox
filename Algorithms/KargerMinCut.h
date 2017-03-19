#pragma once
#include <algorithm>
#include <unordered_map>


void Contract(std::unordered_map <int, std::vector<int>>& graph, int nodeA, int nodeB);
int GetKargerMinCut(std::unordered_map <int, std::vector<int>>& graph, int numberOfRepetitions);
