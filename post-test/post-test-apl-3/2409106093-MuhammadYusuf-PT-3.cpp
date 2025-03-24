#include <iostream>
#include <string>
#include <iomanip> // Untuk setw dan setfill

using namespace std;

const int MAX_USERS = 100;
const int MAX_DATA = 50;

// Definisi struct untuk menyimpan informasi pengguna
struct User {
    string username;
    string password;
    string data[MAX_DATA];
    int data_count = 0;
};

User users[MAX_USERS];
int total_users = 0;

// Data Admin
string useradmin = "Muhammad Yusuf";
string passadmin = "2409106093";

// Fungsi mencari indeks pengguna berdasarkan username
int findUser(string username) {
    for (int i = 0; i < total_users; i++) {
        if (users[i].username == username) return i;
    }
    return -1;
}

int main() {
    while (true) {
        // Tampilan menu utama dalam bentuk tabel
        cout << "\n====== AI Archive ======\n";
        cout << "+----+---------------------+\n";
        cout << "| No | Opsi                |\n";
        cout << "+----+---------------------+\n";
        cout << "| 1  | Buat Akun           |\n";
        cout << "| 2  | Login               |\n";
        cout << "| 3  | Keluar              |\n";
        cout << "+----+---------------------+\n";
        cout << "Pilih opsi: ";

        int opsi;
        cin >> opsi;
        cin.ignore();

        if (opsi == 1) {  
            if (total_users >= MAX_USERS) {
                cout << "Maksimal pengguna telah tercapai!\n";
                continue;
            }

            string username, password;
            cout << "Masukkan Nama: ";
            getline(cin, username);

            if (findUser(username) != -1) {
                cout << "Username sudah terdaftar!\n";
            } else {
                cout << "Masukkan password: ";
                getline(cin, password);

                users[total_users].username = username;
                users[total_users].password = password;
                total_users++;

                cout << "Akun berhasil dibuat!\n";
            }
        } 
        else if (opsi == 2) {  
            string username, password;
            int attempts = 3;

            while (attempts > 0) {
                cout << "Input Nama: ";
                getline(cin, username);
                cout << "Input password: ";
                getline(cin, password);

                if (username == useradmin && password == passadmin) {
                    cout << "Login Admin Berhasil!\n";
                    bool admin_logged_in = true;

                    while (admin_logged_in) {
                        // Tampilan menu admin dalam bentuk tabel
                        cout << "\n=== Admin Mode ===\n";
                        cout << "+----+---------------------+\n";
                        cout << "| No | Opsi                |\n";
                        cout << "+----+---------------------+\n";
                        cout << "| 1  | Lihat Semua Pengguna|\n";
                        cout << "| 2  | Lihat Data Pengguna |\n";
                        cout << "| 3  | Hapus Pengguna      |\n";
                        cout << "| 4  | Logout              |\n";
                        cout << "+----+---------------------+\n";
                        cout << "Pilih menu: ";

                        int opsiadmin;
                        cin >> opsiadmin;
                        cin.ignore();

                        if (opsiadmin == 1) {  
                            cout << "\nDaftar Pengguna:\n";
                            for (int i = 0; i < total_users; i++) {
                                cout << "- " << users[i].username << endl;
                            }
                        } 
                        else if (opsiadmin == 2) {  
                            cout << "\n=== Data Seluruh Pengguna ===\n";
                            if (total_users == 0) {
                                cout << "Tidak ada pengguna terdaftar.\n";
                            } else {
                                for (int i = 0; i < total_users; i++) {
                                    cout << "\n🔹 Pengguna: " << users[i].username << "\n";
                                    if (users[i].data_count == 0) {
                                        cout << "   ➝ Tidak ada data tersimpan.\n";
                                    } else {
                                        for (int j = 0; j < users[i].data_count; j++) {
                                            cout << "   " << j + 1 << ". " << users[i].data[j] << endl;
                                        }
                                    }
                                }
                            }
                        }
                        else if (opsiadmin == 3) {  
                            cout << "Masukkan nama pengguna yang ingin dihapus: ";
                            string user;
                            getline(cin, user);

                            int index = findUser(user);
                            if (index != -1) {
                                for (int i = index; i < total_users - 1; i++) {
                                    users[i] = users[i + 1];
                                }
                                total_users--;
                                cout << "Pengguna " << user << " berhasil dihapus.\n";
                            } else {
                                cout << "Pengguna tidak ditemukan.\n";
                            }
                        } 
                        else if (opsiadmin == 4) {
                            cout << "Logout berhasil.\n";
                            admin_logged_in = false;
                        } 
                        else {
                            cout << "Pilihan tidak valid.\n";
                        }
                    }
                    break;
                }

                int userIndex = findUser(username);
                if (userIndex == -1 || users[userIndex].password != password) {
                    cout << "Username atau password salah!\n";
                    attempts--;
                    cout << "Sisa percobaan: " << attempts << endl;
                    if (attempts == 0) {
                        cout << "Gagal login 3 kali. Coba lagi nanti.\n";
                        break;
                    }
                    continue;
                }

                cout << "Login berhasil!\n";
                bool logged_in = true;

                while (logged_in) {
                    // Tampilan menu pengguna dalam bentuk tabel
                    cout << "\n=== AI Archive ===\n";
                    cout << "+----+---------------------+\n";
                    cout << "| No | Opsi                |\n";
                    cout << "+----+---------------------+\n";
                    cout << "| 1  | Tambah Data         |\n";
                    cout << "| 2  | Baca Data           |\n";
                    cout << "| 3  | Perbarui Data       |\n";
                    cout << "| 4  | Hapus Data          |\n";
                    cout << "| 5  | Logout              |\n";
                    cout << "+----+---------------------+\n";
                    cout << "Pilih menu: ";

                    int opsiuser;
                    cin >> opsiuser;
                    cin.ignore();

                    if (opsiuser == 1) {  
                        if (users[userIndex].data_count >= MAX_DATA) {
                            cout << "Maksimal data tercapai!\n";
                            continue;
                        }
                        cout << "Masukkan data baru: ";
                        getline(cin, users[userIndex].data[users[userIndex].data_count]);
                        users[userIndex].data_count++;
                        cout << "Data berhasil ditambahkan.\n";
                    } 
                    else if (opsiuser == 2) {  
                        cout << "\nData Anda:\n";
                        if (users[userIndex].data_count == 0) {
                            cout << "Tidak ada data tersimpan.\n";
                        } else {
                            for (int i = 0; i < users[userIndex].data_count; i++) {
                                cout << i + 1 << ". " << users[userIndex].data[i] << endl;
                            }
                        }
                    } 
                    else if (opsiuser == 3) { 
                        cout << "\nData Anda:\n";
                        if (users[userIndex].data_count == 0) {
                            cout << "Tidak ada data tersimpan.\n";
                        } else {
                            for (int i = 0; i < users[userIndex].data_count; i++) {
                                cout << i + 1 << ". " << users[userIndex].data[i] << endl;
                            }
                        }

                        cout << "Masukkan nomor data yang ingin diperbarui: ";
                        int index;
                        cin >> index;
                        cin.ignore();

                        if (index > 0 && index <= users[userIndex].data_count) {
                            cout << "Masukkan data baru: ";
                            getline(cin, users[userIndex].data[index - 1]);
                            cout << "Data berhasil diperbarui.\n";
                        } else {
                            cout << "Nomor data tidak valid!\n";
                        }
                    } 
                    else if (opsiuser == 4) { 
                        cout << "\nData Anda:\n";
                        if (users[userIndex].data_count == 0) {
                            cout << "Tidak ada data tersimpan.\n";
                        } else {
                            for (int i = 0; i < users[userIndex].data_count; i++) {
                                cout << i + 1 << ". " << users[userIndex].data[i] << endl;
                            }
                        }
                         
                        cout << "Masukkan nomor data yang ingin dihapus: ";
                        int index;
                        cin >> index;
                        cin.ignore();

                        if (index > 0 && index <= users[userIndex].data_count) {
                            for (int i = index - 1; i < users[userIndex].data_count - 1; i++) {
                                users[userIndex].data[i] = users[userIndex].data[i + 1];
                            }
                            users[userIndex].data_count--;
                            cout << "Data berhasil dihapus.\n";
                        } else {
                            cout << "Nomor data tidak valid!\n";
                        }
                    } 
                    else if (opsiuser == 5) {
                        cout << "Logout berhasil.\n";
                        logged_in = false;
                    } 
                    else {
                        cout << "Pilihan tidak valid.\n";
                    }
                }
                break;
            }
        } 
        else if (opsi == 3) {
            cout << "Keluar dari sistem.\n";
            break;
        } 
        else {
            cout << "Pilihan tidak valid.\n";
        }
    }
    return 0;
}