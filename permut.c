#include<stdio.h>

void swap(char *x,char *y)
{
	char t;
	t=*x;
	*x=*y;
	*y=t;
}

void permut(char *str,int j)
{
	int i,k=0;
	if(!str[j])
	{
		printf("%s ",str);
		return;
	}
	for(i=j;str[i];i++)
	{
		if(!(k&(1<<(str[i]-97))))
		{
		k=k|1<<(str[i]-97);
		swap(str+i,str+j);
		permut(str,j+1);
		swap(str+i,str+j);
		//k=k^(1<<(str[i]-97));
		}
	}

}

int main()
{
	char str[20];
	scanf("%s",str);
	permut(str,0);
	return 0;
}
