#pragma once
#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Algorithms\Inversions.h"
#include "..\Algorithms\Sort.h"
#include <iostream>
#include <algorithm>
#include <list>
#include "TestUtiliy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmsTests
{
	TEST_CLASS(TestInversionCounting)
	{
	public:

		TEST_METHOD(TestInversionCountingWithVectorInput)
		{
			std::vector<int> v1{ 1, 3, 5, 2, 4, 6 };
			unsigned int inversionCount = 0;
			unsigned int expectedCount = 3;
			SortAndCountInversions(v1.begin(), v1.end(), inversionCount);
			Assert::AreEqual(expectedCount, inversionCount);

			inversionCount = 0;
			expectedCount = 5;
			std::vector<int> v2{ 1, 20, 6, 4, 5 };
			SortAndCountInversions(v2.begin(), v2.end() , inversionCount = 0);
			Assert::AreEqual(expectedCount, inversionCount);
		}
		TEST_METHOD(TestInversionCountingWithListInput)
		{
			std::list<int> l{ 1, 3, 5, 2, 4, 6 };
			unsigned int inversionCount = 0;
			unsigned int expectedCount = 3;
			SortAndCountInversions(l.begin(), l.end(), inversionCount);
			Assert::AreEqual(expectedCount, inversionCount);

			inversionCount = 0;
			expectedCount = 5;
			std::list<int> v2{ 1, 20, 6, 4, 5 };
			SortAndCountInversions(v2.begin(), v2.end(),inversionCount);
			Assert::AreEqual(expectedCount, inversionCount);
		}
		TEST_METHOD(TestInversionCountingWithVeryLargeInput)
		{
			unsigned int inversionCount = 0;
			unsigned int expectedCount = 2407905288;
			std::vector<int> v = ReadVectorFromFile("..\\Data\\IntegerArray.txt");
			SortAndCountInversions(v.begin(), v.end(), inversionCount);
			Assert::AreEqual(expectedCount, inversionCount);
		}
	};
}