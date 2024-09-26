#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

void GetNext(char* sub,int* next,int lenSub)
{
	next[0] = -1;
	next[1] = 0;

	int i = 2, k = 0;
	while (i < lenSub)
	{
		if (k == -1 || next[i - 1] == next[k])
		{
			next[i++] = ++k;
		}
		else
		{
			k = next[k];
		}

	}
}


int KMP(char* str, char* sub, int pos)
{
	assert(str && sub);
	int lenStr = strlen(str);
	int lenSub = strlen(sub);
	if (lenStr == 0 || lenSub == 0) return -1;
	if (pos < 0 || pos > lenSub) return -1;

	int* next = (int*)malloc(sizeof(int) * lenSub);
	assert(next);

	GetNext(sub, next,lenSub);

	int i = pos,j = 0;
	while ((i < lenStr) && (j < lenSub))
	{
		if (j == -1 || str[i] == sub[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= lenSub)
		return i - j;
	return -1;

}
int main()
{
	char str[] = "abcabcabcabcdabcde";
	int ret = KMP(str,"da",0);
	printf("%d ", ret);
	return 0;
}