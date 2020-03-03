#include <stdio.h>
#include <sys/resource.h>
int main()
{
	int i;
	struct rlimit r[6];
	for(i =0;i<=6;i++)
	{
		getrlimit(i,&r[i]);
		printf("褰撳墠闄愬埗锛?lu,绯荤粺闄愬埗锛?lu\n",r[i].rlim_cur,r[i].rlim_max);
	}
	return 0;
}
