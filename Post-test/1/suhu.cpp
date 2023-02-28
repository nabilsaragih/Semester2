#include <iostream>
#include <string>
using namespace std;

class Celcius {
    private:
        float suhuCelcius;

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
    cout << "5. Keluar\n"; 
    cout << "=====================\n";
    cout << "Pilih: ";
}

int main() {
    int banyakPercobaan = 3;
    string username, password;
    int pilihan;
    char ulang;
    float suhu;

    while(banyakPercobaan > 0) {
        cout << "Masukkan username: ";
        getline(cin, username);
        cout << "Masukkan password: ";
        getline(cin, password);

        if (username != "Muhammad Nabil Saragih" && password != "2209106032") {
            banyakPercobaan -= 1;
            cout << "Username atau password yang anda masukkan salah!\n";
            system("cls");
        } else {
            do {
                system("cls");
                menuUtama();
                cin >> pilihan;
                switch (pilihan) {
                    case 1:
                        system("cls");
                        cout << "Masukkan suhu: ";
                        cin >> suhu;
                        Celcius ubahCelcius;
                        ubahCelcius.setSuhu(suhu);
                        cout << "Suhu dalam Reamur: " << ubahCelcius.getSuhu().suhuReamur << "\n";
                        cout << "Suhu dalam Fahrenheit: " << ubahCelcius.getSuhu().suhuFahrenheit << "\n";
                        cout << "Suhu dalam Kelvin: " << ubahCelcius.getSuhu().suhuKelvin << "\n";
                        break;
                    case 2:
                        system("cls");
                        cout << "Masukkan suhu: ";
                        cin >> suhu;
                        Reamur ubahReamur;
                        ubahReamur.setSuhu(suhu);
                        cout << "Suhu dalam Reamur: " << ubahReamur.getSuhu().suhuCelcius << "\n";
                        cout << "Suhu dalam Fahrenheit: " << ubahReamur.getSuhu().suhuFahrenheit << "\n";
                        cout << "Suhu dalam Kelvin: " << ubahReamur.getSuhu().suhuKelvin << "\n";
                        break;
                    case 3:
                        system("cls");
                        cout << "Masukkan suhu: ";
                        cin >> suhu;
                        Fahrenheit ubahFahrenheit;
                        ubahFahrenheit.setSuhu(suhu);
                        cout << "Suhu dalam Fahrenheit: " << ubahFahrenheit.getSuhu().suhuCelcius << "\n";
                        cout << "Suhu dalam Reamur: " << ubahFahrenheit.getSuhu().suhuReamur << "\n";
                        cout << "Suhu dalam Kelvin: " << ubahFahrenheit.getSuhu().suhuKelvin << "\n";
                        break;
                    case 4:
                        system("cls");
                        cout << "Masukkan suhu: ";
                        cin >> suhu;
                        Kelvin ubahKelvin;
                        ubahKelvin.setSuhu(suhu);
                        cout << "Suhu dalam Kelvin: " << ubahKelvin.getSuhu().suhuCelcius << "\n";
                        cout << "Suhu dalam Reamur: " << ubahKelvin.getSuhu().suhuReamur << "\n";
                        cout << "Suhu dalam Fahrenheit: " << ubahKelvin.getSuhu().suhuFahrenheit << "\n";
                        break;
                    case 5:
                        system("cls");
                        break;

                    default:
                        cout << "Pilihan yang anda masukkan tidak ada di menu!\n";
                    }

                    cout << "Apakah anda ingin mengkonversi suhu lagi (Y/N)? ";
                    cin >> ulang;

            } while (ulang != 'n');
        }
    }

    cout << "Anda tidak diperbolehkan masuk!";

    return 0;
}