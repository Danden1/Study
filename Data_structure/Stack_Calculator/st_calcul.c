#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //정수 확인
 
struct Node {
    int data;
    Node* next;
};
 
struct Stack {
    Node *head;
};
 
void StackInit(Stack *stack) {
    stack->head = NULL;
}
int StackEmpty(Stack *stack) {
    if (stack->head == NULL)
        return 1;
    else
        return 0;
}
 
int Peek(Stack * stack)
{
    if (StackEmpty(stack))
    {
        printf("Error!");
        exit(-1);
    }
 
    return stack->head->data;
}
 
void Push(Stack *stack, int data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = stack->head;
    stack->head = newnode;
}
int Pop(Stack *stack) {
    int rdata;
    Node *rnode;
 
    if (StackEmpty(stack)) {
        printf("Error!");
        exit(-1);
    }
    rdata = stack->head->data;
    rnode = stack->head;
 
    stack->head = stack->head->next;
    free(rnode);
 
    return rdata;
}
int GetOpPrec(char op){ //우선순위 결정.
    switch (op)
    {
    case '*':
    case '/':
        return 5;
    case '+':
    case '-':
        return 3;
    case '(':
        return 1;
    }
 
    return -1; 
}
 
 
int WhoPrecOp(char op1, char op2){ //우선순위 비교
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);
 
    if (op1Prec > op2Prec)
        return 1;
    else if (op1Prec < op2Prec)
        return -1;
    else
        return 0;
}
 
 
void ConvToRPNExp(char exp[]){ //후위 표기법으로 변환
    Stack stack;
    int expLen = strlen(exp);
    char * convExp = (char*)malloc(expLen+1);
 
    int i, idx=0;
    char tok, popOp;
    
    memset(convExp, 0, sizeof(char)*expLen+1);
    StackInit(&stack);
 
    for(i=0; i<expLen; i++)
    {
        tok = exp[i];
        if(isdigit(tok))
        {
            convExp[idx++] = tok;
        }
        else
        {
            switch(tok)
            {
            case '(':
                Push(&stack, tok);
                break;
 
            case ')':
                while(1)
                {
                    popOp = Pop(&stack);
                    if(popOp == '(')
                        break;
                    convExp[idx++] = popOp;
                }
                break;
 
            case '+': case '-': 
            case '*': case '/':
                while(!StackEmpty(&stack) && 
                        WhoPrecOp(Peek(&stack), tok) >= 0)
                    convExp[idx++] = Pop(&stack);
 
                Push(&stack, tok);
                break;
            }
        }
    }
 
    while(!StackEmpty(&stack))
        convExp[idx++] = Pop(&stack);
 
    strcpy(exp, convExp);
    free(convExp);
}
 
 
 
int EvalRPNExp(char exp[]){ //후위 표기법 계산
    Stack stack;
    int expLen = strlen(exp);
    int i;
    char tok, op1, op2;
 
    StackInit(&stack);
 
    for (i = 0; i<expLen; i++)
    {
        tok = exp[i];
 
        if (isdigit(tok))
        {
            Push(&stack, tok - '0');     // 숫자로
        }
        else
        {
            op2 = Pop(&stack);    
            op1 = Pop(&stack);
 
            switch (tok)
            {
            case '+':
                Push(&stack, op1 + op2);
                break;
            case '-':
                Push(&stack, op1 - op2);
                break;
            case '*':
                Push(&stack, op1*op2);
                break;
            case '/':
                Push(&stack, op1 / op2);
                break;
            }
        }
    }
    return Pop(&stack);
}
int EvalInfixExp(char exp[]){
    int len = strlen(exp);
    int ret;
    char *expcpy = (char*)malloc(len + 1);
    strcpy(expcpy, exp);
 
    ConvToRPNExp(expcpy);
    ret = EvalRPNExp(expcpy);
 
    free(expcpy);
    return ret;
}
int main() {
    char exp1[] = "1+2*3";
    char exp2[] = "(1+2)*3";
    char exp3[] = "((1-2)+3)*(5-2)";
 
    printf("%s = %d \n", exp1, EvalInfixExp(exp1));
    printf("%s = %d \n", exp2, EvalInfixExp(exp2));
    printf("%s = %d \n", exp3, EvalInfixExp(exp3));
 
    return 0;
}
