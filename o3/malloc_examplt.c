#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[],char* envp[])   //argc参数个数，argv[]为参数 envp[]存放所有环境变量 
{
	int count;
	int* array;
	if((array=(int*)malloc(10*sizeof(int)))==NULL)		//分配空间 
	{
		printf("malloc memory unsuccessful");
		exit(1);
		
	}
	for(count=0;count<10;count++)		//赋值 
	{
		*array=count;
		array++;
	}
	for(count=9;count>=0;count--)		//赋值 
	{
		array--;
		printf("%4d",*array);
	}
	printf("\n");
	free(array);						//释放空间 
	array=NULL;							//将指针置为空，避免不安全访问 
	exit(0)； 
}
















