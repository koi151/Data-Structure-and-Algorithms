#include <stdio.h>

#define SoPhanTu 100

typedef struct{
    int DuLieu[SoPhanTu];
    int Dinh;
}NganXep;

void khoitao(NganXep *pS){
    pS->Dinh = 100;
}

int ktRong( NganXep S){
    return S.Dinh == 100;
}

int ktDay(NganXep S){
    return S.Dinh == 0;
}

void xoaDinh(NganXep *pS){
    if (!ktRong(*pS))
        pS->Dinh++;
}

int giatriDinh (NganXep S){
    return S.DuLieu[S.Dinh];
}

void them ( int x, NganXep *pS){
    if (!ktDay(*pS)){
        pS->Dinh --;
        pS->DuLieu[pS->Dinh] = x;
    }
}

void xoa(NganXep *pS){
    pS->Dinh ++;
}

void hienthi(NganXep *pS){
    while (!ktRong(*pS)){
        printf("%d ", pS->DuLieu[pS->Dinh]);
        pS->Dinh ++;
    }
    printf("\n");
}

//============================================
int main ()
{
    NganXep S;
    S.Dinh=99;
    S.DuLieu[S.Dinh] = 10;
    xoa(&S);
    if(S.Dinh==SoPhanTu)
    printf("Ngan xep rong");
    else
    printf("Ngan xep khong rong");
    return 0;
}