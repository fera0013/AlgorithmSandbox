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
		TEST_METHOD(TestQuickSortWithVectorInputAndFirstAsPivot)
		{
			std::vector<int> v{ 3, 8, 2, 5, 1, 4, 7, 6 };
			auto quickSort = v;
			auto stdSort = v;
			Quicksort(
				quickSort.begin(),
				quickSort.end(),
				[](auto a, auto b) { return a; });
			std::sort(stdSort.begin(), stdSort.end());
			Assert::IsTrue(quickSort == stdSort);

			v = std::vector<int>{ 8, 4, 1, 9, 16, 3 };
			quickSort = v;
			stdSort = v;
			Quicksort(
				quickSort.begin(),
				quickSort.end(),
				[](auto a, auto b) { return a; });
			std::sort(stdSort.begin(), stdSort.end());
			Assert::IsTrue(quickSort == stdSort);
		}
		TEST_METHOD(TestQuickSortWithListInputAndFirstAsPivot)
		{
			std::list<int> l{ 3, 8, 2, 5, 1, 4, 7, 6 };
			std::list<int> quickSort = l;
			std::list<int> stdSort = l;
			Quicksort(
				quickSort.begin(),
				quickSort.end(),
				[](auto a, auto b) { return a; });
			stdSort.sort();
			Assert::IsTrue(quickSort == stdSort);

			l = std::list<int>{ 3, 8, 2, 5, 1, 4, 7, 6 };
			quickSort = l;
			stdSort = l;
			Quicksort(
				quickSort.begin(),
				quickSort.end(),
				[](auto a, auto b) { return a; });
			stdSort.sort();
			Assert::IsTrue(quickSort == stdSort);
		}

		TEST_METHOD(TestQuickSortWithVectorInputAndLastAsPivot)
		{
			std::vector<int> v{ 3, 8, 2, 5, 1, 4, 7, 6 };
			auto quickSort = v;
			auto stdSort = v;
			Quicksort(
				quickSort.begin(),
				quickSort.end(),
				[](auto a, auto b) { return std::prev(b); });
			std::sort(stdSort.begin(), stdSort.end());
			Assert::IsTrue(quickSort == stdSort);

			v = std::vector<int>{ 8, 4, 1, 9, 16, 3 };
			quickSort = v;
			stdSort = v;
			Quicksort(
				quickSort.begin(),
				quickSort.end(),
				[](auto a, auto b) { return std::prev(b); });
			std::sort(stdSort.begin(), stdSort.end());
			Assert::IsTrue(quickSort == stdSort);
		}
		TEST_METHOD(TestQuickSortWithListInputAndLastAsPivot)
		{
			std::list<int> l{ 3, 8, 2, 5, 1, 4, 7, 6 };
			std::list<int> quickSort = l;
			std::list<int> stdSort = l;
			Quicksort(
				quickSort.begin(),
				quickSort.end(),
				[](auto a, auto b) { return std::prev(b); });
			stdSort.sort();
			Assert::IsTrue(quickSort == stdSort);

			l = std::list<int>{ 3, 8, 2, 5, 1, 4, 7, 6 };
			quickSort = l;
			stdSort = l;
			Quicksort(
				quickSort.begin(),
				quickSort.end(),
				[](auto a, auto b) { return std::prev(b); });
			stdSort.sort();
			Assert::IsTrue(quickSort == stdSort);
		}

		TEST_METHOD(TestGetMedianOfThreePivot)
		{
			constexpr int excpectedPivotValue = 4;
			std::vector<int> v{ 8, 2, 4, 5, 7, 1 };
			auto pivot = GetMedianOfThreePivot(v.begin(), v.end());
			Assert::AreEqual(excpectedPivotValue, *pivot);

			v= std::vector<int>{ 8, 2, 3, 4, 5, 7, 1 };
			pivot = GetMedianOfThreePivot(v.begin(), v.end());
			Assert::AreEqual(excpectedPivotValue, *pivot);
		}

		TEST_METHOD(TestPartition)
		{
			std::vector<int> v{ 3, 8, 2, 5, 1, 4, 7, 6 };
			auto pivot = *v.begin();
			auto i = Partition(v.begin(), v.end(), v.begin());
			Assert::AreEqual(pivot, *i);
			Assert::IsTrue(
				std::is_partitioned(
					v.begin(),
					v.end(),
					[pivot](int e) { return e <= pivot; }));
		}
		TEST_METHOD(TestQuickSortWithVeryLargeInputAndFirstAsPivot)
		{
			std::vector<int> v = ReadVectorFromFile("..\\Data\\QuickSort.txt");
			auto quickSort = v;
			auto stdSort = v;
			std::sort(stdSort.begin(), stdSort.end());
			Quicksort(
				quickSort.begin(),
				quickSort.end(),
				[](auto a, auto b) { return a; });
			Assert::IsTrue(quickSort == stdSort);
		}
		TEST_METHOD(TestQuickSortAndComparisonCountWithVeryLargeInput)
		{
			unsigned int numberOfComparisons = 0;
			constexpr unsigned int expectedNumberOfComparisonsUsingFirstElementAsPivot = 162085;
			std::vector<int> v = ReadVectorFromFile("..\\Data\\QuickSort.txt");
			auto quickSort = v;
			auto stdSort = v;
			std::sort(stdSort.begin(), stdSort.end());
			QuicksortAndCountComparisons(
				quickSort.begin(),
				quickSort.end(),
				[](auto a, auto b) { return a; },
				numberOfComparisons);
			Assert::IsTrue(quickSort == stdSort);
			Assert::AreEqual(expectedNumberOfComparisonsUsingFirstElementAsPivot, numberOfComparisons);

			numberOfComparisons = 0;
			constexpr unsigned int expectedNumberOfComparisonsUsingLastElementAsPivot = 164123;
			quickSort = v ;
			stdSort = v;
			std::sort(stdSort.begin(), stdSort.end());
			QuicksortAndCountComparisons(
				quickSort.begin(),
				quickSort.end(),
				[](auto a, auto b) { return std::prev(b); },
				numberOfComparisons);
			Assert::IsTrue(quickSort == stdSort);
			Assert::AreEqual(expectedNumberOfComparisonsUsingLastElementAsPivot, numberOfComparisons);

			numberOfComparisons = 0;
			constexpr unsigned int expectedNumberOfComparisonsUsingMedianElementAsPivot = 138382;
			quickSort = v;
			stdSort = v;
			std::sort(stdSort.begin(), stdSort.end());
			QuicksortAndCountComparisons(
				quickSort.begin(),
				quickSort.end(),
				GetMedianOfThreePivot<decltype(v.begin())>,
				numberOfComparisons);
			Assert::IsTrue(quickSort == stdSort);
			Assert::AreEqual(expectedNumberOfComparisonsUsingMedianElementAsPivot, numberOfComparisons);
		}
	};
}