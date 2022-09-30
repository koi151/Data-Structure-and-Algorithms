#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElementType;
struct Node {
	ElementType Element;
	struct Node	*Next;
};
typedef struct Node* Position;
typedef struct {
	Position Front, Rear;
} Queue; 

void makenullQueue(Queue *pQ) {
	Position Header;
	Header=(struct Node*)malloc(sizeof(struct Node)); 
	Header->Next=NULL;
	pQ->Front=Header;
	pQ->Rear=Header;
}

int emptyQueue(Queue Q) {
	return (Q.Front==Q.Rear);
} 

void enQueue(ElementType X, Queue *pQ) { 
	pQ->Rear->Next=(struct Node*)malloc(sizeof(struct Node));
	pQ->Rear=pQ->Rear->Next;
	pQ->Rear->Element=X;
	pQ->Rear->Next=NULL;
} 

void deQueue(Queue *pQ) {
	if (!emptyQueue(*pQ)){
		Position Tempt;
		Tempt=pQ->Front;
		pQ->Front=pQ->Front->Next;
		free(Tempt);
	}
	else 
		printf("Loi: Hang rong");
 } 

ElementType front(Queue Q) {
	if (!emptyQueue(Q))
		return Q.Front->Next->Element;
	else {
	    printf("Loi, hang rong");
	    return -1;
	}	
} 

int countElements(Queue Q){
    int cnt = 0;
    Position P = Q.Front;
    while (P != Q.Rear){
        cnt ++;
        P = P->Next;
    }
    return cnt;
}

//========================================
int main (){
    Queue Q;
    makenullQueue(&Q);
    int n, i, t, temp;
    char c;
    scanf("%d", &n);
    getchar();
    for ( i = 1; i <= n; i++){
        // getchar();
        scanf("%c", &c);
        
        if (c == 'E'){
            scanf("%d", &t);
            getchar();
            enQueue(t, &Q);
            printf("%d\n", countElements(Q));
            
        } else if (c == 'D'){
            getchar();
            if(!emptyQueue(Q)){
	            temp=front(Q);
	            deQueue(&Q);
	            printf("%d %d\n",temp,countElements(Q));
	            
	       }else {
                printf("-1 0\n");
            }
        }
        
    }
    return 0;
}



















