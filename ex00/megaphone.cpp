#include <iostream>
#define ERR_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv)
{
	std::string str;
	int 		i = 1;

	if (argc < 2) {
		std::cout << ERR_MSG << std::endl;
		return 0;
	}
	while (argv[i])	{
		str = argv[i];
		for (unsigned int j = 0; j < str.length(); j++) {
			char ch = std::toupper(str[j]);
			std::cout << ch;
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}
