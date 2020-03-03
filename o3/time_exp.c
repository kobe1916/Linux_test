#include<stdio.h>
#include<time.h>
#include<string.h>
int main()
{
	time_t timep;
	time(&timep);  
	printf("褰撳墠鏃堕棿:%ld\n",timep);
	time_t timep1;
	printf(" 绗﹀悎鏃ュ父鐢熸椿涔犳儻鐨勫綋鍓嶆椂闂?%s\n",asctime(localtime(&timep1)));
	return 0;
}
