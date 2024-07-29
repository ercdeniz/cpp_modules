#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			BitcoinExchange exchange(av[1]);
			exchange.readAndParseDataFile();
			exchange.readAndParseInputFile();
		}
		catch (const std::exception &e)
		{
			EXCEPTERROR
		}
		return 0;
	}
	USAGEERROR
}
