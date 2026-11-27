#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
typedef  int  Element;
typedef struct node {
	Element data;
	struct node* next;
}Node;
Node* initList(Element e) {//初始化链表
	Node* p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	p->data = e;
	return p;
}
Node* gettail(Node* p) {//获取尾节点
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}
Node* tailadd(Node* tail, Element e) {//尾插
	Node* l = (Node*)malloc(sizeof(Node));
	l->data = e;
	tail->next = l;
	l->next = NULL;
	return l;
}
int addpos(Node* p, Element e, int pos) {//特定位置插入
	if (pos < 0) { return 0; }
	for (int i = 0;i < pos - 1;i++) {
		p = p->next;
		if (p == NULL) {
			return 0;
		}
	}
	Node* l = (Node*)malloc(sizeof(Node));
	l->data = e;
	l->next = p->next;
	p->next = l;
	return 1;
}
void ListNode(Node* p) {//遍历单链表
	p = p->next;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
	printf("\n");
}
int DataDelete(Node* p, int pos) {//删除特定位置节点
	if (pos < 0) { return 0; }
	for (int i = 0;i < pos - 1;i++) {
		if (p == NULL) { return 0; }
		p = p->next;
	}
	Node* q = p->next;
	p->next = q->next;
		free(q);
return 1;
}
void freeList(Node* p) {//清空链表
	Node* l = p;
	p = p->next;
	Node* q ;
	while (p != NULL) {
		q = p->next;//先保留p的next域，（不要写q=q->next会越界）
		free(p);
		p = q;
	}
	l->next = NULL;////清空后一定要将头指针next域赋为NULL
}
int Listlength(Node* p) {//获取单链表长度，结果包含头节点
	int len = 0;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}
int findNodeFS(Node*p,int k) {
	Node* fast = p->next, * slow = p->next;
	for (int i = 0;i < k;i++) {
		if (fast == NULL) { printf("位置不合理无法查找\n");return 0; }
		fast = fast->next;
	}
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
		}
	printf("倒数第%d个节点的数据域是%d\n", k,slow->data);
	return 1;
}
int main(void) {
	Node* List = initList(7);
	Node* tail = gettail(List);
	tail = tailadd(tail, 6);
	tail = tailadd(tail, 5);
	tail = tailadd(tail, 8);
	tail = tailadd(tail, 7);
	tail = tailadd(tail, 0);
	tail = tailadd(tail, 1);
	tail = tailadd(tail, 3);
	if (!addpos(List, 6, 80)) {
		printf("位置不合理无法插入\n");
	}
	ListNode(List);
	if (!DataDelete(List, 4)) {
		printf("位置不合理无法删除\n");
	}
	ListNode(List);
	printf("%d\n", Listlength(List));
	findNodeFS(List, 2);
	freeList(List);
	ListNode(List);
	printf("%d\n", Listlength(List));
	findNodeFS(List, 2);

	return 0;
}