#pragma once
#include <vector>
#include <iterator>
#include <functional>

template<typename It>
std::vector<typename It::value_type> merge(const It begin, const It mid, const It end)
{
	std::vector<typename It::value_type> v;
	It it_l{ begin }, it_r{ mid };
	const It it_mid{ mid }, it_end{ end };

	while (it_l != it_mid && it_r != it_end)
	{
		v.push_back((*it_l <= *it_r) ? *it_l++ : *it_r++);
	}

	v.insert(v.end(), it_l, it_mid);
	v.insert(v.end(), it_r, it_end);

	return v;
}

template<typename It>
void MergeSort(It begin, It end)
{
	auto size = std::distance(begin, end);
	if (size < 2)
		return;

	auto mid = std::next(begin, size / 2);
	MergeSort(begin, mid);
	MergeSort(mid, end);

	auto v = merge(begin, mid, end);
	std::move(v.cbegin(), v.cend(), begin);
}

template<typename It>
It GetMedianOfThreePivot(It begin, It end)
{
	auto length = std::distance(begin, end);
	auto movePositions = length % 2 == 0 ? (length / 2) - 1 : length / 2;
	auto middle = std::next(begin, movePositions);
	end = std::prev(end, 1);
	if ((*begin <= *middle && *middle <= *end) || (*end <= *middle && *middle <= *begin))
		return middle;
	if ((*middle <= *end && *end <= *begin) || (*begin <= *end && *end <= *middle))
		return end;
	if ((*end <= *begin && *begin <= *middle) || (*middle <= *begin && *begin <= *end))
		return begin;

}

template<typename It, typename T>
void Foo(It begin, It end, T&& CallBar)
{
	CallBar(begin, end);
}

template<typename It>
It Bar(It begin, It end)
{
	return begin;
}


template<typename It>
It Partition(It begin,It end,It pivot)
{
	std::swap(*begin, *pivot); 
	pivot = begin;
	It i{ begin }, j = std::next(begin, 1);
	for(;j != end; j++)
	{
		if(*j < *pivot)
			std::swap(*j, *++i);
	}
	std::swap(*pivot, *i);
	return i;
}


template<typename It, typename Pivot>
void Quicksort(It begin, It end, Pivot&& GetPivot)
{
	if (std::distance(begin, end) == 0)
		return;
	It pivot{ GetPivot(begin,end) };
	It elementAtCorrectPosition = Partition(begin, end,pivot);
	Quicksort(begin, elementAtCorrectPosition, GetPivot);
	Quicksort(std::next(elementAtCorrectPosition, 1), end, GetPivot);
}

template<typename It, typename Pivot>
void QuicksortAndCountComparisons(It begin, It end, Pivot&& GetPivot, unsigned int& comparisonCount)
{
	if (std::distance(begin, end) == 0)
		return;
	comparisonCount += std::distance(begin, end) - 1;
	It pivot{ GetPivot(begin,end) };
	It elementAtCorrectPosition = Partition(begin, end, pivot);
	It newEnd{ elementAtCorrectPosition };
	It newStart{ std::next(elementAtCorrectPosition, 1) };
	QuicksortAndCountComparisons(begin, newEnd, GetPivot, comparisonCount);
	QuicksortAndCountComparisons(newStart, end, GetPivot,comparisonCount);
}






