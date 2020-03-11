#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char **argv)
{
	int result;
	optrr = 0;	//不输出错误信息 
	while((result = gepopt(argc,argv,"ab:c::"))!=-1)
	{			//一直解析 
		switch(result)
		{
			case 'a':			//选项a 
				printf("option=a,optopt=%c,optarg=%s\n",optopt,optarg);
				braek;
			case 'b':
				printf("option=b,optopt=%c,optarg=%s\n",optopt,optarg);
				braek;
			case 'c':
				printf("option=c,optopt=%c,optarg=%s\n",optopt,optarg);
				braek;
			case '?':
				printf("result=?,optopt=%c,optarg=%s\n",optopt,optarg);
				braek;
			defult:
				printf("defult,result=%c\n",result);
				break;	
		}
		printf("argv[%d]=%s\n",optind,argv[optind]);
	}
	printf("result=-1,optind=%d\n",optind);		//打印最后有可能出错的位置 
	
	for(result = optind;result<argc;result++)
		printf("----argv[%d]=%s\n",result,argv[result]);	//打印余下错误选项 
	for(result = 1;result<argc;result++)
		printf("at the end-----argv[%d]=%s\n",result,argv[result]);	//打印重新排列的选项列表 
	return 0;
}





















