#include <regex>
#include "CoinRate.hpp"
#include "BadInput.hpp"

#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"
#define C_CYAN "\033[36m"
#define C_RED "\033[31m"
#define LINE "-----------------------------------------"
#define DB_PATH "./data.csv"


CoinRate::CoinRate(std::string path) : _DBFile(DB_PATH), _input(path)
{
	std::string		value;
	if (!_DBFile.is_open())
		throw BadInput("Error: Could not open database: ");
	if (!_input.is_open())
		throw BadInput("Error: Could not open file: " + path);

	//decided database content validation is out of scope
	getline(_DBFile, value);
	for (std::string key; std::getline(_DBFile, key, ',');)
	{
		std::getline(_DBFile, value);
		_rateMap[key] = std::stof(value);
	}
}

bool	CoinRate::printConversion(std::string &line)
{
	using	MapEntry = std::map<std::string, float>::iterator;

	float			rate;
	size_t			dateEnd =	line.find(' ');
	std::string		date = 		line.substr(0, dateEnd);
	float			value = 	std::stof(line.substr(dateEnd + 2));
	MapEntry		it = 		_rateMap.find(date);
	
	if (it == _rateMap.end())
	{
		it = _rateMap.lower_bound(date);
		if (it == _rateMap.begin())
			return (false);
		it--;
	}
	rate = it->second;
	std::cout << date << " => " << value << " = " << value * rate << std::endl;
	return (true);
}


//using Regex B) if u wanna learn check my notion or regexone.com
void	CoinRate::ShowAllRates()
{
	std::string	line;
	std::regex	LinePattern("^\\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2]\\d|3[0-1]) \\| (1000|\\d{1,3}|\\d{1,3}\\.\\d{1,4})$");

	std::getline(_input, line);
	if (line != "date | value") 
		throw BadInput("Expected 'date | value' in the first line.\n\nbut line == " + line);
	while (std::getline(_input, line))
	{
		if (!std::regex_match(line, LinePattern) || !printConversion(line))
			printError(line);
	}
}


void	CoinRate::printError(std::string &line)
{
	std::string	errorMsg;
	std::regex	datePattern("^\\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2]\\d|3[0-1]) \\|");
	std::regex	ValuePattern("\\| (1000|\\d{1,3}|\\d{1,3}\\.\\d{1,4})$");
	if (!std::regex_search(line, datePattern))
		errorMsg = "Invalid date, please use valid Y-M-D format";
	else if (!std::regex_search(line, ValuePattern))
		errorMsg = "Invalid Value, can only be between 0-1000";
	else
		errorMsg = "date valid but too early! No lower database entry to match with :s";
	std::cerr << C_RED "Error on line \"" C_YELLOW  << line << C_RED "\": " << errorMsg << C_RESET << std::endl;
}