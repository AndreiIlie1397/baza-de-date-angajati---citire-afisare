#ifndef ANGAJAT_H
#define ANGAJAT_H
#include <iostream>
using namespace std;

class Angajat
{
private:
    char *nume;
    float salariu;
public:
    Angajat(); ///constructor de initializare fara parametrii
    Angajat(char *n, float sal); ///constructor de initializare cu parametrii
    Angajat(Angajat &r); ///constructor de copiere
    virtual void display(); ///functie de afisare
    char *getNume() const; ///returneaza nume
    void setNume(char *n); ///seteaza nume
    float getSalariu() const; ///returneaza salariu
    void setSalariu(float sal); ///seteaza salariu
    virtual ~Angajat(); ///destructor
    friend istream &operator>>(istream &in, Angajat &a); ///supraincarcarea operatorului de citire
    friend ostream &operator<<(ostream &out,Angajat &a); ///supraincarcarea operatorului de scriere
    Angajat &operator=(const Angajat &a); ///supraincarcarea operatorului egal (=)
};

class Administrator: public Angajat
{
    int sectie;
public:
    Administrator();
    Administrator(char *n, float sal, int sec);
    Administrator(Administrator &r);
    void display();
    int getSectie() const;
    void setSectie(int s);
    ~Administrator();
    friend istream &operator>>(istream &in, Administrator &a);
    friend ostream &operator<<(ostream &out, Administrator &a);
};

#endif
