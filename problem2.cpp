#include <iostream>
using namespace std;

int nilaiHuruf(char huruf) {
    return huruf - 'A' + 1;
}

char ubahKeHuruf(int nilai) {
    return 'A' + nilai - 1;
}

void enkripsi(char teks[], int panjang) {
    for (int i = 1; i < panjang; i++) {
        int nilaiSekarang = nilaiHuruf(teks[i]);
        int nilaiSebelumnya = nilaiHuruf(teks[i - 1]);

        int nilaiBaru = nilaiSekarang + nilaiSebelumnya;

        if (nilaiBaru > 26) {
            nilaiBaru = nilaiBaru - 26;
        }

        teks[i] = ubahKeHuruf(nilaiBaru);
    }
}

int main() {
    char teks[1000];
    int panjang = 0;

    cout << "Masukkan teks: ";
    cin >> teks;

    while (teks[panjang] != '\0') {
        panjang++;
    }

    cout << "Teks awal: " << teks << endl;

    enkripsi(teks, panjang);

    cout << "Hasil enkripsi: " << teks << endl;

    return 0;
}
