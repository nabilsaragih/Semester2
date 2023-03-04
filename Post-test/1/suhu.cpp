#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


// class untuk menyimpan suhu dan mengkonversi
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
    int banyakPercobaan = 3;    // variabel untuk membantu jalannya program
    string namalengkap, nim, suhuTemporer, pilihanTemporer, ulang;
    int pilihan;
    float suhu;

    while (banyakPercobaan > 0) {
        cout << "Masukkan nama lengkap: ";
        getline(cin, namalengkap);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        if (namalengkap != "Muhammad Nabil Saragih" && nim != "2209106032") {
            banyakPercobaan -= 1;
            cout << "Username atau password yang anda masukkan salah!\n";
            system("cls");
        } else {
            while (true) {
                system("cls");
                menuUtama();
                getline(cin, pilihanTemporer);
                pilihan = stoi(pilihanTemporer);
                switch (pilihan) {
                    case 1:
                        system("cls");
                        cout << "Masukkan suhu: "; getline(cin, suhuTemporer);
                        try {
                        suhu = stof(suhuTemporer);
                        Celcius ubahCelcius;
                        ubahCelcius.setSuhu(suhu);
                        cout << "Suhu dalam Reamur: " << ubahCelcius.getSuhu().suhuReamur << "\n";
                        cout << "Suhu dalam Fahrenheit: " << ubahCelcius.getSuhu().suhuFahrenheit << "\n";
                        cout << "Suhu dalam Kelvin: " << ubahCelcius.getSuhu().suhuKelvin << "\n";
                        break;
                        } catch (const invalid_argument &e) { // error handling
                            cout << "Angka yang anda masukkan tidak valid, tekan ENTER untuk kembali. ";
                            getch(); // untuk kembali
                            menuUtama();
                        }
                    case 2:
                        system("cls");
                        cout << "Masukkan suhu: "; getline(cin, suhuTemporer);
                        try {
                        suhu = stof(suhuTemporer);
                        Reamur ubahReamur;
                        ubahReamur.setSuhu(suhu);
                        cout << "Suhu dalam Reamur: " << ubahReamur.getSuhu().suhuCelcius << "\n";
                        cout << "Suhu dalam Fahrenheit: " << ubahReamur.getSuhu().suhuFahrenheit << "\n";
                        cout << "Suhu dalam Kelvin: " << ubahReamur.getSuhu().suhuKelvin << "\n";
                        break;
                        } catch (const invalid_argument &e) {
                            cout << "Angka yang anda masukkan tidak valid, tekan ENTER untuk kembali. ";
                            getch();
                            menuUtama();
                        }
                    case 3:
                        system("cls");
                        cout << "Masukkan suhu: "; getline(cin, suhuTemporer);
                        try {
                        suhu = stof(suhuTemporer);
                        Fahrenheit ubahFahrenheit;
                        ubahFahrenheit.setSuhu(suhu);
                        cout << "Suhu dalam Fahrenheit: " << ubahFahrenheit.getSuhu().suhuCelcius << "\n";
                        cout << "Suhu dalam Reamur: " << ubahFahrenheit.getSuhu().suhuReamur << "\n";
                        cout << "Suhu dalam Kelvin: " << ubahFahrenheit.getSuhu().suhuKelvin << "\n";
                        break;
                        } catch (const invalid_argument &e) {
                            cout << "Angka yang anda masukkan tidak valid, tekan ENTER untuk kembali. ";
                            getch();
                            menuUtama();
                        }
                    case 4:
                        system("cls");
                        cout << "Masukkan suhu: "; getline(cin, suhuTemporer);
                        try {
                        suhu = stof(suhuTemporer);
                        Kelvin ubahKelvin;
                        ubahKelvin.setSuhu(suhu);
                        cout << "Suhu dalam Kelvin: " << ubahKelvin.getSuhu().suhuCelcius << "\n";
                        cout << "Suhu dalam Reamur: " << ubahKelvin.getSuhu().suhuReamur << "\n";
                        cout << "Suhu dalam Fahrenheit: " << ubahKelvin.getSuhu().suhuFahrenheit << "\n";
                        break;
                        } catch (const invalid_argument &e) {
                            cout << "Angka yang anda masukkan tidak valid, tekan ENTER untuk kembali. ";
                            getch();
                            menuUtama();
                        }
                    case 5:
                        system("cls");
                        break;

                    default:
                        cout << "Pilihan yang anda masukkan tidak ada di menu!\n";
                    }

                    cout << "Apakah anda ingin mengkonversi suhu lagi (Y/N)? ";
                    getline(cin, ulang);

                    if (ulang == "N" || ulang == "n") {
                        system("cls");
                        exit(0);
                    }
            }
        }
    }

    return 0;
}