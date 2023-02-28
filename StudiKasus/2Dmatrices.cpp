#include <iostream>
using namespace std;

int main() {
    int twoDimensional[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Masukkan angka: ";
            cin >> twoDimensional[i][j];
        }
    }

    cout << "\nBentuk Matriks\n[ ";
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            if (x == 1 && y == 1) {
                cout << twoDimensional[x][y] << " ]";
            } else if (x == 1 && y == 0) {
                cout << "  " << twoDimensional[x][y] << " ";
            } else if (y == 1) {
                cout << twoDimensional[x][y] << " \n"; 
            } else {
                cout << twoDimensional[x][y] << " "; 
            }
        }
    }

    return 0;
}