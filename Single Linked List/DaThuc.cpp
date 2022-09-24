#include <stdio.h>
#include <stdlib.h>

typedef struct{
	double he_so;
	int bac;
}DonThuc;

struct Node{
	DonThuc e;
	struct Node* Next;	
};

typedef struct Node* Position;
typedef Position DaThuc;

DaThuc khoitao(){
	DaThuc d = (struct Node*)malloc(sizeof(struct Node));
	d->Next = NULL;
	return d;
}

void chenDonThuc( DonThuc s, DaThuc *pD){
	Position P = (*pD);
	int flag = 0;
	while ( P->Next != NULL && !flag){
		if ( P->Next->e.bac > s.bac)
			P = P->Next;
		else flag = 1;
	}
	
	if ( P->Next != NULL){
		if ( P->Next->e.bac == s.bac)
			P->Next->e.he_so += s.he_so;
		else{
			Position temp = (struct Node*)malloc(sizeof(struct Node));
			temp->e = s;
			temp->Next = P->Next;
			P->Next = temp;
		}
	} else {
			Position temp = (struct Node*)malloc(sizeof(struct Node));
			temp->e = s;
			temp->Next = P->Next;
			P->Next = temp;
	}
}

DaThuc nhapDaThuc(){
	DaThuc D;
	D = khoitao();
	DonThuc T;
	int n,i;
	scanf("%d", &n);
	for ( i  = 0; i < n; i ++){
		scanf("%lf %d", &T.he_so, &T.bac);
		chenDonThuc(T,&D);
	}
	return D;
}

void inDaThuc(DaThuc d){
	Position p=d;
	while(p->Next!=NULL){
		if (p->Next->Next==NULL)
			printf("%.3fX^%d",p->Next->e.he_so,p->Next->e.bac);
		else
			printf("%.3fX^%d + ",p->Next->e.he_so,p->Next->e.bac);
		p=p->Next;	
	}
	printf("\n");
}

DaThuc congDaThuc(DaThuc D1, DaThuc D2){
	DaThuc D = khoitao();
	Position P = D1;
	while (P->Next != NULL){
		chenDonThuc(P->Next->e, &D);
		P = P->Next;
	}
	
	P=D2;
	while(P->Next != NULL){
		chenDonThuc(P->Next->e, &D);
		P = P->Next;
	}
	return D;
}

DaThuc nhanDaThuc(DaThuc D1, DaThuc D2){
	DaThuc D = khoitao();
	Position P,Q;
	DonThuc temp;
	P = D1;
	while ( P->Next != NULL){
		Q = D2;
		while (Q->Next != NULL){
			temp.he_so = P->Next->e.he_so * Q->Next->e.he_so; 
			temp.bac = P->Next->e.bac + Q->Next->e.bac;
			chenDonThuc(temp, &D);
			Q= Q->Next;
		}
		P= P->Next;
	}
	return D;
}

DaThuc tinhDaoHam(DaThuc D){
	DaThuc Q = khoitao();
	DonThuc L;
	Position P = D;
	while (P->Next != NULL){
		L = P->Next->e;
		L.he_so *= L.bac;
		L.bac --;
		chenDonThuc(L,&Q); 
		P = P->Next;
	}
	return Q;
}

//===================================
int main(){
	DaThuc d1=nhapDaThuc();			
	DaThuc d = tinhDaoHam(d1);
	inDaThuc(d);
	return 0;
}
