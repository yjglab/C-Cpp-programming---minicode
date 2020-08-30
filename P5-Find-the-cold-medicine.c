#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	printf("\n\n �������    ������� ã�ƶ� by.yjglab    ������� \n\n\n\n");
	printf("\n\t  ... �����Ϸ��� EnterŰ�� �������� ...\n");
	getchar();

	printf("\n\n\n ���� ���� ���� : 1  ���� ��� : 2  ���� ���� : 3 ���� \n\n\n\n");
	int start;
	scanf_s("%d", &start);

	if (start == 1)
	{
		printf("\n\n\n ����������  ������ �����մϴ�  ����������\n\n\n\n");
	}
	else if (start == 2)
	{
		printf("\n\n\n ����������       ���ӹ��      ����������\n\n\n\n");
		printf(" 1������ 4������ �˾��� �ִ�. �� �˾� �� �ϳ��� ���⸦ �����ϴ� Ưȿ���̴�.\n ��Ʈ�� ���� ������� ������� ������! \n\n\n\n");
	}
	else if (start == 3)
	{
		printf("\n\n\n ����������  ������ �����մϴ�  ����������\n\n");
		exit(0);
	}
	else
	{
		printf(" \n\n �Է� ���� ! (1~3) ���ڸ� �Է����ּ��� !\n");
		exit(0);
	}
	getchar();
	printf("\n\t  ... �����Ϸ��� EnterŰ�� �������� ...\n\n\n\n");
	getchar();

	int answer;
	int treatment = rand() % 4; // �˾� ���� (0-3)
	int cntShowPill = 0; // �̹� ���뿡�� ���� �˾� ����
	int prvShowPill = 0; // ���� ���뿡�� ���� �˾� ����
	// ���� �����ִ� �˾� ������ �ٸ��� �Ͽ� ����� ��� 

	// �� 3���� �˾� ���� ��ȸ
	for (int i = 1; i <= 3; i++)
	{
		int pill[4] = { 0, 0, 0, 0 }; //���� ���õ��� ���� �˾� 4��
		do
		{
			cntShowPill = rand() % 2 + 2; // ������ �˾� ���� (0-1, +2 -> 2, 3)
		} while (cntShowPill == prvShowPill); // ���� ���뿡�� ������ �˾� ������ �ٸ� ���� ���ö����� �ݺ�
		
		int Included = 0; // ������ �˾� �� ����� ���� ����(1 : ����, 0 : ������)
		printf(" �� %d��° ���� : ", i);
		
		for (int j = 0; j < cntShowPill; j++) // ������ �˾� ��ȣ ����
		{
			int randPill = rand() % 4; // 0~3
			
			if (pill[randPill] == 0) // ���� ���õ��� ���� �˾��̸�
			{
				pill[randPill] = 1; // ����ó��
				if (randPill == treatment)
				{
					Included = 1;
				}
			}
			else
			{
				j--; // �̹� ���õ� �˾��̸�, �ߺ��̹Ƿ� �ٽ� ����
			}
		}
		
		for (int k = 0; k < 4; k++)
		{
			if (pill[k] == 1) // bottle[k] k �ε����� ������ ���õ� ���� �� 1���� 0������ ��
				printf("%d�� ", k + 1); 
		}
		printf("�˾��� �Ծ����ϴ�\n\n");
		
		if (Included == 1)
		{
			printf(" >> ���� ����� ���������ϴ�!\n\n");
		}
		else
		{
			printf(" >> �ƹ��� ��ȭ�� �����ϴ�..\n\n");
		}

		printf("\n\n\n\t  ... ����Ϸ��� EnterŰ�� �������� ...\n\n\n\n");
		getchar();
	
	}

	printf(" Q. ������� ��� �˾��ϱ��? ");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("\n >> �����Դϴ�! ���Ⱑ ������ ���ҽ��ϴ�!\n");
		printf("\n\n\n ����������  ������ �����մϴ�  ����������\n\n");
	}
	else if (answer != treatment + 1)
	{
		printf("\n >> �����Դϴ�! ������ %d�� �˾��Դϴ�\n", treatment + 1);
		printf("\n\n\n ����������  ������ �����մϴ�  ����������\n\n");
	}
	//else
	return 0;
}