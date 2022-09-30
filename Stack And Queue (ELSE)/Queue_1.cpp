// 	Input:
//R	3		F
// 	3 2 1
// 	2 3 1

// Begin
// 	1 2 3
//  2 3 1

// Step 1
// 	3 1 2
//  2 3 1

// Step 2
// 	2 3 1 
//  2 3 1

// Step 3
// 	2 3
//  2 3

// Step 4
// 	2
//  2

// Step 5 
// 	NULL
//  NULL

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node {
	ElementType Element;
	struct Node* Next;
}Node;

typedef Node* Positon;
typedef struct{
	Positon Front, Rear;
}Queue;

void makenullQueue(Queue *pQ){
	Positon Header = (Node*)malloc(sizeof(Node));
	Header->Next = NULL;
	pQ->Front = Header;
	pQ->Rear = Header; 
}

int emptyQueue(Queue Q){
	return Q.Front == Q.Rear;
}

void enQueue(ElementType x,Queue *pQ){
	pQ->Rear->Next = (Node*)malloc(sizeof(Node));
	pQ->Rear = pQ->Rear->Next;
	pQ->Rear->Element = x;
	pQ->Rear->Next = NULL;
}

void deQueue(Queue *pQ){
	if (!emptyQueue(*pQ)){
		Positon T = pQ->Front;
		pQ->Front = pQ->Front->Next;
		free(T);
	}
}

void readQueue(int n, Queue *pQ){
	int i;
	ElementType x;
	makenullQueue(pQ);
	for (i = 0; i < n; i ++){
		scanf("%d",&x);
		enQueue(x, pQ);
	}
}







//============================
int main (){
	Queue Q, T;
	int n, cnt = 0;
	scanf("%d", &n);
	readQueue(n, &Q);
	readQueue(n, &T);
	
	while (!emptyQueue(Q)){
		if (!emptyQueue(T)){
			if (Q.Front->Element == T.Front->Element){
				deQueue(&Q);
				deQueue(&T);
				cnt ++;
			} else {
				enQueue(Q.Front->Element, &Q);
				deQueue(&Q);
				cnt ++; 
			}
		}
	}
	printf("%d", cnt);
	return 0;
}