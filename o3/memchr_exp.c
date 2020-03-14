#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char *p1 = "abcdefabcdefg";
	char *p2 = NULL;
	char *p3 = NULL;
	p2 = memchr(p1,'c',10);  //在p1起始位置10个字符内查找c 
	
	printf("search in 10,p2-p1=%d\n",p2-p1);
	p3 = memchr(p1,'c',2);   //在p1起始位置2个字符内查找c 
	printf("search in 2,p3-p1=%d\n",p3-p1);
	return 0;
}
