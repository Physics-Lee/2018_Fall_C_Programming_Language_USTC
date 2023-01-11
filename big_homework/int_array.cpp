//�������������
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define N 10000
#define PF printf
#define NL "\n"
#define PN PF(NL)
#define SF scanf

int a[1000];
int nn = 20, col = 5, width = 6; //�������� ��ӡʱÿ��������������  ÿ�����ݵĿ��

void swap(int *m, int *n)
{ //ָ�뽻��
	int t;
	t = *m;
	*m = *n;
	*n = t;
}
void sushu(int n)
{ //ɸ̭��������
	int i, j;
	int s[n + 1] = {0};
	for (i = 2; i <= n; i++)
	{
		if (s[i] == 0)
		{
			for (j = i * 2; j <= n; j = j + i)
				s[j] = 10;
		}
	}
	for (i = 2; i <= n; i++)
		if (s[i] == 0)
			printf("%d\n", i);
}

// 5
void yuesefuhuan(int man[], int n, int interval)
{ // n�����鳤�ȣ� interval�Ǽ��
	int i, k, pos;
	for (i = 0; i <= n - 1; i++)
		man[i] = 0;

	i = k = 0;

	for (pos = 0; k < n; pos = (pos + 1) % n) { //��nȡ����������
		if (man[pos] == 0)
			i++;
		if (i == interval)
		{
			i = 0;
			k++; // k is the number of death people
			man[pos] = k;
		}
	}
	return;
}
void reverse(int a[], int start, int end)
{ // ��������
	int i, j, t;
	for (i = start, j = end; i < j; i++, j--)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
}
void leftrotate(int a[], int nixiang, int length)
{ //��������
	reverse(a, 0, nixiang - 1);
	reverse(a, nixiang, length - 1);
	reverse(a, 0, length - 1);
}
void rightrotate(int a[], int nixiang, int length)
{ //��������
	leftrotate(a, length - nixiang, length);
}
void rightrotate2(int a[], int nixiang, int length)
{ //�������� 2
	reverse(a, 0, length - 1);
	leftrotate(a, nixiang, length);
	reverse(a, 0, length - 1);
}
void jioufenqu(int a[], int n)
{ //��ż����
	int flag = 0;
	for (int i = 0; i <= n - 1; i++)
	{
		if (a[i] % 2 == 1)
		{
			int t = a[flag];
			a[flag] = a[i];
			a[i] = t;
			flag++;
		}
	}
}
// 11 ��Ϊ�����  ��С����
void exchangesort(int a[], int n)
{ //��������
	int temp;
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
			if (a[i] > a[j])
			{

				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	}
}
void bubblesort(int a[], int n)
{ //ð������
	int i, j, t, flag;
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - 1 - i; j++)
			if (a[j] < a[j + 1])
			{ //��ʯͷ����    ��С��  ���� ���ĳ���
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				flag = 1;
			}
		if (flag == 0)
			return;
	}
}
void selectsort(int a[], int n)
{ //ѡ������
	int i, j, min, t;
	for (i = 0; i < n - 1; i++)
	{
		for (min = i, j = i + 1; j < n; j++)
		{
			if (a[j] > a[min])
				min = j;
		}
		if (min != i)
		{
			t = a[i];
			a[i] = a[min];
			a[min] = t;
		}
	}
	return;
}
// 6
int normalsearch(int r[], int n, int key)
{ //��ͨ����
	int i;
	for (i = 0; i < n; i++)
		if (r[i] == key)
			return i;
	return -1;
}
int binarysearch(int r[], int n, int key)
{ // ���ֲ���     ��������
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key > r[mid])
			low = mid + 1;
		else if (key == r[mid])
			return (mid);
		else
			high = mid - 1;
	}
	return -1;
}
// 8
int mydelete(int a[], int n, int id)
{ //ɾ���±�id��Ԫ��
	if (id < 0 || id >= n)
	{
		//	   printf("�ף���������ַ����Ϸ�Ŷ������\n");
		return 0;
	}
	else
	{
		for (int i = id; i <= nn - 2; i++)
		{
			a[i] = a[i + 1];
		}
		n = n - 1;
		return n; //����n����ʽ������ʵ�ʲ�������ֵ�ĳ��Ȳ�δ�ı�
	}
}
int deleteequal(int a[], int n, int m)
{ //ɾ�����������е���m��Ԫ��
	int flag = 0;
	for (int i = 0; i <= n - 1 - flag; i++)
	{
		if (a[i] == m)
		{
			mydelete(a, n, i);
			flag++; //��flag��¼����
			i = -1;
		}
	}
	n = n - flag;
	return n;
}
int deleterange(int a[], int n, int id, int m)
{ //ɾ��m��Ԫ��
	if (id < 0 || id >= n || m < 0)
	{
		printf("�ף���������ַ����Ϸ�Ŷ������\n");
		return 0;
	}
	else if (id + m >= n)
	{
		n = id;
		PF("��ɾ��������\n");
		return n;
	}
	else
	{
		for (int i = id; i + m <= n - 1; i++)
		{
			a[i] = a[i + m];
		}
		PF("��ɾ��������\n");
		return n - m;
	}
}
int deleterepeatelement(int a[], int n)
{ //ɾ����ͬԪ��

	for (int i = 0; i <= n - 2; i++)
	{
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (a[i] == a[j])
			{
				n = deleteequal(a, n, a[i]);
				i = -1;
				break;
			}
		}
	}
	return n;
}

