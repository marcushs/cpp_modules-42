#include <algorithm>
#include <iostream>
#include <deque>
 
template<class Iter>
void merge_sort(Iter first, Iter last)
{
    if (last - first > 1)
    {
        Iter middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
    }
}
 
int main()
{
    std::deque<std::deque<int> > d{{8, 2}, {-2, 0}, {11, 11}, {1, 7}, {3}};
    merge_sort(d.begin(), d.end());
    for (std::deque<std::deque<int> >::iterator it = d.begin(); it != d.end(); ++it) {
		for (std::deque<int>::iterator j = (*it).begin(); j != (*it).end(); ++j) {
			std::cout << *j << ' ';
		}
	}
    std::cout << '\n';
}
