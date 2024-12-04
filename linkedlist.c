#include<stdio.h>
#include<stdlib.h>
	struct node{
	int data
	struct node*next;
  };
 
typedef struct node node;
node *head;
void insert_end(){
int data;
node*temp,*pre;
printf("\n Enter values : ");
scanf("%d",&data);
