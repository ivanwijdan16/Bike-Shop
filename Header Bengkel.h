#ifndef HEADER_BENGKEL_H_INCLUDED
#define HEADER_BENGKEL_H_INCLUDED

using namespace std;

//VARIABEL GLOBAL
int i, j; // PERULANGAN
int x; //PERHITUNGAN GOTOXY
int barang = -1; //POSISI BARANG

int y = 0; //MENGECEK PENGISIAN

int jual = -1;

COORD coord = {0,0}; //GOTOXY VOID

int bayar, total_bayar = 0, kembalian;

int totalhrg, kembalian_service, bayar_service;
string nama_pemilik, kendaraan, paket;
int nomor = 0;

string nama_mekanik;

// DEKLARASI

// STRUCT BARANG
struct dataBarang
{
    string nama;
    string kode;

    int jumlah;
    int harga;
    int jumlhbrg;
    int totalharga;
    string masukan;

}data[100];

// STRUCT ANTRIAN
struct antrian
{
       int nomor;
       string nama_pemilik;
       string kendaraan;
       string paket;
       int byr;
       antrian *next;
};
antrian *head, *tail, *baru, *bantu, *hapus;

// STRUCT MEKANIK
struct Mekanik
{
    string nama;

    Mekanik *next_mekanik;
    Mekanik *prev_mekanik;
};
Mekanik *head_mekanik, *tail_mekanik, *baru_mekanik, *bantu_mekanik, *temp;

// STRUCT LAPORAN PENJUALAN
struct Laporan
{
    string pembeli_laporan;
    int jumlhbrg_laporan;
    int totalharga_laporan;
    string masukan_laporan;
    Laporan *link;
};
Laporan *top = NULL;

// STRUCT LAPORAN SERVICE
struct LaporanService
{
    string nama_pemiliklaporanservice;
    string kendaraanlaporanservice;
    string paket_laporanservice;
    int byr_laporanservice;
    LaporanService *link_service;
};
LaporanService *top_service = NULL;

void gotoxy(int x,int y) //PROSEDUR YANG DIGUNAKAN UNTUK MENGATUR TAMPILAN DI TERMINAL/CMD PROMPT.
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

#endif // HEADER_BENGKEL_H_INCLUDED
