#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

string barang[] = {"Kaos", "Jaket", "Topi", "Hoodie", "Celana"};
int harga[] = {100000, 200000, 80000, 150000, 120000};
int stok[] = {50, 30, 20, 15, 25};
int pesanan[] = {0, 0, 0, 0, 0};

void menu(){
    cout<<endl;
    cout << "|| Menu Toko Distro ||" << endl;
    cout << "1. Memesan Barang" << endl;
    cout << "2. Pembatalan Pemesanan" << endl;
    cout << "3. Pembayaran" << endl;
    cout << "4. Cek Stok Barang" << endl;
    cout << "5. Keluar Program" << endl;
    cout << "Pilih menu: ";
}

void logins(){
    int pw;
    char login;
    string nama,password;
    do{
        password.clear(); 
        cout<<"+===================================+"<<endl;
        cout<<"+            LOGIN AKUN             +"<<endl;
        cout<<"+===================================+"<<endl;
        if (login == 'y') {
            cin.ignore(); 
        }
        cout << "Username : ";
        getline(cin,nama); 
        cout << "Password : ";
        while (true) {
            pw = getch();
            if(pw == 13){ 
                break;
            }else if(pw == 8){  
                if(!password.empty()){
                    password.pop_back();       
                    cout << "\b \b";           
                }
            }else{           
                password.push_back(pw);
                cout << '*';
            }
        }
        if((nama == "Alvin" && password == "123240193" || nama =="Rihal" && password == "123240181" || nama == "Kafka" && password == "123240203" || nama == "Zaky" && password == "123240222" || nama == "Adwa" && password == "123240187")){
            cout<<endl;
            cout<<"SELAMAT ANDA BERHASIL LOGIN "<<endl;
            break; 
        }else{
            cout << endl;
            cout<<"SILAHKAN ULANGI DAN MASUKAN PASSWORD ATAU USERNAME ANDA DENGAN BENAR! :";
            cin >> login;
        }
    }while(login == 'y');
}

void pemesanan(){
    int pilihan, jumlah;
    cout<<endl;
    cout <<setfill(' ')<<setw(28)<<"|| Daftar Barang ||" <<setw(28)<<endl;
    cout<<left <<setfill(' ')<<setw(3)<<"No"<<setw(20)<<"Nama Barang "<<setw(10)<<"Harga Barang"<<endl;
    for(int i = 0; i < 5; i++){
        cout<<left<<setfill(' ')<<setw(3)<<i+1<<setw(20)<<barang[i]<<setw(10)<<harga[i]<<endl;
    }

    cout << "Pilih nomor barang yang ingin dipesan: ";
    cin >> pilihan;
    cout << "Masukkan jumlah yang ingin dipesan: ";
    cin >> jumlah;
    
    if(pilihan > 0 && pilihan <= 5 && stok[pilihan - 1] >= jumlah){
        stok[pilihan - 1] -= jumlah;
        pesanan[pilihan - 1] += jumlah;
        cout << jumlah << " " << barang[pilihan - 1] << " berhasil dipesan." << endl << endl;
        cout << "Ingin kembali ke menu utama? (y/n) : ";
    }else{
        cout << "Stok tidak mencukupi atau pilihan tidak valid." << endl << endl;
        cout << "Ingin kembali ke menu utama? (y/n) : ";
    }
}

void pembatalan(){
    int produkbatal,stokbatal;

    cout <<setfill(' ')<<setw(28)<<"|| Pembatalan Barang ||" <<setw(28)<<endl;
    cout<<left <<setfill(' ')<<setw(3)<<"No"<<setw(20)<<"Nama Barang "<<setw(25)<<"Jumlah Pesanan"<<endl;  
    for(int i = 0; i < 5; i++){
        if(pesanan[i]>0){
        cout<<left<<setfill(' ')<<setw(3)<<i+1<<setw(20)<<barang[i]<<setw(25)<<pesanan[i]<<endl;
        }
    }
    if(pesanan[0] == 0  && pesanan[1] == 0  && pesanan[2] == 0  && pesanan[3] == 0  && pesanan[4] == 0){     
      
        cout << endl;
        cout<< "Anda belum memesan barang" <<endl;
        cout << "Silahkan memesan terlebih dahulu" << endl;
    }else{
        cout<<"Masukkan Nomor Produk Yang Ingin Dibatalkan : ";
        cin>>produkbatal;
        cout<<"Masukkan Jumlah Stok Yang Ingin Dibatalkan : ";
        cin>>stokbatal;
        if(pesanan[produkbatal - 1] < stokbatal){
        cout<<"JUMLAH PEMBATALAN LEBIH DARI PEMESANAN!"<<endl;
        }
        else{
            if(produkbatal > 0 && produkbatal <= 5 && stok[produkbatal - 1] >= stokbatal){
                stok[produkbatal - 1] += stokbatal;
                pesanan[produkbatal - 1] -= stokbatal;
            }
        }
    }
    cout << "Ingin kembali ke menu utama? (y/n) : ";
    
}


