#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int Key;
    struct Node *Left, *Right;
}Node;

typedef Node* Tree;

Tree initTree()
{
    return NULL;
}

int isEmpty(Tree T)
{
    return T == NULL;
}

void posOrder(Tree T)
{
    if (T != NULL)
    {
        posOrder(T->Left);
        posOrder(T->Right);
        printf("%d ", T->Key);
    }
}

void preOrder(Tree T)
{
    if (T != NULL)
    {
        printf("%d ", T->Key);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

Tree getParent(int x, Tree T)
{
    Tree P=T, Parent = NULL;
    if (P != NULL)
    {
        if (P->Key == x) return Parent;
        Parent = P;
        else if (P->Key > x) P=P->Left;
        else P=P->Right;        
    }
    return NULL;
}

Tree searchNode(int x, Tree T)
{
    Tree P = T;
    while (P != NULL)
    {
        if(P->Key == x) return P;
        else if (P->Key > x)
            P = P->Left;
        else P = P->Right;
    }
    return NULL;
}

Tree getMin(Tree T)
{
    if (T == NULL) return NULL;
    if (T->Left == NULL) return T;
    return getMin(T->Left);
}

Tree getNext(int x, Tree T)
{
    Tree P = T, Ancestor = NULL;
    while (P != NULL)
    {
        if (P->Key == x)
        {
            if (P->Right == NULL)
                return Ancestor;
            else return getMin(P->Right);
        }
        else if (P->Key > x)
        {
            Ancestor = P;
            P = P->Left;
        }
        else P = P->Right;
    }
    return NULL;
}

int getHeight(Tree T)
{
    if (T == NULL) return -1;
    else 
    {
        int left_height = getHeight(T->Left);
        int right_height = getHeight(T->Right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

int deleteMin(Tree *pT)
{
    int k;
    if ((*pT)->Left == NULL)
    {
         k = (*pT)->Key;
        (*pT) = (*pT)->Right;
        return k;
    }
    else return deleteMin(&(*pT)->Left);
}

void deleteNode(int x, Tree *pT)
{
    if ((*pT) != NULL)
    {
        if ((*pT)->Key == x)
        {
            if ((*pT)->Left == NULL && (*pT)->Right == NULL)
                (*pT) = NULL;
            else if ((*pT)->Left == NULL)
                (*pT) = (*pT)->Right;
            else if ((*pT)->Right == NULL)
                (*pT) = (*pT)->Left;
            else {
                (*pT)->Key = deleteMin(&(*pT)->Right);
            }
        }
        else if ((*pT)->Key > x) 
            deleteNode(x, &(*pT)->Left);
        else deleteNode(x, &(*pT)->Right);   
    }
}


//======================================
int main ()
{
    Tree T = initTree();
    if (T==NULL) {
        printf("Da khoi tao thanh cong");
    }
    else{
	printf("Loi");
}
}