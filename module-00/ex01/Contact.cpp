#include "Contact.hpp"

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

std::string	Contact::input_Info(std::string field_name)
{
	int	error_count = 3;
	std::string	input;
	while (true)
	{
		std::cout << "please enter " << C_YELLOW << field_name << ':' << C_RESET;
		std::getline(std::cin, input); //switched from cin to avoid spaces leading to double entries :)
		if (!input.empty())
			return (input);
		std::cout << "\nNo empty fields allowed silly!" << std::endl << error_count \
		<< " tries left before defaulting to \"silly\"\n" << std::endl;
		error_count--;
		if (error_count == 0)
		{
			std::cout << C_RED << "guess typing is hard huh :')\n" << C_RESET << field_name << " is" \
			<< C_PURPLE << " silly.\n" << std::endl;
			input = C_PURPLE "Silly" C_RESET;
			return (input);
		}
	}
}
