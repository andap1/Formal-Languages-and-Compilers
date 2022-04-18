#include <iostream>
#include <string>
int main()
{
    int nr_cuvinte;
    int gasit=1;
    int n = 0;
    char vector_cuvinte[100][100];
    char s1[100];
    char vector_cuvinte_nou[100][100];
    std::cout << "numarul de cuvinte din vector ";
    std::cin >> nr_cuvinte;
    std::cout << "cuvintele din vector";
    for(int i=0;i<nr_cuvinte;i++)
    std::cin >> vector_cuvinte[i];
    std::cout << "subsirul este: ";
    std::cin >> s1;

    for (int i = 0; i < nr_cuvinte; i++)
    {
        int j = 0;
        int k = 0;
        gasit = 1;
        while (k < strlen(s1)&& j<strlen(vector_cuvinte[i])&&gasit==1)
        {
            if (vector_cuvinte[i][j] != s1[k])
                while (vector_cuvinte[i][j] != s1[k])
                             j++;
            else
            {
                if (vector_cuvinte[i][j+1] != s1[k+1])
                    gasit = 0;
                else
                  while(vector_cuvinte[i][j] == s1[k]&&k < strlen(s1) && j < strlen(vector_cuvinte[i]))
                {
                    j++;
                    k++;
                }
            }
              
        }
        if (gasit == 1)
            strcpy_s(vector_cuvinte_nou[n++], vector_cuvinte[i]);

    }
    for (int i = 0; i < n; i++)
        std::cout << vector_cuvinte_nou[i] << "  ";
}


