/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 17:45:56 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/12/04 17:45:56 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include <iostream>
#include <limits>
#include <iomanip>

#define MAX_INDEX 7
#define C_RED "\033[1;31m"
#define C_RESET "\033[0m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"

class	Contact
{
	public:
		//info to input
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	darkest_secret;

		bool	empty_entry;
		// int		id;

				Contact();
		void	add_Contact(void);
};

class PhoneBook
{
private:
	Contact Contacts[MAX_INDEX];
	inline void format_name(std::string name);
public:
		PhoneBook(/* args */);
		~PhoneBook();

void	add_contact();
void	search();
int		find_oldest_contact_index();

};


#endif // PhoneBook_HPP
