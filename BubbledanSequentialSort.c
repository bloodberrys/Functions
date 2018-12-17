#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

//how to search value in an array set
	
	
int array[SIZE] = {0};
int dummies[SIZE] = {0};
int dummies1[SIZE] = {0};


int i,j;
int c, first, last, middle, angkadicari; 

void mengurutkan();
int ascending_sorting(int ar[],int size);
int descending_sorting(int ar1[], int size1);
int dummy_array(int a[],int b[],int size2);
int dummy_array1(int a[],int b[],int size2);
void cari();
int searching(int element,int ar[],int found);
int binary(int ar[],int angka, int size);
void binari();

int main(){
	menu();
	return 0;
}


menu(){
	char a = "0";
	system("cls");
	printf("  .===========.\n");
	printf("  |   MENU    |\n");
	printf("  '==========='\n\n\n");
	
	printf("  1. Aplikasi Bubble Sort\n\n  2. Sequential Search\n\n  3. Binary Search\n\n");
	printf("  Pilih: ");
	scanf("%c",&a);
	switch(a){
		case '1':
			system("cls");
			mengurutkan();
			break;
		case '2':
			system("cls");
			cari();
			break;
		case '3':
			system("cls");
			binari();
			break;
		default:
			
			printf("Salah!");
			Sleep(1000);
			return menu();
	}
	
}



int searching(int element,int ar[],int found){
	
	int i=0;
	for(i=0;i<10;i++){
		if(element == ar[i]){
		found = i;	
		}
	}
	
	
if(found != -1){
	printf("  Data yang Anda cari ditemukan, pada address ke-%d, yaitu bernilai %d",found,ar[found]);
	printf("\n\n  Tekan apapun untuk kembali ke menu.");
	getch();
	
	
}
else{
	printf("  Maaf, data tidak ditemukan.");
	Sleep(1000);
	
}
	return menu();
}

int ascending_sorting(int ar[], int size){
	int i,j,n;
	int simpan;
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(ar[i]>ar[j]){
			simpan = ar[i];
			ar[i] = ar[j];
			ar[j] = simpan;
			}
		}
	}
	
}


int descending_sorting(int ar1[], int size1){
	int i,j,n;
	int simpan1;
	for(i=0;i<size1;i++){
		for(j=i+1;j<size1;j++){
			if(ar1[i]<ar1[j]){
			simpan1 = ar1[i];
			ar1[i] = ar1[j];
			ar1[j] = simpan1;
			}
		}
	}
	
}

int dummy_array(int a[],int b[],int size2){
	int i;
	for(i=0;i<size2;i++){
		b[i]=a[i];
	}

}


int dummy_array1(int a[],int b[],int size2){
	int i;
	for(i=0;i<size2;i++){
		b[i]=a[i];
	}

}




void mengurutkan(){

//input array anda:
	printf("  .==============.\n");
	printf("  |   SORTING    |\n");
	printf("  '=============='\n\n\n");
printf("  Input 10 data array: \n\n");

for(i=0;i<SIZE;i++){
	printf("  Data ke-%d: ",i+1);
	scanf("%d",&array[i]);
}

//menduplikasi array pada dummy array
dummy_array(array,dummies,SIZE);
dummy_array1(array,dummies,SIZE);
system("cls");
printf("\n  Array Anda pada: \n\n");

for(i=0;i<SIZE/2;i++){
	printf("                   \t|\n  Address ke-%d = %d \t|\t Address ke-%d = %d\n                   \t|\n",i,array[i],i+5,array[i+5]);
}

//sorting array with modular
ascending_sorting(array,SIZE);

printf("\n  Array after ascending sorting:\n  ");
for(i=0;i<SIZE;i++){
	printf("  %d ",array[i]);
}

printf("\n");

descending_sorting(dummies,SIZE);

printf("\n  Array after descending sorting:\n  ");
for(i=0;i<SIZE;i++){
	printf("  %d ",dummies[i]);
}
	
printf("\n\n  Tekan apapun untuk kembali ke menu.\n");
getch();
printf("  Data tersimpan!");
Sleep(1000);
return menu();
system("cls");

	
}

void cari(){
int elemen = 0;
int ketemu = -1;

	if (array[0] == 0){
			printf("\n\n  Silahkan ke menu (1) Untuk mengisi data Array Anda!");
			Sleep(1000);
			return menu();
		}
		else{

	printf("  .==========================.\n");
	printf("  |   SEQUENTIAL SEARCHING   |\n");
	printf("  '=========================='\n\n\n");
	printf("  Array Anda: \n\n");
 			for(i=0;i<SIZE;i++){
 			printf("  %d ",array[i]);
 			}
printf("\n\n  Masukkan nilai elemen yang akan Anda cari:\n\n");
scanf("  %d",&elemen);

searching(elemen,array,ketemu);
		}
}

int binary(int ar[],int angka, int size){
  
  first = 0;
  last = size-1; 
  middle=(first+last)/2;
   while (first<=last) {
   	
   if (ar[middle] < angka) {
   first=middle+1; 
	}
   
   else if ( ar[middle]==angka) {
   printf ( "\n  Data %d ditemukan pada address ke - %d ", angka, middle); 
   break;
	}
    
	else {
	last = middle - 1 ; 
	}
	middle = (first+last)/2; 
	}
	if (first>last){
		printf ( "  Data %d Tidak ditemukan!" , angka);
		Sleep(1000);
		return menu;
}
}

void binari(){

		if (array[0] == 0){
			printf("\n\n  Silahkan ke menu (1) Untuk mengisi data Array Anda!");
			Sleep(1000);
			return menu();
		}
		
		else{
				printf("  .=============.\n");
				printf("  |   BINARY    |\n");
				printf("  '============='\n\n\n");
 			printf("  Array Anda: \n\n");
 			for(i=0;i<SIZE;i++){
 			printf("  %d ",array[i]);
 			}
 			printf ("\n\n  Masukkan angka yang dicari: "); 
 			scanf ( "%d", &angkadicari ) ; 
 			binary(array,angkadicari,SIZE);
		}
}


