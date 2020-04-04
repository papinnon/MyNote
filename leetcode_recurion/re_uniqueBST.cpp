#include <iostream>
#include <stdlib.h>
#include <unordered_map>

std::unordered_map<long ,long> memo;
// T(n) = sigma(i=0, i=n) T(i)*T(n-i-1)
//
long TreeCount(long n)
{
	long acc=0;
	if(memo[n] )
		return memo[n];
	for(long i=0; i<n ;++i)
	{
		acc +=  TreeCount(i)*TreeCount(n-i-1);
	}
	memo[n]= acc;
	return acc;
}

int main(int argc, char ** argv)
{
	memo[0]= 1;
	memo[1]= 1;
	std::cout<< TreeCount(atol(argv[1])) <<std::endl;
}
