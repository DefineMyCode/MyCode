#include <stdio.h>
void main()
{	
	int n,odds,evens,count;
	double avg;
	odds=evens=count=0;
	while(1)
	{
		if(scanf("%d",&n))//�����벻�����ʽ���Ƶ�ֵʱscanf���ӻ�������ȡ����
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
	printf("����֮��:%d\nż��֮��:%d\nƽ��ֵ%g\n",
	        odds,evens,avg);
}