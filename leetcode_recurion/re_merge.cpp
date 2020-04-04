#include <iostream>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};


ListNode * mergeList(ListNode * left, ListNode * right)
{
	ListNode * newl, *newr, *min;
	if(left == NULL || right == NULL)
		return left == NULL?right: left;
	if(left->val > right->val)
	{
		newl = left;
		newr = right->next;
		min = right;
	}
	else
	{
		newl = left->next;
		newr = right;
		min = left;
	}
	ListNode * first = mergeList(newl, newr);
	min->next = first;
	return min;
}

int main()
{
	ListNode l1(1),l2(2),l3(4),r1(1),r2(3),r3(4);
	l1.next = &l2;
	l2.next = &l3;
	r1.next = &r2;
	r2.next = &r3;
	for(ListNode * it=mergeList(&l1, &r1); it!=NULL; it= it->next )
		std::cout<< it->val << ",";
}
