#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

main() {
  int pil;
  int on = 1;
  system("cls");
  while(on){
  system("cls");

  printf("\n          QUEUE           \n");
  printf("  | 1. Insert Queue   |\n");
  printf("  | 2. Delete Queue   |\n");
  printf("  | 3. Tampilkan Queue|\n");
  printf("  | 4. Exit           |\n");
  printf("\nPilihan : ");
  scanf("%d", &pil);

  switch(pil){
  case 1 :
    system("cls");
    insert();
    break;
  case 2 :
    system("cls");
    delete();
    break;
  case 3 :
    system("cls");
    tampil();
    break;
  case 4 :
    exit(1);
    break;
  default :
    printf("\nInput Salah !"); } } }

insert() {
  int add;
  system("cls");
  if(rear==MAX-1){
  printf("Queue Overflow !!!\n");}
  else {
  if(front==-1)
  front = 0;
  printf("Masukkan Nilai Elemen Queue : ");
  scanf("%d",&add);
  rear=rear+1;
  queue[rear] = add; } }

delete() {
  system("cls");
  if (front==-1 || front > rear) {
  printf("Queue Underflow \n");
  return;
  } else {
  printf("Queue yang di Delete adalah : %d \n", queue[front]);
  front=front+1;
  getch(); } }

tampil() {
  int i;
 system("cls");
  if (front == -1){
  printf("Antrean kosong\n");
  }else {
  printf("Nilai Queue Adalah : \n");
  for(i=front;i<=rear;i++){
  printf("%d",queue[i]);
  printf(" ");} }
  getch(); }
