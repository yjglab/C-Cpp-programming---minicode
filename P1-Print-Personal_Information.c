#include <stdio.h>

int main()
{
	char name[50];
	printf("�̸��� �Է��ϼ���. ");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("���̸� �Է��ϼ���. ");
	scanf_s("%d", &age);

	double weight;
	printf("ü���� �Է��ϼ���. ");
	scanf_s("%lf", &weight);

	double height;
	printf("Ű�� �Է��ϼ���. ");
	scanf_s("%lf", &height);

	char job[50];
	printf("������ �Է��ϼ���. ");
	scanf_s("%s", job, sizeof(job));

	//�Ż����� ���
	printf("\n\n---�ο� ����---\n\n");
	printf("�̸� : %s\n", name);
	printf("���� : %d\n", age);
	printf("ü�� : %.2lf\n", weight);
	printf(" Ű  : %.2lf\n", height);
	printf("���� : %s\n", job);

	return 0;
}