void cekStok(){
    cout <<setfill(' ')<<setw(25)<<"|| Cek Stok Barang ||" <<setw(20)<<endl;
    cout<<left <<setfill(' ')<<setw(3)<<"No"<<setw(20)<<"Nama Barang "<<setw(10)<<"Stok"<<endl;
    for(int i = 0; i < 5; i++){
        cout<<left<<setfill(' ')<<setw(3)<<i+1<<setw(20)<<barang[i]<<setw(10)<<stok[i]<<endl;
    }
    cout << endl;
    cout << "Ingin kembali ke menu utama? (y/n) : ";
}

void pembayaran(){
    int total = 0,harga_setelahdiskon,diskon;
    char promo;
    string kode;
    cout <<setfill(' ')<<setw(28)<<"|| Struk Pembayaran ||" <<setw(28)<<endl;
    cout<<left <<setfill(' ')<<setw(3)<<"No"<<setw(20)<<"Nama Barang "<<setw(25)<<"Jumlah Pesanan"<<setw(10)<<"Harga Barang"<<endl;
    for(int i = 0; i < 5; i++){
        if(pesanan[i] > 0){
            cout<<left<<setfill(' ')<<setw(3)<<i+1<<setw(20)<<barang[i]<<setw(25)<<pesanan[i]<<setw(10)<<harga[i]<<endl;
            total += pesanan[i]*harga[i]; 
        }    
    } 
    if(pesanan[0] > 0 || pesanan[1] > 0 || pesanan[2] > 0 || pesanan[3] > 0 || pesanan[4] > 0 ){
        cout <<"Apakah anda memiliki kode promo (y/n): "; 
        cin >> promo;
        if (promo=='y' || promo =='Y') {
            cout << "masukan kode \t: ";
            cin >> kode;
            if (kode == "KEL8"){
                diskon = 0.15 * total;
                cout << "\nDiskon \t\t: Rp " << diskon;
                harga_setelahdiskon = total - diskon;
                total = harga_setelahdiskon;
            }else {
                cout << "Maaf kode promo salah" << endl;
            }
        }
        for(int i = 0; i < 5; i++){
            pesanan[i] = 0;
        }
    }
     

    cout<<"\nTotal Pembayaran : Rp "<<total<<endl;
    if(total == 0){
        for(int j = 0; j < 1; j++){
            if(pesanan[j] == 0){
                cout<<endl;
                cout<<"Keranjang Anda Masih Kosong Yuk Kembali Isikan Keranjang Anda"<<endl;
            }
        }
    }
    
    cout << "Ingin kembali ke menu utama? (y/n) : ";
}

void keluar(){
    cout << "TERIMAKASIH SUDAH BERBELANJA"<<endl;
    exit(0);
}


int main(){
    char kembaliMenu;
    int pilihan;
    logins();
    cout << "\033c";
    do{
        menu();
        cin >> pilihan;
        cout<<endl;
        switch(pilihan){
            case 1:
                pemesanan();
                cin >> kembaliMenu;
                cout << "\033c";
                break;
            case 2 :
                pembatalan(); 
                cin >> kembaliMenu;
                cout << "\033c";
                break;
            case 3 :
                pembayaran();
                cin>> kembaliMenu;
                cout << "\033c";
                break;
            case 4 :
                cekStok(); 
                cin >> kembaliMenu;
                cout << "\033c";
                break;
            case 5 :
                keluar();
                cout << "\033c";
                break;
            default :
                cout << "ERROR MENU TIDAK TERSEDIA!!!" << endl;
                kembaliMenu == 'y';
                cout << "\033c";
                break;
        }
    }while(kembaliMenu == 'y' || kembaliMenu == 'Y'); 
}