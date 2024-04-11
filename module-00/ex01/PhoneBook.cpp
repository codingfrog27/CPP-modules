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
}

PhoneBook::~PhoneBook()
{
		std::cout << "I have been destructed";
}

void	PhoneBook::add_contact(){

	size_t i = 0;
	while (i < MAX_INDEX && !Contacts[i].empty_entry) //was for loop but more readable like this?
		i++;
	if (i > MAX_INDEX){
		std::cout << "PhoneBook Full, Removing oldest entry";
		i = find_oldest_contact_index();
	}
	Contacts[i].add_Contact();
	std::cout << "\nContact saved!! :))" << std::endl;
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

int	PhoneBook::find_oldest_contact_index()
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

void	Contact::add_Contact(void)
{
	first_name = input_Info("first name");
	last_name = input_Info("last name");
	nickname = input_Info("Nickname");
	darkest_secret = input_Info("ur filthiest darkest secret uwu");
	empty_entry = false;
}

std::string	input_Info(std::string field_name)
{
	int	error_count = 3;
	std::string	input;
	while (true)
	{
		std::cout << "please enter " << C_YELLOW << field_name << ':' << C_RESET;
		std::getline(std::cin, input); //switched from cin to avoid spaces leading to double entries :)
		if (!input.empty())
			return (input);
		std::cout << "No empty fields allowed silly!" << std::endl << error_count \
		<< " tries left before defaulting to \"silly\"\n" << std::endl;
		error_count--;
		if (error_count == 0)
		{
			std::cout << C_RED << "guess typing is hard huh :')" << field_name << "is silly" << std::endl;
			input = "default";
			return (input);
		}

	}
 //input reading only stops on non empty input so no need to check .... I take it back on repeated calls it doesnt get flushed
//  without this check
}

void PhoneBook::search()
{
	if (Contacts[0].empty_entry){
		std::cout << C_RED << "No contacts to search yet :s" << std::endl;
		return ;
	}
	int	i = 0;
	std::cout << LINE << std::endl;
	while (Contacts[i].empty_entry == false)
	{
		// std::cout << std::right << std::setw(10) << i << '|' << std::setw(10) << display[0]
		// << '|' << std::setw(10) << Contacts[i].last_name << '|' << std::setw(10) << Contacts[i].nickname << std::endl;
		std::cout << '|' << std::setw(10) << i << '|';
		format_name(Contacts[i].first_name);
		format_name(Contacts[i].last_name);
		format_name(Contacts[i].nickname);
		std::cout << std::endl;
		i++;
	}
	std::cout << LINE << std::endl;
	choose_and_display(i - 1);
}

void	PhoneBook::choose_and_display(int max_index)
{
	int	index;
	while (1)
	{
		std::cout << "\nPlease give the index of the contact you'd like to see :)" << std::endl;
		std::cin >> index;
		if (std::cin.fail() || index > max_index || index < 0)
		{
			std::cout << C_RED "Please give a valid existing index" << C_RESET << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			break;
	}
	std::cout << std::endl << Contacts[index].first_name;
	std::cout << std::endl << Contacts[index].last_name;
	std::cout << std::endl << Contacts[index].nickname;
	std::cout << std::endl << Contacts[index].darkest_secret <<std::endl;
}

inline void PhoneBook::format_name(std::string name)
{
	std::string output;
	output = (name.size() > 10) ? (name.substr(0, 9) + '.') : name;
	std::cout << std::setw(10) << output << '|';
}

		// if (Contacts[i].first_name.size() > 10)
		// 	display[0] = Contacts[i].first_name.substr(0, 9) + '.';
		// else
		// 	display[0] = Contacts[i].first_name;
