/*
Nama        : Natasya Rizky Maharani
NPM         : 140810180004
kelas       : B
Tanggal     : Rabu, 14 April 2019
Deskripsi   : Program ini menampilkan data pesanan di restoran lalala
*/

#include<iostream>
#include<iomanip>
using namespace std;

struct ElemtList{
 char nama[50];
 char namaOrang[50];
 int jumlah;
 int harga;
 ElemtList* next;
};

typedef ElemtList* pointer;
typedef pointer list;

void createList(list& First){
 First=NULL;
}

void createElemt(pointer& pBaru){
 pBaru = new ElemtList;
 cout<<"Nama Barang : ";cin.getline(pBaru->nama,50);
 cout<<"Jumlah : ";cin>>pBaru->jumlah;
 cout<<"Harga satuan : ";cin>>pBaru->harga;
 pBaru->next=NULL;
}

void insertLast(list& First, pointer pBaru){
 pointer last;
 if(First==NULL){
  First=pBaru;
 }
 else{
  last=First;
  while (last->next!=NULL){
   last=last->next;
  }
  last->next=pBaru;
 }
}

void sort(list& First,pointer pBantu){
    int tukar,temp;
    pointer terbesar,pNull=NULL;
    if(First==NULL){
  return;
 }
  do{
  tukar=0;
  pBantu=First;
  while(pBantu->next!=NULL){
   if(pBantu->jumlah > pBantu->next->jumlah){
    swap(pBantu->jumlah,pBantu->next->jumlah);
    tukar=1;
   }
   pBantu=pBantu->next;
  }
  pNull=pBantu;
  }while(tukar);
 }

void swap(pointer a,pointer b){
 int temp =a->;
 a->info=b->info;
 b->info=temp;
}

void traversal(list First,pointer pBantu){
 int i=1;
 if(First==NULL){
  cout<<"List kosong"<<endl;
 }
 else{
    pBantu=First;
    cout<<setw(2)<<"No"<<setw(15)<<"Nama Makanan"<<setw(11)<<"Harga"<<endl;
    do{
    cout<<setw(1)<<i++<<setw(14)<<pBantu->nama<<setw(10)<<pBantu->harga<<endl;
    pBantu=pBantu->next;
    }
  while(pBantu!=NULL);
 }
}

int main(){
    int n;
    list a;
    pointer b;
    createList(a);

    cout<<"Masukkan banyak pesanan : ";cin>>n;
    for(int i=0;i<n;i++){
        createElemt(b);
        insertLast(a,b);
    }
    sort(a,b);
    traversal(a);
}
