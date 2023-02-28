#include <iostream>
using namespace std;

int main() {
    int x[2][2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                cout << "Masukkan angka: ";
                cin >> x[i][j][k];
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "\n";
            for (int k = 0; k < 2; k++) {
                cout << x[i][j][k] << " ";
            }
        }
    }

    return 0;
}
