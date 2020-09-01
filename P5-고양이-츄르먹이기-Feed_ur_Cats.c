#include <stdio.h>
#include <time.h>

int level;
int hungerIndex[5];
int* ptrcat;

void showCats();
void initData();
void decreaseIndex(long passedTime);
int checkCatsAlive();


int main(void)
{
	//intro
	printf("\n\n������������������������������������   ����� �򸣸��̱�   ������������������������������������\n\n");
	printf("\n\n\t  ... �����Ϸ��� EnterŰ�� �������� ...\n\n");
	getchar();

	printf("\n\n����������������   1: ���ӽ���  2: ���ӹ��  3: ��������   ������������������\n\n\n");
	int start;
	scanf_s("%d", &start);

	if (start == 1)
	{
		printf("\n\n������������������������������������   ������ �����մϴ�   ������������������������������������\n\n");
	}
	else if (start == 2)
	{
		printf("\n\n������������������������������������        ���� ���       ������������������������������������\n\n");
		printf("\n\n ����� 5������ ����̸� Ű��� �ִ�.\n ���� ���� �ʾ� ����̵��� ��������� �������� �ִ�!\n ����̵鿡�� �򸣸� �Կ��� ��������� �ʵ��� ������!\n ��������� 0�� �Ǹ� ����̵��� �װԵȴ�.\n\n\n\n");
		printf("������������������������������������������������������������������������������������������������������������������������\n\n");
	}
	else if (start == 3)
	{
		printf("\n\n������������������������������������   ������ �����մϴ�   ��������������������������������������\n\n");
		exit(0);
	}
	else
	{
		printf(" \n\n �Է� ���� ! (1~3) ���ڸ� �Է����ּ��� !\n");
		exit(0);
	}
	getchar();
	printf("\n\n\n\t  ... �����Ϸ��� EnterŰ�� �������� ...\n\n\n\n");
	getchar();
	printf("������������������������������������������������������������������������������������������������������������������������\n\n\n\n\n\n");

	long startTime = 0;
	long totalPassedTime = 0; // ���� ����ð�
	long prvPassedTime = 0; // ���������� ���� �� �ð����� ���� �帥 �ð�

	int N; // ��� ����̿��� �򸣸�.
	initData();

	ptrcat = hungerIndex;

	startTime = clock(); 

	while (1)
	{
		showCats();
		printf("� ����̿��� �򸣸� �ٷ�? ");
		scanf_s("%d", &N);

		if (N < 1 || N > 5) // 1~5 �� ���� ���� üũ
		{
			printf("\n\n�� ����̴� 1��~ 5���ۿ� ����� ��\n\n\n");
			continue;
		}

		totalPassedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("\n\n ��  ���� �ð� : %ld�� ���               \n", totalPassedTime);

		prvPassedTime = totalPassedTime - prvPassedTime;
		printf(" ��  ���������� �� ���� �ð� : %ld�� �� \n\n", prvPassedTime);

		decreaseIndex(prvPassedTime); // ������� ����

		if (ptrcat[N - 1] <= 0) // ����� ��������� 0�̸�
		{
			printf("\n\n�� %d�� ����̰� �׾����ϴ�.. ��\n\n\n\n", N);
		}
		else if (ptrcat[N - 1] + 1 < 100)
		{
			printf("%d�� ����̿��� �򸣸� �Կ����ϴ�\n\n", N);
			ptrcat[N - 1] += 2; // ������� �߰�
		}

		if (totalPassedTime / 15 > level - 1) // level �ý���
		{
			level++;
			printf("\n\n\n�� ����̵��� �򸣸� �԰� ��緮�� %d000 Kcal���� %d000 Kcal�� �þ����ϴ� ��\n            ��緮 ���� : ���� ����̵��� ���� �� ������մϴ�\n\n\n\n\n", level - 1, level);

			if (level == 5)
			{
				printf("\n\n�� ����̵��� ��緮�� 5000 Kcal�� �޼��Ͽ� ���� ���������� �մϴ�! ��\n                ���� �򸣸� �׸��൵ �� �� �����ϴ�\n\n");
				printf("\n\n������������������������������������   ������ �����մϴ�   ��������������������������������������\n\n");
				exit(0);
			}

		}

		if (checkCatsAlive() == 0) // ��ü ����� ���� ���� Ȯ��
		{
			printf("\n\n�� ��� ����̵��� ����ļ� �׾���Ƚ��ϴ�.. ��\n\n");
			printf("\n\n������������������������������������   ������ �����մϴ�   ��������������������������������������\n\n");
			exit(0);
		}

		prvPassedTime = totalPassedTime;
	}

	return 0;
}

void initData()
{
	level = 1;
	for (int i = 0; i < 5; i++) // ����� 5����
	{
		hungerIndex[i] = 100; // ������� (0 - 100)
	}
}

void showCats() // ����� ���� and ���� ������� �˸�
{
	printf("�����  %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5);
	printf("�������");
	for (int i = 0; i < 5; i++)
	{
		printf("  %3d ", hungerIndex[i]);
	}
	printf("\n\n");
}

void decreaseIndex(long passedTime)
{
	for (int i = 0; i < 5; i++)
	{
		hungerIndex[i] -= (level * 2 * (int)passedTime); // ���̵� ���� ��
		if (hungerIndex[i] < 0)
		{
			hungerIndex[i] = 0;
		}
	}
}

int checkCatsAlive()
{
	for (int i = 0; i < 5; i++)
	{
		if (hungerIndex[i] > 0)
			return 1; // true -> ��� ����
	}
	return 0;
}