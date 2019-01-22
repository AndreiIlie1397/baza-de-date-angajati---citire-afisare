#include "Angajat.h"
#include <iostream>
using namespace std;

int main()
{
    int N, M, i;
    cout<<"Introduceti numarul de angajati: ";
    cin>>N;
    cout<<endl;
    Angajat grup[N];
    for(i=0; i<N; i++)
    {
        cout<<"Introduceti datele angajatului "<<i+1<<":"<<endl;
        cin>>grup[i];
        cout<<endl;
    }
    for(i=0; i<N; i++)
    {
        cout<<"Datele angajatului "<<i+1<<":"<<endl;
        cout<<grup[i];
        cout<<endl;
    }
    cout<<endl<<"Introduceti numarul de administratori: ";
    cin>>M;
    cout<<endl;
    Administrator Grup[M];
     for(i=0; i<M; i++)
    {
        cout<<"Introduceti datele administratorului "<<i+1<<":"<<endl;
        cin>>Grup[i];
        cout<<endl;
    }
    for(i=0; i<M; i++)
    {
        cout<<"Datele administratorului "<<i+1<<":"<<endl;
        cout<<Grup[i];
        cout<<endl<<endl;
    }
    return 0;
}
