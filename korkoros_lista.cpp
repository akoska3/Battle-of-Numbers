#include <iostream>
#include <ctime>
#include "korl.h"

using namespace std;

void elokeszuletek(Lista& x, int& a) {
    srand(time(NULL));
    int n;
    char s[50];
    cout << "A jatekosok szama: ";
    cin >> n;
    while (n < 2) {
        cout << "hiba: Legalabb 2 ember kell jatszon." << endl;
        cin >> n;
    }
    cout << "A jatekosok nevei:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". jatekos neve: ";
        cin >> s;
        while (x.keres(s) != NULL) {
            cout << "hiba: Mar van ilyen nevu jatekos." << endl;
            cout << i + 1 << ". jatekos neve: ";
            cin >> s;
        }
        x.beszur(s, i);
    }
    a = rand();
    cout << "A jatekot " << x.nev(x.poz(a)) << " kezdi." << endl << endl;
}

void be(int& k, char* a) {
    cout << a << ": ";
    cin >> k;
    while (k < 1 || k > 9) {
        cout << "hiba: A szam az 1-9 kozott kell legyen." << endl;
        cout << a << ": ";
        cin >> k;
    }
}

void jatek(Lista& x, int a) {
    int ossz = 0, k;
    while (ossz < 100) {
        be(k, x.nev(x.poz(a)));
        ossz += k;
        a++;
    }
    cout << x.nev(x.poz(a - 1)) << " szamaval az osszeg " << ossz << " lett, tehat kiesett a jatekbol." << endl;
    x.torol(x.nev(x.poz(a - 1)));
    ossz = 0;
}

void szabalyzat() {
    cout << "Jatekleiras:" << endl;
    cout << "A jatekot legalabb ketten jatsszak." << endl;
    cout << "A jatekosok korbe mennek es mindegyik mond egy 1 - 9 kozotti szamot." << endl;
    cout << "A szamokat osszeadjuk. Aki eloszor eleri a 100-at, az kiesik." << endl;
    cout << "Az nyer, aki utoljara bentmarad." << endl;
    cout << "A jatek kozben ki- es belephetnek jatekosok minden kor utan." << endl << endl;
}

void jatekosok(Lista& x, bool& tovabb) {
    char k, nev[50], nev2[50];
    int w = 1, q;
    tovabb = true;
    do {
        cout << "jatekban levo jatekosok : ";
        x.kiir();
        cout << "Ha egy jatekos ki akar szallni usse le az x billentyut!" << endl;
        cout << "Ha egy uj jatekos szeretne belepni a jatekba nyomja meg az y billlentyut!" << endl;
        cout << "Ha tovabb szeretne folytatni a jatekot nyomja meg a 0 billlentyut!" << endl;
        cin >> k;
        if (k == 'x') {
            cout << "Ki szeretne kilepni?" << endl;
            cin >> nev;
            x.torol(nev);
            if (x.elemszam() == 1) {
                cout << "Csak egy jatekos maradt bent szoval a jateknak vege!";
                tovabb = false;
                return;
            }
        }
        else if (k == 'y') {
            cout << "Ki szeretne csatlakozni?" << endl;
            cin >> nev;
            cout << "Ki utan szeretne ulni?" << endl;
            cin >> nev2;
            if (x.keres(nev) == NULL) {
                x.beszurutan(nev, nev2);
            }
            else cout << "hiba: Mar van ilyen nevu jatekos." << endl;
        }
        else if (k != '0') {
            tovabb = false;
            return;
        }
    } while (k == 'x' || k == 'y');
}

int main()
{
    Lista x;
    szabalyzat();
    int a;
    bool tovabb;
    elokeszuletek(x, a);
    jatek(x, a);
    while (x.elemszam() > 1) {
        jatekosok(x, tovabb);
        if (!tovabb) return 0;
        jatek(x, a);
    }
    cout << "A jatekot megnyerte " << x.nev(x.poz(a - 1)) << '!' << endl;
    return 0;
}