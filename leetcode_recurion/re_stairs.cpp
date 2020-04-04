#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

unordered_map<int, int> cache;
vector<int> buf;
int init()
{
cache[0]=0;
cache[1]=1;
cache[2]=2;
buf.assign(1000,0);
buf[0]=0;
buf[1]=1;
buf[2]=2;
return 0;
}

int climbStairs(int n)
{
	if(cache[n]!=0)
		return cache[n];
	int ways = climbStairs(n-1)+climbStairs(n-2);
	cache[n] = ways;
	return ways;
}

int climbStairs1(int n)
{
	if(n==1 || n==2)
		return n;
	return climbStairs1(n-1)+climbStairs1(n-2);
}
int main()
{
	init();
	std ::cout<< climbStairs(6)  <<std::endl;

}
