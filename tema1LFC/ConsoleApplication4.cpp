#include <iostream>
#include<string>
int main()
{
	std::string s;
	std::getline(std::cin, s);
	int nr = 0;
	int i = 0;
	while(i<s.length()-1)
	{
		if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
		{
			nr += 1;
			std::cout << nr << ". ";
			while (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
			{
				std::cout << s[i];
				i++;
			}
			std::cout << std::endl;
		}
		else
		{
			i++;
		}
	}
	
}

