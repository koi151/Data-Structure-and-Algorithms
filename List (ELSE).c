#include <stdio.h>

#define Maxlength 100 
typedef int ElementType;
typedef int Position;

typedef struct{
    ElementType Elements[Maxlength];
    int Last;
}List;

void makenullList(List *pL)
{
    pL->Last = 0;
}

int member(ElementType x, List L)
{
    Position i = 0;
    while (i < L.Last)
    {
        if (L.Elements[i++] == x)
        return 1;
    }
    return 0;
}

int locate(ElementType x, List L)
{
    Position i = 0;
    while (i < L.Last)
    {
        if (L.Elements[i++] == x)
        return i;
    }
    return ++L.Last;
}

void sort(List *pL)
{
    for (Position i = 0; i < pL->Last ; i++)
    {
        for (Position j = i+1; j < pL->Last; j++)
        {
            if (pL->Elements[i] > pL->Elements[j])
            {
                pL->Elements[i] ^= pL->Elements[j];
                pL->Elements[j] ^= pL->Elements[i];
                pL->Elements[i] ^= pL->Elements[j];
            }
        }
    }
}

void printOddNumbers(List L)
{
    for (int i = 0; i < L.Last; i++)
    {
        if (L.Elements[i] % 2 != 0)
            printf("%d ",L.Elements[i]);
    }
}

void insertList (ElementType x, Position p ,List *pL)
{
    if (pL->Last == Maxlength)
        printf("Danh sach day!\n");
    else if ( p > pL->Last + 1 || p < 1)
        printf("Nhap lieu sai\n");
    else {
        Position i;
        for (i = pL->Last; i > p-1; i--)
            pL->Elements[i+1] = pL->Elements[i];
        pL->Elements[p-1] = x;
        pL->Last ++; 
    }
}

void insertSet(ElementType x, List *pL)
{
    if (pL->Last == Maxlength)
        printf("Danh sach day!");
    else {
        pL->Elements[pL->Last] = x;
        pL->Last ++;
    }
}

void copyEvenNumbers(List L1, List *pL2)
{
    makenullList(pL2);
    for (int i = 0; i < L1.Last; i++)
        if (L1.Elements[i] % 2 == 0)
            insertList(L1.Elements[i], pL2->Last+1, pL2);
}

void intersection( List L1, List L2, List *pL)
{
    makenullList(pL);
    Position i;
    for (i = 0; i < L1.Last; i++)
        if (member(L1.Elements[i], L2))
            insertSet(L1.Elements[i], pL);
}

void readList(List *pL)
{
    makenullList(pL);
    int n, x;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &x);
        insertList(x, pL->Last+1, pL);
    }
}

void removeAll(ElementType x, List *pL)
{
    Position i;
    for (i = 0; i < n; i++)
        if 
}

//========================================
int main ()
{
    List L;
    int i;
    L.Last=0;
    for(i=0;i<5;i++)
    {  L.Elements[i] = 2*i;}
    L.Last=5;
    removeAll(0,&L);
    for(i=0;i<L.Last;i++)
    {    printf("%d ",L.Elements[i]);}

}