// 9
void tongji(int *a, int n, int *pmin, int *pmax, double *paver, double *pfang)
{ // 5��ͳ����
	int *p = a;
	double sum = 0;
	for (p = a; p <= a + n - 1; p++)
	{
		sum += *p;
		if (*p < *pmin)
			*pmin = *p;
		if (*p > *pmax)
			*pmax = *p;
	} //��� ��min ��max

	*paver = sum / n;
	for (p = a; p <= a + n - 1; p++)
	{
		*pfang += (*paver - *p) * (*paver - *p) / n;
	}
}
// 10
int isequal(int a[], int n)
{
	int flag = 0;
	for (int i = 0; i <= n - 2; i++)
		if (a[i] != a[i + 1])
			flag++;
	if (flag != 0)
		return 0;
	else
		return 1;
}
int isascending(int a[], int n)
{
	int flag = 0;
	for (int i = 0; i <= n - 2; i++)
		if (a[i] >= a[i + 1])
			flag++;
	if (flag != 0)
		return 0;
	else
		return 1;
}
int isdescending(int a[], int n)
{
	int flag = 0;
	for (int i = 0; i <= n - 2; i++)
		if (a[i] <= a[i + 1])
			flag++;
	if (flag != 0)
		return 0;
	else
		return 1;
}

// 0��1����Ҫ�Ӳ˵�
void printarray(int a[], int n)
{ // 2��ӡ����  �Ӳ˵�
	int i;
	char s[10] = {'%', 48 + width, 'd', '\0'}; //"5d"
	for (i = 0; i < n; i++)
	{
		printf(s, a[i]);
		if ((i + 1) % col == 0)
			printf("\n");
	}
	printf("\n");
}
void config()
{ // 3���ò����Ӳ˵�
	printf("����������������ÿ����������ÿ��������ռ���\n(��ʼ��ֵΪ 20 5 6)\n");
	scanf("%d%d%d", &nn, &col, &width);
	return;
}

