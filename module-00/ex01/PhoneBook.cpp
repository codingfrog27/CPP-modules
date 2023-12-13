/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 17:04:41 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/12/05 17:04:41 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	input_Info(std::string field_name);

PhoneBook::PhoneBook()
{
	created_contacts = 0;
}

PhoneBook::~PhoneBook()
{
		std::cout << "I have been destructed";
}

void	PhoneBook::add_contact(){

	size_t i = 0;
	while (i < MAX_INDEX && !Contacts[i].empty_entry) //was for loop but more readable like this?
		i++;
	//if (created_contacts > MAX_COUNTACTS)
	if (i > MAX_INDEX){
		std::cout << "PhoneBook Full, Removing oldest entry";
		i = remove_oldest();
	}
	Contacts[i].add_Contact(created_contacts);
	created_contacts++;
	std::cout << "Contact saved!! :))";
}


// int	PhoneBook::remove_oldest(){
// 	int	replace_index;

// 	for (size_t i = 0; i < MAX_INDEX; i++)
// 	{
// 		if (Contacts[i].id == 0)
// 			replace_index = i;
// 		else
// 			Contacts[i].id--;
// 	}
// 	created_contacts--;
// 	return (replace_index);
// }

int	PhoneBook::remove_oldest()
{
	static int	replace_counter;

	if (replace_counter > MAX_INDEX)
		replace_counter = 0;
	replace_counter++;
	return (replace_counter - 1);
}

Contact::Contact()
{
	empty_entry = true;
}

void	Contact::add_Contact(int id)
{
	first_name = input_Info("first name");
	last_name = input_Info("last name");
	nickname = input_Info("Nickname");
	darkest_secret = input_Info("ur filthiest darkest secret uwu");
	empty_entry = false;
	this->id = id;
}

std::string	input_Info(std::string field_name)
{
	std::cout << "please enter " << field_name << std::endl;
	std::string	input;
	while (true)
	{
		std::cin >> input;
		if (!input.empty())
			return (input);
		std::cout << "No empty fields allowed bucko >:)";
	}

}
