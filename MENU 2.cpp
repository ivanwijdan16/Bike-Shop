#include "Header Bengkel.h"

/// LAPORAN PENJUALAN BARANG

int isEmpty_laporan()
{
    if(top == NULL)
        return 1;
    else
        return 0;
}

//Insert Data (Push)
void push (string masukan_laporan, int jumlhbrg_laporan, int totalharga_laporan)
{
    Laporan *ptr = new Laporan();
    ptr->masukan_laporan = masukan_laporan;
    ptr->jumlhbrg_laporan = jumlhbrg_laporan;
    ptr->totalharga_laporan = totalharga_laporan;
    ptr->link = top;
    top = ptr;
}


//Tampilkan Stack
void displayStack()
{
     if (isEmpty_laporan() == 1)
        cout << " Stack masih kosong!" << endl;
     else
     {
        Laporan *temp_laporan = top;
        cout << "\n==============================================================================";
        gotoxy(50-3,2);cout << " LAPORAN PENJUALAN BARANG";
        cout << "\n=============================================================================="<<endl;
        cout << "\n Nama Barang\tJumlah\tTotal Harga" << endl;
        while(temp_laporan != NULL){
            cout << endl;
            cout << " " << temp_laporan->masukan_laporan << "\t\t" << temp_laporan->jumlhbrg_laporan << "\t" << temp_laporan->totalharga_laporan << endl;
            temp_laporan = temp_laporan->link;
        }
        cout << endl;
     }
 }
