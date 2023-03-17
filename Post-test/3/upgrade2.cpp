#include <iostream>
#include <string>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace this_thread;
using namespace chrono;

struct Film {
    string judulFilm;
    string genreFilm;
    string durasiFilm;
    int tahunFilm;
};

Film films[100];
auto *filmsPtr = films;

string namaInput, nimInput, nama = "nabil", nim = "032";
string judul, genre, durasi;
string tempVar;
int tahun;
int pilih, pilihBagian, percobaan = 3, indexData = 0, keluar = 0;
char ulang;

void menu() {
    cout << "--------------- Menu ---------------\n";
    cout << "1) Tambah Film\n";
    cout << "2) Lihat Film\n";
    cout << "3) Ubah Film\n";
    cout << "4) Hapus Film\n";
    cout << "5) Keluar\n";
    cout << "------------------------------------\n";
    cout << "Pilih: "; cin >> tempVar; fflush(stdin);

    try {
        pilih = stoi(tempVar);
    } catch(const invalid_argument &e) {
        system("cls");
    }
}

void create() {
    system("cls");
    cout << "Masukkan judul film: ";
    getline(cin, films[indexData].judulFilm); fflush(stdin);
    cout << "Masukkan genre film: ";
    getline(cin, films[indexData].genreFilm); fflush(stdin);
    cout << "Masukkan durasi film: ";
    getline(cin, films[indexData].durasiFilm); fflush(stdin);
    cout << "Masukkan tahun film: "; cin >> films[indexData].tahunFilm; fflush(stdin);
    indexData++;
    sleep_for(milliseconds(1000));
    pilih = 0;
    system("cls");
    cout << "Film berhasil ditambahkan!";
    sleep_for(milliseconds(1000));
    system("cls");
}

void read() {
    system("cls");
    if(films[0].judulFilm != "") {
        for(int i = 0; i < indexData; i++) {
            cout << "Film ke-" << i + 1 << endl;
            cout << "Judul film: " << (filmsPtr + i)->judulFilm << endl;
            cout << "Genre film: " << (filmsPtr + i)->genreFilm << endl;
            cout << "Durasi film: " << (filmsPtr + i)->durasiFilm << endl;
            cout << "Tahun film: " << (filmsPtr + i)->tahunFilm << endl;
            cout << "\n";
        }
    } else {
        cout << "Film belum ada mohon isi terlebih dahulu!" << endl;
    }
    cout << "Tekan ENTER untuk kembali";
}

void update() {
    system("cls");
    cout << "List judul film\n===============" << endl;
    for(int i = 0; i < indexData; i++) {
        cout << i + 1 << ". " << films[i].judulFilm << endl;
    }

    cout << endl;
    cout << "Masukkan judul film yang ingin diubah: "; getline(cin, judul); fflush(stdin);

    for(int i = 1; i < indexData; i++) {
        if (films[indexData - i].judulFilm == judul) {
            system("cls");
            cout << "Film ditemukan!"; sleep_for(milliseconds(1000)); system("cls");

            while(true) {
                cout << "1) Judul\n";
                cout << "2) Genre\n";
                cout << "3) Durasi\n";
                cout << "4) Tahun\n";
                cout << "------------------------------------\n";
                cout << "Pilih bagian yang ingin anda ubah: ";
                cin >> tempVar; fflush(stdin);

                try {
                    pilihBagian = stoi(tempVar);
                } catch (const invalid_argument &e) {
                    cout << "Pilihan anda invalid!" << endl;
                    sleep_for(milliseconds(1000));
                    system("cls");
                    continue;
                }

                switch (pilihBagian) {
                    case 1:
                        cout << "Ubah judul film menjadi: "; getline(cin, judul); fflush(stdin);
                        films[indexData - i].judulFilm = judul;
                        cout << "Film berhasil diubah!"; sleep_for(milliseconds(1000));
                        system("cls");
                        keluar--;
                        break;

                    case 2:
                        cout << "Ubah genre film menjadi: "; getline(cin, genre); fflush(stdin);
                        films[indexData - i].genreFilm = genre;
                        cout << "Film berhasil diubah!"; sleep_for(milliseconds(1000));
                        system("cls");
                        keluar--;
                        break;

                    case 3:
                        cout << "Ubah durasi film menjadi: "; getline(cin, durasi); fflush(stdin);
                        films[indexData - i].durasiFilm = durasi;
                        cout << "Film berhasil diubah!"; sleep_for(milliseconds(1000));
                        system("cls");
                        keluar--;
                        break;

                    case 4:
                        cout << "Ubah tahun film menjadi: "; cin >> tahun; fflush(stdin);
                        cout << "Film berhasil diubah!"; sleep_for(milliseconds(1000));
                        system("cls");
                        keluar--;
                        break;
                        
                    default:
                        cout << "Pilihan tidak ada di menu!";
                        sleep_for(milliseconds(1000));
                        system("cls");
                        break;
                }
                if(keluar < 0) {
                    keluar = 0;
                    break;
                }
            }
        } else {
            cout << "Film tidak ditemukan";
            sleep_for(milliseconds(1000));
            system("cls");
            break;
        }
    }
}

void remove() {
    system("cls");
    cout << "List judul film\n===============" << endl;
    for(int i = 0; i < indexData; i++) {
        cout << i + 1 << ". " << films[i].judulFilm << endl;
    }
    cout << "Masukkan nama film yang ingin dihapus: "; getline(cin, judul); fflush(stdin);
    system("cls");

    for(int i = 0; i < indexData; i++) {
        if(films[i].judulFilm == judul) {
            films[i] = films[i + 1];
            cout << "Film berhasil dihapus!"; sleep_for(milliseconds(1000));
        } else {
            cout << "Film tidak ditemukan"; sleep_for(microseconds(1000));
        }
    }
    system("cls");
    cout <<"Tekan ENTER untuk kembali!";
}

int main() {
    while(true) {
        system("cls");
        cout << "Masukkan nama: "; cin >> namaInput; fflush(stdin);
        cout << "Masukkan nim: "; cin >> nimInput; fflush(stdin);
        
        if(namaInput == nama && nimInput == nim) {
            keluar = 0;
            system("cls");
            cout << "Anda berhasil login" << endl;
            sleep_for(milliseconds(1000));
            system("cls");

            while(true) {
                menu();
                switch (pilih) {
                    case 1:
                        create();
                        break;

                    case 2:
                        read();
                        getch();
                        system("cls");
                        break;

                    case 3:
                        update();
                        break;

                    case 4:
                        remove();
                        getch();
                        system("cls");
                        break;

                    case 5:
                        keluar--;
                        break;

                    default:
                        cout << "Pilihan yang anda masukkan tidak ada di menu" << endl;
                        sleep_for(milliseconds(1000));
                        system("cls");
                }
                if(keluar < 0) {
                    break;
                }
            }
        } else {
            system("cls");
            cout << "Nama atau nim yang anda inputkan salah!" << endl;
            sleep_for(milliseconds(1000));
            system("cls");
        }
        if(keluar < 0) {
            break;
        }
    }

    return 0;
}
