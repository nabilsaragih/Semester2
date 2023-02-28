#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Celcius {
    private:
        float suhuCelcius;
        float suhuReamur;
        float suhuFahrenheit;
        float suhuKelvin;

    public:
        void setSuhu(float temperature) {
            suhuCelcius = temperature;
        }

        auto getSuhu() { 
            struct hasil {
                float suhuReamur;
                float suhuFahrenheit;
                float suhuKelvin;
            };

            return hasil{(suhuCelcius * 4) / 5, ((suhuCelcius *  9) / 5) + 32, suhuCelcius + 273}; 
        }
};

class Reamur {
    private:
        float suhuReamur;
        float suhuCelcius;
        float suhuFahrenheit;
        float suhuKelvin;

    public:
        void setSuhu(float temperature) {
            suhuReamur = temperature;
        }

        auto getSuhu() { 
            struct hasil {
                float suhuCelcius;
                float suhuFahrenheit;
                float suhuKelvin;
            };

            return hasil{((suhuReamur * 5) / 4), ((suhuReamur * 9) / 4) + 32, ((suhuReamur * 5) / 4) + 273}; 
        }
};

class Fahrenheit {
    private:
        float suhuFahrenheit;
        float suhuCelcius;
        float suhuReamur;
        float suhuKelvin;

    public:
        void setSuhu(float temperature) {
            suhuFahrenheit = temperature;
        }

        auto getSuhu() { 
            struct hasil {
                float suhuCelcius;
                float suhuReamur;
                float suhuKelvin;
            };

            return hasil{(((suhuFahrenheit - 32) * 5) / 9), (((suhuFahrenheit - 32) * 4) / 9), (((suhuFahrenheit - 32) * 5) / 9) + 273}; 
        }
};

class Kelvin {
    private:
        float suhuKelvin;
        float suhuCelcius;
        float suhuReamur;
        float suhuFahrenheit;

    public:
        void setSuhu(float temperature) {
            suhuKelvin = temperature;
        }

        auto getSuhu() { 
            struct hasil {
                float suhuCelcius;
                float suhuFahrenheit;
                float suhuReamur;
            };

            return hasil{suhuKelvin - 273, (((suhuKelvin - 273) * 9) / 5) + 32, ((suhuKelvin - 273) * 4) / 5}; 
        }
};

void menuUtama() {
    cout << "Pilihan satuan asal\n"; 
    cout << "1. Celcius\n"; 
    cout << "2. Reamur\n"; 
    cout << "3. Fahrenheit\n"; 
    cout << "4. Kelvin\n"; 
    cout << "=====================\n";
    cout << ""
}

void menuTujuan() {
    cout << "Pilihan satuan tujuan\n"; 
    cout << "1. Celcius\n"; 
    cout << "2. Reamur\n"; 
    cout << "3. Fahrenheit\n"; 
    cout << "4. Kelvin\n"; 
    cout << "=====================\n";
}

int main() {
    int banyakPercobaan = 3;
    string username, password;

    while(banyakPercobaan > 0) {
        cout << "Masukkan username: ";
        getline(cin, username);
        cout << "Masukkan password: ";
        getline(cin, password);

        if (username != "nabil" && password != "12345") {
            banyakPercobaan -= 1;
            cout << "Username atau password yang anda masukkan salah!\n";
        } else {
            do {

            }
        }
    }

    cout << "Anda tidak diperbolehkan masuk!";

    return 0;
}