#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define MAXSIZE 100
typedef int Element;
typedef struct {
 Element data[MAXSIZE];//数据域
 int top;//栈顶下标
}stack;
stack*initstack(void){
    stack* s = (stack*)malloc(sizeof(stack));
    if (s != NULL) {
        s->top = -1;
    }//初始化栈
    return s;
}
int isEmpty(stack* s) {//判断是否空栈
    if (s->top == -1) {
        printf("空栈\n");
        return 1;
    }
        return 0;
}
int push(stack* s, Element e) {//入栈
    if (s->top >= MAXSIZE - 1) {//判断栈是否已满
        printf("满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}
Element pop(stack* s, Element* e) {//出栈
    if (isEmpty(s)) {//判断1是否空栈
        return 0;
    }
    *e = s->data[s->top];//带出栈顶元素
    s -> top--;//栈顶指针--
    return 1;
}
int GetStacktop(stack* s,Element*e) {//获取栈顶元素不出栈
    if (isEmpty(s)) {
        return 0;
   }
    *e = s->data[s->top];
    return 1;
}
int LiseStack(stack* s) {
    if (isEmpty(s)) {
        return 0;
    }
    for (int i = 0;i <= s->top;i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
    return 1;
}




int main() {
    stack* s = initstack();
    if (s == NULL) {
        printf("error\n");
        return 0; }
    int n;
    Element e;
    do {
        scanf("%d", &n);
        if (n > MAXSIZE) {
            printf("超了\n");
        }
    } while (n > MAXSIZE);
    for (int i = 0;i < n;i++) {
        scanf("%d", &e);
        push(s, e);
    }
    LiseStack(s);
    while (!isEmpty(s)) {
        pop(s, &e);
        printf("%d\n", e);
        GetStacktop(s, &e);
        printf("%d\n", e);
    }
    LiseStack(s);
    return 0;
}