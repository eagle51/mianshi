#include <iostream>
#include "jiecheng.h"
#include "zhebanchazhao.h"
#include "mylist.h"
using namespace std;

int main(void)
{
	node *head;
	head = creat();
	cout << "\nlength:" << length(head) << endl;
	print(head);
	head = del(head, 3);
	cout << "\nlength:" << length(head) << endl;
	print(head);
	head = insert(head, 3);
	cout << "\nlength:" << length(head) << endl;
	print(head);
	head = sort(head);
	cout << "\nlength:" << length(head) << endl;
	print(head);
	head = reverse2(head);
	cout << "\nlength:" << length(head) << endl;
	print(head);
	system("pause");
	return 0;
}
