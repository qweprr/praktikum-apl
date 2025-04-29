#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_USERS = 100;
const int MAX_DATA = 50;

struct User {
    string username;
    string password;
    string data[MAX_DATA];
    int data_count = 0;
};

const string useradmin = "Muhammad Yusuf";
const string passadmin = "2409106093";

// Fungsi dan Prosedur
int findUser(User users[], int total_users, const string& username);
void displayMainMenu();
void createAccount(User* users, int* total_users);
void login(User* users, int* total_users);
void adminMenu(User* users, int* total_users);
void userMenu(User* user);
void viewAllUsers(const User* users, int total_users);
void viewAllUserData(const User* users, int total_users);
void deleteUser(User* users, int* total_users);
void addUserData(User* user);
void viewUserData(const User& user);
void updateUserData(User* user);
void deleteUserData(User* user);

// Fungsi Sorting
float extractSize(const string& data);
void bubbleSortByDescription(User* user);
void selectionSortBySizeDescending(User* user);
void merge(string arr[], int l, int m, int r);
void mergeSortBySizeAscending(string arr[], int l, int r);
void applyMergeSort(User* user);

int main() {
    User users[MAX_USERS];
    int total_users = 0;

    while (true) {
        displayMainMenu();
        int opsi;
        cin >> opsi;
        cin.ignore();

        switch (opsi) {
            case 1:
                createAccount(users, &total_users);
                break;
            case 2:
                login(users, &total_users);
                break;
            case 3:
                cout << "Keluar dari sistem.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }
}

void displayMainMenu() {
    cout << "\n====== AI Archive ======\n";
    cout << "+----+---------------------+\n";
    cout << "| No | Opsi                |\n";
    cout << "+----+---------------------+\n";
    cout << "| 1  | Buat Akun           |\n";
    cout << "| 2  | Login               |\n";
    cout << "| 3  | Keluar              |\n";
    cout << "+----+---------------------+\n";
    cout << "Pilih opsi: ";
}

int findUser(User users[], int total_users, const string& username) {
    for (int i = 0; i < total_users; i++) {
        if (users[i].username == username) return i;
    }
    return -1;
}

void createAccount(User* users, int* total_users) {
    if (*total_users >= MAX_USERS) {
        cout << "Maksimal pengguna telah tercapai!\n";
        return;
    }

    string username, password;
    cout << "Masukkan Nama: ";
    getline(cin, username);

    if (findUser(users, *total_users, username) != -1) {
        cout << "Username sudah terdaftar!\n";
    } else {
        cout << "Masukkan password: ";
        getline(cin, password);

        users[*total_users].username = username;
        users[*total_users].password = password;
        (*total_users)++;

        cout << "Akun berhasil dibuat!\n";
    }
}

void login(User* users, int* total_users) {
    string username, password;
    int attempts = 3;

    while (attempts > 0) {
        cout << "Input Nama: ";
        getline(cin, username);
        cout << "Input password: ";
        getline(cin, password);

        if (username == useradmin && password == passadmin) {
            cout << "Login Admin Berhasil!\n";
            adminMenu(users, total_users);
            break;
        }

        int userIndex = findUser(users, *total_users, username);
        if (userIndex == -1 || users[userIndex].password != password) {
            cout << "Username atau password salah!\n";
            attempts--;
            cout << "Sisa percobaan: " << attempts << endl;
            if (attempts == 0) {
                cout << "Gagal login 3 kali. Coba lagi nanti.\n";
            }
            continue;
        }

        cout << "Login berhasil!\n";
        userMenu(&users[userIndex]);
        break;
    }
}

void adminMenu(User* users, int* total_users) {
    bool admin_logged_in = true;

    while (admin_logged_in) {
        cout << "\n=== Admin Mode ===\n";
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

        switch (opsiadmin) {
            case 1:
                viewAllUsers(users, *total_users);
                break;
            case 2:
                viewAllUserData(users, *total_users);
                break;
            case 3:
                deleteUser(users, total_users);
                break;
            case 4:
                cout << "Logout berhasil.\n";
                admin_logged_in = false;
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }
}

void userMenu(User* user) {
    bool logged_in = true;

    while (logged_in) {
        cout << "\n=== AI Archive ===\n";
        cout << "+----+---------------------+\n";
        cout << "| 1  | Tambah Data         |\n";
        cout << "| 2  | Baca Data           |\n";
        cout << "| 3  | Perbarui Data       |\n";
        cout << "| 4  | Hapus Data          |\n";
        cout << "| 5  | Logout              |\n";
        cout << "| 6  | Sorting Data        |\n";
        cout << "+----+---------------------+\n";
        cout << "Pilih menu: ";

        int opsiuser;
        cin >> opsiuser;
        cin.ignore();

        switch (opsiuser) {
            case 1:
                addUserData(user);
                break;
            case 2:
                viewUserData(*user);
                break;
            case 3:
                updateUserData(user);
                break;
            case 4:
                deleteUserData(user);
                break;
            case 5:
                cout << "Logout berhasil.\n";
                logged_in = false;
                break;
            case 6: {
                int metode;
                cout << "\nPilih metode sorting:\n";
                cout << "1. Huruf (Ascending - Bubble Sort)\n";
                cout << "2. Ukuran (Descending - Selection Sort)\n";
                cout << "3. Ukuran (Ascending - Merge Sort)\n";
                cout << "Pilihan: ";
                cin >> metode;
                cin.ignore();
                switch (metode) {
                    case 1: bubbleSortByDescription(user); break;
                    case 2: selectionSortBySizeDescending(user); break;
                    case 3: applyMergeSort(user); break;
                    default: cout << "Pilihan tidak valid.\n";
                }
                break;
            }
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }
}

void viewAllUsers(const User* users, int total_users) {
    cout << "\nDaftar Pengguna:\n";
    for (int i = 0; i < total_users; i++) {
        cout << "- " << users[i].username << endl;
    }
}

void viewAllUserData(const User* users, int total_users) {
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

void deleteUser(User* users, int* total_users) {
    cout << "Masukkan nama pengguna yang ingin dihapus: ";
    string user;
    getline(cin, user);

    int index = findUser(users, *total_users, user);
    if (index != -1) {
        for (int i = index; i < *total_users - 1; i++) {
            users[i] = users[i + 1];
        }
        (*total_users)--;
        cout << "Pengguna " << user << " berhasil dihapus.\n";
    } else {
        cout << "Pengguna tidak ditemukan.\n";
    }
}

void addUserData(User* user) {
    if (user->data_count >= MAX_DATA) {
        cout << "Maksimal data tercapai!\n";
        return;
    }

    string description;
    float sizeInMB;

    cout << "Masukkan deskripsi data baru: ";
    getline(cin, description);

    cout << "Masukkan ukuran data/MB: ";
    cin >> sizeInMB;
    cin.ignore();

    if (sizeInMB <= 0) {
        cout << "Ukuran data tidak valid! Harus lebih besar dari 0.\n";
        return;
    }

    user->data[user->data_count] = description + " (Ukuran: " + to_string(sizeInMB) + " MB)";
    user->data_count++;

    cout << "Data berhasil ditambahkan.\n";
}

void viewUserData(const User& user) {
    cout << "\nData Anda:\n";
    if (user.data_count == 0) {
        cout << "Tidak ada data tersimpan.\n";
    } else {
        for (int i = 0; i < user.data_count; i++) {
            string data = user.data[i];
            size_t start = data.find("(Ukuran: ");
            size_t end = data.find(" MB)");

            if (start != string::npos && end != string::npos) {
                string sizeStr = data.substr(start + 9, end - (start + 9));
                cout << i + 1 << ". " << data.substr(0, start) << " (Ukuran: " << sizeStr << " MB)" << endl;
            } else {
                cout << i + 1 << ". " << data << endl;
            }
        }
    }
}

void updateUserData(User* user) {
    viewUserData(*user);

    if (user->data_count == 0) return;

    cout << "Masukkan nomor data yang ingin diperbarui: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index > 0 && index <= user->data_count) {
        cout << "Masukkan data baru: ";
        getline(cin, user->data[index - 1]);
        cout << "Data berhasil diperbarui.\n";
    } else {
        cout << "Nomor data tidak valid!\n";
    }
}

void deleteUserData(User* user) {
    viewUserData(*user);

    if (user->data_count == 0) return;

    cout << "Masukkan nomor data yang ingin dihapus: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index > 0 && index <= user->data_count) {
        for (int i = index - 1; i < user->data_count - 1; i++) {
            user->data[i] = user->data[i + 1];
        }
        user->data_count--;
        cout << "Data berhasil dihapus.\n";
    } else {
        cout << "Nomor data tidak valid!\n";
    }
}

// Fungsi Sorting

float extractSize(const string& data) {
    size_t start = data.find("(Ukuran: ");
    size_t end = data.find(" MB)");
    if (start != string::npos && end != string::npos) {
        string sizeStr = data.substr(start + 9, end - (start + 9));
        return stof(sizeStr);
    }
    return 0;
}

void bubbleSortByDescription(User* user) {
    for (int i = 0; i < user->data_count - 1; i++) {
        for (int j = 0; j < user->data_count - i - 1; j++) {
            string desc1 = user->data[j].substr(0, user->data[j].find("(Ukuran:"));
            string desc2 = user->data[j + 1].substr(0, user->data[j + 1].find("(Ukuran:"));

            if (desc1 > desc2) {
                swap(user->data[j], user->data[j + 1]);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan deskripsi (ascending).\n";
}

void selectionSortBySizeDescending(User* user) {
    for (int i = 0; i < user->data_count - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < user->data_count; j++) {
            if (extractSize(user->data[j]) > extractSize(user->data[maxIdx])) {
                maxIdx = j;
            }
        }
        swap(user->data[i], user->data[maxIdx]);
    }
    cout << "Data berhasil diurutkan berdasarkan ukuran (descending).\n";
}

void merge(string arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    string L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (extractSize(L[i]) <= extractSize(R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortBySizeAscending(string arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortBySizeAscending(arr, l, m);
        mergeSortBySizeAscending(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void applyMergeSort(User* user) {
    mergeSortBySizeAscending(user->data, 0, user->data_count - 1);
    cout << "Data berhasil diurutkan berdasarkan ukuran (ascending).\n";
}
