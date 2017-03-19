#include "KargerMinCut.h"
#include "stdafx.h"
#include <algorithm>
#include <unordered_map>
#include <map>
#include <random>

void Contract(std::unordered_map <int, std::vector<int>>& graph, int nodeA, int nodeB)
{
	graph[nodeB].insert(graph[nodeB].end(), graph[nodeA].begin(), graph[nodeA].end());
	auto nodesConnectedToA = graph[nodeA];
	for (auto node : nodesConnectedToA)
	{
		auto position = graph[node].end();
		while ((position = std::find(
			graph[node].begin(),
			graph[node].end(),
			nodeA)) != graph[node].end())
		{
			*position = nodeB;
		}	
	}
	auto selfNodePosition = graph[nodeB].end();
	while ((selfNodePosition = std::find(
		graph[nodeB].begin(),
		graph[nodeB].end(),
		nodeB)) != graph[nodeB].end())
	{
		graph[nodeB].erase(selfNodePosition);
	}	
	graph.erase(nodeA);
}

int GetKargerMinCut(std::unordered_map<int, std::vector<int>>& graph, int numberOfRepetitions)
{
	auto n = graph.size();
	int minNodeNumber = (n*(n - 1)) / 2; //set to maximum number of possible edges
	auto originalGraph = graph;
	for (int i = 0; i < numberOfRepetitions; i++)
	{
		graph = originalGraph;
		std::random_device rd{};
		// Use Mersenne twister engine to generate pseudo-random numbers.
		std::mt19937 engine( rd () );
		for (auto numberOfNodes = graph.size(); numberOfNodes > 2; numberOfNodes = graph.size())
		{
			std::uniform_int_distribution<int> uni1(0, numberOfNodes - 1);
			auto random_integer = uni1(engine);
			auto graphElement = std::next(graph.begin(), random_integer);
			auto firstNode = graphElement->first;
			auto numberOfAdjacentNodes = graph[firstNode].size();
			std::uniform_int_distribution<int> uni2(0, numberOfAdjacentNodes - 1);
			random_integer = uni2(engine);
			auto secondNode = graph[firstNode][random_integer];
			Contract(graph, firstNode, secondNode);
		}
		auto nodeNumber = graph.begin()->second.size();
		if (nodeNumber < minNodeNumber)
			minNodeNumber = nodeNumber;
	}
	return minNodeNumber;
}

