#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <windows.h>

using namespace std;

struct data
{
	int kode;
	int jns_kendaraan;
	int tanggal;
	int jam;
	int menit;
	int detik;
};
data data_park[100];
data temp;
int jml_data = 0;

void gotoxy(int x, int y){
	COORD c = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void menu()
{
	system("CLS");
	cout<<"Menu\n";
	cout<<"================================\n";
	cout<<"1. Pembuatan Tiket\n";
	cout<<"2. Pembayaran\n";
	cout<<"3. Tampil Data Parkir\n";
	cout<<"4. Simpan Data Ke File\n";
	cout<<"5. Baca Data Dari File\n";
	cout<<"6. Keluar\n";
	cout<<endl;
}
void buat_tiket()
{
	time_t now = time(0); 
	tm *ltm = localtime(&now);
	int jam=ltm->tm_hour;
	int menit=ltm->tm_min;
	int detik=ltm->tm_sec;
	int tanggal=ltm->tm_mday;
	
	system("CLS");
	int jnsk;

	cout<<"Pilih Jenis Kendaraan\n";
	cout<<"1. Motor\n";
	cout<<"2. Mobil\n";
	cout<<"3. Truk\n";
	cout<<"Masukan Pilihan : ";cin>>jnsk;	//Memasukan Jenis Kendaran
	if(jnsk==1)		//Pengkondisian Untuk Jenis Kendaraan
	{
		if(jam<10) 	//Pengkondisian Untuk Jam Agar Mempunyai Format 01-24
		{
			if(menit<10)	//Pengkondisian Untuk Jam Agar Mempunyai Format 01-60
			{
				cout<<"Kode Parkir = "<<jml_data<<"0"<<jam<<"0"<<menit;
			}else
			{
				cout<<"Kode Parkir = "<<jml_data<<"0"<<jam<<menit;
			}
		}else
		{
			if(menit<10)
			{
				cout<<"Kode Parkir = "<<jml_data<<jam<<"0"<<menit;
			}else
			{
				cout<<"Kode Parkir = "<<jml_data<<jam<<menit;
			}
		}
		
	}
	else if(jnsk==2)
	{
		if(jam<10)
		{
			if(menit<10)
			{
				cout<<"Kode Parkir = "<<jml_data<<"0"<<jam<<"0"<<menit;
			}else
			{
				cout<<"Kode Parkir = "<<jml_data<<"0"<<jam<<menit;
			}
		}else
		{
			if(menit<10)
			{
				cout<<"Kode Parkir = "<<jml_data<<jam<<"0"<<menit;
			}else
			{
				cout<<"Kode Parkir = "<<jml_data<<jam<<menit;
			}
		}
	}else{
		if(jam<10)
		{
			if(menit<10)
			{
				cout<<"Kode Parkir = "<<jml_data<<"0"<<jam<<"0"<<menit;
			}else
			{
				cout<<"Kode Parkir = "<<jml_data<<"0"<<jam<<menit;
			}
		}else
		{
			if(menit<10)
			{
				cout<<"Kode Parkir = "<<jml_data<<jam<<"0"<<menit;
			}else
			{
				cout<<"Kode Parkir = "<<jml_data<<jam<<menit;
			}
		}
	}
	data_park[jml_data].kode = jml_data;
	data_park[jml_data].jns_kendaraan = jnsk;
	data_park[jml_data].tanggal = tanggal;
	data_park[jml_data].jam = jam;
	data_park[jml_data].menit = menit;
	data_park[jml_data].detik = detik;
	jml_data++;
	
	char ulangi;
	cout<<"\nTambah Lagi? (Y/N) : "; cin>>ulangi;
	if (ulangi == 'y' || ulangi == 'Y')
		buat_tiket();
}
int search(data a[], int jml, int target)
{
	for (int n = jml - 1; n > -2; n--)
		if (n == -1 || a[n].kode == target) return n;
}
void pembayaran()
{
	system("CLS");
	int index = 0;
	
	time_t now = time(0); 
	tm *ltm = localtime(&now); 
	int jam=ltm->tm_hour;
	int menit=ltm->tm_min;
	int detik=ltm->tm_sec;
	int duajam = (jam*3600)+(menit*60)+detik;
	
	string txt;
	int kode;
	cout<<"Masukan Kode Tiket : "; cin>>txt;
	if(txt.length() == 5){
		txt = txt.substr(0,1);
		stringstream sementara(txt);
		sementara >> kode;
	}else if(txt.length() == 6){
		txt = txt.substr(0,2);
		stringstream sementara(txt);
		sementara >> kode;
	}else{
		txt = txt.substr(0,3);
		stringstream sementara(txt);
		sementara >> kode;
	}
	
	index = search(data_park, jml_data, kode);
	if(data_park[index].jns_kendaraan == 1)
	{
		cout<<"Jenis Kendaraan : Motor\n";
	}else if(data_park[index].jns_kendaraan == 2)
	{
		cout<<"Jenis Kendaraan : Mobil\n";
	}else
	{
		cout<<"Jenis Kendaraan : Truk\n";
	}
	cout<<"Masuk Pada Tanggal : "<<data_park[index].tanggal<<endl;
	cout<<"Jam : "<<data_park[index].jam<<":"<<data_park[index].menit<<":"<<data_park[index].detik<<endl;
	int totaldetik = (data_park[index].jam*3600)+(data_park[index].menit*60)+data_park[index].detik;
	
	if(duajam - totaldetik >= 7200)
	{
		if(data_park[index].jns_kendaraan == 1)
		{
			cout<<"Biaya Parkir : Rp3500";
		}else if(data_park[index].jns_kendaraan == 2){
			cout<<"Biaya Parkir : Rp6000";
		}else{
			cout<<"Biaya Parkir : Rp8000";
		}
	}else{
		if(data_park[index].jns_kendaraan == 1)
		{
			cout<<"Biaya Parkir : Rp2000";
		}else if(data_park[index].jns_kendaraan == 2){
			cout<<"Biaya Parkir : Rp3500";
		}else{
			cout<<"Biaya Parkir : Rp5000";
		}
	}
	
}

int sorting()
{
	for(int i = 1; i < jml_data; i++){
		for(int j = jml_data - 1; j >= i; j--){
			if(data_park[j].kode > data_park[j-1].kode){
				temp = data_park[j];
				data_park[j] = data_park[j-1];
				data_park[j-1] = temp;
			}
		}
	}
}
void readfile()
{
	system("CLS");
	ifstream myfile("Data Parkir.txt");
	string line;
	if(myfile.is_open()){
		while(getline(myfile, line)){
			cout << line << "\n";
		}
		myfile.close();
	}else{
		cout << "Tidak Dapat Membaca File!\n";
	}
}
void savetofile()
{
	sorting();
	system("CLS");
	ofstream myfile("Data Parkir.txt");
	if(jml_data != 0 && myfile.is_open()){
		for(int i = 0; i < jml_data; i++){
			myfile << "Kode				: " << data_park[i].kode << "\n";
			myfile << "Jenis Kendaraan	: " << data_park[i].jns_kendaraan << "\n";
			myfile << "Tanggal			: " << data_park[i].tanggal << "\n";
			myfile << "Jam				: " << data_park[i].jam << "\n";
			myfile << "Menit			: " << data_park[i].menit << "\n";
			myfile << "Detik			: " << data_park[i].detik << "\n";
			myfile<<endl;
		}
		cout<<"Data Berhasil Disimpan";
	}else{
		cout<<"Data Gagal Disimpan";
	}
}
void tampil()
{
	system("CLS");
	
	sorting();
	cout<<"====================================================================================================================\n";
	cout<<"===========================================TAMPIL DATA PARKIR=======================================================\n";
	cout<<"====================================================================================================================\n";
	gotoxy(0,3); cout<<"|";
	gotoxy(2,3); cout<<"No.";
	gotoxy(6,3); cout<<"|";
	
	gotoxy(9,3); cout<<"JENIS KENDARAAN";
	gotoxy(25,3); cout<<"|";
	
	gotoxy(27,3); cout<<"TANGGAL";
	gotoxy(35,3); cout<<"|";
	
	gotoxy(37,3); cout<<"JAM";
	gotoxy(41,3); cout<<"|";
	
	gotoxy(42,3); cout<<"MENIT";
	gotoxy(48,3); cout<<"|";
	
	gotoxy(49,3); cout<<"DETIK";
	gotoxy(55,3); cout<<"|";
	
	
	int y = 4;
	for(int i = 0; i < jml_data; i++){
		gotoxy(0,y); cout<<"| "<<data_park[i].kode;
		gotoxy(6,y); cout<<"| "<<data_park[i].jns_kendaraan;
		gotoxy(25,y); cout<<"| "<<data_park[i].tanggal;
		gotoxy(35,y); cout<<"| "<<data_park[i].jam;
		gotoxy(41,y); cout<<"| "<<data_park[i].menit;
		gotoxy(48,y); cout<<"| "<<data_park[i].detik;
		y++;
	}
}
int main()
{
	int pilihMenu;
	char backToMenu = 'y';
	do{
		menu();
		cout<<endl<<"Pilih Menu (1-5) : "; cin>>pilihMenu;
		
		switch(pilihMenu)
		{
			case 1 : buat_tiket(); break;
			case 2 : pembayaran(); break;
			case 3 : tampil(); break;
			case 4 : savetofile(); break;
			case 5 : readfile(); break;
			case 6 : return 0; break;
			default : cout<<"\nPilihan Menu Tidak Ada!\n";
		}
		cout<<"\nKembali Ke Menu? (Y/N) : "; cin>>backToMenu;
	}while(backToMenu == 'y' || backToMenu == 'Y');
}

