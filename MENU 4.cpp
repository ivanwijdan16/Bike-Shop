#include "Header Bengkel.h"

/// LAPORAN SERVICE KENDARAAN

// ISEMPTY
int isEmpty_laporanservice()
{
    if(top_service == NULL)
        return 1;
    else
        return 0;
}

//MASUKAN PUSH DATA
void push_service(string nama_pemiliklaporanservice, string kendaraanlaporanservice, string paket_laporanservice, int byr_laporanservice)
{
    LaporanService *ptr_service = new LaporanService();
    ptr_service->nama_pemiliklaporanservice = nama_pemiliklaporanservice;
    ptr_service->kendaraanlaporanservice = kendaraanlaporanservice;
    ptr_service->paket_laporanservice = paket_laporanservice;
    ptr_service->byr_laporanservice = byr_laporanservice;
    ptr_service->link_service = top_service;
    top_service = ptr_service;
}


//MENAMPILKAN DATA SERVICE
void displayStackService()
{
     if (isEmpty_laporanservice() == 1)
        cout << " Laporan masih kosong!" << endl;
     else
     {
        LaporanService *temp_laporanservice = top_service;
        cout << "\n==============================================================================";
        gotoxy(50-3,2);cout << " LAPORAN SERVICE";
        cout << "\n=============================================================================="<<endl;
        cout << "\n Nama Pemilik\tKendaraan\tJenis Paket\t\tHarga" << endl;
        while(temp_laporanservice != NULL){
            cout << endl;
            cout << " " << temp_laporanservice->nama_pemiliklaporanservice << "\t\t" << temp_laporanservice->kendaraanlaporanservice << "\t\t" << temp_laporanservice->paket_laporanservice << "\t\t" << temp_laporanservice->byr_laporanservice << endl;
            temp_laporanservice = temp_laporanservice->link_service;
        }
        cout << endl;
     }
 }
