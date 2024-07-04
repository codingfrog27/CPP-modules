#ifndef CONTACT_HPP

#define CONTACT_HPP
#include <iostream>
#define C_RED "\033[1;31m"
#define C_RESET "\033[0m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define C_PURPLE "\033[35m"
#define C_BOLD "\033[1m"

class	Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	darkest_secret;
		bool	empty_entry;

					Contact();
		void		add_Contact(void);
		std::string	input_Info(std::string field_name);
};


#endif // CONTACT_HPP
