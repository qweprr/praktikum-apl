#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14;
string username = "Muhammad yusuf";
string password = "2409106093";

void hitungLuas();
void hitungKeliling();
void hitungVolume();

int main() {
    string inputUsername, inputPassword;
    cout << "=== LOGIN ===" << endl;
    cout << "username: ";
    getline(cin, inputUsername);
    cout << "password: ";
    cin >> inputPassword;

    if (inputUsername != username || inputPassword != password) {  
        cout << "Password atau username salah!!" << endl;
        return 0; // Keluar dari program jika login salah
    }

    int opsi;
    do {
        cout << "\n=== SISTEM HITUNG BANGUN DATAR DAN BANGUN RUANG ===" << endl;
        cout << "[1] Hitung Luas" << endl;
        cout << "[2] Hitung Keliling" << endl;
        cout << "[3] Hitung Volume" << endl;
        cout << "[4] Log Out" << endl;
        cout << "Pilih Opsi: ";
        cin >> opsi;

        switch (opsi) {
            case 1: hitungLuas(); break;
            case 2: hitungKeliling(); break;
            case 3: hitungVolume(); break;
            case 4: cout << "Log out berhasil!" << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (opsi != 4);

    return 0;
}

void hitungLuas() {
    int opsi;
    do {
        cout << "\n=== HITUNG LUAS ===" << endl;
        cout << "[1] Persegi" << endl;
        cout << "[2] Persegi Panjang" << endl;
        cout << "[3] Lingkaran" << endl;
        cout << "[4] Segitiga" << endl;
        cout << "[5] Kembali" << endl;
        cout << "Pilih: ";
        cin >> opsi;

        double sisi, panjang, lebar, jari, alas, tinggi;

        switch (opsi) {
            case 1:
                do {
                    cout << "Masukkan sisi: "; cin >> sisi;
                } while (sisi < 0);
                cout << "Luas Persegi: " << sisi * sisi << endl;
                break;
            case 2:
                do {
                    cout << "Masukkan panjang: "; cin >> panjang;
                    cout << "Masukkan lebar: "; cin >> lebar;
                } while (panjang < 0 || lebar < 0); 
                cout << "Luas Persegi Panjang: " << panjang * lebar << endl;
                break;
            case 3:
                do {
                    cout << "Masukkan jari-jari: "; cin >> jari;
                } while (jari < 0);
                cout << "Luas Lingkaran: " << PI * jari * jari << endl;
                break;
            case 4:
                do {
                    cout << "Masukkan alas: "; cin >> alas;
                    cout << "Masukkan tinggi: "; cin >> tinggi;
                } while (alas < 0 || tinggi < 0); 
                cout << "Luas Segitiga: " << 0.5 * alas * tinggi << endl;
                break;
        }
    } while (opsi != 5);
}

void hitungKeliling() {
    int opsi;
    do {
        cout << "\n== HITUNG KELILING ==" << endl;
        cout << "[1] Persegi" << endl;
        cout << "[2] Persegi Panjang" << endl;
        cout << "[3] Lingkaran" << endl;
        cout << "[4] Segitiga" << endl;
        cout << "[5] Kembali" << endl;
        cout << "Pilih: ";
        cin >> opsi;

        double sisi, panjang, lebar, jari, a, b, c;

        switch (opsi) {
            case 1:
                do {
                    cout << "Masukkan sisi: "; cin >> sisi;
                } while (sisi < 0);
                cout << "Keliling Persegi: " << 4 * sisi << endl;
                break;
            case 2:
                do {
                    cout << "Masukkan panjang: "; cin >> panjang;
                    cout << "Masukkan lebar: "; cin >> lebar;
                } while (panjang < 0 || lebar < 0); 
                cout << "Keliling Persegi Panjang: " << 2 * (panjang + lebar) << endl;
                break;
            case 3:
                do {
                    cout << "Masukkan jari-jari: "; cin >> jari;
                } while (jari < 0);
                cout << "Keliling Lingkaran: " << 2 * PI * jari << endl;
                break;
            case 4:
                do {
                    cout << "Masukkan sisi a: "; cin >> a;
                    cout << "Masukkan sisi b: "; cin >> b;
                    cout << "Masukkan sisi c: "; cin >> c;
                } while (a < 0 || b < 0 || c < 0);
                cout << "Keliling Segitiga: " << a + b + c << endl;
                break;
        }
    } while (opsi != 5);
}

void hitungVolume() {
    int opsi;
    do {
        cout << "\n== HITUNG VOLUME ==" << endl;
        cout << "[1] Kubus" << endl;
        cout << "[2] Balok" << endl;
        cout << "[3] Bola" << endl;
        cout << "[4] Kerucut" << endl;
        cout << "[5] Kembali" << endl;
        cout << "Pilih: ";
        cin >> opsi;

        double sisi, panjang, lebar, tinggi, jari;

        switch (opsi) {
            case 1:
                do {
                    cout << "Masukkan sisi: "; cin >> sisi;
                } while (sisi < 0);
                cout << "Volume Kubus: " << pow(sisi, 3) << endl;
                break;
            case 2:
                do {
                    cout << "Masukkan panjang: "; cin >> panjang;
                    cout << "Masukkan lebar: "; cin >> lebar;
                    cout << "Masukkan tinggi: "; cin >> tinggi;
                } while (panjang < 0 || lebar < 0 || tinggi < 0); 
                cout << "Volume Balok: " << panjang * lebar * tinggi << endl;
                break;
            case 3:
                do {
                    cout << "Masukkan jari-jari: "; cin >> jari;
                } while (jari < 0);
                cout << "Volume Bola: " << (4.0 / 3) * PI * pow(jari, 3) << endl;
                break;
            case 4:
                cout << "Masukkan jari-jari: "; cin >> jari;
                cout << "Masukkan tinggi: "; cin >> tinggi;
                cout << "Volume Kerucut: " << (1.0 / 3) * PI * pow(jari, 2) * tinggi << endl;
                break;
        }
    } while (opsi != 5);
}
