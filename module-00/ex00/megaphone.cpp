/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 17:31:09 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/04/10 17:31:09 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define COLOUR_END "\033[0m"
#define COLOUR_RED "\033[0;31m"
#define COLOUR_GREEN "\033[0;32m"
#define COLOUR_BLUE "\033[0;34m"

// returns a colour code text string, is initialized on static for easy passing
// w/o reallocating (could refactor into printing for u instead of returning and taking an int as counter instead of having one be static)
char *rainbow_text(void)
{
	static int counter;
	static char colours[3][10] = {COLOUR_RED, COLOUR_GREEN, COLOUR_BLUE};
	counter++;
	if (counter > 2)
		counter = 0;
	return (colours[counter]);
}

int	main (int argc, char **argv)
{
	if (argc > 2)
	{
		for (size_t i = 1; argv[i]; i++)
		{
			for (size_t j = 0; argv[i][j]; j++)
				argv[i][j] = std::toupper(argv[i][j]);
			std::cout << rainbow_text() << argv[i] << COLOUR_END << " ";
		}
	}
	else
		std::cout << COLOUR_RED << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << COLOUR_END;
	std::cout << std::endl; //is there any functional diff between endl and \n?
	return (0);
}
