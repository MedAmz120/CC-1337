#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip> // set precision
#include <ctime>
#include <vector>
#include <list>


class PmergeMe {
    public:
    PmergeMe ();
    ~PmergeMe ();
    PmergeMe (const PmergeMe& copie);
    PmergeMe& operator=(const PmergeMe& copie);

    bool    check_input(int ac, char **av);
    bool    check_duplicate(int num, int arr[], int size);
    bool    check_type(char *arg);
    void    merge_insert_sort(std::vector<int>& arr);
    void    pairing(const size_t  s, std::vector<int>& arr, std::vector<int> &larger, std::vector<int> &smaller);
    void    merge_insert_sort_list(std::list<int>& arr);

};

#endif