#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int pil;
void pilih();
void buat_baru();
void tambah_depan();
void tambah_tengah();
void tambah_belakang();
void hapus_tengah();
void hapus_belakang();
void hapus_depan();
void tampil();

int simpan_total = 0;

struct node{
	char nama[20];
	int nim;
	char asal[30];
	node *prev, *next;
};

node *baru, *head=NULL, *tail=NULL, *hapus, *bantu, *bantu2;


int main(){
do{
system("cls");
cout<<"INPUT DATA MAHASISWA "<<endl;
cout<<"=========================\n";
cout<<"1. Penambahan Depan"<<endl;
cout<<"2. Penambahan Tengah"<<endl;
cout<<"3. Penambahan Belakang"<<endl;
cout<<"4. Hapus Depan"<<endl;
cout<<"5. Hapus tengah"<<endl;
cout<<"6. Hapus Belakang"<<endl;
cout<<"7. Tampilkan"<<endl;
cout<<"8. Keluar"<<endl;
cout<<"Pilihan : ";cin>>pil;
pilih();
}
while(pil!=8);
}


void pilih(){
if(pil==1)
tambah_depan();
else if(pil==2)
tambah_tengah();
else if(pil==3)
tambah_belakang();
else if(pil==4)
hapus_depan();
else if(pil==5)
hapus_tengah();
else if(pil==6)
hapus_belakang();
else if(pil==7)
tampil();
else
cout<<"selesai";
}
void buat_baru(){
char *nome = "ASU";
int npm = 17051412;
char *daerah = "asdasdasd";

baru =new(node);

strcpy(baru->nama,nome);
baru->nim=npm;
strcpy(baru->asal,daerah);
simpan_total = simpan_total + npm;
cout << simpan_total << endl;
//cout<<"Nama \t: ";cin>>baru->nama;
//cout<<"Nim \t: ";cin>>baru->nim;
//cout<<"Asal \t: ";cin>>baru->asal;
getch();
baru->prev=NULL;
baru->next=NULL;
}
void tambah_belakang()
{
buat_baru();
if(head==NULL)
{
head=baru;
tail=baru;
}
else
{
tail->next=baru;
baru->prev=tail;
tail=baru;
}
cout<<endl<<endl;
tampil();
}



void tambah_depan(){
buat_baru();
if(head==NULL){
head=baru;
tail=baru;
}else{
baru->next=head;
head->prev=baru;
head=baru;
}
cout<<endl<<endl;
tampil();
}

void hapus_depan() {
if (head==NULL)
cout<<"Kosong";
else if(head->next==NULL){
hapus=head;
head=NULL;
tail=NULL;
delete hapus;
}else {
hapus=head;
head=hapus->next;
head->prev=NULL;
delete hapus;
}
cout<<endl<<endl;
tampil();
}
void hapus_belakang()
{
if (head==NULL)
cout<<"Kosong";
else if (head->next==NULL)
{
hapus=head;
head=NULL;
tail=NULL;
delete hapus;
}
else
{
hapus=tail;
tail=hapus->prev;
tail->next=NULL;
delete hapus;
}
cout<<endl<<endl;
tampil();
}
void tambah_tengah(){
int posisi_sisip;
if(head!=NULL){
cout<<"akan disisipkan diposisi data ke- : ";cin>>posisi_sisip;
baru=new node;
baru->next=NULL;
baru->prev=NULL;
bantu=head;
for(int i=1;i<posisi_sisip-1;i++)
{bantu=bantu->next;}

buat_baru();
bantu2= bantu->next;
baru->next=bantu2;
bantu2->prev=baru;
bantu->next=baru;
baru->prev=bantu;
}
else{
cout<<"belum ada data"<<endl;
}
cout<<endl;
tampil();
}
void hapus_tengah()
{
int sisip;
cout<<"Masukan Posisi Sisip yg anda ingin hapus Anda : ";cin>>sisip;
bantu=head;

for(int i=1;i<sisip-1;i++)
{
bantu=bantu->next;
}
hapus=bantu->next;
bantu2=hapus->next;
bantu->next=hapus->next;
bantu2->prev=bantu;
delete hapus;
cout<<endl;
tampil();

}
void tampil(){
if (head==NULL)
cout<<"Kosong\n";
else {
bantu=head;
cout<<" No \t | Nama \t | NIM \t | Asal\t\t |"<<endl;
int no=0;
while(bantu!=NULL){
no++;
// cout<<" Nama \t: "<<bantu->nama<<"\t | ";
// cout<<" NIM \t: "<<bantu->nim<<"\t | ";
//cout<<" Asal \t: "<<bantu->asal<<"\t | "<<endl;
cout<<" "<<no<<"\t | ";
cout<<" "<<bantu->nama<<"\t | ";
cout<<" "<<bantu->nim<<"\t | ";
cout<<" "<<bantu->asal<<"\t | "<<endl;
bantu=bantu->next;
}
}system("pause");
}
