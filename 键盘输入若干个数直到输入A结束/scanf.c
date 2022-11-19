#include <stdio.h>
void main()
{	
	int n,odds,evens,count;
	double avg;
	odds=evens=count=0;
	while(1)
	{
		if(scanf("%d",&n))//当输入不满足格式控制的值时scanf不从缓冲区读取数据
		{
			count++;
			if(n%2==0)
				evens+=n;
			else
				odds+=n;
		}
		else
		{
			if(getchar()=='A')
			break;
		}
	}
	avg=1.0*(odds+evens)/count;
	printf("奇数之和:%d\n偶数之和:%d\n平均值%g\n",
	        odds,evens,avg);
}