void fillarraymenu(int a[])
{ // 4�������������Ӳ˵�
	int i, menu, low, high, m;
	printf("\n\n**    �������������Ӳ˵�    **\n\n");
	printf("0�����������˵�\n");
	printf("1����ָ����Χ�������\n");
	printf("2������ͬһ��ֵ��������\n");
	printf("3������Ȳ�����\n");
	printf("4������������\n");
	printf("\n��ѡ��");
	scanf("%d", &menu);

	switch (menu)
	{
	case 1:
		printf("��������Ԫ�ظ���(<=10000):");
		scanf("%d", &nn);
		nn = nn > N ? N : nn;
		printf("������������½���Ͻ磺");
		scanf("%d%d", &low, &high);
		m = high - low + 1;
		srand((unsigned)time(NULL));
		for (i = 0; i < nn; i++)
			a[i] = low + rand() % m;
		break;
	case 2:
		printf("��������Ԫ�ظ���(<=10000):");
		scanf("%d", &nn);
		nn = nn > N ? N : nn;
		printf("������д�����������");
		scanf("%d", &m);
		for (i = 0; i < nn; i++)
			a[i] = m;
		break;
	case 3:
		printf("��������Ԫ�ظ���(<=10000):");
		scanf("%d", &nn);
		nn = nn > N ? N : nn;
		printf("����Ȳ����е�����͹��");
		scanf("%d%d", &low, &m);
		for (i = 0; i < nn; i++)
			a[i] = low + i * m;
		break;
	case 4:
		printf("��������Ԫ�ظ���(<=10000):");
		scanf("%d", &nn);
		nn = nn > N ? N : nn;
		printf("������%d���������ÿո��س�������\n", nn);
		for (i = 0; i < nn; i++)
			scanf("%d", &a[i]);
		break;
	default:;
	}
}

void arrangemenu()
{ // 5 ��������   �Ӳ˵�
	int menu;
	printf("\n\n**    �����Ӳ˵�    **\n\n");
	printf("0--�������˵�\n");
	printf("1--��������\n");
	printf("2--��������\n");
	printf("3--��������\n");
	printf("4--��ż����\n");
	printf("\n��ѡ��");
	scanf("%d", &menu);
	switch (menu)
	{
	case 1:
		int start, end;
		printf("�ף����������õ������յ�\n");
		SF("%d%d", &start, &end);
		reverse(a, start, end);
		PF("������������ɣ�����");
		break;

	case 2:
		int nixiang;
		printf("�ף�����������������������λ��");
		PN;
		scanf("%d", &nixiang);
		leftrotate(a, nixiang, nn);
		printf("������������ɣ�����");
		break;

	case 3:
		int want;
		printf("�ף�����������������������λ��");
		PN;
		scanf("%d", &want);
		rightrotate(a, want, nn);
		printf("������������ɣ�����");
		break;

	case 4:
		jioufenqu(a, nn);
		PF("��ż��������ɣ�����");
		break;
	default:
		return;
	}
}

void searchmenu()
{ // 6�����Ӳ˵�
	int menu, k, i = -1;
	printf("\n\n**    �����Ӳ˵�    **\n\n");
	printf("0--�������˵�\n");
	printf("1--��ͨ����\n");
	printf("2--���ֲ���\n");
	printf("\n��ѡ��");
	scanf("%d", &menu);
	switch (menu)
	{
	case 1:
		printf("����Ҫ���ҵ�Ԫ�أ�");
		scanf("%d", &k);
		i = normalsearch(a, nn, k);
		break;
	case 2:
		printf("����Ҫ���ҵ�Ԫ�أ�");
		scanf("%d", &k);
		if (isascending(a, nn) == 0 && isdescending(a, nn) == 0)
		{
			PF("�������飬����ʹ�ö��ֲ��ң�����\n");
		}
		else
			i = binarysearch(a, nn, k);
		break;
	default:
		return;
	}
	if (i >= 0)
		printf("Ԫ�� %4d ���±���%d\n", k, i);
	else
		printf("�Ҳ��� %d\n", k);
}

