#include<stdio.h>
#define bool int

/* Function to check if x is a power of 2 */
bool isPowerOfTwo(int x)
{
	//First x is for the case when x = 0
	return x && (!(x&(x-1)));	
}

//Driver program to test above function
int main()
{
	isPowerOfTwo(31)?printf("Yes\n"):printf("No\n");
	isPowerOfTwo(17)?printf("Yes\n"):printf("No\n");
	return 0;
}
