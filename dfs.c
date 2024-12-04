#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

define MAX 6

int vertex_count = 0;

struct vertex{
	char data;
	bool visited;
};

struct vertex *graph[max];

int adj_matrix[MAX][MAX];

int stack[max];
int top = -1;

void push(int data){
	stack[++top]=data;
}

int pop(){
	return stack[top--];
}

int peek(){
	return stack[top];
}
bool is_stack_empty(){
	return top==-1;
}

void add_vertex(char data){
	struct vertex *new = (struct vertex*)malloc(sizeof(struct vertex));
	new->data=data;
	new->visited=false;
	graph[vertex_count]=new;
	vertex_count++;
	}

void add_edge(int start,int end){
	adj_matrix[start][end]=1;
	adj_matrix[end][start]=1;
}

void add_vertex(int vertex_get){
	int i;
	for(i=0;i<vertex_count;i++){
		if(adj_matrix[vertex_get][1]==1 && graph[i]->visited == false){
		return i;
}
}
return -1;

void display_vertex(int pos){
	printf("%c",graph[pos]->data);
	











