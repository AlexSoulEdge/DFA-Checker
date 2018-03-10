#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include "DFA.h"


using namespace std;

ifstream fin ("dfa.txt");
vector < vector <string> > matrice_adiacenta;
vector <unsigned int> stari_finale;

void citire_dfa(unsigned int &nr_stari, unsigned int &stare_initiala, string litere)
{
    unsigned int n, nod1, nod2, nr_litere, nr_stari_finale, stare;
    char muchie, litera;

    fin >> n >> nr_litere;
    nr_stari = n;

    for(int i = 0; i < nr_litere; i ++)
    {
        fin >> litera;
        litere.push_back(litera);
        //cout << litere[i] << " ";
    }
    //cout << endl << endl;

    fin >> stare;
    stare_initiala = stare;

    fin >> nr_stari_finale;

    for(int i = 0; i < nr_stari_finale; i ++)
    {
        fin >> stare;
        stari_finale.push_back(stare);
        //cout << stare << " ";
    }

    //cout << endl << endl;

    matrice_adiacenta.resize(n);
    for(int i = 0; i < n; i ++)
    {
        matrice_adiacenta[i].resize(n);
    }




    while(fin >> nod1 >> nod2 >> muchie)
    {
        matrice_adiacenta[nod1][nod2].push_back(muchie);
    }

    /*
    cout <<endl;
    cout<<"Nr stari:"<<nr_stari;cout <<endl;
    cout<<"Stare initiala:"<<stare_initiala;cout <<endl;
    cout<<"Stari finale:"; for(int i = 0; i < stari_finale.size(); i ++) cout<<stari_finale[i] << " "; cout <<endl;
    cout<<endl<<endl;
    */

}

int isfinal(unsigned int stare)
{
    for(int i = 0; i < stari_finale.size(); i ++)
    {
        if(stare == stari_finale[i])
            return 1;
    }

    return 0;
}

int foundinstring(string x, char c)
{
    for(int i = 0; i < x.length(); i ++)
    {
        if(x[i] == c)
            return 1;
    }

    return 0;
}

int verificare(string word,unsigned int nr_stari, unsigned int stare_initiala)
{
    unsigned int stare1 = stare_initiala, stare2;
    unsigned int found = 0;
    if(word[0] == '0')
    {
        if(!isfinal(stare_initiala))
            return 0;
        return 1;
    }

    //cout<<"Noduri parcurse: " << stare_initiala << " - ";

    for(int i = 0; i < word.length(); i ++)
    {
        found = 0;
        for(int j = 0; j < nr_stari; j ++)
        {
            if(foundinstring(matrice_adiacenta[stare1][j], word[i]))
            {
                stare1 = j;
                j = nr_stari;
                found = 1;
            }

        }
        if (!found)
            return 0;
        //cout<<stare1<<" - ";

    }

    //cout<<"END"<<endl<<endl;

    if(!isfinal(stare1))
        return 0;

    return 1;



}



int main()
{
    unsigned int n = 0, option;
    unsigned int stare_initiala;
    string litere, cuvant;


    citire_dfa(n, stare_initiala, litere);
    fin.close();

tryagain:
    cout << "Introduceti un cuvant (pentru cuvantul vid, introduceti 0): ";
    cin >> cuvant;

    cout << endl << endl;
    if(verificare(cuvant, n, stare_initiala))
        cout << "Acceptat.";
    else
        cout << "Neacceptat.";

    cout << endl;

    cout << "Alt cuvant? 1 - da, 0 - nu :";
    cin >> option;
    cout << endl << endl;


    if(option)
        goto tryagain;

    /*
    cout<<endl<<endl;
    for(int i = 0; i < n; i ++)
    for(int j = 0; j < n; j ++)
    {
        if(matrice_adiacenta[i][j].empty())
            cout<<"x ";
        else
        cout << matrice_adiacenta[i][j] << " ";

        if(j == n-1)
            cout << endl;
    }
    */



    return 0;
}
