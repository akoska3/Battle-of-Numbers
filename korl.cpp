#include "korl.h"
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS

Lista::Lista() : fej(NULL) {}

void Lista::beszur(char* a, int poz)
{
    if (poz < 0) return;
    if (poz == 0) {
        beszurele(a);
        return;
    }
    Elem* x = new Elem();
    strcpy_s(x->ertek, 50, a);
    int i = 1;
    if (fej != NULL) {
        Elem* t = fej;
        while (t->kovi != fej && i < poz) {
            t = t->kovi;
            i++;
        }
        Elem* y = t->kovi;
        t->kovi = x;
        x->kovi = y;
    }
    else
    {
        x->kovi = x;
        fej = x;
    }
}

void Lista::beszurele(char* a)
{
    Elem* x = new Elem();
    strcpy_s(x->ertek, 50, a);
    x->kovi = fej;
    if (fej != NULL) {
        Elem* t = fej;
        while (t->kovi != fej) {
            t = t->kovi;
        }
        t->kovi = x;
    }
    else
    {
        x->kovi = x;
    }
    fej = x;
}

void Lista::kiir()
{
    Elem* x = fej;
    if (fej != NULL) {
        do {
            cout << x->ertek << " ";
            x = x->kovi;
        } while (x != fej);
    }
    cout << endl;
}

Elem* Lista::keres(char* a) {
    if (fej == NULL) return NULL;
    if (strcmp((fej)->ertek, a) == 0) return (fej);
    Elem* x = (fej);
    while (x->kovi != fej && strcmp(x->kovi->ertek, a) != 0) {
        x = x->kovi;
    }
    if (strcmp(x->kovi->ertek, a) == 0) {
        return x->kovi;
    }
    else return NULL;
}

void Lista::torol(char* a)
{
    if (fej == NULL) return;
    if (strcmp((fej)->ertek, a) == 0 && (fej)->kovi == fej) {
        free(fej);
        fej = NULL;
        return;
    }
    Elem* x = fej;
    if (strcmp((fej)->ertek, a) == 0) {
        while (x->kovi != fej) {
            x = x->kovi;
        }
        x->kovi = (fej)->kovi;
        free(fej);
        fej = x->kovi;
        return;
    }
    while (x->kovi != fej && strcmp(x->kovi->ertek, a) != 0) {
        x = x->kovi;
    }
    if (strcmp(x->kovi->ertek, a) == 0) {
        Elem* d = x->kovi;
        x->kovi = d->kovi;
        free(d);
    }
    else cout << "Nem talalhato a listaban" << endl;
}

void Lista::elozo(char* a) {
    if (fej == NULL) {
        cout << "hiba" << endl;
        return;
    }
    if (strcmp((fej)->ertek, a) == 0 && (fej)->kovi == fej) {
        free(fej);
        fej = NULL;
        cout << "hiba" << endl;
        return;
    }
    Elem* x = fej;
    if (strcmp((fej)->ertek, a) == 0) {
        while (x->kovi != fej) {
            x = x->kovi;
        }
        cout << x->ertek << endl;
        return;
    }
    while (x->kovi != fej && strcmp(x->kovi->ertek, a) != 0) {
        x = x->kovi;
    }
    if (strcmp(x->kovi->ertek, a) == 0) {
        cout << x->ertek << endl;
    }
    else cout << "hiba" << endl;
}

void Lista::kovetkezo(char* a) {
    if (keres(a) == NULL) {
        cout << "Nincs" << endl;
    }
    cout << keres(a)->kovi->ertek << endl;
}

int Lista::elemszam() {
    if (fej == NULL) return 0;
    Elem* x = fej;
    int i = 1;
    while (x->kovi != fej) {
        i++;
        x = x->kovi;
    }
    return i;
}

Elem* Lista::poz(int j) {
    if (fej == NULL) return NULL;
    Elem* x = fej;
    for (int i = 1; i < j; i++) {
        x = x->kovi;
    }
    return x;
}

char* Lista::nev(Elem* p) {
    return p->ertek;
}

Lista::~Lista() {
    if (fej == NULL) {
        return;
    }
    Elem* x = fej;
    Elem* y;
    do {
        y = x->kovi;
        free(x);
        x = y;
    } while (x != fej);
    fej = NULL;
}

void Lista::beszurutan(char* a, char* b) {
    int i = 0;
    if (keres(b) == NULL) return;
    if (keres(b) == fej) {
        beszur(a, 1);
        return;
    }
    while (keres(b) != poz(i)) i++;
    beszur(a, i);
}