//     10
void insertmenu()
{ // 7���롢�滻�Ӳ˵�
	int menu;
	printf("\n\n**    ���롢�滻�Ӳ˵�    **\n\n");
	printf("0--�������˵�\n");
	printf("1--��ָ���±�λ�ò�����Ԫ��\n");
	printf("2--�����������в�����Ԫ��\n");
	printf("3--������������ֵΪm��Ԫ���滻Ϊn\n");
	printf("\n��ѡ��");
	scanf("%d", &menu);
	switch (menu)
	{
	case 1:
		int x;
		int k;
		PF("�ף�����������������Ԫ�� \n");
		SF("%d", &x);
		PF("�ף���������Ԫ�ص��±�λ�� \n");
		SF("%d", &k);
		nn++;
		for (int i = nn; i >= k + 1; i--)
			a[i] = a[i - 1];
		a[k] = x;
		PF("��ɿ���������ʹ����ʾ���鹦�ܲ鿴");
		break;
	case 2:
		selectsort(a, nn);
		PF("�ף�����������������Ԫ�� \n");
		int y;
		SF("%d", &y);
		nn++;
		a[nn - 1] = y;
		exchangesort(a, nn);
		PF("��ɿ���������ʹ����ʾ���鹦�ܲ鿴\n");

		break;
	case 3:
		int m, n;
		PF("�ף���������ϣ����mֵ\t");
		SF("%d", &m);
		PF("�ף���������ϣ����nֵ\t");
		SF("%d", &n);

		for (int i = 0; i <= nn - 1; i++)
		{
			if (a[i] == m)
				a[i] = n;
		}
		PF("��ɿ���������ʹ����ʾ���鹦�ܲ鿴\n");
		break;
	default:
		break;
	}
}

void deletemenu()
{ // 8ɾ���Ӳ˵�
	int menu;
	printf("\n\n**    ɾ���Ӳ˵�    **\n\n");
	printf("0--�������˵�\n");
	printf("1--ɾ��ָ���±�Ԫ��\n");
	printf("2--ɾ������ָ��ֵ������Ԫ��\n");
	printf("3--ɾ��ָ���±��ָ�������Ԫ��\n");
	PF("4--ɾ�������е��ظ�ֵ");
	printf("\n��ѡ��");
	scanf("%d", &menu);
	switch (menu)
	{
	case 1:
	{
		int id;
		PF("�ף��������±�\n");
		SF("%d", &id);
		nn = mydelete(a, nn, id);
		PF("��ɾ��������\n");
		break;
	}
	case 2:
	{
		int m;
		PF("�ף�������ָ��ֵ\n");
		SF("%d", &m);
		nn = deleteequal(a, nn, m);
		PF("��ɾ��������\n");
		break;
	}
	case 3:
	{
		int id2, m;
		PF("�ף��������±ꡢָ������ĳ���");
		SF("%d%d", &id2, &m);
		nn = deleterange(a, nn, id2, m);
		break;
	}
	case 4:
	{
		nn = deleterepeatelement(a, nn);
		PF("��ɾ���ظ�ֵ������");
		break;
	}
	}
}

void statisticsmenu()
{ // 9ͳ���Ӳ˵�
	int menu;
	printf("\n\n**    ͳ���Ӳ˵�    **\n\n");
	printf("0--�������˵�\n");
	printf("1--�����ֵ\n");
	printf("2--����Сֵ\n");
	printf("3--��ƽ��ֵ\n");
	PF("4--�󷽲�\n");
	PF("5--��������׼�\n");
	printf("\n��ѡ��");
	scanf("%d", &menu);

	int min = *a, max = *a, *pmin = &min, *pmax = &max;
	double aver, fang, *paver = &aver, *pfang = &fang;
	tongji(a, nn, pmin, pmax, paver, pfang);
	switch (menu)
	{
	case 1:
		PF("���ֵ %-4d\n", max);
		break;
	case 2:
		PF("��Сֵ %-4d\n", min);
		break;
	case 3:
		PF("ƽ��ֵ %4lf\n", aver);
		break;
	case 4:
		PF("���� %lf\n", fang);
		break;
	case 5:
		PF("�������׼��) %lf\n", sqrt(fang));
		break;
	default:
		break;
	}
}

