#pragma once
#include <iostream>
using namespace std;

class Elem {
public:
    char ertek[50];
    Elem* kovi;
};

class Lista {
private:
    Elem* fej;
public:
    Lista();
    ~Lista();
    void beszur(char* a, int poz); //beszur egy elemet az i. poziciora
    void beszurele(char* a); //beszur egy elemet "a lista elejere"
    void beszurutan(char* a, char* b); //beszurja az 'a' erteku elemet a 'b' erteku elem utan
    void torol(char* a); //kitorli az elso 'a' erteku elemet
    Elem* keres(char* a); //megkeresi az elso 'a' erteku elemet
    void elozo(char* a); //kiirja az elozo erteket
    void kovetkezo(char* a); //kiirja a kovetkezo erteket
    int elemszam(); //hany elem van a listaban
    void kiir(); //kiirja a listat
    Elem* poz(int j); //visszateriti az j. elemre mutato pointert
    char* nev(Elem* p); //visszaterit egy nevet
};