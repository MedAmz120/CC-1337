#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe p1;

    if (!p1.check_input(ac, av))
        return 1;
    
    // ------------ First container Vector ----------- //
    std::vector<int> arr1;
    for (int i = 1; i < ac; i++) {
        arr1.push_back(std::atoi(av[i]));
    }


    std::cout << "Before : ";
	for (size_t i = 0; i < arr1.size(); ++i)
		std::cout << arr1[i] << " ";
	std::cout << std::endl;


    std::clock_t start = std::clock(); // processor clock time (CPU time) // clock_t return an integer value
	p1.merge_insert_sort(arr1); 
	std::clock_t end = std::clock(); // (CPU time) after the sorting process
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC; //  the number of clock ticks per second (convert to seconds)
    // casting to double, the division produces a more accurate floating-point resul
    
    
    std::cout << "After : ";
	for (size_t i = 0; i < arr1.size(); ++i)
		std::cout << arr1[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << arr1.size() << " elements with std::vector : "  <<
	std::fixed << std::setprecision(6) << time << " sec" << std::endl;

    // ------------- Second container List ---------- //

    std::list<int> arr2;
    for (int i = 1; i < ac; i++) {
        arr2.push_back(std::atoi(av[i]));
    }

    start = std::clock();
    p1.merge_insert_sort_list(arr2);
    end = std::clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << arr2.size() << " elements with std::list : " << std::fixed <<
    std::setprecision(7) << time << " sec" << std::endl;
    
    return 0;
}

