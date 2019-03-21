#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream f("date.txt");

int main()
{

    int automat[100][100], iesire[100];
    int i, j, stareInitiala, stareFinala, stareStart, numarIesiri, numarStari, numarLegaturi;
    char cuvantDeVerificat[100], literaLegatura;

    for (i = 0; i < 100; i++)
        for (j = 0; j < 100; j++)
            automat[i][j] = -1;

    for (i = 0; i < 100; i++)
        iesire[i] = 0;
    //cout << "\nnumarul de stari=";
    f >> numarStari;
    //cout<<numarStari;
    //cout << "\nintroduceti numarul de legaturi:";
    f >> numarLegaturi;
    //cout<<numarLegaturi;
    //cout << "\nintroduceti starea de start:";
    f >> stareStart;
    //cout<<stareStart;
    for (i = 0; i < numarLegaturi; i++) {
        //cout<<"\nlegatura numarul:"<<i+1;
        //cout << "\nintroduceti starea din care pleaca legatura:";
        f >> stareInitiala;
        //cout<<stareInitiala;
        //cout << "introduceti litera de legatura:";
        f >> literaLegatura;
        //cout<<literaLegatura;
        //cout << "introduceti starea in care ajunge legatura:";
        f >> stareFinala;
        //cout<<stareFinala;
        automat[stareInitiala][literaLegatura - 31] = stareFinala;
    }
    //cout << "\nintroduceti numarul starilor de iesire:";
    f >> numarIesiri;
    //cout<<numarIesiri;
    for (i = 0; i < numarIesiri; i++) {
        //cout << "\nintroduceti starea de iesire:";
        f >> iesire[i];
        //cout<<iesire[i];
    }

    //cout << "\nintroduceti cuvantul de verificat:";
    f >> cuvantDeVerificat;
    //cout<<cuvantDeVerificat;

    f.close();
    // cazul in care a fost citit cuvantul vid
    if (!strlen(cuvantDeVerificat)) {
        for (i = 0; i < numarIesiri; i++) {
            if (iesire[i] == stareStart) {
                cout << "\napartine";
                return 0;
            }
        }
        cout << "\nnu apartine";
        return 0;
    }
    else { //daca exista legatura
        if (automat[stareStart][cuvantDeVerificat[0] - 31] != -1) {
            //eliminam prima litera,schimbam starea
            stareInitiala = automat[stareStart][cuvantDeVerificat[0] - 31];
            strcpy(cuvantDeVerificat, cuvantDeVerificat + 1);
            //daca cuvantul era format doar dintr-o litera
            if (!strlen(cuvantDeVerificat)) {
                for (j = 0; j < numarIesiri; j++) {
                    if (iesire[j] == stareInitiala) {
                        cout << "\napartine";
                        return 0;
                    }
                }
                cout << "\nnu apartine";
                return 0;
            }
        }
        else {
            cout << "\nnu apartine";
            return 0;
        }

        while (strlen(cuvantDeVerificat)) {
            //daca exista legatura
            if (automat[stareInitiala][cuvantDeVerificat[0] - 31] != -1) {
                stareInitiala = automat[stareInitiala][cuvantDeVerificat[0] - 31];
                strcpy(cuvantDeVerificat, cuvantDeVerificat + 1);
            }
            else {
                cout << "\nnu apartine";
                return 0;
            }
            //daca am ajuns la cuvantul vid
            if (!strlen(cuvantDeVerificat)) {
                for (j = 0; j < numarIesiri; j++) {
                    if (iesire[j] == stareInitiala) {
                        cout << "\napartine";
                        return 0;
                    }
                }
                cout << "\nnu apartine";
                return 0;
            }
        }
    }
}
