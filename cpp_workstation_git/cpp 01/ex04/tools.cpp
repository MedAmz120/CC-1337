#include "Sed.hpp"

void ft_replace(args *data, size_t pos, std::string& line)
{
    line.erase(pos, data->s1.length()); // delete a portion of the string starting from a pos
    line.insert(pos, data->s2); // The function modifies the string in place.
}

void    ft_sed(args *data)
{
    const std::string   out_name = data->source_file + ".replace";
    std::ofstream       out_file(out_name); // "output file stream" and is used to write data to files. 
    std::string         line;
    size_t              position = 0;

    if (!out_file.is_open()) // checking whether it's created (exist or open) or not
        quit_program (EXIT_FAILURE, "ERROR:unable to open input.replace file\n");
    while (std::getline(data->src,line))   // getline from ifstream data->src file
    {    
        position = 0;
        while (true)
        {
            position = line.find(data->s1, position); //It returns an iterator to the first occurrence of the specified element in the given sequence
            if (position != std::string::npos) // npos = no valid position within the string
            {
                ft_replace(data, position, line);
                position += data->s2.length();
            }
            else
                break ;
        }
        out_file << line;
        out_file << std::endl;
    }
    out_file.close();
}

void    quit_program(int error, std::string cerr)
{
    if (error == EXIT_FAILURE)
    {
        std::cerr << cerr;
        exit (EXIT_FAILURE);
    }
    else
        exit(EXIT_SUCCESS);
}
