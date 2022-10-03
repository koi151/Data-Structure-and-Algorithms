#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int Data;
    struct Node *Left, *Right;
}Node;
typedef Node* Tree;

// Tạo nút có giá trị value
Tree createNode(int value){
    struct Node* N = (Node*)malloc(sizeof(Node));
    N->Data = value;
    N->Left = NULL;
    N->Right = NULL;
    return N;
}

// Khởi tạo, trả về 1 cây rỗng
Tree initTree(){
    return NULL;
}

// Kiểm tra cây T có rỗng không
int isEmpty(Tree T){
    return T == NULL;
}

// Xác định con trái
Tree leftChild(Tree T){
    if (T != NULL) return T->Left;
    else return NULL;
}

// Xác định con phải
Tree rightChild(Tree T){
    if (T != NULL) return T->Right;
    else return NULL;
}

// Kiểm tra xem nút có pháỉ là nút lá không
int isLeaf(Node* N){
    if (N != NULL)
        // return (N->Left == NULL && N->Right == NULL)
        return (leftChild(N) == NULL) && (rightChild(N) == NULL);
    else return 0; 
}


// Duyệt tiền tự cây nhị phân T (NLR)
void preOrder(Tree T){
    if (T != NULL){
        printf("%d ", T->Data);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

// Duyệt trung tự cây nhị phân T (LNR)
void inOrder(Tree T){
    if(T != NULL){
        inOrder(T->Left);
        printf("%d ", T->Data);
        inOrder(T->Right);
    }
}


// Duyệt hậu tự cây nhị phân T (LRN)
void postOrder(Tree T){
    if (T != NULL){
        postOrder(T->Left);
        postOrder(T->Right);
        printf("%d ", T->Data);
    }
}

// Tạo một cây nhị phân từ giá trị x và hai cây con l, r
Tree createTree(int x, Tree l, Tree r){
    Tree T = (Node*)malloc(sizeof(Node));
    T->Data = x;
    T->Left = l;
    T->Right = r;
    return T;
}

// Tính chiều cao của cây nhị phân T
// Nếu cây rỗng trả về -1
int getHeight(Tree T){
    if (T == NULL) return -1;
    else {
        int left_height = getHeight(T->Left);
        int right_height = getHeight(T->Right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

// Đếm số nút lá của cây nhị phân T
int getLeaves(Tree T){
    if (T  == NULL) return 0;
    else if (T->Left == NULL && T->Right == NULL) return 1;
    else return getLeaves(T->Left) + getLeaves(T->Right);
}




//=================================
int main (){

    return 0;
}