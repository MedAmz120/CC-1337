#include "PmergeMe.hpp"

/* ------------ Orthodox canonical Form ------------- */

PmergeMe::PmergeMe () {}

PmergeMe::~PmergeMe () {}

PmergeMe::PmergeMe (const PmergeMe& copie) {
    *this = copie;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copie) {
    if (this != &copie)
        return *this;
    return *this;
}


/* ------------ Algo Methods ---------------------- */

void    PmergeMe::pairing(const size_t  s, std::vector<int>& arr, std::vector<int> &larger, std::vector<int> &smaller) {
    for (size_t i = 0; i < s; i += 2)
	{
		if (i + 1 < s)
		{
			larger.push_back(std::max(arr[i], arr[i + 1]));
			smaller.push_back(std::min(arr[i], arr[i + 1]));
		} else
			larger.push_back(arr[i]);
	}
}

void    PmergeMe::merge_insert_sort(std::vector<int>& arr) {
	size_t s = arr.size();
	if (s <= 1) return;
	std::vector<int> larger, smaller;

	// Pairing and finding larger and smaller elements
    pairing(s, arr, larger, smaller);
	// Recursive sort the larger vector
	merge_insert_sort(larger);
	
	// Find the corresponding smaller element for the smallest larger element
	int smallestLarger = larger[0];
	int correspondingSmaller = -1;
	for (size_t i = 0; i < s; i += 2)
	{
		if (i + 1 < s)
		{
			if (arr[i] == smallestLarger || arr[i + 1] == smallestLarger)
			{
				correspondingSmaller = std::min(arr[i], arr[i + 1]);
				break;
			}
		}
	}

	arr.clear();
	arr = larger;
	if (correspondingSmaller != -1)
		arr.insert(arr.begin(), correspondingSmaller);

	// rermeaning smaller elements we insert them and in case of an odd number of numbers
	for (size_t i = 0; i < smaller.size(); ++i)
	{
		if (smaller[i] != correspondingSmaller)
		{
			std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), smaller[i]); // find the right position for the correspondingSmaller
			arr.insert(it, smaller[i]);
		}
	}
}

// merge_insert_sort([9, 3, 7, 4, 8])
//     -> merge_insert_sort([9, 7, 8])
//         -> merge_insert_sort[9, 8])
//             -> merge_insert_sort([9])  // Base Case


void	PmergeMe::merge_insert_sort_list(std::list<int>& arr)
{
	size_t n = arr.size();
	if (n <= 1) return;

	std::list<int> larger, smaller;

	std::list<int>::iterator it = arr.begin();
	for (size_t i = 0; i < n; i += 2)
	{
		if (i + 1 < n)
		{
			int first = *it++;
			int second = *it++;
			larger.push_back(std::max(first, second));
			smaller.push_back(std::min(first, second));
		} else
			larger.push_back(*it++);
	}


	merge_insert_sort_list(larger);

	int smallestLarger = larger.front();
	int correspondingSmaller = -1;
	it = arr.begin();
	for (size_t i = 0; i < n; i += 2)
	{
		if (i + 1 < n)
		{
			int first = *it++;
			int second = *it++;
			if (first == smallestLarger || second == smallestLarger)
			{
				correspondingSmaller = std::min(first, second);
				break;
			}
		}
	}

	arr.clear();
	arr = larger;

	if (correspondingSmaller != -1)
		arr.push_front(correspondingSmaller);

	for (std::list<int>::iterator it = smaller.begin(); it != smaller.end(); ++it)
	{
		if (*it != correspondingSmaller)
		{
			std::list<int>::iterator pos = std::lower_bound(arr.begin(), arr.end(), *it);
			arr.insert(pos, *it);
		}
	}
}
/* ----------------------------------------------------------------------------- */

/* ------------------------------ Input checkers Methods ---------------------- */
bool	PmergeMe::check_duplicate(int num, int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == num)
			return true;
	}
	return false;
}

bool	PmergeMe::check_type(char *arg)
{
	for (size_t j = 0; j < std::strlen(arg); ++j)
	{
		if (!std::isdigit(arg[j]))
			return true;
	}
	return false;
}

bool    PmergeMe::check_input(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Bad Usage: ./PmergeMe " << "<[0...9999]>" << std::endl;
        return 0;
    }

    int input[ac - 1];
    int count = 0;

	for (int i = 1; i < ac; ++i)
	{
		char *arg = av[i];

		if (check_type(arg))
		{
			std::cerr << "Error: Invalid Input: " << arg << std::endl;
			return false;
		}
		long num = std::atol(arg);
		if (num > INT_MAX || num < 0)
		{
			std::cerr << "Error: Negative numbers are not accepted and number <= INT_MAX: " << num << std::endl;
			return false;
		}
		if (check_duplicate(num, input, count))
		{
			std::cerr << "Error: There are duplicate numbers: " << num << std::endl;
			return false;
		}
		input[count] = static_cast<int>(num);
		++count;
	}
	return true;
}

/* ----------------------------------------------------------------------------- */