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

void	replacin_time(std::string find, std::string replace, \
					std::ifstream	&infile, std::ofstream	&outfile);

int main(int argc, const char** argv)
{
	if(argc != 4)
	{
		std::cout << "Please give 3 parameters, no more no less :)" << std::endl;
		return (1);
	}
	std::string		filename = argv[1];
	std::string		find = argv[2];
	std::string		replace = argv[3];
	std::ifstream	infile(filename);
	std::ofstream	outfile(filename + ".replace");
	size_t			ret_val = 1;

	if (find.empty())//  || replace.empty()
		std::cerr << "Error:find strings is empty!.\n";
	else if (!infile.is_open())
		std::cerr << "Error: Could not open the input file.\n";
	else
	{
		ret_val = 0;
		replacin_time(find, replace, infile, outfile);
		infile.close();
	}
	outfile.close();
	return (ret_val);
}


void	replacin_time(std::string find, std::string replace, \
					std::ifstream	&infile, std::ofstream	&outfile)
{
	std::string		buffer;
	size_t	replace_index = 0;
	size_t	replace_len = replace.length();
	size_t	find_len = find.length();

	while ((std::getline(infile, buffer)))
	{
		buffer.append("\n");
		replace_index = buffer.find(find);
		while (replace_index != std::string::npos)
		{
			buffer.erase(replace_index, find_len);
			buffer.insert(replace_index, replace);
			replace_index = buffer.find(find, replace_index + replace_len);
		}
		outfile << buffer;
	}
}
