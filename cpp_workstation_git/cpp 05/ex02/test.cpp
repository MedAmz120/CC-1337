#include <iostream>
#include <fstream>

int main()
{
    // int a = 10;
    // int b = 0;

    // try {
    //     if (b == 0)
    //         throw "You can't do this shet here";
    //     else
    //         std::cout << "Division result is " << a / b << std::endl;
    // }
    // catch (const char* error) {
    //    std::cout << error << std::endl;
    // }

    std::ofstream file;
    std::string name = "testFILE";
	file.open(name.c_str(), std::ofstream::out);

    std::string tree = 
              "      *\n"
               "     /|\\\n"
               "    / | \\\n"
              "   /  |  \\\n"
              "  /   |   \\\n"
               " /    |    \\\n"
             "/_____|_____\\\n"
                "     | |\n"
              "    -----      \n";
    if (!file)
    {
        std::cout << "error while creating file" << std::endl;
        return 0;
    }
    file << tree;
	file.close();
}