#include "Header Bengkel.h"

// INISIALISASI NODE
void init_Mekanik()
{
    head_mekanik = NULL;
    tail_mekanik = head_mekanik;
}

//isEmpty
int isEmpty_Mekanik()
{
    if (head_mekanik == NULL && tail_mekanik == NULL)
        return 1; //true
    else
        return 0; //false
}

// MENGHITUNG DATA MEKANIK
int hitungMekanik()
{
    if(head_mekanik == NULL){
        return 0;
    }
    else{
        int counter_mekanik = 0;
        bantu_mekanik = head_mekanik;
        while(bantu_mekanik != NULL){
            counter_mekanik++;
            bantu_mekanik = bantu_mekanik -> next_mekanik;
        }
        return counter_mekanik;
    }
}

// BUAT NODE BARU
void create(string nama)
{
    baru_mekanik = new Mekanik;
    baru_mekanik -> nama = nama;
    baru_mekanik -> next_mekanik = NULL;
    baru_mekanik -> prev_mekanik = NULL;
}

// MENAMBAHKAN NODE DATA MEKANIK
void tambah_mekanik(string nama)
{
    create(nama);

    if (isEmpty_Mekanik() == 1){
        head_mekanik = baru_mekanik;
        tail_mekanik = head_mekanik;
        head_mekanik -> prev_mekanik = tail_mekanik;
        tail_mekanik -> next_mekanik = head_mekanik;
    }
    else{
        baru_mekanik -> prev_mekanik = tail_mekanik;
        tail_mekanik -> next_mekanik = baru_mekanik;
        tail_mekanik = baru_mekanik;
        tail_mekanik -> next_mekanik = head_mekanik;
        head_mekanik -> prev_mekanik = tail_mekanik;
    }
}

// MENAMBAHKAN DATA MEKANIK
void input_mekanik()
{
	gotoxy(40-3, 1);cout << "=====================================";
	gotoxy(50,2);cout << "INPUT DATA MEKANIK" << endl;
	gotoxy(40-3, 3);cout << "====================================="<<endl;
    cout << " \n Masukkan Nama Mekanik  : ";
    cin.ignore();
    getline(cin, nama_mekanik);
    tambah_mekanik(nama_mekanik);
    cout << "\n Mekanik Berhasil di Tambahkan\n " << endl;

}

// MENAMPILKAN MEKANIK
void tampil_mekanik()
{
    i = 1;
    cout << endl;
    if (isEmpty_Mekanik() == 0){
        bantu_mekanik = head_mekanik;
        cout << " No." << "\tNama " << endl;
        do{
            cout << " " << i++ << "\t" << bantu_mekanik -> nama << endl;
            bantu_mekanik = bantu_mekanik -> next_mekanik;
        }while (bantu_mekanik != head_mekanik);
        cout << endl;
    }
    else{
        cout << " Data mekanik tidak ada!" << endl;
    }
}

// PENCARIAN MEKANIK
void Search_mekanik(string nama){

    Mekanik* temp_mekanik = head_mekanik;

    int ketemu = 0;
    int i = 0;

    if(temp_mekanik != NULL) {
        while(true) {
          i++;
          if(temp_mekanik -> nama == nama) {
            ketemu++;
            break;
          }
          temp_mekanik = temp_mekanik -> next_mekanik;
          if(temp_mekanik == head_mekanik){
            break;
          }
        }
        if (ketemu == 1) {
          cout << "\n Mekanik " << nama <<" ditemukan pada urutan ke = " << i << "\n";
        }
        else {
        cout << "\n Mekanik " << nama << " tidak ditemukan di list\n";
        }
    }
    else {
    cout << " Data mekanik tidak ada! \n";
    }
}

// INPUT PENCARIAN MEKANIK
void cari_mekanik()
{
    tampil_mekanik();
    cout << " \n Masukkan Nama Mekanik yang ingin dicari : ";
    cin.ignore();
    getline(cin, nama_mekanik);
    Search_mekanik(nama_mekanik);
}


