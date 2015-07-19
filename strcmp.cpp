#include<stdio.h>
#include<iostream>
using namespace std;

/*Implementation of strcmp that ignores cases*/
int stricmp(char* string1, char* string2)
{
	int i;
	for(i = 0; string1[i] && string2[i]; ++i)
	{
		// If characters are same or inverting the sixth bit makes them the same, them continue
		if(string1[i] == string2[i] || (string1[i] ^ 32) == string2[i])
			continue;
		else
			break;
	}

	/* */
	if(string1[i] == string2[i])
		return 0;
	if((string1[i]|32) < (string2[i]|32))
		return -1;
	return 1;
}

int main()
{
	//main method to test some cases!!!
	printf("%d\n",stricmp("mebin", "jacob"));
	printf("%d\n",stricmp("mebin", "Mebin"));
	return 0;
}
