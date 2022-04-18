#include <iostream>
#include <string>
//5.	Scrieți un subprogram care să citească n cuvinte de la tastatură și care să le sorteze în ordine crescătoare
int main()
{
    int n, ok = 0;
    char s[100];
    char saux1[100][100];
    char cuvant[100];

    std::cout << "numarul de cuvinte n= ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> s;
        strcpy_s(saux1[i], s);
    }


    for (int i = 0; i < n; i++)
        std::cout << saux1[i] << " ";
    std::cout << std::endl;



    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (saux1[i][0] > saux1[j][0])
            {

                strcpy_s(cuvant, saux1[i]);
                strcpy_s(saux1[i], saux1[j]);
                strcpy_s(saux1[j], cuvant);
                ok = 1;

            }
            if (saux1[i][0] == saux1[j][0])
            {
                int l = 0;
                int k = 0;
                while (l < strlen(saux1[i]) && k < strlen(saux1[j]) && ok == 0)
                {
                    if (saux1[i][l] > saux1[j][k])
                    {

                        strcpy_s(cuvant, saux1[i]);
                        strcpy_s(saux1[i], saux1[j]);
                        strcpy_s(saux1[j], cuvant);
                        ok = 1;

                    }
                    if (saux1[i][l] <= saux1[j][k])
                    {
                        l++;
                        k++;
                    }
                }
            }
            
        }
    }
    for (int i = 0; i < n; i++)

        std::cout << saux1[i] << " ";
    return 0;
}

