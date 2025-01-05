#include "Array.hpp"

int main()
{
    try {
        Array<int> a1(4);
        a1[1] = 1999;
        std::cout << "Normal Test 1 :" << std::endl;
        std::cout << "a2 size is : " << a1.size() << std::endl;
        std::cout << a1[1] << std::endl;
        std::cout << "-----------------------" << std::endl << std::endl;

        Array<int> a2(3);
        std::cout << "Normal Test 2 :" << std::endl;
        a2[0] = 888;
        a2[1] = 889;
        a2[2] = 900;
        std::cout << "a2 size is : " << a2.size() << std::endl;
        for (unsigned int i = 0; i < a2.size(); i++){
            std::cout << "a2["<< i <<"] = " << a2[i] << std::endl;
        }
        std::cout << "-----------------------" << std::endl << std::endl;
        
        
        Array<int> a3 = a2;
        std::cout << "Copy constructor Test 1 A3 Must be a copie of A2 :" << std::endl;
        std::cout << "a3 size is : " << a3.size() << std::endl;
        a3[0] = 57;
        std::cout << "a3[0] = " << a3[0] << std::endl;
        std::cout << "a2[0] (shouldn't be updated) = " << a2[0] << std::endl;
        std::cout << "-----------------------" << std::endl << std::endl;


        Array<int> a4;
        a4 = a2;
        std::cout << "Copy Assignment operator Test :" << std::endl;
        std::cout << "a4 size is : " << a4.size() << std::endl;
        a4[0] = 69;
        std::cout << "a4[0] = " << a4[0] << std::endl;
        std::cout << "a2[0] (shouldn't be updated) = " << a2[0] << std::endl;
        std::cout << "-----------------------" << std::endl << std::endl;

        Array<float> float_arr(3);
        std::cout << "Float Array Test :" << std::endl;
        std::cout << "float_arr size is : " << float_arr.size() << std::endl;
        float_arr[0] = 5.5;
        float_arr[1] = 123.44;
        float_arr[2] = 99.54;
        for (unsigned int i = 0; i < a2.size(); i++){
            std::cout << "float_arr["<< i <<"] = " << float_arr[i] << std::endl;
        }
        std::cout << "-----------------------" << std::endl << std::endl;

        Array<std::string> str1(12);
        str1[0] = "Lorem ipsum";
        std::cout << "String Array Test :" << std::endl;
        std::cout << "str1 size is : " << str1.size() << std::endl;
        std::cout << "str1[0] = " << str1[0] << std::endl;
        std::cout << "-----------------------" << std::endl << std::endl;

        const Array<int> const_array = a2;
        Array<int> a8;
        a8 = const_array;
        std::cout << "a8 size is : " << a8.size() << std::endl;
        for (unsigned int i = 0; i < a8.size(); i++){
            std::cout << "a8["<< i <<"] = " << a8[i] << std::endl;
        }
        // Verify that const_array (and indirectly a2) is unchanged
        std::cout << "const_array (should remain unchanged): " << std::endl;
        for (unsigned int i = 0; i < const_array.size(); i++) {
            std::cout << "const_array[" << i << "] = " << const_array[i] << std::endl;
        }
        std::cout << "a2 (should remain unchanged, as const_array was copied from it): " << std::endl;
        for (unsigned int i = 0; i < a2.size(); i++) {
            std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
        }

        //std::cout << "let's try to access float_arr[12] : " << float_arr[12] << std::endl;

        int *a = new int();
        *a = 42;
        std::cout << *a << std::endl;
        delete a;
    }
    catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }
}