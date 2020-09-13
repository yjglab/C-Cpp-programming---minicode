#include <stdio.h>
#include <time.h>


int arrayCard[4][5];
int checkCard[4][5];
char* strCard[10];

void initCardArray();
void initCardName();
void shuffleCard();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
int foundAllCard();
void printCard();
void printQuestion();




int main(void)
{
	//intro
	printf("\n\n������������������   ���� ī�� ���߱�   ������������������\n\n");
	printf("\n\n  ... �����Ϸ��� EnterŰ�� �������� ...\n\n");
	getchar();

	printf("\n��������������������������������������������������������������������������������\n");
	printf("  1: ���ӽ���  2: ���ӹ��  3: �������� ");
	printf("\n��������������������������������������������������������������������������������\n\n");
	int start;
	scanf_s("%d", &start);

	if (start == 1)
	{
		printf("\n\n������������������   ������ �����մϴ�   ����������������\n\n");
	}
	else if (start == 2)
	{
		printf("\n\n����������������        ���� ���       ����������������\n\n");
		printf("\n\n 10������ ���� ī�尡 2�徿 �� 20���� �ֽ��ϴ�.\n ������ �����ϸ� ī����� ��� �޸����� �ٲ�ϴ�.\n ī�带 2�� ��� ���� �׸��� ���� ī�带 ���߾����.\n\n\n");
		printf("��������������������������������������������������������������������������������\n\n");
	}
	else if (start == 3)
	{
		printf("\n\n������������������   ������ �����մϴ�   ����������������\n\n");
		exit(0);
	}
	else
	{
		printf(" \n\n �Է� ���� ! (1~3) ���ڸ� �Է����ּ��� !\n");
		exit(0);
	}
	getchar();
	printf("\n\n    ... EnterŰ�� ���� �����ϼ��� ...\n\n\n");
	getchar();
	printf("��������������������������������������������������������������������������������\n\n\n\n\n\n");

	srand(time(NULL));
	
	initCardArray();
	initCardName();
	shuffleCard();

	int failCount = 0;
	printCard();

	while (1)
	{
		int select1 = 0;
		int select2 = 0;

		
		printQuestion();
		printf("\n����������������������������������������������������������������������������������\n");
		printf("\n\n������ ī�� 2���� ��ȣ�� �Է��ϼ��� : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2)
			continue;

		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		if ((checkCard[firstSelect_x][firstSelect_y] == 0
			&& checkCard[secondSelect_x][secondSelect_y] == 0)

			&&

			(arrayCard[firstSelect_x][firstSelect_y]
				== arrayCard[secondSelect_x][secondSelect_y])
			)
		{
			printf("\n\n\n\n\n\n\n\n\n�ܼ���! [%s] ī�带 ã�ҽ��ϴ�!��\n\n", strCard[arrayCard[firstSelect_x][firstSelect_y]]);
			checkCard[firstSelect_x][firstSelect_y] = 1;
			checkCard[secondSelect_x][secondSelect_y] = 1;
		}
		else
		{
			printf("\n\n\n\n\n\n\n\n\n�����! ");
			printf("�� ī��� %d�� [%s] ī��� ", select1, strCard[arrayCard[firstSelect_x][firstSelect_y]]);
			printf("%d�� [%s] ī���Դϴ١�", select2, strCard[arrayCard[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++;
		}

		if (foundAllCard() == 1)
		{
			printf("\n����������������������������������������������������������������������������������\n");
			printf("\n\n�������մϴ�! ��� ī�带 �� ã�ҽ��ϴ�!��\n");
			printf("���� Ƚ�� : %dȸ\n\n", failCount);
			break;
		}
	}




	return 0;
}

void initCardArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayCard[i][j] = -1;
		}
	}
}

void initCardName()
{
	strCard[0] = "ġŲ";
	strCard[1] = "����";
	strCard[2] = "����";
	strCard[3] = "ȸ��ħ";
	strCard[4] = "������";

	strCard[5] = "������";
	strCard[6] = "����";
	strCard[7] = "Ƣ��";
	strCard[8] = "����";
	strCard[9] = "������";

}

void shuffleCard()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayCard[x][y] = i;
		}
	}
}

int getEmptyPosition()
{
	while (1)
	{
		int randPos = rand() % 20;

		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayCard[x][y] == -1)
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x)
{
	return x / 5;
}

int conv_pos_y(int y)
{
	return y % 5;
}

void printCard()
{
	printf("\n�Ʒ� ī����� �迭�� ����ϼ���!\n");
	printf("\n����������������������������������������������������������������������������������\n");
	for (int i = 0; i < 4; i++)
	{
		printf("\n");
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strCard[arrayCard[i][j]]);
		}
		printf("\n");
	}
	printf("\n����������������������������������������������������������������������������������\n\n");
	printf("�� ����ϼ̴ٸ� EnterŰ�� ���� �����ϼ���!");
	getchar();
	printf("\n\n\n\n\n\n\n\n\n\n\n");
}

void printQuestion()
{
	printf("\n\nī�带 ���߾����!\n\n");
	printf("\n����������������������������������������������������������������������������������\n");
	int seq = 0;

	for (int i = 0; i < 4; i++)
	{
		printf("\n");
		for (int j = 0; j < 5; j++)
		{
			if (checkCard[i][j] != 0)
			{
				printf("%8s", strCard[arrayCard[i][j]]);
			}
			else
			{
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllCard()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkCard[i][j] == 0)
				return 0;
		}
	}
	return 1;
}