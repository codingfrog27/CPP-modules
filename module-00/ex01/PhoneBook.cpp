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
	std::cout << BOLD PURPLE << "\n\tW E L C O M E   T O\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "✨M Y" << std::flush;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "    C U T E" << std::flush;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "    P H O N E B O O K✨\n\n\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "\t\tyou can:\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(600));
	std::cout << C_YELLOW "\t\tADD\n"<< std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout << "\t\tSEARCH\n"<< std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	std::cout <<"\t\tEXIT\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
}


PhoneBook::~PhoneBook()
{
	std::cout << PURPLE BOLD << "\nI'm being destructed 😭\n\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout <<  "✨✨✨✨✨✨✨✨✨\n✨B Y E   C U T I E✨\n  ✨✨✨✨✨✨✨✨✨\n\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
}

void	PhoneBook::add_contact(){

	size_t i = 0;
	while (i <= MAX_INDEX && !Contacts[i].empty_entry)
		i++;
	if (i > MAX_INDEX){
		std::cout << "PhoneBook Full, Removing oldest entry\n\n";
		i = find_oldest_contact_index();
	}
	Contacts[i].add_Contact();
	std::cout << "\nContact saved!! :)) (press enter to continue)" << std::endl;
}

int	PhoneBook::find_oldest_contact_index()
{
	static int	replace_counter;

	if (replace_counter > MAX_INDEX)
		replace_counter = 0;
	replace_counter++;
	return (replace_counter - 1);
}

void PhoneBook::search()
{
	if (Contacts[0].empty_entry){
		std::cout << C_RED << "No contacts to search yet :s" << std::endl;
		return ;
	}
	int	i = 0;
	std::cout << LINE << std::endl;
	while (i <= MAX_INDEX && Contacts[i].empty_entry == false)
	{

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
	std::cout << "\nFirst name: " << Contacts[index].first_name << std::endl;
	std::cout << "\nLast name:" << Contacts[index].last_name << std::endl;
	std::cout << "\nNickname:" << Contacts[index].nickname << std::endl;
	std::cout << "\ndarkest secret 0-0:" << Contacts[index].darkest_secret << std::endl;
}

inline void PhoneBook::format_name(std::string name)
{
	std::string output;
	output = (name.size() > 10) ? (name.substr(0, 9) + '.') : name;
	std::cout << std::setw(10) << output << '|';
}
