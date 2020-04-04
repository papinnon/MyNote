#include <iostream>

int KthSymbol(int r, int c)
{
	int zero []= {0,1};
	int one []= {1,0};
	if(r == 1 && c== 1)
		return 0;
	int d = KthSymbol(r-1, (c+1)/2);
	int * tmp = (d == 0? zero: one);
	int idx = (c-1)%2;
	return tmp[idx];
}

int main()
{
	std::cout<< KthSymbol(4,5);
}
