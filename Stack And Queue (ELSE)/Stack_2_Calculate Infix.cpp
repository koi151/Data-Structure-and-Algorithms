#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 100
typedef int ElementType;

typedef struct{
    ElementType Data[Max];
    ElementType Top;
}Stack;

void makenullStack(Stack *pS){
    pS->Top = Max;
}

int emptyStack(Stack S){
    return S.Top == 100;
}

void hienthi(Stack S){
    while (!emptyStack(S)){
        printf("%d ", S.Data[S.Top]);
        S.Top ++;
    }
    printf("\n");
}

ElementType top(Stack S){
    return S.Top[S.Data];
}

void pop(Stack *pS){
    if (!emptyStack(*pS))
        pS->Top ++;
}

void push(ElementType x, Stack *pS){
    if (pS->Top != 0){
        pS->Top --;
        pS->Data[pS->Top] = x;
    } else {
        printf("Stack full!");
    }
}

int Priority(char op){
  if (op=='+' || op=='-')
      return 1;
  else if (op=='*' || op=='/' || op == '%')
      return 2;
    return 0;
}

void to_Postfix(char infix[], char postfix[]) {
  Stack s;
  makenullStack(&s);
  int len = 0;
  for (int i = 0; i < strlen(infix); i++) {
  	if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9')) {
  		postfix[len] = infix[i];
  		len++;
  	}
  	else if (infix[i] == '(') {
        push(infix[i], &s);
  	}
  	else if (infix[i] == ')') {
  		while (top(s) != '(')
  		{
  			postfix[len] = top(s);
  			pop(&s);
  			len++;
  		}
  		pop(&s);
  	}
  	else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%')
  	{
  		while (!emptyStack(s) && top(s) != '(' && Priority(infix[i]) <= Priority(top(s)))
  		{
  			postfix[len] = top(s);
  			pop(&s);
  			len++;
  		}
  		push(infix[i], &s);
  	}

  }

while (!emptyStack(s))
  {
  	postfix[len] = top(s);
  	pop(&s);
  	len++;
  }
  postfix[len] = '\0';
}

float evaluate(char st[]) {
 Stack S;
 float result = 0;
 makenullStack(&S);
 int len = strlen(st);
 for (int i = 0; i < len; i++) {
 	if (st[i] >= '0' && st[i] <= '9')
 		push(st[i] - '0', &S);
 	else if (st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/' || st[i] == '%')
 	{
 		result = top(S);
 		pop(&S);
 		if (st[i] == '+')
 			result = top(S) + result;
 		else if (st[i] == '-')
 			result = top(S) - result;
 		else if (st[i] == '*')
 			result = top(S) * result;
 		else if (st[i] == '/')
 			result = top(S) / result;
        else if (st[i] == '%')
 			result = top(S) % (int)result;
 		pop(&S);
 		push(result, &S);
     	}
    }
    return result;
}

//====================================
int main (){    
    char infix[1000], postfix[1000];
    fgets(infix, 1000, stdin);
    if (infix[strlen(infix)-1] == '\n')
      infix[strlen(infix)-1] = '\0';
    
    Stack S;
    makenullStack(&S);

    to_Postfix(infix, postfix);
    for ( int i = 0; i < strlen(postfix); i ++)
      printf("%c ", postfix[i]);
    printf("\n%.2f",evaluate(postfix));

    return 0;
}