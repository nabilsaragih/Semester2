#include <iostream>
using namespace std;

int main() {
    struct matriks {
        int kolom1;
        int kolom2;
        struct matriks *ptr;
    };

    matriks Duatiga[4] {
        {1, 2, &Duatiga[0]},
        {3, 4, &Duatiga[1]},
        {5, 6, &Duatiga[2]},
        {7, 8, &Duatiga[3]}
    };

    for (int i = 0; i < 4; i++) {
        cout << Duatiga[i].ptr->kolom1 << " " << Duatiga[i].ptr->kolom2 << endl;
    }
}