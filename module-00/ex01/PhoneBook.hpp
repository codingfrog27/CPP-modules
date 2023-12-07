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

#define MAX_CONTACTS 8

class	Contact
{
	public:
		//info to input
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	darkest_secret;

		bool	empty_entry;
		int		id;

				Contact();
		void	add_Contact(int	id);
};

class PhoneBook
{
private:
	Contact Contacts[MAX_CONTACTS];
public:
		PhoneBook(/* args */);
		~PhoneBook();

void	add_contact();
int		remove_oldest();

int		created_contacts;

};



// class MyClass //damm bruh vscode autocomplete almost too strong
// {
// public:
// 	MyClass();
// 	MyClass(MyClass &&) = default;
// 	MyClass(const MyClass &) = default;
// 	MyClass &operator=(MyClass &&) = default;
// 	MyClass &operator=(const MyClass &) = default;
// 	~MyClass();

// private:

// };

// MyClass::MyClass()
// {
// }

// MyClass::~MyClass()
// {
// }
#endif // PhoneBook_HPP
