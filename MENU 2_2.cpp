#include "Header Bengkel.h"

/// MENU PENJUALAN BARANG

// PENJUALAN DATA BARANG
void jual_barang()
{
    int letak = x + 9; //peletakan y di prosedur gotoxy pd prosedur jual baarng
    jual=0;
    char input;
    total_bayar=0;

    if (y == 1){
        tampilbarang();
        cout << endl;
        cout << "\n === PEMBELIAN === ";
        do {
            jual--;
            buy:
            jual++;
            cout << endl;
            cout << "\n Masukkan nama barang : ";
            cin.ignore();
            getline(cin, data[jual].masukan);
            cout << endl;
            int posisi = searchingData(data, barang, data[jual].masukan);
                if (posisi != -1) {
                    cout << " Jumlah " << data[posisi].nama << " : ";
                    cin >> data[jual].jumlhbrg;
                    if(data[jual].jumlhbrg <= data[posisi].jumlah){
                        data[jual].totalharga = data[posisi].harga * data[jual].jumlhbrg;
                        data[posisi].jumlah -= data[jual].jumlhbrg;
                        if (data[posisi].jumlah == 0){
                            posisi-1; //posisi jadi -1
                            barang--; //barang akan menjadi hilang
                            for(i = posisi; i < barang; i++){
                                data[i] = data[i+1];
                            }
                        }
                        beli:
                        cout << " tambah pembelian? (y/n) : ";
                        cin >> input;
                        if (input == 'y') {
                            goto buy;
                        }else if (input == 'n'){
                            cout << "\n==============================================================================";
                            cout << "\n\t\t\t CETAK STRUK";
                            cout << "\n=============================================================================="<<endl;
                            cout << "\n No\tJumlah\tNama Barang\tTotal Harga" << endl; // DISINI MASIH BUG UNTUK MENAMPILKAN DATA
                            for(i=0; i <= jual; i++){
                                cout << " " << i+1 << "\t" << data[i].jumlhbrg << "\t"<< data[i].masukan << "\t\t" << data[i].totalharga << endl;
                                total_bayar = total_bayar + data[i].totalharga;
                                push(data[i].masukan, data[i].jumlhbrg, data[i].totalharga);
                            }
                            bay:
                            cout << "\n\n Total : " << total_bayar << endl;
                            cout << " Bayar : ";
                            cin >> bayar;
                            kembalian = bayar - total_bayar;
                            if(bayar > total_bayar)
                            {
                                cout << " kembalian : " << kembalian << endl;
                                cout << "\n\n==============================================================================";
                                cout << "\n\t\t\t TERIMAKASIH";
                                cout << "\n=============================================================================="<<endl;
                            }
                            else if(bayar == total_bayar)
                            {
                                cout << "\n==============================================================================";
                                cout << "\n\t\t\t TERIMAKASIH";
                                cout << "\n=============================================================================="<<endl;
                            }
                            else
                            {
                                cout << " uang kurang" << endl;
                                goto bay;
                            }
                        }else{
                            cout << " SILAKAN MASUKAN SESUAI PERINTAH, JANGAN GUNAKAN HURUF KAPITAL" << endl;
                        }
                    }else{
                        cout << " Stok masih kurang" << endl;
                        goto beli;
                    }
                } else {
                    cout << " Barang tidak ditemukan";
                    jual--;
                    goto beli;
                }
            } while (input != 'n');
    }else {
        cout << "   SILAKAN HUBUNGI OPERATOR GUDANG UNTUK MEMASUKAN DATA BARANG TERLEBIH DAHULU" << endl;
    }
}
