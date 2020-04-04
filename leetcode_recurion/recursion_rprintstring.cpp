/*
 * Print a string in reverse order.
 */
#include <vector>
#include <iostream>
#include <string>
using namespace std;
void rprint(const char * ptr)
{
	if(*ptr == 0)
		return; 
	rprint(ptr+1);
	std::cout << *ptr;
}

void reversestring(vector<char>& s )
{
	vector<char>::iterator l = s.begin(),r= s.end();
	if(s.size() <= 1)
		return;
	--r;
	while(l < r)
	{
		char tmp = *r;
		*r = *l;
		*l = tmp;
		++l;
		--r;
	}
}

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};

ListNode * swapPairs(ListNode * head)
{
	ListNode * first= head;
	if(first == NULL)
		return NULL;
	ListNode * second = head->next;
	if(second == NULL)
		return first;

	ListNode * subHead  = swapPairs(second->next );
	head->next= subHead;
	second->next = first;
	return second;
}

int main()
{
	std::string str("hello world\n");
	std::vector<char> chars = {'a','b' ,'c','d'};
	reversestring(chars);
	ListNode n1(2),n2(3),n3(4);
	ListNode head(1);
	head.next= &n1;
	n1.next = &n2;
	n2.next = &n3;
	ListNode * nhead = swapPairs(&head);
	for(ListNode * i= nhead; i!=NULL; i= i->next)
		std::cout<< "->" << i->val;
}
