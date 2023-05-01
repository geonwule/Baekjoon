#include <stdio.h>
#include <string.h>
int main() {
	int ret=0;
	for(int i=1;i<=5;i++)
	{
		char arr[11];
		scanf("%s",arr);
		for(int j=0;arr[j]!='\0';j++)
		{
			if(strncmp("FBI",&arr[j],3)==0)
			{
				if(ret>0)
					printf(" ");
				printf("%d",i);
				ret++;
				break ;
			}
		}
	}
	if(ret==0)
		printf("HE GOT AWAY!");
}
