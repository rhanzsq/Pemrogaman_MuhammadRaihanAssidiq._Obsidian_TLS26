#include <iostream>
using namespace std;

int cariPosisiKeluar(int posisi, int K, int jumlah) {
    return (posisi + K - 1) % jumlah;
}

void hapusAstronaut(int astronaut[], int &jumlah, int posisiKeluar) {
    for (int i = posisiKeluar; i < jumlah - 1; i++) {
        astronaut[i] = astronaut[i + 1];
    }

    jumlah--;
}

void ubahK(int &K, int yangKeluar) {
    if (yangKeluar % 2 == 0) {
        K = K + 2;
    } else {
        K = K - 1;
    }

    if (K < 2) {
        K = 2;
    }
}

int main() {
    int N, K;

    cout << "Masukkan jumlah astronaut (N): ";
    cin >> N;

    cout << "Masukkan nilai awal K: ";
    cin >> K;

    cout << endl;
    cout << "N = " << N << endl;
    cout << "K = " << K << endl;

    int astronaut[1000];

    for (int i = 0; i < N; i++) {
        astronaut[i] = i + 1;
    }

    int jumlah = N;
    int posisi = 0;

    cout << "Urutan eliminasi: ";

    while (jumlah > 1) {

        int posisiKeluar = cariPosisiKeluar(posisi, K, jumlah);

        int yangKeluar = astronaut[posisiKeluar];

        cout << yangKeluar << " ";

        hapusAstronaut(astronaut, jumlah, posisiKeluar);

        ubahK(K, yangKeluar);

        posisi = posisiKeluar;

        if (posisi >= jumlah) {
            posisi = 0;
        }
    }

    cout << endl;
    cout << "Astronaut terakhir: " << astronaut[0] << endl;

    return 0;
}
