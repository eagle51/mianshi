/************************************************************************/
/*链表的创建，测长，打印，插入，删除，其中插入和删除有可能会重置头结点               */
/************************************************************************/
#ifndef __MYLIST_H
#define __MYLIST_H
#pragma warning( disable : 4996)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
using namespace std;
typedef struct mylist
{
	int data;
	struct mylist *next;
}node;

node *creat()
{
	node *head, *p, *s;
	int x, cycle = 1;
	head = (node *)malloc(sizeof(node));
	p = head;
	while (cycle) {
		printf("\nplease input the data:");
		scanf("%d",&x);
		if (x != 0) {
			s = (node *)malloc(sizeof(node));
			s->data = x;
			printf("\n%d",s->data);
			p->next = s;
			p = s;
		}
		else cycle = 0;
	}
	head = head->next;
	p->next = NULL;
	//printf("\n yyy %d",head->data);
	return (head);
}
int length(node *head)
{
	int n = 0;
	node *p;
	p = head;
	while (head != NULL) {
		n++;
		head = head->next;
	}
	return (n);
}
void print(node *head)
{
	node *p;int n;
	n = length(head);
	printf("\nNow,these %d records are:\n",n);
	p = head;
	if(head != NULL)
		while (p != NULL)
		{
			printf("\n uuu %d   ",p->data);
			p = p->next;
		}
}
node *del(node *head, int num)
{
	node *p1 = NULL, *p2 = NULL;
	p1 = head;
	while (num != p1->data && p1->next!= NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (num == p1->data) {
		if (p1 == head) {
			head = p1->next;
			free(p1);
		}
		else
			p2->next = p1->next;
	}
	else
		printf("\n%d could not been found",num);
	return (head);
}

node *insert(node *head, int num)
{
	node *p0 = NULL;
	node *p1 = NULL;
	node *p2 = NULL;
	p1 = head;
	p0 = (node *)malloc(sizeof(node));
	p0->data = num;
	while (p0->data > p1->data&&p1->next != NULL) {
		p2 = p1;
		p1 = p1->next;
	}
	if (p0->data <= p1->data) {
		if (head == p1) {
			p0->next = p1;
			head = p0;
		}
		else
		{
			p2->next = p0;
			p0->next = p1;
		}
	}
	else {
		p1->next = p0;
		p0->next = NULL;
	}
	return (head);
}

node* sort(node* head)
{
	node *p = NULL;
	node *p2 = NULL;
	node *p3 = NULL;
	int n = 0;
	int temp = 0;
	n = length(head);
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	p = head;
	for (int j = 1;j < n;++j) {
		p = head;
		for (int i = 0;i < n - j;++i) {
			if (p->data > p->next->data) {
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
	}
	return (head);
}

node *reverse(node *head)
{
	node *p1, *p2, *p3;
	if (head == NULL || head->next == NULL)
		return head;

	p1 = head, p2 = p1->next;
	while (p2) {
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}

	head->next = NULL;
	head = p1;
	return (head);
}
node *reverse2(node *head)
{
	node *p, *q;
	p = head->next;
	while (p->next != NULL) {
		q = p->next;
		p->next = q->next;
		q->next = head->next;
		head->next = q;
	}
	p->next = head;
	head = p->next->next;
	p->next->next = NULL;
	return head;
}
#endif