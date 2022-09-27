#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct Node{
	ElementType Elements;
	struct Node* Next;
};

typedef struct Node* Position;
typedef struct{
	Position Front, Rear;
}Queue;
 
void makenullQueue(Queue *pQ){
	Position Header;
	Header = (struct Node*)malloc(sizeof(struct Node));
	Header->Next = NULL;
	pQ->Rear = Header;
	pQ->Front = Header;
}

int emptyQueue(Queue Q){
	return Q.Front == Q.Rear;	
}

void enQueue (ElementType x, Queue *pQ){
	pQ->Rear->Next = (struct Node*)malloc(sizeof(struct Node));
	pQ->Rear = pQ->Rear->Next;
	pQ->Rear->Elements = x;
	pQ->Rear->Next = NULL;
}

void deQueue (Queue *pQ){
	if (!emptyQueue(*pQ)){
		Position Temp;
		Temp = pQ->Front;
		pQ->Front = pQ->Front->Next;
		free(Temp);
	} else {
		printf("Loi: Hang rong");
	}
}

void readQueue( int n, Queue *pQ){
	ElementType t;
	makenullQueue(pQ);
	while (n--){
		scanf("%d", &t);
		enQueue(t, pQ);
	}
}


//========================================
int main (){
	Queue Q, T;
	int n, cnt = 0;
	scanf("%d", &n);
	readQueue(n, &Q);
	readQueue(n, &T);
	while (!emptyQueue(Q)){
		if (!emptyQueue(T)){
			if (Q.Front->Elements == T.Front->Elements){
				deQueue(&Q);
				deQueue(&T);
				cnt ++;
			} else {
				enQueue(Q.Front->Elements, &Q);
				deQueue(&Q);
				cnt ++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}

    







