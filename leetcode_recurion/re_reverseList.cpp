#include <iostream>


using namespace std;
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode * reverseList(ListNode * head)
{
	if(head == NULL || head->next == NULL)
		return head;
	ListNode * rest = reverseList(head->next);
	head->next->next= head;
	head->next = NULL;
	return rest;
}
int main()
{
	ListNode n1(1),n2(2),n3(3),n4(4),n5(5);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	ListNode * newList = reverseList(&n1);
	for(ListNode * it = newList; it !=NULL; it=it->next)
		std::cout << "->" << it->val;
}
