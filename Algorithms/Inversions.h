#pragma once
#include <vector>
#include <iterator>
#include <stdio.h>

template<typename It>
std::vector<typename It::value_type> SortAndCountInversionsSubroutine(const It begin, const It middle, const It end, unsigned int& count)
{
	std::vector<typename It::value_type> v;
	It left{ begin }, right{ middle };
	while (left != middle && right != end)
	{
		if (*left <= *right)
		{
			v.push_back(*left++);
		}
		else
		{
			count+= std::distance(left, middle);
			v.push_back(*right++);
		}
	}
	v.insert(v.end(), left, middle);
	v.insert(v.end(), right, end);
	return v;
}

template<typename It>
void SortAndCountInversions(It begin, It end,unsigned int& count)
{ 
	auto size = std::distance(begin, end);
	if (size < 2)
		return;
	auto mid = std::next(begin, size / 2);
	SortAndCountInversions(begin, mid, count);
	SortAndCountInversions(mid, end, count);
	auto v = SortAndCountInversionsSubroutine(begin, mid, end, count);
	std::move(v.cbegin(), v.cend(), begin);
}
