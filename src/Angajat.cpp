#include "Angajat.h"
#include <string.h>

Angajat::Angajat() ///constructorul de initializare implicit
{
    nume=new char[strlen("Anonim")+1];
    strcpy(nume, "Anonim");
    salariu=0;
}

Angajat::Angajat(char *n, float sal) ///constructorul de initializare cu parametrii
{
    nume=new char[strlen(n)+1];
    strcpy(nume, n);
    salariu=sal;
}

Angajat::Angajat(Angajat &r) ///constructorul de copiere
{
    nume=new char[strlen(r.nume)+1];
    strcpy(this->nume, r.nume);
    this->salariu=r.salariu;
}

Administrator::Administrator():Angajat() ///constructorul de initializare implicit
{
    sectie=0;
}

Administrator::Administrator(char *n, float sal, int sec): Angajat(n, sal) ///constructorul de initializare cu parametrii
{
    sectie=sec;
}

Administrator::Administrator(Administrator &r): Angajat(r) ///constructorul de copiere
{
    sectie=r.sectie;
}

void Angajat::setNume(char *s) ///setare Nume
{
    if(nume!=NULL)
    delete[] nume;
    nume=new char[strlen(s)+1];
    strcpy(this->nume,s);
}

void Angajat::setSalariu(float s) ///setare Salariu
{
    this->salariu=s;
}

void Administrator::setSectie(int s) ///setare Sectie
{
    this->sectie=s;
}

char* Angajat::getNume() const ///returnare Nume
{
    return this->nume;
}

float Angajat::getSalariu() const ///returnare Salariu
{
    return this->salariu;
}

int Administrator::getSectie() const ///returnare Sectie
{
    return this->sectie;
}

Angajat::~Angajat() ///destructor
{
    delete[] this->nume;
}

Administrator::~Administrator(){} ///destructor

void Angajat::display() ///afisarea angajatilor
{
    cout<<"Numele:   "<<nume<<endl;
    cout<<"Salariul: "<<salariu<<endl;
}

void Administrator::display() ///afisarea administratorilor
{
    Angajat::display();
    cout<<"Sectia:   "<<sectie;
}

istream &operator>>(istream &in, Angajat &a) ///operatorul de citire
{
    string sir;
    cout<<"Introduceti numele angajatului: ";
    in>>sir;
    a.nume=new char[strlen(sir.c_str())+1];
    strcpy(a.nume, sir.c_str());
    float sal;
    cout<<"Introduceti salariul angajatului: ";
    in>>sal;
    a.setSalariu(sal);
    return in;
}

istream &operator>>(istream &in, Administrator &A) ///operatorul de citire
{
    Angajat *x;
    x=&A;
    cin>>*x;
    cout<<"Introduceti sectia administratorului: ";
    in>>A.sectie;
    return in;
}

ostream &operator<<(ostream &out, Angajat &a) ///operatorul de afisare
{
    a.display();
    return out;
}

ostream &operator <<(ostream &out, Administrator &A) ///operatorul de afisare
{
    A.display();
    return out;
}

Angajat &Angajat::operator=(const Angajat &a) ///operatorul =
{
    delete[] nume;
    nume=new char[strlen(a.nume)+1];
    strcpy(this->nume, a.nume);
    this->salariu=a.salariu;
    return *this;
}
