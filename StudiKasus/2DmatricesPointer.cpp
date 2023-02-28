#include <iostream>
#include <string>
using namespace std;

int main() {
    int x[4];
    struct matriks {
        int kolom1;
        int kolom2;
        struct matriks *ptr;
    };

    for (int i = 0; i < 4; i++) {
        cout << "Masukkan angka: ";
        cin >> x[i];
    }

    matriks DuaDimensi[2] = {
        {x[0], x[1], &DuaDimensi[0]},
        {x[2], x[3], &DuaDimensi[1]}
    };

    for (int i = 0; i < 2; i++) {
        cout << DuaDimensi[i].ptr->kolom1 << " " << DuaDimensi[i].ptr->kolom2 << endl;
    }

    return 0;
}