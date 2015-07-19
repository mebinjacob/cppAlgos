#include<stdio.h>

unsigned int swapBits(unsigned int x)
{
	//Get all even bits of x
	unsigned int even_bits = x & 0xAAAAAAAA;
	
	//Get all odd bits of x
	unsigned int odd_bits = x & 0x55555555;

	even_bits >>=1; // Right shift even bits
	odd_bits  >>=1;	// Left shift odd bits

	return (even_bits|odd_bits); // Combine odd and even bits
}

//Driver program to test above function
int main()
{
	unsigned int x = 23;
	
	//Output is 43 (00101011)
	printf("%u", swapBits(x));
	return 0;
}
