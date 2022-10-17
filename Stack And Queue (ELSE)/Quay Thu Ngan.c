#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node{
    ElementType Element;
    struct Node* Next;
}Node;

typedef Node* Position; 

typedef struct{
    Position Front, Rear;
}Queue;

void makenullQueue(Queue *pQ)
{
    Position Header = (Node*)malloc(sizeof(Node));
    Header->Next = NULL;
    pQ->Front = Header;
    pQ->Rear = Header;
}

int emptyQueue(Queue Q)
{
    return Q.Rear == Q.Front;
}

ElementType front(Queue Q)
{
    return Q.Front->Next->Element;
}

void deQueue(Queue *pQ)
{
    if (!emptyQueue(*pQ))
    {
        Position T = pQ->Front;
        pQ->Front = pQ->Front->Next;
        free(T);
    }
}

void enQueue(ElementType x, Queue *pQ)
{
    pQ->Rear->Next = (Node*)malloc(sizeof(Node));
    pQ->Rear = pQ->Rear->Next;
    pQ->Rear->Element = x;
    pQ->Rear->Next = NULL;
}

void xep_hang(int sokhach, int tden_tb, Queue *pQ)
{
    int stt;
    makenullQueue(pQ);
    for (stt = 1; stt <= sokhach; stt++)
        enQueue(stt * tden_tb, pQ);
}

int tinhQuayMo (int sokhach,int td_tb, int t_xuly, int soQuayMax, int t_muctieu, float *t_tb)
{
    Queue Q;
    makenullQueue(&Q);

    int soQuayMo = 1, td_den, td_di ; 
    int td_khachtruocdi[soQuayMax];

    *t_tb = t_muctieu + 1;
    int sttQuay;

    while (soQuayMo <= soQuayMax && *t_tb > t_muctieu)
    {
        for (sttQuay = 1; sttQuay <= soQuayMo; sttQuay++)
            td_khachtruocdi[sttQuay-1] = 0;

        xep_hang(sokhach, td_tb, &Q);

        int t_tong = 0;
        while(!emptyQueue(Q))
        {
            for (sttQuay = 1; sttQuay <= soQuayMo && !emptyQueue(Q); sttQuay++)
            {
                td_den = front(Q);
                deQueue(&Q);

                if (td_den >= td_khachtruocdi[sttQuay - 1])
                    td_di = td_den + t_xuly;
                else td_di = td_khachtruocdi[sttQuay -1] + t_xuly;

                td_khachtruocdi[sttQuay - 1] = td_di;
                t_tong += td_di - td_den;
            }
        }

        *t_tb = t_tong / sokhach;

        printf("So quay: %d; Thoi gian trung binh ma khach phai bo ra: %.1f\n", soQuayMo, *t_tb);
        ++soQuayMo;
    }
    return soQuayMo - 1;
}

//==========================================
int main ()
{
    int sokhach, soQuayMax, td_tb, t_mt, t_xuly;
    float t_tb;
    scanf("%d %d %d %d %d", &sokhach, &soQuayMax, &t_xuly, &td_tb, &t_mt);
    int re = tinhQuayMo(sokhach, td_tb, t_xuly, soQuayMax, t_mt, &t_tb);
    
    if (re != soQuayMax)
        printf("=> Sieu thi se mo %d quay",re);
    else printf("Voi %d quay hien co, khach phai bo ra trung binh %.1f giay moi hoan thanh viec thanh toan!!!.",soQuayMax, t_tb);
    return 0;
}