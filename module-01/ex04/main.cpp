/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/05 19:42:01 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/06/05 19:42:01 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char** argv)
{
	if(argc != 4)
	{
		std::cout << "Please give 3 parameters, no more no less :)\n";
		return (1);
	}

	std::string		filename = argv[1];
	std::string		find = argv[2];
	std::string		replace = argv[3];
	std::string		buffer;
	std::ifstream	infile(filename);
	std::ofstream	outfile(filename + ".replace");
	size_t	replace_index = 0;

	 if (!infile.is_open()) {
        std::cerr << "Error: Could not open the input file.\n";
        return 1;
    }

	std::cout << "FIND IS: " << find << std::endl;
	std::cout << "replace IS: " << replace << std::endl;

	while ((std::getline(infile, buffer)))
	{
		buffer.append("\n");
		replace_index = buffer.find(find);
		while (replace_index != std::string::npos)
		{
			buffer.replace(replace_index, find.length(), replace);
			replace_index = buffer.find(find, replace_index + replace.length());
		}
		std::cout << buffer;
		outfile << buffer;
	}
	infile.close();
	outfile.close();
	return 0;
}

//could put all the strings and streams into a single class for overview but
// think this is fine :)


//already doesnt work properly since if the replace word is not in the line it
// wont be put into buffer

// also getline doesnt copy the newline so might have to read everything into buffer first?


	// while ((std::getline(infile, buffer)))
	// {
	// 	// replace_index = buffer.find(find);
	// 	while (replace_index != std::string::npos);
	// 	{
	// 		buffer.replace(replace_index, find.length(), replace);
	// 		outfile << buffer << std::endl;
	// 		replace_index = buffer.find(find, replace_index + replace.length());
	// 	}
	// }
