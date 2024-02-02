#include "Header Bengkel.h"

/// MENU SERVICE KENDARAAN

// MENGHITUNG JUMLAH ANTRIAN
int hitungAntrian()
{
    if(head == NULL){
        return 0;
    }
    else{
        int counter = 0;
        bantu = head;
        while(bantu != NULL){
            counter++;
            bantu = bantu -> next;
        }
        return counter;
    }
}

// MENGECEK ANTRIAN
bool isEmpty()
{
    if(hitungAntrian() == 0){
        return true;
    }
    else {
        return false;
    }
}

// MENAMBAHKAN DATA ANTRIAN
void enqueue(int nomor, string nama_pemilik, string kendaraan, string paket, int byr)
{
    if(isEmpty()){
        head = new antrian();
        head->nomor = nomor;
        head->nama_pemilik = nama_pemilik;
        head->kendaraan = kendaraan;
        head->paket = paket;
        head->byr = byr;
        head -> next = NULL;
        tail = head;
        cout << "\n Berhasil menambahkan antrian servis baru" << endl;
    }
    else{
        baru = new antrian();
        baru->nomor = nomor;
        baru->nama_pemilik = nama_pemilik;
        baru->kendaraan = kendaraan;
        baru->paket = paket;
        baru->byr = byr;
        baru -> next = NULL;
        tail -> next = baru;
        tail = baru;
        cout << "\n Berhasil menambahkan antrian servis selanjutnya" << endl;
    }
}

// MENGAMBIL DATA ANTRIAN
void dequeue()
{
    int jasa = 25000;
    if(isEmpty()){
        cout << " Antrian kosong" << endl;
    }
    else{
    	system("cls");
        bantu = head;
        while(bantu != NULL){
        gotoxy(40-3, 1);cout << "=====================================";
        gotoxy(50-3,2);cout << " -RILIS ANTRIAN-" << endl;
        gotoxy(40-3, 3);cout << "====================================="<<endl;
        cout << " \n\n Nama Pemilik\t\t: " << bantu->nama_pemilik << endl;
        cout << " Kendaraan\t\t: " << bantu->kendaraan << endl;
        cout << " Paket\t\t        :" << bantu->paket << endl;
        cout << " Harga\t\t        : " << bantu->byr << endl;
        cout << " Harga Jasa\t\t: " << jasa << endl;
        totalhrg = bantu->byr + jasa;
        cout << " Total\t\t        : " << totalhrg << endl;
        cout << endl;
        vice:
        cout << "\n==============================================================================";
        cout << " \n\n Bayar\t\t\t: ";
        cin >> bayar_service;

        if(bayar_service < totalhrg)
        {
            cout << " \n Uang Kurang" << endl;
            goto vice;
        }
        else if (bayar_service > totalhrg)
        {
            kembalian_service = bayar_service - totalhrg;
            cout << " Kembalian\t\t: " << kembalian_service;
            cout << "\n\n==============================================================================";
			cout << "\n\t\t\t TERIMAKASIH";
            cout << "\n=============================================================================="<<endl;
            break;
        }
        else
        {
            cout << "\n\n==============================================================================";
            cout << "\n\t\t\t TERIMAKASIH";
            cout << "\n=============================================================================="<<endl;
            break;
        }
        }
        push_service(head->nama_pemilik, head->kendaraan, head->paket, totalhrg);
        hapus = head;
        head = head -> next;
        hapus -> next = NULL;
        delete hapus;
        cout << endl;
    }
}

// MENAMPILKAN ANTRIAN
void display()
{
	system("cls");
	gotoxy(40-3, 0);cout << "=====================================";
    gotoxy(50,1);cout << " Data Antrian" << endl;
    gotoxy(40-3, 2);cout << "====================================="<<endl;
    if(isEmpty()){
        cout << " Antrian kosong" << endl;
    }
    else{
        cout << " Jumlah antrian: " << hitungAntrian() << endl;
        bantu = head;
        cout << "\n Nomor Antrian\tNama Pemilik Kendaraan\tJenis Paket\tHarga" << endl;
        while(bantu != NULL){
            cout << " " << bantu->nomor << "\t\t" << bantu->nama_pemilik << "\t\t\t" << bantu->kendaraan << "\t\t" << bantu->paket << "\t\t" << bantu->byr << endl;
            bantu = bantu -> next;
        }
    }
    cout << endl;
}

// MENGHAPUS SELURUH ANTRIAN
void clear()
{
    if(isEmpty()){
        cout << " Antrian servis kosong " << endl;
    }
    else{
        head -> next = NULL;
        head = NULL;
        cout << " Menghapus seluruh Antrian Servis" << endl;

        bantu = head;
        while(bantu != NULL){
            hapus = bantu;
            bantu = bantu -> next;

            //menghapus node
            hapus -> next = NULL;
            delete hapus;
        }
        head = NULL;
    }
}

// MASUKAN DATA KENDARAAN
void masukkan_kendaraan()
{
            int pil2;
            int byr;
            ser:
            system("cls");
            gotoxy(40-3, 0);cout << "=====================================";
            gotoxy(50,1);cout<< " PAKET SERVIS ";
            gotoxy(40-3, 2);cout << "====================================="<<endl;
            cout << "\n 1. Servis Ringan    Rp. 75.000" << endl;
            cout << " 2. Servis Lengkap   Rp. 125.000" << endl;
            cout << "\n Pilih : ";
            cin >> pil2;
            switch (pil2){
            case 1:
                nomor++;
                cout << "\n Antrian Nomor : " << nomor  <<  endl;
                cout << "\n Nama Pemilik  : ";
                cin.ignore();
                getline(cin, nama_pemilik);
                cout << " Kendaraan       : ";
                getline(cin, kendaraan);
                byr = 75000;
                paket = "Servis Ringan";
                enqueue(nomor, nama_pemilik, kendaraan, paket, byr);
                break;
            case 2:
                nomor++;
                cout << "\n Antrian Nomor : " << nomor  << endl;
                cout << "\n Nama Pemilik  : ";
                cin.ignore();
                getline(cin, nama_pemilik);
                cout << " Kendaraan       : ";
                getline(cin, kendaraan);
                byr = 125000;
                paket = "Servis Lengkap";
                enqueue(nomor, nama_pemilik, kendaraan, paket, byr);
                break;
            default:
                cout << " Masukkan Piihan yang benar" << endl;
                break;
            }
}
