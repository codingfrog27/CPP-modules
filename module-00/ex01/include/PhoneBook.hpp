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
#include <thread>
#include <chrono>
#include "Contact.hpp"

#define MAX_INDEX 2
#define LINE "--------------------------------------------"
#define C_RED "\033[1;31m"
#define C_RESET "\033[0m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define PURPLE "\033[35m"
#define BOLD "\033[1m"


class PhoneBook
{
private:
	Contact Contacts[MAX_INDEX + 1];
	inline void format_name(std::string name);
public:
		PhoneBook(/* args */);
		~PhoneBook();

void	add_contact();
void	search();
int		find_oldest_contact_index();
void	choose_and_display(int existing_contacts);

};


#endif // PhoneBook_HPP
