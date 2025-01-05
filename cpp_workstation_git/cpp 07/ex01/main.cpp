#include "iter.hpp"


template <typename ourtype>
void    inc_ints(ourtype &i) {
    i++;
}

template <typename ourtype>
void    inc_float(ourtype &i) {
    i += 0.1;
}

void    print_int_arr(int &i){
    std::cout << i << ", ";
}

void    print_flo_arr(float &i){
    std::cout << i << ", ";
}

void    print_str_arr(std::string &str){
    std::cout << str << ", ";
}

int main ()
{
    int         int_arr[] = {4, 5, 2, 1, 0, 32, 412};
    float       flo_arr[] = {2.1, 5.4, 123.1, 0.5, 12314.33, 90.1};
    std::string str_arr[3] = {"Lorem", "ipsum", "jake"};
    int         int_arr_lenght = 7;
    int         float_arr_lenght = 6;

    std::cout << "Try incrementing the int_arr with inc_ints() :" << std::endl;
    iter(int_arr, int_arr_lenght, inc_ints<int>); // <int> here we create a version of inc_ints where ourtype is int
    iter(int_arr, int_arr_lenght, print_int_arr);
    std::cout << std::endl << std::endl;

    std::cout << "Now let's Print str_arr :" << std::endl;
    iter(str_arr, 3, print_str_arr);
    std::cout << std::endl << std::endl;

    std::cout << "Try incrementing the int_arr with inc_ints() :" << std::endl;
    iter(flo_arr, float_arr_lenght, inc_float<float>);
    iter(flo_arr, float_arr_lenght, print_flo_arr);
    std::cout << std::endl << std::endl;
}