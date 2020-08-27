#include <stdio.h>
#include <time.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main()
{
	srand(time(NULL));
	int count = 0;
	
	printf("���й�ȣ�� �ɸ� �濡 �������ȴ�! ������ Ǯ�� ���� Ż����!��\n\n\n");
	for (int i = 1; i < 6; i++)
	{	
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);

		/*printf("%d X %d�� ����? ", num1, num2);*/
		showQuestion(i, num1, num2);

		int answer;
		scanf_s("%d", &answer);
		if (answer == -1)
		{
			printf("\n������� �����մϴ١�\n\n\n\n");
			exit(0);
		}
		else if (answer == num1 * num2)
		{
			success();
			count++;
		}
		else
		{
			fail();
			printf(" ������ �� �濡�� ��������!\n\n");
			break;
		}
	}

	printf("\n\n������ 5���� ��й�ȣ �� %d���� �������ϴ١�\n", count);
	return 0;
}

int getRandomNumber(int level)
{
	//level�� �����Ҽ��� *10+5�� ���̵� ����. +5�� *0 ������
	return rand() % (level * 10) + 5;
}
void showQuestion(int level, int num1, int num2)
{
	printf("\n\n\n-----%d��° ��й�ȣ-----\n\n", level);
	printf("\n\t%d X %d��?\n\n", num1, num2);
	printf("------------------------\n");
	printf("\n��й�ȣ�� �Է��ϼ��� (�����ϱ� : -1) >>");
}
void success()
{
	printf("\n\n �����Դϴ�! ��й�ȣ 1���� �����߽��ϴ�.");
}
void fail()
{
	printf("\n\n �����Դϴ�!");
}