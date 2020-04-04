#include <iostream>

using namespace std;

enum {MaxRow = 34};
int times = 0;
// Pascal's Triangle  a[i][j] == 0 only if j==0 or i == j

typedef struct pastri{
	int a[34][34];
	pastri(){
		for(int i =0;i < 34; ++i)
			for(int j =0; j< 34; ++j)
			{
				if( j==0 || i==j)
					a[i][j] = 1;
				else
					a[i][j] = -1;
			}
	}
}PT, *pPT;


int solve(PT & t, int i, int j);
PT generate(int rows)
{
	PT t;

	if(rows > MaxRow)
		exit(0);
	for(int i=0; i <rows; ++i)
		for(int j =0; j < i ;++j)
		{
			int & num  =t.a[i][j];			
			if(num ==1)
				continue;
			num = solve(t , i , j);
		}
	return t;
}

int solve(PT & t , int i, int j)
{
	if(t.a[i][j] !=-1)
		return t.a[i][j];
	++times;
	return solve(t ,i-1, j-1)+solve(t,i-1, j);
}

int solve1(int i , int j)
{
    if(j==0 || i==j)
        return 1;
    ++times;
    return solve1(i-1, j-1)+solve1(i-1,j);
}
#define N 10
int main()
{
	//PT t =generate(24)  //avoid Duplicate Caculation;
	//for(int i=0; i<= N ;++i)
	//	std::cout << t.a[N][i] << ",";
	
	for(int i=0; i< N; ++i)
		std::cout << solve1(N, i) << ",";

	std::cout<< std::endl;
	std::cout << "time: "<< times<< std::endl ;
}