void sortmenu()
{ // 11�����Ӳ˵�
	int menu;
	printf("\n\n**    �����Ӳ˵�    **\n\n");
	printf("0--�������˵�\n");
	printf("1--�������� �����\n");
	printf("2--ð������ �����\n");
	printf("3--ѡ������ �����\n");
	printf("\n��ѡ��");
	scanf("%d", &menu);

	switch (menu)
	{
	case 1:
		exchangesort(a, nn);
		printf("������������ɣ���\n");
		printarray(a, nn);
		break;
	case 2:
		bubblesort(a, nn);
		printf("ð����������ɣ���\n");
		printarray(a, nn);
		break;
	case 3:
		selectsort(a, nn);
		printf("ѡ����������ɣ���\n");
		printarray(a, nn);
		break;
	}
}
void othermenu()
{ // 12 �����Ӳ˵�
	int menu;
	printf("\n\n**    ��������    **\n\n");
	PF("****���๦�����ڿ���֮�У������ڴ�****\n\n");
	printf("0--�������˵�\n");
	printf("1--Լɪ��\n");
	printf("2--ɸ̭��������\n");
	printf("\n��ѡ��");
	scanf("%d", &menu);
	switch (menu)
	{
	case 1:
	{
		int i, m, baohu, sum;
		int man[100] = {0};
		PF("������������(<=100)�ͱ������\n");
		scanf("%d%d", &sum, &m); // sum, m are int
		yuesefuhuan(man, sum, m);
		PF("Լɪ�򻷣������е�i���������i���˵�������ţ���\n");
		printarray(man, sum);
		PF("\n���뱣����������");
		SF("%d", &baohu);
		PF("��������Ӧ�����ڣ�");
		for (i = 0; i < baohu; i++)
			PF("%5d", 1 + normalsearch(man, sum, (sum - i)));
		PN;
		;
		break;
	}
	case 2:
	{
		printf("�ף�������һ���������ҽ���������������ڵ�����\n");
		int n;
		scanf("%d", &n);
		sushu(n);
		break;
	}
	}
}
main()
{
	int i, menu;
	for (;;)
	{
		printf("\n                ************    ��������������     *************\n");
		printf("                  1������ʾȫ������Ԫ��            \n");
		printf("                  2������������Ԫ��        3���������������\n");
		printf("                  4��������                5��������\n");
		printf("                  6��������                7�������롢�滻\n");
		printf("                  8����ɾ��                9����ͳ��\n");
		printf("                  10�����ж�               11��������\n");
		printf("                  12��������               13�����˳�\n");
		printf("\n                *********************************************\n\n");
		printf("                  ѡ�����˵���\n");
		PF("             ����ܰ��ʾ����ʼ������Ԫ�ؾ�Ϊ0��                  \n");
		PF("             ����ܰ��ʾ���������ֺ󰴻س���������ЧŶ����       \n");
		PF("             ����ܰ��ʾ������Խ�����ֻ������ַ��᷵�����˵�Ŷ!��\n");
		scanf("%d", &menu);
		switch (menu)
		{
		case 13:
			return 0; //����main
		case 4:
			system("cls");
			break;
		case 1:
			printarray(a, nn);
			break;
		case 3:
			config();
			break;
		case 2:
			fillarraymenu(a);
			break;
		case 5:
			arrangemenu();
			break;
		case 6:
			searchmenu();
			break;
		case 7:
			insertmenu();
			break;
		case 8:
			deletemenu();
			break;
		case 9:
			statisticsmenu();
			break;
		case 10:
			if (isequal(a, nn))
				printf("����Ԫ��ȫ����ȣ�����\n");
			else if (isascending(a, nn))
				printf("�ϸ�������飡����\n");
			else if (isdescending(a, nn))
				printf("�ϸ�ݼ����飡����\n");
			else
				printf("��ȫ�����Ҳ���ϸ񵥵����飡����\n");
			break;
		case 11:
			sortmenu();
			break;
		case 12:
			othermenu();
			break;
		default:
			break;
		}

		// end switch
	} // end for
} // end main