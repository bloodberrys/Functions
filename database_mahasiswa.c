#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


typedef struct mahasiswa{
	char nama[50];
	int npm;
	char status[50];
	char nomor_hp[50];
	char id_line[50];
	struct mahasiswa *next, *prev;
		
}mahasiswa;

mahasiswa *entry;
mahasiswa *head = NULL;
mahasiswa *tail = NULL;
mahasiswa *print;
mahasiswa *print2;

//password
										#define maxPasswordLength (int)15
								char password[maxPasswordLength + 1];
						char loginpassword[] = "sienltd";
				char ch;
			int characterPosition = 0;


void linked_list();
void entry_data();
void menu();
void gotoxy(int x, int y);
void show_cursor();
void hide_cursor();
void arrow();
void login();

int main(){
	login();
	menu();
	return 0;
	
}

void arrow(int real_position, int arrow_position){
	
	if(real_position == arrow_position){
		printf("        -> ");
	}
	else{
		printf("           ");
	}
	
}

void entry_data(){
	
	entry = (struct mahasiswa *)malloc(sizeof(struct mahasiswa));
	
	printf("Masukkan nama : "); scanf(" %[^\n]s",entry->nama);
	printf("NPM           : "); scanf(" %d",&entry->npm);
	printf("Id line       : "); scanf(" %[^\n]s",entry->id_line);
	printf("No. HP        : "); scanf(" %[^\n]s",entry->nomor_hp);
	printf("Status        : "); scanf(" %[^\n]s",entry->status);
	

	
	entry->prev=NULL;
	entry->next=NULL;
	
}

void linked_list_bawah(){
	entry_data();
	if(head == NULL){
		head = entry;
		tail = entry;
	}
	else{
		
		tail->next=entry;
		entry->prev=tail;
		tail = entry;
		
	}
	printer();
}

void printer(){
	if (head == NULL){
		printf("tidak ada data makasih oke!.");
		Sleep(1000);
		return menu();
		
	}
	else{
		print = head;
		int nomor = 0;
		printf("Database: \n");
		while (print != NULL){
			
			nomor++;
			printf("%d. %s		%d		%s		%s		%s\n",
			nomor,
			print->nama,
			print->npm,
			print->id_line,
			print->nomor_hp,
			print->status);
			print = print->next;
		}
		
	}
	system("pause");
	return menu();
	
}


void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void showcursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 10;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(int x, int y){
	
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		
}

void menu(){
	
	system("cls");
	hidecursor();
	int posisi = 1;
	int key = 0;
	
	while (key!=13){
	
	gotoxy(30,12);
	arrow(1,posisi);	
	printf("Insert Data Kamu (List Bawah)");
	gotoxy(30,13);
	arrow(2,posisi);	
	printf("Insert Data Kamu (List Atas) ");
	gotoxy(30,14);
	arrow(3,posisi);	
	printf("Insert Data Kamu (List Tengah) ");
	gotoxy(30,15);
	arrow(4,posisi);	
	printf("Searching");
	gotoxy(30,16);
	arrow(5,posisi);	
	printf("Lihat Data Mahasiswa");
	
	key = getch();
	
	if(key == 80 && posisi!=5){
		posisi++;
	}
	else if(key == 72 && posisi!=1){
		posisi--;
	}
	else{
		posisi = posisi;
	}
}

switch(posisi){
	case 1:
		system("cls");
		linked_list_bawah();
		break;
	case 2:
		system("cls");
		
		
		linked_list_atas();
		break;
	case 3:
		system("cls");
		linked_list_tengah();
		break;
	case 4:
		system("cls");
		search();
		break;
	case 5:
		system("cls");
		printer();
		break;
	default:
		printf("");
}
	
	
}

void linked_list_atas(){
	entry_data();
	
	if(head==NULL){
		head=entry;
		tail=entry;
	}
	else{
		entry->next=head;
		head->prev=entry;
		head=entry;
	}

	printer();
	
}


void linked_list_tengah(){
	
	int posisi_sisip;
	int i = 0;
	if(head!=NULL){
	
	printf("Akan disisipkan diposisi data ke- : ");scanf("%d",&posisi_sisip);
	entry  = (struct mahasiswa *)malloc(sizeof(struct mahasiswa));
	entry->next=NULL;
	entry->prev=NULL;
	print=head;
	for(i=1;i<posisi_sisip-1;i++){
		print = print->next;
	}

entry_data();
print2= print->next;
entry->next=print2;
print2->prev=entry;
print->next=entry;
entry->prev=print;
}
else{
printf("belum ada data");
}

printer();
}


void login(){
	hidecursor();
	system("cls");
	gotoxy(45,14);
	printf("PASSCODE :",maxPasswordLength);
	
	while(1){
		ch = getch();
		if( ch == 13 ){
			break;
		}else if( ch == 8 ){
			if( characterPosition > 0){
				characterPosition--;
				password[characterPosition] = '\0';
				printf("\b \b");
			}
		}else if( ch == 32 || ch == 9){
			continue;
		}else{
			if( characterPosition < maxPasswordLength ){
				password[characterPosition] = ch;
				characterPosition++;
				printf("*");
			}else{
				printf("\n Your Input Exceeds Maksimum Password length of %d. So only First %d characters will be considered",maxPasswordLength,maxPasswordLength);
				break;
			}
		}
		
		
	}
	password[characterPosition]= '\0';
	printf("\n");
	if( strlen(password) ==0){
		printf("No Password Entered");
	}else{
		if(strcmp(password,loginpassword)==0){
			gotoxy(45,16);
		
			printf("Login Success");
		
				//reset
			int o = 0;
			for(o = 0;o<15;o++){
				password[o] = 0;
			}
			ch = 0;
			characterPosition = 0;
			
			Sleep(1000);
			menu();
		}else{
			gotoxy(45,16);
		
			printf("Login Failure");
			
			//reset
			int o = 0;
			for(o = 0;o<15;o++){
				password[o] = 0;
			}
			ch = 0;
			characterPosition = 0;
			Sleep(1000);
			return login();
		}
	}
	
}

#define MAX_STRING_LENGTH (int)30

void search(){
	
	char *keyword=NULL;
    mahasiswa *current=head;
    printf("Masukan Nama: ");
    fflush(stdin);
    keyword=(char*) malloc(MAX_STRING_LENGTH*sizeof(char));
    gets(keyword);
    for (current=head;current!=NULL;current=current->next)
    {
        if (strcmp(current->nama,keyword)==0) {
            puts(current->nama);
            printf("%s",current->nama);
            printf("%d",current->npm);
            printf("%s",current->nomor_hp);
            printf("%s",current->status);
            printf("%s",current->id_line);
        }
    }
	getch();
}


