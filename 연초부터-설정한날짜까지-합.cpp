#include <stdio.h>

// int�� int�� �� �Է��ϸ� ���� ��µ˴ϴ�! yjg.lab
int getDays(int month, int day)
{
	int i, sum = 0;	
	for(i = 1; i < month; i++)
	{
		if(i == 2)
		{
			sum += 28;
		}
		else if(i == 8)
		{
			sum += 31;
		}
		else if(i == 9)
		{
			sum += 30;
		}
		else if(i == 10)
		{
			sum += 31;
		}
		else if(i == 11)
		{
			sum += 30;
		}
		else if(i == 12)
		{
			sum += 31;
		}
		else if(i % 2 == 0)
		{
			sum += 30;
		}
		else
		{
			sum += 31;
		}
	}
	return sum + day;
} 

int main(void)
{
	int month, day;
	scanf("%d�� %d��", &month, &day);
	printf("1�� 1�Ϻ��� %d�� %d�ϱ����� ���� %d���Դϴ�.", month, day, getDays(month, day));
}
