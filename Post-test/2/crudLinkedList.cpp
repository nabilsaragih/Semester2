#include <iostream>
#include <string>
using namespace std;

void init(string judul, string genre, string durasi, int tahun);
void tambah(string judul, string genre, string durasi, int tahun);
void lihat();
void ubah();
void hapus();
void menu();

struct Film {
    string judulFilm, genreFilm, durasiFilm;
    int tahunFilm;

    Film *next;
};

Film *head, *curr, *tail, *newNode;

int main() {
    string nama = "asd", nim = "123";
    string judul, genre, durasi;
    char ulang;
    int pilih, tahun;

    cout << "Masukkan judul: ";
    getline(cin, judul); cout << endl;
    cout << "Masukkan genre: ";
    getline(cin, genre); cout << endl;
    cout << "Masukkan durasi: ";
    getline(cin, durasi); cout << endl;
    cout << "Masukkan tahun: ";
    cin >> tahun;

    init(judul, genre, durasi, tahun);

    tambah(judul, genre, durasi, tahun);

    lihat();

    return 0;
}

void init(string judul, string genre, string durasi, int tahun) {
    head = new Film();
    head->judulFilm = judul;
    head->genreFilm = genre;
    head->durasiFilm = durasi;
    head->tahunFilm = tahun;
    head->next = NULL;
    tail = head;
};

void tambah(string judul, string genre, string durasi, int tahun) {
    newNode = new Film();
    newNode->judulFilm = judul;
    newNode->genreFilm = genre;
    newNode->durasiFilm = durasi;
    newNode->tahunFilm = tahun;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
};

void lihat() {
    curr = head;
    while (curr != NULL) {
        cout << "Judul film: " << curr->judulFilm << endl;
        cout << "Genre film: " << curr->genreFilm << endl;
        cout << "Durasi film: " << curr->durasiFilm << endl;
        cout << "Tahun film: " << curr->tahunFilm << endl;
        curr = curr->next;
    }
};

void ubah() {};

void hapus() {};

void menu() {
    cout << "--------------- Menu ---------------\n";
    cout << "1) Tambah Film\n";
    cout << "2) Lihat Film\n";
    cout << "3) Ubah Film\n";
    cout << "4) Hapus Film\n";
}