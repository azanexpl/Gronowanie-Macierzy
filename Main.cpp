#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    fstream plikwej, plikwej2;
    string a;
    int rozm;
    vector <int> gron;
    double is=0;
    double ml=0;
    double suma=0;
    double gronmacierzy;
    int licznik = 0;

    plikwej.open("WE.txt", fstream::in);
    getline(plikwej, a);
    rozm=((a.length()+1)/2);
    plikwej.close();

    int tablica[rozm][rozm];

    plikwej2.open("WE.txt", fstream::in);
    for(int i=0; i<rozm; i++)
    {
        for(int j=0; j<rozm; j++)
        {
            plikwej2 >> tablica[i][j];
            cout << tablica[i][j] << "  ";
        }
        cout << endl;
    }
    plikwej2.close();

    for(int i=0; i<rozm; i++)
    {
        for(int j=0; j<rozm; j++)
        {
            is = is+tablica[i][j];

            if(tablica[i][j]==1)
            {
                gron.push_back(j);
            }
        }

        if(is==0)
            {
                licznik--;
                ml=0;
                is=0;
                gron.clear();
            }
        else if(is==1)
            {
                licznik--;
                ml=0;
                is=0;
                gron.clear();
            }
        else
            {
                for(int i=0; i<gron.size(); i++)
                {
                    for(int j=0; j<gron.size(); j++)
                    {
                        ml = ml+tablica[gron[i]][gron[j]];
                    }
                }

                suma = suma + (ml/is);
                ml=0;
                is=0;
                gron.clear();

            }
    }
        gronmacierzy = suma / (rozm+licznik);

        cout << "Wspolczynnik gronowania macierzy wynosi: " << gronmacierzy;

    getch();
    return 0;
}
