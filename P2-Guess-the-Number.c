#include <stdio.h>
#include <time.h>

int main()
{
	/*srand(time(NULL));*/
	int N; /*= rand() % 100 + 1;*/
	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &N);
	int answer; // ����
	int chance = 5; // ��ȸ 5��
	while (1)
	{
		printf("  ���� ��ȸ�� %d���Դϴ�.\n", chance--);
		printf("���ڸ� ���߾� ������. [1 ~ 100] : ");
		scanf_s("%d", &answer);

		if (answer > N)
		{
			printf("\nDOWN��\n\n");
		}
		else if (answer < N)
		{
			printf("\nUP��\n\n");
		}
		else if (answer == N)
		{
			printf("\n����!\n\n");
			break;
		}
		else
		{
			printf("���ڸ� �Է��ؾ� �մϴ�!");
		}

		if (chance == 0)
		{
			printf("��ȸ�� ��� ���̳׿�! �����߽��ϴ�.\n\n");
			break;
		}
	}
	return 0;
}