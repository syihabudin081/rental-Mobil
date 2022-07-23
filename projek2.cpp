#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>

using namespace std;
//deklarasi dtruk utk node
typedef struct biodata *typeptr;
typedef struct mobil *typeptr2;

struct biodata
{

    string nama;
    int nik;
    int hari;
    string mobil;
    int bayar;
    typeptr next;
};

struct mobil
{
    string nama;
    string id;
    typeptr2 next;
};

typeptr awal, akhir;
typeptr2 awal2, akhir2;

void newstack()
{
    typeptr list;
    list = new biodata();
    list = NULL;
    awal = list;
    akhir = list;
};

void stackmobil()
{

    typeptr2 list2;
    list2 = new mobil();
    list2 = NULL;
    awal2 = list2;
    akhir2 = list2;
}

void data_mobil(string id_mobil, string nama_mobil)
{

    typeptr2 MB;
    MB = new mobil();
    MB->nama = nama_mobil;
    MB->id = id_mobil;

    if (awal2 == NULL)
    {
        awal2 = MB;
        akhir2 = MB;
    }
    else
    {
        akhir2->next = MB;
    }
    akhir2 = MB;
    akhir2->next = NULL;
};

void pinjam(string nama, int nik, string mobil, int har, int tot)
{

    typeptr NB;
    NB = new biodata();
    NB->nama = nama;
    NB->nik = nik;
    NB->mobil = mobil;
    NB->hari = har;
    NB->bayar = tot;
    if (awal == NULL)
    {
        awal = NB;
        akhir = NB;
    }
    else
    {
        akhir->next = NB;
    }
    akhir = NB;
    akhir->next = NULL;
};

void hapus(string pilmob)
{

    typeptr2 hapus, bantu;
    if (awal2 == NULL)
    {
        cout << "Data tidak ditemukan \n";
    }
    else
    {
        if (awal2->id == pilmob)
        {
            hapus = awal2;
            awal2 = hapus->next;
            free(hapus);
        }
        else
        {
            bantu = awal2;
            while ((bantu->next->id != pilmob) && (bantu->next != NULL))
            {
                bantu = bantu->next;
            }
            hapus = bantu->next;
            if (hapus == akhir2)
            {
                akhir2 = bantu;
                akhir2->next = NULL;
            }
            else
            {
                bantu->next = hapus->next;
            }
            free(hapus);
        }
    }
}

void cetakstack()
{
    typeptr bantu;
    bantu = awal;
    cout<<"\t============================================================================================\n";
	cout<<"\t|        Nama              |           NIK            |  ID Mobil   |Lama Peminjaman(hari) |\n";
 	cout<<"\t============================================================================================\n";
    while (bantu != NULL)
    {	cout<<"\t| "<<setiosflags(ios::left)<<setw(25)<<bantu->nama<<"|";
  		cout<<" "<<setiosflags(ios::left)<<setw(25)<<bantu->nik<<"|";
  		cout<<" "<<setiosflags(ios::left)<<setw(12)<<bantu->mobil<<"|";
  		cout<<" "<<setiosflags(ios::left)<<setw(21)<<bantu->hari<<"|"<<endl;

        bantu = bantu->next;
    }
     	cout<<"\t============================================================================================\n";

}

void cetakstack2()
{
    typeptr2 bantu;
    bantu = awal2;
    cout<<"\t===================================\n";
	cout<<"\t|  ID  |        Nama Mobil        |\n";
 	cout<<"\t===================================\n";


    while (bantu != NULL)
    {	
    int i=0;
    cout<<"\t| "<<setiosflags(ios::left)<<setw(5)<<bantu->id<<"|";
  	cout<<" "<<setiosflags(ios::left)<<setw(25)<<bantu->nama<<"|"<<endl;
    bantu = bantu->next;
        
    }
	  cout<<"\t===================================\n";

};

