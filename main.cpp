#include <iostream>
#include <fstream>
#include <vector>
#include "DFA.h"


using namespace std;

ifstream fin ("dfa.txt");
void citire_dfa(ifstream f, unsigned int &nr_stari, unsigned int *matrice_adiacenta)
{
    unsigned int n, nod1, nod2;
    char muchie;

    f >> n;
    nr_stari = n;
    char matrice[n][n];

    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            matrice[n][n] = '\0';
        }


    while(!f.eof())
    {
        f >> nod1 >> nod2;
        f >> muchie;

        matrice_adiacenta[nod1][nod2] = muchie;
    }


    f.close();
}

int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
