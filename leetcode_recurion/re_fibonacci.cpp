#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int ,int> cache;
int fib(int N)
{
	if(cache[N])
		return cache[N];
	if(N < 2)
		return N;
	return fib(N-1)+fib(N-2);
}

int main()
{
	std::cout << fib(3) <<std::endl;
}
