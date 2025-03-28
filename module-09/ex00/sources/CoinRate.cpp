#define DB_PATH "./data.csv"
#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"
#define C_CYAN "\033[36m"
#define C_RED "\033[31m"
#define LINE "-----------------------------------------"

#include <regex>
#include "CoinRate.hpp"
#include "BadInput.hpp"

CoinRate::CoinRate(std::string path) : _DBFile(DB_PATH), _input(path)
{
	std::string		value;


	ValidateFiles(path);
	getline(_DBFile, value);
	for (std::string key; std::getline(_DBFile, key, ',');)
	{
		//regex validation check? or maybe in validate function
		std::getline(_DBFile, value);
		// std::cout << "WHAT THA HELL " << value << std::endl;
		_rateMap[key] = std::stof(value); //stof except catch
	}
}

// REGEX NOTES
//^ and $==match from start till end of string
//  double \ cause 1 for regex one for string literal in C
//starts w 20, then 0, 1 or 2, then any digit and hopefully u get the picture
//the last part is any digit + for at least one
// //.?//d$ == optional . followed by any optional extra digits and the $ == end of string
// std::regex datePattern("^20[0-2]\\d-[01]\\d-[0-3]\\d \\| -?\\d+\\.?\\d*$");

//ewww I have to check if values are between 0 and 1000?
// check Year-month-day-format && for valid dates
// check if every value is float or pos int between 0 and 1000

void	CoinRate::ValidateFiles(std::string path)
{
	std::regex	datePattern("^20[0-2]\\d-[01]\\d-[0-3]\\d \\| (\\d+|\\d+\\.\\d+)$");
	std::string	line;

	if (!_DBFile.is_open())
		throw BadInput("Error: Could not open database: "); //diff error for database?
	if (!_input.is_open())
		throw BadInput("Error: Could not open file: " + path);
	
	std::getline(_input, line);
	if (line != "date | value") 
		throw BadInput("Expected 'date | value' in the first line.\n\nbut line == " + line);

	// std::cout << "Regex pattern: " << datePattern.mark_count() << std::endl;
	while (std::getline(_input, line)) {
		if (!std::regex_match(line, datePattern))
			throw BadInput("incorrect input on line " + line);
		
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