#include "Header Bengkel.h"

/// MENU INFORMASI DATA BARANG

// INPUT DATA BARANG
void inputbarang()
{
    barang++;
	y = 1; //penanda bahwa sudah mengisi
	system("cls");
	gotoxy(40-3, 1);cout << "=====================================";
    gotoxy(50-4,2);cout << " INPUT STOK BARANG " << endl;
    gotoxy(40-3, 3);cout << "====================================="<<endl;
    cout << "\n Nama Barang : ";
    cin.ignore();
    getline(cin, data[barang].nama);
    cout << " Kode Barang : ";
    getline(cin, data[barang].kode);

    cout << " Jumlah Barang : ";
    cin >> data[barang].jumlah;

    cout << " Harga Barang Satuan : ";
    cin >> data[barang].harga;

    cout << "\n\n STOK BARANG BERHASIL DIMASUKKAN" << endl;
}

// TAMPILKAN DATA BARANG
void tampilbarang()
{
	if (y == 1 && barang > 0 || barang > - 1){
		system("cls");
		gotoxy(40-3, 0);cout << "=====================================";
		gotoxy(50-4,1);cout << " STOK BARANG BENGKEL" << endl;
		gotoxy(40-3, 2);cout << "====================================="<<endl;
	    cout << "\n No\tNama Barang\tKode\tJumlah\tHarga Satuan" << endl;
	    for(int i=0; i<=barang; i++){
	        cout << " " << i+1 << "\t"<< data[i].nama << "\t\t" << data[i].kode << "\t" << data[i].jumlah << "\t" << data[i].harga << endl;
	    }
	} else {
		system("cls");
		cout << "\n Stock Gudang Kosong " << endl;
		cout << " Silakan hubungi pihak gudang untuk memasukan data terlebih dahulu " << endl;
	}
}

// PENCARIAN DATA BARANG
int searchingData(struct dataBarang data[], int barang, string cari)
{

    int posisi, i, ketemu;

    if (barang < 0)
        posisi = -1;
    else {
		barang++;
        ketemu = 0;
        i = 0;
        while ((i <= barang) && !ketemu) {
            if (data[i].nama == cari) {
                posisi = i;
                ketemu = 1;
            } else {
                i++;
            }
            if (!ketemu) {
                posisi = -1;
            }
        }
    }
    return posisi;
}

// MENAMPILKAN HASIL PENCARIAN
void tampilsearching()
{
    string cari;

	if (y == 1 || barang > -1){
		system("cls");
		gotoxy(40-3, 1);cout << "=====================================";
	    gotoxy(50-4,2);cout << " PENCARIAN BARANG" << endl;
	    gotoxy(40-3, 3);cout << "====================================="<<endl;
	    cout << "\n Nama Barang : ";
	    cin.ignore();
	    getline(cin, cari);
        int posisi = searchingData(data, barang, cari);
        if (posisi != -1) {
            cout << "\n Barang " << cari << " Ditemukan pada urutan ke - " << posisi+1 << endl;
        } else {
            cout << " Barang tidak ditemukan";
        }
	}else{
        cout << endl;
	}
}

