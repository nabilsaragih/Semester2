#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct Film {
    string judulFilm;
    string genreFilm;
    string durasiFilm;
    int tahunFilm;
};

Film films[100];

void ubah();
void hapus();
void menu();

int main() {
    string nama = "Muhammad Nabil Saragih", nim = "2209106032", nama_input, nim_input, judul, genre, durasi;
    string *namaPtr = &nama, *nimPtr = &nim;
    char ulang;
    int pilih, percobaan = 3, indexData = 0, pilihBagian, tahun;

    while(percobaan > 0) {
        cout << "Masukkan nama: ";
        getline(cin, nama_input);
        cout << "Masukkan NIM: ";
        getline(cin, nim_input);

        if(nama_input == *namaPtr && nim_input == *nimPtr) {
            while(true) {
                menu();
                cin >> pilih;
                fflush(stdin);
                switch (pilih) {
                    case 1:
                        system("cls");
                        cout << "Masukkan judul film: "; fflush(stdin);
                        getline(cin, films[indexData].judulFilm);
                        cout << "Masukkan genre film: "; fflush(stdin);
                        getline(cin, films[indexData].genreFilm);
                        cout << "Masukkan durasi film: "; fflush(stdin);
                        getline(cin, films[indexData].durasiFilm);
                        cout << "Masukkan tahun film: ";
                        cin >> films[indexData].tahunFilm;
                        indexData++;
                        cout << "\n";
                        cout << "Tekan ENTER untuk kembali"; getch();
                        pilih = 0;

                    case 2:
                        for(int i = 0; i < indexData; i++) {
                            cout << "Film ke-" << i + 1 << endl;
                            cout << "Judul film: " << films[i].judulFilm << endl;
                            cout << "Genre film: " << films[i].genreFilm << endl;
                            cout << "Durasi film: " << films[i].durasiFilm << endl;
                            cout << "Tahun film: " << films[i].tahunFilm << endl;
                            cout << "\n";
                        }
                        cout << "Tekan ENTER untuk kembali"; getch();

                    case 3:
                        cout << "Masukkan judul film yang ingin diubah: "; fflush(stdin);
                        getline(cin, judul);

                        for(int i = 0; i < indexData; i++) {
                            if (films[i].judulFilm == judul) {
                                cout << "Film ditemukan\n\n";
                                cout << "1) Judul\n";
                                cout << "2) Genre\n";
                                cout << "3) Durasi\n";
                                cout << "4) Tahun\n";
                                cout << "------------------------------------\n";
                                cout << "Pilih bagian yang ingin anda ubah:";
                                cin >> pilihBagian;
                                fflush(stdin);

                                switch (pilihBagian) {
                                    case 1:
                                        cout << "Ubah judul film menjadi: ";
                                        getline(cin, judul);
                                        films[i].judulFilm = judul;
                                        cout << "Film berhasil diubah!";
                                        break;
                                    case 2:
                                        cout << "Ubah genre film menjadi: ";
                                        getline(cin, genre);
                                        films[i].genreFilm = genre;
                                        cout << "Film berhasil diubah!";
                                        break;
                                    case 3:
                                        cout << "Ubah durasi film menjadi: ";
                                        getline(cin, durasi);
                                        films[i].durasiFilm = durasi;
                                        cout << "Film berhasil diubah!";
                                        break;
                                    case 4:
                                        cout << "Ubah tahun film menjadi: ";
                                        cin >> tahun;
                                        fflush(stdin);
                                        cout << "Film berhasil diubah!";
                                        break;
                                    default:
                                        cout << "Pilihan tidak ada di menu!";
                                        continue;
                                }
                            } else {
                                cout << "Film tidak ditemukan";
                                break;
                            }
                        }

                    case 4:
                        cout << "Masukkan nama film yang ingin dihapus: "; fflush(stdin);
                        getline(cin, judul);

                        for(int i = 0; i < indexData; i++) {
                            if(films[i].judulFilm == judul) {
                                films[i] = films[i + 1];
                                cout << "Film berhasil dihapus!";
                            } else {
                                cout << "Film tidak ditemukan";
                            }
                        }
                        cout <<"Tekan ENTER untuk kembali!";
                        getch();
                
                    default:
                        cout << "Pilihan anda tidak ada di menu!";
                        continue;
                }
            } 
        } else {
            if(percobaan > 0) {
                percobaan--;
            }
        }
    }
}

void menu() {
    system("cls");
    cout << "--------------- Menu ---------------\n";
    cout << "1) Tambah Film\n";
    cout << "2) Lihat Film\n";
    cout << "3) Ubah Film\n";
    cout << "4) Hapus Film\n";
    cout << "------------------------------------\n";
    cout << "Pilih: ";
};