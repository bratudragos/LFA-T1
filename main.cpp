#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream f("date.txt");

int a[100][100],iesire[100];
int i,j,init, final, starestart, nriesire, nrstari, nrlegaturi;
char s[100],lit;
int main() {

    for(i=0;i<100;i++)
        for(j=0;j<100;j++)
            a[i][j]=-1;
    //cout << "\nnumarul de stari=";
    f >> nrstari;
    //cout<<nrstari;
    //cout << "\nintroduceti numarul de legaturi:";
    f >> nrlegaturi;
    //cout<<nrlegaturi;
    //cout << "\nintroduceti starea de start:";
    f >> starestart;
    //cout<<starestart;
    for (i = 0; i < nrlegaturi; i++) {
        //cout<<"\nlegatura numarul:"<<i+1;
        //cout << "\nintroduceti starea din care pleaca legatura:";
        f >> init;
        //cout<<init;
        //cout << "introduceti litera de legatura:";
        f >> lit;
        //cout<<lit;
        //cout << "introduceti starea in care ajunge legatura:";
        f >> final;
        //cout<<final;
        a[init][lit - 31] = final;

    }
    //cout << "\nintroduceti numarul starilor de iesire:";
    f >> nriesire;
    //cout<<nriesire;
    for (i = 0; i < nriesire; i++) {
        //cout << "\nintroduceti starea de iesire:";
        f >> iesire[i];
        //cout<<iesire[i];
    }

    //cout << "\nintroduceti cuvantul de verificat:";
    f>>s;
    //cout<<s;

    f.close();

    if (!strlen(s))
    {
        for (i = 0; i < nriesire; i++)
        {
            if (iesire[i] == starestart)
            {
                cout << "\napartine";
                return 0;
            }
        }
        cout<<"\nnu apartine";
        return 0;
    }
    else {
            if(a[starestart][s[0]-31]!=-1)
            {
                init=a[starestart][s[0]-31];
                strcpy(s,s+1);
                if(!strlen(s)){
                    for (j = 0; j < nriesire; j++)
                    {
                        if (iesire[j] == init)
                        {
                            cout << "\napartine";
                            return 0;
                        }
                    }
                    cout<<"\nnu apartine";
                    return 0;
                }
            }
            else {
                cout<<"\nnu apartine";
                return 0;
            }

        while (strlen(s)) {
            if(a[init][s[0]-31]!=-1){
                init=a[init][s[0]-31];
                strcpy(s,s+1);
            }
            else{
                cout<<"\nnu apartine";
                return 0;
            }
            if(!strlen(s)){
                for (j = 0; j < nriesire; j++)
                {
                    if (iesire[j] == init)
                    {
                        cout << "\napartine";
                        return 0;
                    }
                }
                cout<<"\nnu apartine";
                return 0;
            }
        }
    }
}
