#include <iostream>
#include <iomanip>
using namespace std;

void menu_utama(int &pilihan);
void tambah_book(string jdl_bk[], string pngr[], int thntbt[], int &data);
void liat_dafbook(string jdl_bk[], string pngr[], int thntbt[], int data);
void hapus_book(string jdl_bk[], string pngr[], int thntbt[], int data);
void find_book(string jdl_bk[], string pngr[], int thntbt[],int data);
void sort_book(string jdl_bk[], string pngr[], int thntbt[],int data);

int main(){
    int pilihan ;
    bool ngulang;
    char balik; int max = 100;
    string nama, nim, jdl_bk[max], pngr[max]; int thntbt[max];
    int  coba = 0, kesempatan = 2, data = 0;
    
    do{ 
        system("cls");
        cout << "=== Login ===\n";
        cout << "Username : ";
        cin >> nama;
        cout << "Password (3 digit terakhir nim anda) : ";
        cin >> nim;
        if(nama == "ryan" && nim == "067"){
            cout << "Login berhasil !!\n";
            ngulang = false;
        } else if (nama != "ryan" || nim != "067"){
            cout << "Login gagal.";
            cout << "Sisa kesempatan " << kesempatan << endl;
            ngulang = true; 
            coba++;
        }
        kesempatan--;
        system("pause");
        if(coba > 2){
            cout << "Coba kembali nanti";
            return 0;
        }
    } while (ngulang);
    do{
        menu_utama(pilihan);
        switch(pilihan){
            case 1 :
            tambah_book(jdl_bk,pngr,thntbt,data);
            break;
            case 2 :
            liat_dafbook(jdl_bk,pngr,thntbt,data);
            break;
            case 3 :
            hapus_book(jdl_bk,pngr,thntbt,data);
            break;
            case 4 :
            find_book(jdl_bk,pngr,thntbt,data);
            break;
            case 5 :
            sort_book(jdl_bk,pngr,thntbt,data);
            break;
            case 6 :
            cout << "Terimakasih sudah berkunjung.\n";
            system("exit");
            break;
            default :
            cout << "Pilihan tidak valid\n";
            cout << "Mohon masukkan pilihan yang benar(1-6)\n";
        }
        if(pilihan == 6){
            ngulang = false;
        } else {
            cout << "\nApakah anda ingin kembali ke menu utama?(y/n) :";
            cin >> balik;
            if(balik == 'y'){
                ngulang = true;
            } else {
                ngulang = false;
            }
        }
    } while (ngulang);
    return 0;
}

void menu_utama(int &pilihan){
    system("cls");
    cout << "==== Menu Utama ====\n";
    cout << "1. Tambah Buku\n";
    cout << "2. Liat Daftar Buku\n";
    cout << "3. Hapus Buku\n";
    cout << "4. Cari Buku\n";
    cout << "5. Urut Buku\n";
    cout << "6. Keluar\n";
    cout << "Pilihan(1-6) : ";
    cin >> pilihan;
}

void tambah_book(string jdl_bk[], string pngr[], int thntbt[], int &data){
    int tambah;
    cout << "\n===+ Tambah Buku +===\n";
    cout << "Mau menambahkan berapa buku? : ";
    cin >> tambah;
    cin.ignore();
    for(int i = 0; i < tambah; i++){
        cout << endl << "Buku " << i + 1 << endl;
        cout << "Judul Buku : ";
        getline(cin, jdl_bk[data]);
        cout << "Pengarang : ";
        getline(cin, pngr[data]);
        cout << "Tahun Terbit : ";
        cin >> thntbt[data];
        cin.ignore();
        data++; 
    }
    cout << "Buku berhasi ditambahkan";
}

void liat_dafbook(string jdl_bk[], string pngr[], int thntbt[], int data){
    cout << "\n===+ Daftar Buku +===\n";
    cout << setfill('=') << setw(100) << "=" << endl;
    cout << setfill(' ') << setw(5) << left << "No"
         << setw(30) << left << "Judul Buku"
         << setw(30) << left << "Pengarang"
         << setw(15) << left << "Tahun Terbit" << endl;
    cout << setfill('-') << setw(100) << "-" << endl;
    for(int j = 0; j < data; j++){
        cout << setfill(' ') << setw(5) << j + 1
        //cout << endl << "Buku " << j + 1 << endl;
        << setw(30) << left << jdl_bk[j]
        << setw(30) << left << pngr[j]
        << setw(15) << left << thntbt[j] << endl;
    }
}

void find_book(string jdl_bk[], string pngr[], int thntbt[], int data){
    string judul;
    int cek;
    cout << "\n===+ Find Book +===\n";
    cout << "Judul buku yang ingin dicari : ";
    cin >> judul;
    cout << endl;
    for(int i = 0; i < data; i++){
        if(jdl_bk[i] == judul){
            cek = 1;
        }
    }
    if(cek == 1){
        for(int j = 0; j < data; j++)
        if(jdl_bk[j] == judul){
            cout << "Judul Buku : " << jdl_bk[j] << endl;
            cout << "Pengarang : " << pngr[j] << endl;
            cout << "Tahun Terbit : " << thntbt[j] << endl; 

        } 
    } else {
        cout << "Buku tidak ada dalam daftar\n";
    }
}

void sort_book(string jdl_bk[], string pngr[], int thntbt[], int data){
    int ram;
    cout << "\n===+ Mengurutkan Buku Berdasarkan Tahun Terbit +===\n";
    for(int i = 1; i < data; i++){
        for(int j = 0; j < data - i; j++){
            if(thntbt[j] > thntbt [j + 1]){
                ram = thntbt[j];
                thntbt[j] = thntbt[j + 1];
                thntbt[j + 1] = ram;
            }            
        }
    }
    for(int v = 0; v < data; v++){
        cout << endl << "Buku " << v + 1 << endl;
        cout << "Judul Buku : " << jdl_bk[v] << endl;
        cout << "Pengarang : " << pngr[v] << endl;
        cout << "Tahun Terbit : " << thntbt[v] << endl;
    }
}

void hapus_book(string jdl_bk[], string pngr[], int thntbt[], int data){
    int nomer;
    cout << "\n===+ Hapus Buku +===\n";
    liat_dafbook(jdl_bk,pngr,thntbt,data);
    cout << "Masukkan nomer buku yang ingin dihapus : ";
    cin >> nomer;
    data = data - 1;
    for(int i = nomer - 1; i < data; i++){
        jdl_bk[i] = jdl_bk[i+1];
        pngr[i] = pngr[i+1];
        thntbt[i] = thntbt[i+1];
    }
    liat_dafbook(jdl_bk,pngr,thntbt,data);
}