// Linked List


void printer(){
	system("cls");
	if(head == NULL){
int i = 0;		
printf(

"          -=[ shopping cart ]=-                             \n"
"          ___                             \n"
"          '-||__/________                             \n"
"            |==/_|__|___/                             \n"
"            |=/__|__|__/                             \n"
"            |/|__|__|_/                             \n"
"              )_____(_                             \n"
"             [--------|                             \n"
"             (o)""""(o)                             \n");

int nomor = 0;
int digit = 0;

printf(
"  .===========================================================================.\n"
"  | No  |               Items                    |  QTY  |       Harga        |\n"           
"  |-----|----------------------------------------|-------|--------------------|\n"
//"  |  ");
//printf("%d  |",nomor);
//          printf(" %s ",nama);for(i=0;i<38-strlen(nama);i++){printf(" ");}printf("|   %d   |    %d",quantity,harga);
//while(harga>0){harga=(harga-(harga%10))/10;digit++;}for(i=0;i<16-digit;i++){printf(" ");}printf("|\n");
//printf(
"  |     |         TIDAK ADA ITEM                 |       |                    |\n"
"  '---------------------------------------------------------------------------'\n"
);

	}
	else{
		tampil = head;
int nomor = 0;
		while (tampil != NULL){
		nomor++;
		printf(

"          -=[ shopping cart ]=-                             \n"
"          ___                             \n"
"          '-||__/________                             \n"
"            |==/_|__|___/                             \n"
"            |=/__|__|__/                             \n"
"            |/|__|__|_/                             \n"
"              )_____(_                             \n"
"             [--------|                             \n"
"             (o)""""(o)                             \n");

int nomor = 0;
int digit = 0;
i = 0;


printf(
"  .===========================================================================.\n"
"  | No  |               Items                    |  QTY  |       Harga        |\n"           
"  |-----|----------------------------------------|-------|--------------------|\n"
"  |  ");
printf("%d  |",nomor+1);
          printf(" %s ",tampil->nama);for(i=0;i<38-strlen(tampil->nama);i++){printf(" ");}printf("|   %d   |    %d",quantity,tampil->harga);
while(tampil->harga>0){tampil->harga=(tampil->harga-(tampil->harga%10))/10;digit++;}for(i=0;i<16-digit;i++){printf(" ");}printf("|\n");
printf(
"  |     |                                        |       |                    |\n"
"  '---------------------------------------------------------------------------'\n"
);

		
		tampil = tampil->next;
	}
	}
	
	getch();
	pil = '0';
	return menu();
}

int quantity = 0;

void entry_katalog_buah(){
	
	
	entry = (struct katalog *)malloc(sizeof(struct katalog));
	
	switch(posisi){
		case 1:
			strcpy(entry->nama=bs1);
			entry->harga=harga_bs1;
			entry->nomor=no_bs1;
			quantity++;
			break;
		case 2:
			strcpy(entry->nama=bs2);
			entry->harga=harga_bs2;
			entry->nomor=no_bs2;
			quantity++;
			break;
		case 3:
			strcpy(entry->nama=bs3);
			entry->harga=harga_bs3;
			entry->nomor=no_bs3;
			quantity++;
			break;
		case 4:
			strcpy(entry->nama=bs4);
			entry->harga=harga_bs4;
			entry->nomor=no_bs4;
			quantity++;
			break;
		case 5:
			strcpy(entry->nama=bs5);
			entry->harga=harga_bs5;
			entry->nomor=no_bs5;
			quantity++;
			break;
		case 6:				
			KatalogAnimation();
			return yukBelanja();
			break;
		default:
			printf("nothing");
	}
	
	entry->prev=NULL;
	entry->next=NULL;	
	
}

void AddKatalog(){
	
entry_katalog();

	if(head==NULL)
{
head=entry;
tail=entry;
}
else
{
tail->next=entry;
entry->prev=tail;
tail=entry;
}
printer();
}
