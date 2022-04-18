#include<string>
#include <iostream>
using namespace std;
//1.	Să se determine de câte ori apare un anumit caracter într-un șir de caractere dat. 
int main()
{
    string s;
    getline(cin, s);
    char c;
    cin >> c;
    int nr = 0;
    for (int i = 0; i < s.length(); ++i)
        if (c==s[i])
            nr++;
    cout << nr;

    
}

