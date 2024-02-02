#include <iostream>
#include <windows.h>
#include "MENU 1.cpp"
#include "MENU 2.cpp"
#include "MENU 2_2.cpp"
#include "MENU 3.cpp"
#include "MENU 4.cpp"
#include "MENU 4_2.cpp"
#include "Header Bengkel.h"

using namespace std;

/// Ivan Wijdan Boediardjo ( 21102072 )
/// Addharuqutni Azzyumardi N. ( 21102073 )
/// Ardea Himawan Nugroho ( 21102076 )

int main()
{
    int pilih;
    do{
        menu_utama:
        system("cls");
        gotoxy(40-3, 0);cout << "=====================================";
        gotoxy(50, 1);cout << " BENGKEL 1.0";
        gotoxy(40-3, 2);cout << "=====================================";
        cout << "\n\n 1. Informasi Barang Bengkel" << endl;
        cout << " 2. Penjualan Barang" << endl;
        cout << " 3. Mekanik" << endl;
        cout << " 4. Service Kendaraan" << endl;
        cout << " 5. Laporan" << endl;
        cout << " 6. Exit" << endl;
        cout << "\n Pilihan : ";
        cin >> pilih;
        switch(pilih)
        {
        case 1:
            system("cls");
            int pilBarang;
            cout << endl;
            gotoxy(40-3, 0);cout << "=====================================";
	        gotoxy(50-7, 1);cout << " INFORMASI BARANG BENGKEL ";
	        gotoxy(40-3, 2);cout << "=====================================";
            cout << "\n 1. Input Barang" << endl;
            cout << " 2. Lihat Barang" << endl;
            cout << " 3. Cari Barang" << endl;
            cout << " 4. Kembali" << endl;
            cout << "\n Pilihan : ";
            cin >> pilBarang;
            switch(pilBarang)
            {
            case 1:
                cout << endl;
                inputbarang();
                break;
            case 2:
                cout << endl;
                tampilbarang();
                break;
            case 3:
                cout << endl;
                tampilbarang();
                cout << endl;
                tampilsearching();
                break;
            case 4:
                goto menu_utama;
                break;
            default:
                cout << " Pastikan input sesuai pilihan !" << endl;
                break;
            }
            break;
        case 2:
            system("cls");
            cout << endl;
            jual_barang();
            break;
        case 3:
            system("cls");
            int pilmekanik;
            gotoxy(40-3, 0);cout << "=====================================";
            gotoxy(48, 1);cout << " MEKANIK BENGKEL" << endl;
            gotoxy(40-3, 2);cout << "=====================================";
            cout << "\n 1. Penambahan mekanik" << endl;
            cout << " 2. Data Mekanik" << endl;
            cout << " 3. Cari Mekanik" << endl;
            cout << " 4. Kembali" << endl;
            cout << "\n Pilihan : ";
            cin >> pilmekanik;
            switch(pilmekanik)
            {
            case 1:
                system("cls");
                cout << endl;
                input_mekanik();
                break;
            case 2:
                cout << endl;
                tampil_mekanik();
                break;
            case 3:
                cout << endl;
                cari_mekanik();
                break;
            case 4:
                goto menu_utama;
                break;
            default:
                cout << " Pastikan input sesuai pilihan !" << endl;
                break;
            }
            break;
        case 4:
            system("cls");
            int pilservice;
            gotoxy(40-3, 0);cout << "=====================================";
            gotoxy(50-3, 1);cout << " SERVICE KENDARAAN ";
            gotoxy(40-3, 2);cout << "=====================================";
            cout << "\n\n 1. Masukkan Kendaraan" << endl;
            cout << " 2. Bayar Service" << endl;
            cout << " 3. Tampil Antrian Service" << endl;
            cout << " 4. Reset Antrian Service" << endl;
            cout << " 5. Kembali" << endl;
            cout << "\n Pilihan : ";
            cin >> pilservice;
            switch(pilservice)
            {
            case 1:
                system("cls");
                masukkan_kendaraan();
                break;
            case 2:
                cout << endl;
                dequeue();
                break;
            case 3:
                cout << endl;
                display();
                break;
            case 4:
                cout << endl;
                clear();
                break;
            case 5:
                goto menu_utama;
                break;
            default:
                cout << " Pastikan input sesuai pilihan !" << endl;
                break;
            }
            break;
        case 5:
            system("cls");
            int pillaporan;
            gotoxy(40-3, 0);cout << "=====================================";
            gotoxy(50-3, 1);cout << "      LAPORAN ";
            gotoxy(40-3, 2);cout << "=====================================";
            cout << "\n\n 1. Laporan Penjualan Barang" << endl;
            cout << " 2. Laporan Service" << endl;
            cout << " 3. Kembali" << endl;
            cout << "\n Pilihan : ";
            cin >> pilservice;
            switch(pilservice)
            {
            case 1:
                system("cls");
                displayStack();
                break;
            case 2:
                system("cls");
                displayStackService();
                break;
            case 3:
                goto menu_utama;
                break;
            default:
                cout << " Pastikan input sesuai pilihan !" << endl;
                break;
            }
            break;
        case 6:
        	system("cls");
        	cout << "\t\t\tANDA TELAH KELUAR DARI PROGRAM" <<endl;
        	cout << "\tAPLIKASI INI TIDAK TERHUBUNG KE DATABASE DALAM BENTUK LOKAL/CLOUD FILE" << endl;
        	cout << "\t\tMAKA JIKA ANDA KELUAR DARI PROGRAM, DATA AKAN HILANG" << endl;
        	cout << "\t\t\tTERIMAKASIH :)"<<endl;
        	break;
        default :
        	system("cls");
        	cout << "\n\t\t  ANDA MENGINPUTKAN MENU YANG SALAH, SILAKAN ULANG KEMBALI " << endl;
        	break;
        }

        cout << endl;
        system("pause");


	} while(pilih != 6);

    return 0;
}
