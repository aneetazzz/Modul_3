#include <iostream>
#include <iomanip>
using namespace std;

// Struktur untuk node produk
struct Product {
    string nama_produk;
    int harga;
    Product* prev;
    Product* next;
};

// Kelas untuk Double Linked List
class DoubleLinkedList {
private:
    Product* head;
    Product* tail;

public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Fungsi untuk menambahkan produk baru
    void addProduct(string nama_produk, int harga) {
        Product* newProduct = new Product;
        newProduct->nama_produk = nama_produk;
        newProduct->harga = harga;
        newProduct->prev = NULL;
        newProduct->next = NULL;

        if (head == NULL) {
            head = newProduct;
            tail = newProduct;
        } else {
            tail->next = newProduct;
            newProduct->prev = tail;
            tail = newProduct;
        }
    }

    // Fungsi untuk menghapus produk berdasarkan nama
    void removeProduct(string nama_produk) {
        Product* current = head;
        while (current != NULL) {
            if (current->nama_produk == nama_produk) {
                if (current == head) {
                    head = head->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    }
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan." << endl;
    }

    // Fungsi untuk memperbarui nama produk dan harga
    void updateProduct(string old_nama_produk, string new_nama_produk, int new_harga) {
        Product* current = head;
        while (current != NULL) {
            if (current->nama_produk == old_nama_produk) {
                current->nama_produk = new_nama_produk;
                current->harga = new_harga;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan." << endl;
    }

    // Fungsi untuk menampilkan semua produk
    void displayProducts() {
        cout << "Nama Produk\tHarga" << endl;
        cout << "=======================" << endl;
        Product* current = head;
        while (current != NULL) {
            cout << setw(12) << left << current->nama_produk << "\t" << current->harga << endl;
            current = current->next;
        }
        cout << endl;
    }

    // Fungsi untuk menambahkan produk di antara dua produk tertentu
    void addProductBetween(string prevProductName, string newProductName, int newPrice) {
        Product* current = head;
        while (current != NULL) {
            if (current->nama_produk == prevProductName) {
                Product* newProduct = new Product;
                newProduct->nama_produk = newProductName;
                newProduct->harga = newPrice;
                newProduct->prev = current;
                newProduct->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = newProduct;
                }
                current->next = newProduct;
                return;
            }
            current = current->next;
        }
        cout << "Produk sebelumnya tidak ditemukan." << endl;
    }

    // Fungsi untuk menghapus data pada posisi tertentu
    void removeAtPosition(int position) {
        if (head == NULL) {
            cout << "List kosong." << endl;
            return;
        }

        Product* current = head;
        int count = 1;

        // Traverse the list to the specified position
        while (current != NULL && count != position) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            cout << "Posisi tidak valid." << endl;
            return;
        }

        // Remove the node at the specified position
        if (current == head) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete current;
        } else if (current == tail) {
            tail = tail->prev;
            tail->next = NULL;
            delete current;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }

    // Fungsi untuk menghapus semua data
    void removeAll() {
        Product* current = head;
        while (current != NULL) {
            Product* temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
    }
};

int main() {
    DoubleLinkedList productList;

    // Menambahkan produk ke dalam linked list
    productList.addProduct("Originote", 60000);
    productList.addProduct("Somethinc", 150000);
    productList.addProduct("Skintific", 100000);
    productList.addProduct("Wardah", 50000);
    productList.addProduct("Hanasui", 30000);

    int choice;
    string prevProductName, newProductName;
    int newPrice;

    do {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Masukkan Nama Produk: ";
                cin >> newProductName;
                cout << "Masukkan Harga: ";
                cin >> newPrice;
                productList.addProduct(newProductName, newPrice);
                break;
            case 2:
                cout << "Masukkan Nama Produk yang Ingin Dihapus: ";
                cin >> newProductName;
                productList.removeProduct(newProductName);
                break;
            case 3:
                cout << "Masukkan Nama Produk yang Ingin Diupdate: ";
                cin >> prevProductName;
                cout << "Masukkan Nama Produk Baru: ";
                cin >> newProductName;
                cout << "Masukkan Harga Baru: ";
                cin >> newPrice;
                productList.updateProduct(prevProductName, newProductName, newPrice);
                break;
            case 4:
                cout << "Masukkan Nama Produk Sebelumnya: ";
                cin >> prevProductName;
                cout << "Masukkan Nama Produk Baru: ";
                cin >> newProductName;
                cout << "Masukkan Harga Baru: ";
                cin >> newPrice;
                productList.addProductBetween(prevProductName, newProductName, newPrice);
                break;
            case 5:
            {
                string productName;
                cout << "Masukkan Nama Produk yang Ingin Dihapus: ";
                cin >> productName;
                productList.removeProduct(productName);
                break;
            }
            case 6:
                productList.removeAll(); // Call the function to remove all data
                cout << "Semua data telah dihapus." << endl;
                break;
            case 7:
                cout << "Data Produk:" << endl;
                productList.displayProducts();
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    } while (choice != 8);

    return 0;
}
