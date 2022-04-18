#include <iostream>
#include <string>

int main()
{
    std::string s, s1, s2;
    std::cout << "sirul initial: ";
    std::getline(std::cin, s);
    std::cout << "sirul care trebuie inlocuit ";
    std::getline(std::cin, s1);
    std::cout << "sirul cu care trebuie inlocuit ";
    std::getline(std::cin, s2);
    for (int i = 0; i < s.length() / 2; ++i)
    {
        char aux = s[i];
        s[i] = s[s.length() - 1 - i];
        s[s.length() - 1 - i] = aux;

    }
    std::cout << "sirul initial-inversat  ";
    std::cout << s << std::endl;
    int i = 0;
    int j = 0;
    int gasit = 1;
    while (i < s.length() && j < s1.length())
    {
        if (s[i] != s1[j])
        {
            while (s[i] != s1[j])
                i++;
        }
        if (s[i] == s1[j])
        {
            int iaux = i;
            while (s[i] == s1[j])
            {
                i++;
                j++;
            }
            if (j != s1.length())
                gasit = 0;
            if (gasit == 1)
            {
                int k = iaux;
                int m = 0;
                while (k < i && m < s2.length())
                {
                    s[k] = s2[m];
                    k++;
                    m++;
                }
            }
            


        }


    }
    if (gasit == 0)
        std::cout << "nu s a gasit sir de inlocuit ";
    else

    std::cout << s;



}

