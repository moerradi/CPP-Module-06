
#include <iostream>
#include <cmath>
#include <limits>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2) 
	{
		std::cerr << "Usage: ./convert [string]" << std::endl;
		return 1;
	}

	std::string str;
	double 		d;
	float 		f;

	str = argv[1];
	if(str.length() == 1 && !std::isdigit(str[0]))
		d = static_cast<double>(str[0]);
	else
		d = atof(argv[1]);
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if((d < 127 && d > 31))
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() || std::isnan(d) || std::isinf(d))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	f = static_cast<float>(d);
	std::cout << "float: " << f;
	if (!(std::isnan(f) || std::isinf(f)) && str.find('.') == std::string::npos)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << d;
	if (!(std::isnan(d) || std::isinf(d)) && str.find('.') == std::string::npos)
		std::cout << ".0";
	std::cout << std::endl;
	return 0;
}

