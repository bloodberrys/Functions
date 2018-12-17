#include<stdio.h>
#include<conio.h>

#define size 5

struct stack {
	int s[size];
	int top;
}st;

int stackFull()
{
	if(st.top>=size-1)
	return 1;
	else
	return 0;
}

int stackEmpty()
{
	if(st.top==-1)
	return 1;
	else
	return 0;
}

void push(int item)
{
	st.top++;
	st.s[st.top]=item;
}

int pop()
{
	int item;
	item=st.s[st.top];
	st.top--;
	return(item);
}

void Display()
{
	int i;
	if(stackEmpty())
	printf("\n Stack Kosong !");
	else
	{
		printf("\n Elemen Stack : ");
		for(i=st.top;i>=0;i--)
		printf(" %d",st.s[i]);
	}
}

void main()
{
	int item,ch;
	st.top=-1;
	system("cls");
	printf("\t\t\tPemrograman Lanjut-02\n\n"); //Nama Mata Kuliah
    printf("======================================================================================================\n");
    printf("Nama Kelompok  : Fahri Alamsyah & Alfian Firmansyah \n"); //Identitas
    printf("======================================================================================================\n");
    printf("STACKS AND QUEUE  \n \n"); //Nama Program
    printf("======================================================================================================\n");
	printf("\n Stack Implementasi ");
	do
	{
		printf("\n\n Main Menu");
		printf("\n 1 : Push ");
		printf("\n 2 : Pop ");
		printf("\n 3 : Display ");
		printf("\n 4 : Exit ");
		
		printf("\n Pilih Operasi : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
				printf("\n Masukan Item yang ingin di Push : ");
				scanf("%d",&item);
				system("cls");
				
			if(stackFull())
			printf("\n Stack Terisi Penuh (Over Flow)");
			else
			push(item);
			break;
			
			case 2 : 
			if(stackEmpty())
				printf("\n Stack Kosong (UnderFlow)");
				else
					item=pop();
					printf("\n Elemen Pop Adalah %d",item);
				break ;
				
			 case 3 :
			 	Display();
			 	break;
			 	
			 case 4 :
			 	printf("Program Selesai");
			}
	}
	while (ch!=4);
	getch();
}
