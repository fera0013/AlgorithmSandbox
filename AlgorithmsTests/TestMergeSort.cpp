#pragma once
#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Algorithms\Sort.h"
#include <iostream>
#include <algorithm>
#include <list>
#include "TestUtiliy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmsTests
{		
	TEST_CLASS(TestMergeSort)
	{
	public:
		TEST_METHOD(TestMergeSortWithVectorInput)
		{
			std::vector<int> v{ 8, 4, 1, 9, 16, 3 };
			auto merge_sorted = v;
			auto std_sorted = v;
			MergeSort(merge_sorted.begin(), merge_sorted.end());
			std::sort(std_sorted.begin(), std_sorted.end());
			Assert::IsTrue(merge_sorted == std_sorted);
		}
		TEST_METHOD(TestMergeSortWithListInput)
		{
			std::list<int> v{ 8, 4, 1, 9, 16, 3 };
			std::list<int> merge_sorted = v;
			std::list<int> std_sorted = v;
			MergeSort(merge_sorted.begin(), merge_sorted.end());
			std_sorted.sort();
			Assert::IsTrue(merge_sorted == std_sorted);
		}
	};
}