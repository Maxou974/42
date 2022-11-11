#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>

bool	is_int;
bool	is_char;
bool	is_float;
bool	is_double;
bool	iof = 0;

bool	isFloat(const std::string &str)
{
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return true;
	int	points = 0;
	int f = 0;
	size_t	i = 0;
	const char *st = str.c_str();
	if (st[0] == '-')
		i = 1;
	while (i < str.size())
	{
		if (st[i] == 'f')
			f++;
		else if (st[i] == '.')
			points++;
		else if (!isdigit(st[i]))
			return false;
		i++;
	}
	if (((f == 1 && points == 1) || points == 0) && str[str.size() - 1] == 'f')
		return true;
	else
		return false;
}

bool	isDouble(const std::string &str)
{
	if (str == "nan" || str == "+inf" || str == "-inf")
		return true;
	int	points = 0;
	size_t	i = 0;
	const char *st = str.c_str();
	if (st[0] == '-')
		i = 1;
	while (i < str.size())
	{
		if (st[i] == '.')
			points++;
		else if (!isdigit(st[i]))
			return false;
		i++;
	}
	if (points == 1 || points == 0)
		return true;
	else
		return false;
}

bool	isInt(const std::string &str)
{
	std::string copy = str;
	size_t pos;
	pos = str.find('.');
	if (pos != std::string::npos)
			copy.erase(pos);
	int	tmp;
	char buffer[13];
	tmp = atoi(copy.c_str());
	sprintf(buffer, "%d", tmp);
	if (!strcmp(copy.c_str(), buffer) && copy == str)
		return true;
	if (copy[copy.size() - 1] == 'f')
		copy.erase(copy.size() - 1);
	if (strcmp(copy.c_str(), buffer))
		iof = 1;
	return false;
}

bool	isChar(const std::string &str)
{
	if (str.size() != 1)
		return false;
	if (str[0] > 20 && str[0] < 127 && !isdigit(str[0]))
		return true;
	return false;
}

void	print(std::string str, char c, int i, float f, double d)
{
	(void)str;
	if (is_char)
	{
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (is_int)
	{
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}
	else if (is_float)
	{
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
	}
	else if (is_double)
	{
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
	}
	std::cout << "char: ";
	if ((i >= 0 && i <= 31) || i == 127)
		std::cout << "Non displayable\n";
	else if (iof || !(i > 31 && i < 127))
		std::cout << "impossible\n";
	else
		std::cout << "'" << c << "'\n";

	std::cout << "int: ";
	if (iof)
		std::cout << "impossible\n";
	else
		std::cout << i << '\n';
	
	std::cout << "float: " << f;
	if (f == i)
		std::cout << ".0f\n";
	else
		std::cout << "f\n";

	std::cout << "double: " << d;
	if (d == i)
		std::cout << ".0\n"; 
	else
		std::cout << '\n';
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char	_char;
		int		_int;
		float	_float;
		double	_double;
		std::string str = argv[1];

		if ((is_char = isChar(str)))
			_char = str[0];
		else if ((is_int = isInt(str)))
			_int = atoi(str.c_str());
		else if ((is_float = isFloat(str)))
			_float = atof(str.c_str());
		else if ((is_double = isDouble(str)))
			_double = atof(str.c_str());
		else
		{
			std::cout << "Nothing to convert\n";
			return 1;
		}
		print(str, _char, _int, _float, _double);
	}
	else
		std::cout << "One arguments needed\n";
}