#pragma once

#include <fstream>
#include <map>
#include <iostream>

class CoinRate
{
	private:
		std::ifstream					_DBFile;
		std::ifstream					_input;
		std::map<std::string, float>	_rateMap;
		void	ValidateInput(std::string path);

	public:
		CoinRate() = delete;
		CoinRate(std::string path);
		~CoinRate() = default;

		//methods
		void	ShowAllRates();
		bool	printConversion(std::string &line);
		void	printError(std::string &line);
};