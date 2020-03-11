#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <alloca.h>

extern void afunc(void);
extern etext,edata,end;

int bss_var;			//未初始化全局数据存储在BSS区 
int data_var=42;		//初始化全局数据存储在数据区 
#define SHW_ADR(ID,I) printf("the %8s\t is at adr:%8x\n",ID,&I);	//打印地址宏 

int main(int argc,char *argv[])
{
	char *p,*b,*nb;
	printf("Adr etext:%8x\t Adr edata %8x\t Adr end %8x\t\n",&etext,&edata,&end);
	printf("\ntext Location:\n");
	SHW_ADR("main",main);		//查看代码段main函数位置 
	SHW_ADR("afunc",afunc);		//查看代码段afunc函数位置 
	printf("\nbss Location:\n");
	SHW_ADR("bss_var",bss_var);		//查看BSS段变量位置 
	printf("\ndata location:\n");
	SHW_ADR("data_var",data_var);		//查看数据段变量 
	printf("\nStack locations:\n");
	afunc();
	p = (char *)alloca(32);		//从栈中分配空间 
	if(p!=NULL)
	{
		SHW_ADR("start",p);
		SHW_ADR("end",p+31);
	}
	b = (char*)malloc(32*sizeof(char));		//从堆中分配空间 
	nb = (char*)malloc(16*sizeof(char));		//从堆中分配空间 
	printf("\nHeap location:\n");
	printf("the Heap start:%p\n",b);			//堆起始位置 
	printf("the Heap end:%p\n",(nb+16*sizeof(char)));     //堆结束位置 
	printf("\nb and nb in Stack\n");
	SHW_ADR("b",b);								//显示栈中数据b的位置 
	SHW_ADR("nb",b);							//显示栈中数据nb位置 
	free(b);									//释放空间 
	free(nb);									//释放空间 
	
	
}
void afunc(void)
{
	static int long level =0;					//静态数据存储在数据段中 
	int stack_var;								//局部变量，存储在栈区 
	if(++level==5)
	{
		return;
	}
	printf("stack_var is at:%p\n",&stack_var);
	SHW_ADR("stack_var in stack section",stack_var);
	SHW_ADR("level in data section",level);
	afunc();
	 
}



















 
