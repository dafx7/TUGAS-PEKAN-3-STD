#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List LA;

    // 01. Meng-create list
    Create_List(LA);

    // Meminta user data pertama yang akan dimasukkan ke list
    DataPertandingan data1;
    cout << "Masukkan Nama Tim Pertama: ";
    cin >> data1.namaTim;
    cout << "Masukkan Skor Pertama: ";
    cin >> data1.skor;
    cout << "Masukkan Tanggal Pertama: ";
    cin >> data1.tanggal;

    // 02. Melakukan create new elemen berdasarkan data yang diinputkan user
    address p1 = New_Element(data1);

    // 03. Memanggil salah satu jenis insert (jangan insert after) - Insert First
    Insert_First(LA, p1);

    // Meminta user data kedua yang akan dimasukkan ke list
    DataPertandingan data2;
    cout << "Masukkan Nama Tim Kedua: ";
    cin >> data2.namaTim;
    cout << "Masukkan Skor Kedua: ";
    cin >> data2.skor;
    cout << "Masukkan Tanggal Kedua: ";
    cin >> data2.tanggal;

    // 04. Melakukan create new elemen berdasarkan data yang diinputkan user
    address p2 = New_Element(data2);

    // 05. Memanggil salah satu jenis insert (berbeda dengan insert yang pertama, jangan insert after) - Insert Last
    Insert_Last(LA, p2);

    // Meminta user data ketiga yang akan dimasukkan ke list
    DataPertandingan data3;
    cout << "Masukkan Nama Tim Ketiga: ";
    cin >> data3.namaTim;
    cout << "Masukkan Skor Ketiga: ";
    cin >> data3.skor;
    cout << "Masukkan Tanggal Ketiga: ";
    cin >> data3.tanggal;

    // 06. Melakukan create new elemen berdasarkan data yang diinputkan user
    address p3 = New_Element(data3);

    // Memanggil salah satu jenis insert - Insert First
    Insert_First(LA, p3);

    // Meminta user data keempat yang akan dimasukkan ke list
    DataPertandingan data4;
    cout << "Masukkan Nama Tim Keempat: ";
    cin >> data4.namaTim;
    cout << "Masukkan Skor Keempat: ";
    cin >> data4.skor;
    cout << "Masukkan Tanggal Keempat: ";
    cin >> data4.tanggal;

    // 07. Melakukan create new elemen berdasarkan data yang diinputkan user
    address p4 = New_Element(data4);

    // 08. Memanggil salah satu jenis insert - Insert Last
    Insert_Last(LA, p4);

    // Meminta user data kelima yang akan dimasukkan ke list
    DataPertandingan data5;
    cout << "Masukkan Nama Tim Kelima: ";
    cin >> data5.namaTim;
    cout << "Masukkan Skor Kelima: ";
    cin >> data5.skor;
    cout << "Masukkan Tanggal Kelima: ";
    cin >> data5.tanggal;

    // 09. Melakukan create new elemen berdasarkan data yang diinputkan user
    address p5 = New_Element(data5);

    // 10. Memanggil salah satu jenis insert (insert after) pada data ke 4
    Insert_After(LA, p4, p5);

    // Meminta user data keenam yang akan dimasukkan ke list
    DataPertandingan data6;
    cout << "Masukkan Nama Tim Keenam: ";
    cin >> data6.namaTim;
    cout << "Masukkan Skor Keenam: ";
    cin >> data6.skor;
    cout << "Masukkan Tanggal Keenam: ";
    cin >> data6.tanggal;

    // 11. Melakukan create new elemen berdasarkan data yang diinputkan user
    address p6 = New_Element(data6);

    // 12. Memanggil salah satu jenis insert (insert after) pada data ke 4
    Insert_After(LA, p4, p6);

    // Memanggil show (01)
    cout << "\nDaftar Tim Setelah Insert: \n";
    Show(LA);

    // 13. Melakukan pencarian dan penghapusan data kedua dengan delete after
    address temp;
    address prec = SearchByNamaTim(LA, data1.namaTim);  // Assume data2 is after data1
    if (prec != NULL) {f
        Delete_After(LA, prec, temp);
        cout << "\nData Tim Kedua telah dihapus.\n";
    }

    // 14. Melakukan pencarian dan penghapusan data keenam (gunakan pengkondisian)
    address prec6 = SearchByNamaTim(LA, data4.namaTim);
    if (prec6 != NULL) {
        if (next(prec6) != NULL && info(next(prec6)).namaTim == data6.namaTim) {
            Delete_After(LA, prec6, temp);
            cout << "\nData Tim Keenam telah dihapus.\n";
        }
    }

    // 15. Melakukan pengurutan elemen pada list berdasarkan skor
    SortBySkor(LA);

    // Memanggil show (02)
    cout << "\nDaftar Tim Setelah Pengurutan: \n";
    Show(LA);

    return 0;
}