void pengembalian(int nik_)
{   string kembali;
    typeptr hapus, bantu;
    if (awal == NULL)
    {
        cout << "\tData Tidak di Temukan \n";
    }
    else
    {
        if (awal->nik == nik_)
        {   kembali=awal->mobil;
            hapus = awal;
            awal = hapus->next;
            free(hapus);
        }
        else
        {
            bantu = awal;
            while ((bantu->next->nik != nik_) && (bantu->next != NULL))
            {
                bantu = bantu->next;
            }
            hapus = bantu->next;
            if (hapus == akhir)
            {
                akhir = bantu;
                akhir->next = NULL;
            }
            else
            {
                bantu->next = hapus->next;
            }
            kembali=hapus->mobil;
            free(hapus);
        }
    }
    if(kembali=="A1"){
         data_mobil(kembali,"AVANZA");
    }
    if(kembali=="A2"){
         data_mobil(kembali,"XENIA");
    }
    if(kembali=="A3"){
         data_mobil(kembali,"ALPHARD");
    }
    if(kembali=="A4"){
         data_mobil(kembali,"FORTUNER");
    }

   

}

int main()
{

    data_mobil("A1", "AVANZA");
    data_mobil("X2", "XENIA");
    data_mobil("A3", "ALPHARD");
    data_mobil("F4", "FORTUNER");

    newstack();
    
    char ulangi;
    int pil, nik, hari, bayar, total;
    string pilmobil;
    string nama;
    while (ulangi = 'y')
    {
    	system("cls");
		cout << "\t================================="<<endl;
        cout << "\t|\t---RENTAL MOBIL---\t|"<<endl;
        cout << "\t================================="<<endl;

        cout << "\t|\t1.Daftar Mobil\t\t|\n";
        cout << "\t|\t2.Pinjam Mobil\t\t|\n";
        cout << "\t|\t3.Daftar Peminjaman\t|\n";
        cout << "\t|\t4.Pengembalian Mobil\t|\n";
    	cout << "\t================================="<<endl;
		cout << "\t|\tPilih\t: ";
        cin >> pil;
        if (pil == 1)
        {
        	system("cls");
            cetakstack2();

            cout << "\n\tKembali ke Menu (y)? : ";
            cin >> ulangi;

            printf("\n");
        }
        if (pil == 2)
        {
        	system("cls");
 			cout << "\t===================================";
            cout << "\n\t|   --INPUT DATA PEMINJAM--	  |"<<endl;
            cout << "\t==================================="<<endl;

            cout << "\tNama \t: ";
            cin >> nama;
            cout << "\tNIK  \t: ";
            cin >> nik;
            system("cls");
            cetakstack2();
            cout << "\n\tPilih Mobil :";
            cin >> pilmobil;
            hapus(pilmobil);
            cout << "\tBerapa Lama (1 Hari = Rp. 300.000) : ";
            cin >> hari;
            total = hari * 300000;
            do
            {
                cout << "\tBayar " << total << " : ";
                cin >> bayar;

            } while (bayar < total);
            system("cls");
            cout << "\t=========================================================";
            cout << "\n\t|	--ANDA BERHASIL MELAKUKAN PEMINJAMAN MOBIL--	|"<<endl;
            cout << "\t========================================================="<<endl;
            pinjam(nama, nik, pilmobil, hari, total);
            cout << "\tKembali ke Menu Utama (y)? : ";
            cin >> ulangi;

            printf("\n");
        }

        if (pil == 3)
        {   
        	system("cls");
			cout<<"\n\t\t\t\t\t===DAFTAR PEMIINJAM MOBIL===\n";
            cetakstack();
            cout << "\n\tKembali ke Menu Utama (y)? : ";
            cin >> ulangi;

            printf("\n");
        }

        if (pil == 4)
        {
        	system("cls");
 			cout << "\t====================================";
            cout << "\n\t|	--PENGEMBALIAN MOBIL--	   |"<<endl;
            cout << "\t===================================="<<endl;
            cout << "\t!!! data peminjaman anda akan dihapus !!!\n";
            cout << "\tMasukkan NIK Anda : ";
            cin >> nik;
            
            pengembalian(nik);
             cout << "\n\tKembali Ke menu Utama (y)? : ";
            cin >> ulangi;

            printf("\n");
        }
    }
}
