#include <stdio.h>

int main(void)
{
	char z;
	int x, y;
	while(1)
	{
		printf("����� ������ �Է��ϼ��� : ");
		scanf("%d %c %d", &x, &z, &y);
		if(z == '+')
		{
			printf("%d %c %d = %d\n", x, z, y, x + y);
		}
		else if(z == '-')
		{
			printf("%d %c %d = %d\n", x, z, y, x - y);
		}
		else if(z == '*')
		{
			printf("%d %c %d = %d\n", x, z, y, x * y);
		}
		else if(z == '/')
		{
			printf("%d %c %d = %d\n", x, z, y, x / y);
		}
		else if(z == '%')
		{
			printf("%d %c %d = %d\n", x, z, y, x % y);
		}
		else
		{
			printf("�ùٸ� ������ �ƴմϴ�.\n");
		}
		getchar();
		printf("���⸦ �����ұ��? (O/X) ");
		getchar();
		scanf("%c", &z);
		if(z == 'x' || z == 'X')
		{
			continue;
		}
		else if(z == 'o' || z == 'O')
		{
			break;
		}
		else
		{
			printf("\n");
			continue; 
		}
	}
	return 0; 
}
