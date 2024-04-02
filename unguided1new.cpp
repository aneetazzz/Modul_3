#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int usia;
    Mahasiswa* next;
};

class LinkedList {
private:
    Mahasiswa* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void tambahMahasiswa(string nama, int usia) {
        Mahasiswa* newMahasiswa = new Mahasiswa;
        newMahasiswa->nama = nama;
        newMahasiswa->usia = usia;
        newMahasiswa->next = head;
        head = newMahasiswa;
    }

    void hapusMahasiswa(string nama) {
        Mahasiswa* current = head;
        Mahasiswa* prev = nullptr;

        while (current != nullptr) {
            if (current->nama == nama) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                cout << "Data mahasiswa dengan nama " << nama << " telah dihapus." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Data mahasiswa dengan nama " << nama << " tidak ditemukan." << endl;
    }

    void tambahMahasiswaDiUrutan(string nama, int usia, int urutan) {
        Mahasiswa* newMahasiswa = new Mahasiswa;
        newMahasiswa->nama = nama;
        newMahasiswa->usia = usia;

        if (urutan == 1 || head == nullptr) {
            newMahasiswa->next = head;
            head = newMahasiswa;
        } else {
            Mahasiswa* current = head;
            int posisi = 1;

            while (posisi < urutan - 1 && current->next != nullptr) {
                current = current->next;
                posisi++;
            }

            newMahasiswa->next = current->next;
            current->next = newMahasiswa;
        }
    }

    void gantiDataMahasiswa(string nama, string namaBaru, int usiaBaru) {
        Mahasiswa* current = head;

        while (current != nullptr) {
            if (current->nama == nama) {
                current->nama = namaBaru;
                current->usia = usiaBaru;
                cout << "Data mahasiswa dengan nama " << nama << " telah diubah." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Data mahasiswa dengan nama " << nama << " tidak ditemukan." << endl;
    }

    void tampilkanDataAwal() {
        Mahasiswa* current = head;

        if (current == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }

        cout << "Data Awal Mahasiswa:" << endl;
        while (current != nullptr) {
            cout << current->nama << " " << current->usia << endl;
            current = current->next;
        }
        cout << endl;
    }

    void tampilkanMahasiswa() {
        Mahasiswa* current = head;

        if (current == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }

        cout << "Data Mahasiswa:" << endl;
        cout << "-----------------" << endl;
        while (current != nullptr) {
            cout << current->nama << " " << current->usia << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList daftarMahasiswa;

    daftarMahasiswa.tambahMahasiswa("Karin", 18);
    daftarMahasiswa.tambahMahasiswa("Hoshino", 18);
    daftarMahasiswa.tambahMahasiswa("Akechi", 20);
    daftarMahasiswa.tambahMahasiswa("Yusuke", 19);
    daftarMahasiswa.tambahMahasiswa("Michael", 18);
    daftarMahasiswa.tambahMahasiswa("Jane", 20);
    daftarMahasiswa.tambahMahasiswa("John", 19);

    daftarMahasiswa.tampilkanDataAwal();

    int pilihan;
    string nama, namaBaru;
    int usia, usiaBaru, urutan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Tambah Data Mahasiswa di Urutan Tertentu\n";
        cout << "4. Ubah Data Mahasiswa\n";
        cout << "5. Tampilkan Semua Data Mahasiswa\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan usia mahasiswa: ";
                cin >> usia;
                daftarMahasiswa.tambahMahasiswa(nama, usia);
                break;
            case 2:
                cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
                cin >> nama;
                daftarMahasiswa.hapusMahasiswa(nama);
                break;
            case 3:
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan usia mahasiswa: ";
                cin >> usia;
                cout << "Masukkan urutan: ";
                cin >> urutan;
                daftarMahasiswa.tambahMahasiswaDiUrutan(nama, usia, urutan);
                break;
            case 4:
                cout << "Masukkan nama mahasiswa yang ingin diubah: ";
                cin >> nama;
                cout << "Masukkan nama baru: ";
                cin >> namaBaru;
                cout << "Masukkan usia baru: ";
                cin >> usiaBaru;
                daftarMahasiswa.gantiDataMahasiswa(nama, namaBaru, usiaBaru);
                break;
            case 5:
                daftarMahasiswa.tampilkanMahasiswa();
                break;
            case 6:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    } while (pilihan != 6);

    return 0;
}
