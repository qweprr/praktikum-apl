#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14;
string username = "Muhammad yusuf";
string password = "2409106093";

int main() {
    string inputUsername, inputPassword;
    cout << "=== LOGIN ===" << endl;
    cout << "username: ";
    getline(cin, inputUsername);
    cout << "password: ";
    cin >> inputPassword;

    if (inputUsername != username || inputPassword != password) {
        cout << "Password atau username salah!!" << endl;
        return 0;
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

        if (opsi == 1) {
            int opsiLuas;
            do {
                cout << "\n=== HITUNG LUAS ===" << endl;
                cout << "[1] Persegi" << endl;
                cout << "[2] Persegi Panjang" << endl;
                cout << "[3] Lingkaran" << endl;
                cout << "[4] Segitiga" << endl;
                cout << "[5] Kembali" << endl;
                cout << "Pilih: ";
                cin >> opsiLuas;
                
                double sisi, panjang, lebar, jari, alas, tinggi;
                if (opsiLuas == 1) {
                    do { cout << "Masukkan sisi: "; cin >> sisi; } while (sisi < 0);
                    cout << "Luas Persegi: " << sisi * sisi << endl;
                } else if (opsiLuas == 2) {
                    do { cout << "Masukkan panjang: "; cin >> panjang; cout << "Masukkan lebar: "; cin >> lebar; } while (panjang < 0 || lebar < 0);
                    cout << "Luas Persegi Panjang: " << panjang * lebar << endl;
                } else if (opsiLuas == 3) {
                    do { cout << "Masukkan jari-jari: "; cin >> jari; } while (jari < 0);
                    cout << "Luas Lingkaran: " << PI * jari * jari << endl;
                } else if (opsiLuas == 4) {
                    do { cout << "Masukkan alas: "; cin >> alas; cout << "Masukkan tinggi: "; cin >> tinggi; } while (alas < 0 || tinggi < 0);
                    cout << "Luas Segitiga: " << 0.5 * alas * tinggi << endl;
                }
            } while (opsiLuas != 5);
        } 
        else if (opsi == 2) {
            int opsiKeliling;
            do {
                cout << "\n=== HITUNG KELILING ===" << endl;
                cout << "[1] Persegi" << endl;
                cout << "[2] Persegi Panjang" << endl;
                cout << "[3] Lingkaran" << endl;
                cout << "[4] Segitiga" << endl;
                cout << "[5] Kembali" << endl;
                cout << "Pilih: ";
                cin >> opsiKeliling;
                
                double sisi, panjang, lebar, jari, a, b, c;
                if (opsiKeliling == 1) {
                    do { cout << "Masukkan sisi: "; cin >> sisi; } while (sisi < 0);
                    cout << "Keliling Persegi: " << 4 * sisi << endl;
                } else if (opsiKeliling == 2) {
                    do { cout << "Masukkan panjang: "; cin >> panjang; cout << "Masukkan lebar: "; cin >> lebar; } while (panjang < 0 || lebar < 0);
                    cout << "Keliling Persegi Panjang: " << 2 * (panjang + lebar) << endl;
                } else if (opsiKeliling == 3) {
                    do { cout << "Masukkan jari-jari: "; cin >> jari; } while (jari < 0);
                    cout << "Keliling Lingkaran: " << 2 * PI * jari << endl;
                } else if (opsiKeliling == 4) {
                    do { cout << "Masukkan sisi a: "; cin >> a; cout << "Masukkan sisi b: "; cin >> b; cout << "Masukkan sisi c: "; cin >> c; } while (a < 0 || b < 0 || c < 0);
                    cout << "Keliling Segitiga: " << a + b + c << endl;
                }
            } while (opsiKeliling != 5);
        } 
        else if (opsi == 3) {
            int opsiVolume;
            do {
                cout << "\n=== HITUNG VOLUME ===" << endl;
                cout << "[1] Kubus" << endl;
                cout << "[2] Balok" << endl;
                cout << "[3] Bola" << endl;
                cout << "[4] Kerucut" << endl;
                cout << "[5] Kembali" << endl;
                cout << "Pilih: ";
                cin >> opsiVolume;
                
                double sisi, panjang, lebar, tinggi, jari;
                if (opsiVolume == 1) {
                    do { cout << "Masukkan sisi: "; cin >> sisi; } while (sisi < 0);
                    cout << "Volume Kubus: " << pow(sisi, 3) << endl;
                } else if (opsiVolume == 2) {
                    do { cout << "Masukkan panjang: "; cin >> panjang; cout << "Masukkan lebar: "; cin >> lebar; cout << "Masukkan tinggi: "; cin >> tinggi; } while (panjang < 0 || lebar < 0 || tinggi < 0);
                    cout << "Volume Balok: " << panjang * lebar * tinggi << endl;
                } else if (opsiVolume == 3) {
                    do { cout << "Masukkan jari-jari: "; cin >> jari; } while (jari < 0);
                    cout << "Volume Bola: " << (4.0 / 3) * PI * pow(jari, 3) << endl;
                } else if (opsiVolume == 4) {
                    do { cout << "Masukkan jari-jari: "; cin >> jari; cout << "Masukkan tinggi: "; cin >> tinggi; } while (jari < 0 || tinggi < 0);
                    cout << "Volume Kerucut: " << (1.0 / 3) * PI * pow(jari, 2) * tinggi << endl;
                }
            } while (opsiVolume != 5);
        }
    } while (opsi != 4);
    
    cout << "Log out berhasil!" << endl;
    return 0;
}
