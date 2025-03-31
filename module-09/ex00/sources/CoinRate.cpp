#include <regex>
#include "CoinRate.hpp"
#include "BadInput.hpp"

#define DB_PATH "./data.csv"
#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"
#define C_CYAN "\033[36m"
#define C_RED "\033[31m"
#define LINE "-----------------------------------------"


CoinRate::CoinRate(std::string path) : _DBFile(DB_PATH), _input(path)
{
	std::string		value;
	if (!_DBFile.is_open())
		throw BadInput("Error: Could not open database: ");
	if (!_input.is_open())
		throw BadInput("Error: Could not open file: " + path);

	ValidateInput(path);
	//decided database content validation is out of scope
	getline(_DBFile, value);
	for (std::string key; std::getline(_DBFile, key, ',');)
	{
		std::getline(_DBFile, value);
		_rateMap[key] = std::stof(value);
	}
}


//using regex B) Looks confusing on first look but think it's a text pattern matching tool worth concidering!
void	CoinRate::ValidateInput(std::string path)
{
	std::regex	datePattern("^20([0-1]\\d|2[0-2])-(0\\d|1[0-2])-([0-2]\\d|3[0-1]) \\| (1000|\\d{1,3}|\\d{1,3}\\.\\d{1,4})$");
	std::string	line;
	float		value;

	
	
	std::getline(_input, line);
	if (line != "date | value") 
		throw BadInput("Expected 'date | value' in the first line.\n\nbut line == " + line);

	while (std::getline(_input, line)) {
		if (!std::regex_match(line, datePattern))
			throw BadInput("incorrect input on line " + line);
		value = std::stof(line.substr(13));
	}
	std::cout << C_CYAN "input is valid! :)" C_RESET << std::endl;

}

void	CoinRate::printConversion()
{
	using	MapEntry = std::map<std::string, float>::iterator;

	MapEntry		current;
	std::string		date;
	size_t			dateEnd;
	float			value;
	float			rate;

	_input.clear();
	_input.seekg(13); //setting the filestream to first char of values
	

	for (std::string line; std::getline(_input, line);)
	{
		
		dateEnd = line.find(' ');
		date = line.substr(0, dateEnd);
		value = std::stof(line.substr(dateEnd + 2));
		current = _rateMap.find(date);
		if (current == _rateMap.end())
		{
			current = _rateMap.lower_bound(date);
			//if current == map.begin
			current--;
		}
		rate = current->second;
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
			
	}
	// 2011-01-03 => 3 = 0.9
}