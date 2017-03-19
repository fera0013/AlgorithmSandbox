#pragma once
#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Algorithms\KargerMinCut.h"
#include "TestUtiliy.h"
#include <Windows.h>
#include <unordered_map>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmsTests
{
	TEST_CLASS(TestGraphAlgorithms)
	{
		TEST_METHOD(TestContraction)
		{
			std::unordered_map <int, std::vector<int>> graph = ReadGraphFromFile("..\\Data\\KargerMinCutSimple.txt");
			auto originalGraph = graph;
			auto graphSizeBeforeContraction = graph.size();
			auto expectedGraphSizeAfterContraction = graphSizeBeforeContraction - 1;
			Contract(graph, 1, 3);
			Assert::AreEqual(expectedGraphSizeAfterContraction, graph.size());
			graphSizeBeforeContraction = graph.size();
			expectedGraphSizeAfterContraction = graphSizeBeforeContraction - 1;
			Contract(graph, 3, 4);
			Assert::AreEqual(expectedGraphSizeAfterContraction, graph.size());
			Assert::AreEqual((size_t)3, graph.begin()->second.size());

			//Test different contraction path
			graph = originalGraph;
			graphSizeBeforeContraction = graph.size();
			expectedGraphSizeAfterContraction = graphSizeBeforeContraction - 1;
			Contract(graph, 1, 3);
			Assert::AreEqual(expectedGraphSizeAfterContraction, graph.size());
			graphSizeBeforeContraction = graph.size();
			expectedGraphSizeAfterContraction = graphSizeBeforeContraction - 1;
			Contract(graph, 2, 3);
			Assert::AreEqual(expectedGraphSizeAfterContraction, graph.size());
			Assert::AreEqual((size_t)2, graph.begin()->second.size());
		}
		TEST_METHOD(TestKargersMinimumCut)
		{
			std::unordered_map <int, std::vector<int>> simpleGraph = ReadGraphFromFile("..\\Data\\KargerMinCutSimple.txt");
			int expectedMinNodeCount = 2;
			int minNodeCount = GetKargerMinCut(simpleGraph, 100);
			Assert::AreEqual(expectedMinNodeCount, minNodeCount);

			std::unordered_map <int, std::vector<int>> largeGraph = ReadGraphFromFile("..\\Data\\KargerMinCut.txt");
			expectedMinNodeCount = 17;
			minNodeCount = GetKargerMinCut(largeGraph, 1000);
			Assert::AreEqual(expectedMinNodeCount, minNodeCount);
		}
	};
}