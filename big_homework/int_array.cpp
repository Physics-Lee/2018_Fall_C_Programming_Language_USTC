//整型数组计算器
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
int nn = 20, col = 5, width = 6; //数据总数 打印时每行所含数据数量  每个数据的宽度

void swap(int *m, int *n)
{ //指针交换
	int t;
	t = *m;
	*m = *n;
	*n = t;
}
void sushu(int n)
{ //筛汰法求素数
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
{ // n是数组长度， interval是间隔
	int i, k, pos;
	for (i = 0; i <= n - 1; i++)
		man[i] = 0;

	i = k = 0;

	for (pos = 0; k < n; pos = (pos + 1) % n) { //对n取做余数运算
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
{ // 倒置数组
	int i, j, t;
	for (i = start, j = end; i < j; i++, j--)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
}
void leftrotate(int a[], int nixiang, int length)
{ //左旋数组
	reverse(a, 0, nixiang - 1);
	reverse(a, nixiang, length - 1);
	reverse(a, 0, length - 1);
}
void rightrotate(int a[], int nixiang, int length)
{ //右旋数组
	leftrotate(a, length - nixiang, length);
}
void rightrotate2(int a[], int nixiang, int length)
{ //右旋数组 2
	reverse(a, 0, length - 1);
	leftrotate(a, nixiang, length);
	reverse(a, 0, length - 1);
}
void jioufenqu(int a[], int n)
{ //奇偶分区
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
// 11 均为升序版  从小到大
void exchangesort(int a[], int n)
{ //交换排序
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
{ //冒泡排序
	int i, j, t, flag;
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - 1 - i; j++)
			if (a[j] < a[j + 1])
			{ //大石头沉底    最小的  或者 最大的沉底
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
{ //选择排序
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
{ //普通查找
	int i;
	for (i = 0; i < n; i++)
		if (r[i] == key)
			return i;
	return -1;
}
int binarysearch(int r[], int n, int key)
{ // 二分查找     必须有序
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
{ //删除下标id的元素
	if (id < 0 || id >= n)
	{
		//	   printf("亲，您输入的字符不合法哦！！！\n");
		return 0;
	}
	else
	{
		for (int i = id; i <= nn - 2; i++)
		{
			a[i] = a[i + 1];
		}
		n = n - 1;
		return n; //这里n是形式参数。实际参数的数值的长度并未改变
	}
}
int deleteequal(int a[], int n, int m)
{ //删除数组中所有等于m的元素
	int flag = 0;
	for (int i = 0; i <= n - 1 - flag; i++)
	{
		if (a[i] == m)
		{
			mydelete(a, n, i);
			flag++; //用flag记录次数
			i = -1;
		}
	}
	n = n - flag;
	return n;
}
int deleterange(int a[], int n, int id, int m)
{ //删除m个元素
	if (id < 0 || id >= n || m < 0)
	{
		printf("亲，您输入的字符不合法哦！！！\n");
		return 0;
	}
	else if (id + m >= n)
	{
		n = id;
		PF("已删除！！！\n");
		return n;
	}
	else
	{
		for (int i = id; i + m <= n - 1; i++)
		{
			a[i] = a[i + m];
		}
		PF("已删除！！！\n");
		return n - m;
	}
}
int deleterepeatelement(int a[], int n)
{ //删除相同元素

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
{ // 5种统计量
	int *p = a;
	double sum = 0;
	for (p = a; p <= a + n - 1; p++)
	{
		sum += *p;
		if (*p < *pmin)
			*pmin = *p;
		if (*p > *pmax)
			*pmax = *p;
	} //求和 求min 求max

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

// 0和1不需要子菜单
void printarray(int a[], int n)
{ // 2打印数组  子菜单
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
{ // 3配置参数子菜单
	printf("请输入数据总数、每行数据数、每个数据所占宽度\n(初始化值为 20 5 6)\n");
	scanf("%d%d%d", &nn, &col, &width);
	return;
}

void fillarraymenu(int a[])
{ // 4产生样本数据子菜单
	int i, menu, low, high, m;
	printf("\n\n**    产生样本数据子菜单    **\n\n");
	printf("0——返回主菜单\n");
	printf("1——指定范围的随机数\n");
	printf("2——用同一数值填满数组\n");
	printf("3——填等差数列\n");
	printf("4——键盘输入\n");
	printf("\n请选择：");
	scanf("%d", &menu);

	switch (menu)
	{
	case 1:
		printf("输入数组元素个数(<=10000):");
		scanf("%d", &nn);
		nn = nn > N ? N : nn;
		printf("输入随机数的下界和上界：");
		scanf("%d%d", &low, &high);
		m = high - low + 1;
		srand((unsigned)time(NULL));
		for (i = 0; i < nn; i++)
			a[i] = low + rand() % m;
		break;
	case 2:
		printf("输入数组元素个数(<=10000):");
		scanf("%d", &nn);
		nn = nn > N ? N : nn;
		printf("输入填写数组的整数：");
		scanf("%d", &m);
		for (i = 0; i < nn; i++)
			a[i] = m;
		break;
	case 3:
		printf("输入数组元素个数(<=10000):");
		scanf("%d", &nn);
		nn = nn > N ? N : nn;
		printf("输入等差数列的首项和公差：");
		scanf("%d%d", &low, &m);
		for (i = 0; i < nn; i++)
			a[i] = low + i * m;
		break;
	case 4:
		printf("输入数组元素个数(<=10000):");
		scanf("%d", &nn);
		nn = nn > N ? N : nn;
		printf("请输入%d个整数，用空格或回车隔开：\n", nn);
		for (i = 0; i < nn; i++)
			scanf("%d", &a[i]);
		break;
	default:;
	}
}

void arrangemenu()
{ // 5 排列数组   子菜单
	int menu;
	printf("\n\n**    排序子菜单    **\n\n");
	printf("0--返回主菜单\n");
	printf("1--逆置数组\n");
	printf("2--左旋数组\n");
	printf("3--右旋数组\n");
	printf("4--奇偶分区\n");
	printf("\n请选择：");
	scanf("%d", &menu);
	switch (menu)
	{
	case 1:
		int start, end;
		printf("亲，请输入逆置的起点和终点\n");
		SF("%d%d", &start, &end);
		reverse(a, start, end);
		PF("数组逆置已完成！！！");
		break;

	case 2:
		int nixiang;
		printf("亲，请输入你想让数组左旋的位数");
		PN;
		scanf("%d", &nixiang);
		leftrotate(a, nixiang, nn);
		printf("数组左旋已完成！！！");
		break;

	case 3:
		int want;
		printf("亲，请输入你想让数组右旋的位数");
		PN;
		scanf("%d", &want);
		rightrotate(a, want, nn);
		printf("数组右旋已完成！！！");
		break;

	case 4:
		jioufenqu(a, nn);
		PF("奇偶分区已完成！！！");
		break;
	default:
		return;
	}
}

void searchmenu()
{ // 6查找子菜单
	int menu, k, i = -1;
	printf("\n\n**    查找子菜单    **\n\n");
	printf("0--返回主菜单\n");
	printf("1--普通查找\n");
	printf("2--二分查找\n");
	printf("\n请选择：");
	scanf("%d", &menu);
	switch (menu)
	{
	case 1:
		printf("输入要查找的元素：");
		scanf("%d", &k);
		i = normalsearch(a, nn, k);
		break;
	case 2:
		printf("输入要查找的元素：");
		scanf("%d", &k);
		if (isascending(a, nn) == 0 && isdescending(a, nn) == 0)
		{
			PF("无序数组，不能使用二分查找！！！\n");
		}
		else
			i = binarysearch(a, nn, k);
		break;
	default:
		return;
	}
	if (i >= 0)
		printf("元素 %4d 的下标是%d\n", k, i);
	else
		printf("找不到 %d\n", k);
}

//     10
void insertmenu()
{ // 7插入、替换子菜单
	int menu;
	printf("\n\n**    插入、替换子菜单    **\n\n");
	printf("0--返回主菜单\n");
	printf("1--在指定下标位置插入新元素\n");
	printf("2--在有序数组中插入新元素\n");
	printf("3--将数组中所有值为m的元素替换为n\n");
	printf("\n请选择：");
	scanf("%d", &menu);
	switch (menu)
	{
	case 1:
		int x;
		int k;
		PF("亲，请输入你想插入的新元素 \n");
		SF("%d", &x);
		PF("亲，请输入新元素的下标位置 \n");
		SF("%d", &k);
		nn++;
		for (int i = nn; i >= k + 1; i--)
			a[i] = a[i - 1];
		a[k] = x;
		PF("完成咯！！！请使用显示数组功能查看");
		break;
	case 2:
		selectsort(a, nn);
		PF("亲，请输入你想插入的新元素 \n");
		int y;
		SF("%d", &y);
		nn++;
		a[nn - 1] = y;
		exchangesort(a, nn);
		PF("完成咯！！！请使用显示数组功能查看\n");

		break;
	case 3:
		int m, n;
		PF("亲，请输入你希望的m值\t");
		SF("%d", &m);
		PF("亲，请输入你希望的n值\t");
		SF("%d", &n);

		for (int i = 0; i <= nn - 1; i++)
		{
			if (a[i] == m)
				a[i] = n;
		}
		PF("完成咯！！！请使用显示数组功能查看\n");
		break;
	default:
		break;
	}
}

void deletemenu()
{ // 8删除子菜单
	int menu;
	printf("\n\n**    删除子菜单    **\n\n");
	printf("0--返回主菜单\n");
	printf("1--删除指定下标元素\n");
	printf("2--删除等于指定值的所有元素\n");
	printf("3--删除指定下标后指定区间的元素\n");
	PF("4--删除数组中的重复值");
	printf("\n请选择：");
	scanf("%d", &menu);
	switch (menu)
	{
	case 1:
	{
		int id;
		PF("亲，请输入下标\n");
		SF("%d", &id);
		nn = mydelete(a, nn, id);
		PF("已删除！！！\n");
		break;
	}
	case 2:
	{
		int m;
		PF("亲，请输入指定值\n");
		SF("%d", &m);
		nn = deleteequal(a, nn, m);
		PF("已删除！！！\n");
		break;
	}
	case 3:
	{
		int id2, m;
		PF("亲，请输入下标、指定区间的长度");
		SF("%d%d", &id2, &m);
		nn = deleterange(a, nn, id2, m);
		break;
	}
	case 4:
	{
		nn = deleterepeatelement(a, nn);
		PF("已删除重复值！！！");
		break;
	}
	}
}

void statisticsmenu()
{ // 9统计子菜单
	int menu;
	printf("\n\n**    统计子菜单    **\n\n");
	printf("0--返回主菜单\n");
	printf("1--求最大值\n");
	printf("2--求最小值\n");
	printf("3--求平均值\n");
	PF("4--求方差\n");
	PF("5--求均方差（标准差）\n");
	printf("\n请选择：");
	scanf("%d", &menu);

	int min = *a, max = *a, *pmin = &min, *pmax = &max;
	double aver, fang, *paver = &aver, *pfang = &fang;
	tongji(a, nn, pmin, pmax, paver, pfang);
	switch (menu)
	{
	case 1:
		PF("最大值 %-4d\n", max);
		break;
	case 2:
		PF("最小值 %-4d\n", min);
		break;
	case 3:
		PF("平均值 %4lf\n", aver);
		break;
	case 4:
		PF("方差 %lf\n", fang);
		break;
	case 5:
		PF("均方差（标准差) %lf\n", sqrt(fang));
		break;
	default:
		break;
	}
}

void sortmenu()
{ // 11排序子菜单
	int menu;
	printf("\n\n**    排序子菜单    **\n\n");
	printf("0--返回主菜单\n");
	printf("1--交换排序 升序版\n");
	printf("2--冒泡排序 升序版\n");
	printf("3--选择排序 升序版\n");
	printf("\n请选择：");
	scanf("%d", &menu);

	switch (menu)
	{
	case 1:
		exchangesort(a, nn);
		printf("交换排序已完成！！\n");
		printarray(a, nn);
		break;
	case 2:
		bubblesort(a, nn);
		printf("冒泡排序已完成！！\n");
		printarray(a, nn);
		break;
	case 3:
		selectsort(a, nn);
		printf("选择排序已完成！！\n");
		printarray(a, nn);
		break;
	}
}
void othermenu()
{ // 12 其他子菜单
	int menu;
	printf("\n\n**    其他功能    **\n\n");
	PF("****更多功能正在开发之中，敬请期待****\n\n");
	printf("0--返回主菜单\n");
	printf("1--约瑟夫环\n");
	printf("2--筛汰法求素数\n");
	printf("\n请选择：");
	scanf("%d", &menu);
	switch (menu)
	{
	case 1:
	{
		int i, m, baohu, sum;
		int man[100] = {0};
		PF("请输入总人数(<=100)和报数间隔\n");
		scanf("%d%d", &sum, &m); // sum, m are int
		yuesefuhuan(man, sum, m);
		PF("约瑟夫环（数组中第i个数代表第i个人的死亡序号）：\n");
		printarray(man, sum);
		PF("\n你想保护的人数：");
		SF("%d", &baohu);
		PF("被保护者应该排在：");
		for (i = 0; i < baohu; i++)
			PF("%5d", 1 + normalsearch(man, sum, (sum - i)));
		PN;
		;
		break;
	}
	case 2:
	{
		printf("亲，请输入一正整数，我将帮你求出该数以内的质数\n");
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
		printf("\n                ************    整型数组运算器     *************\n");
		printf("                  1——显示全部数组元素            \n");
		printf("                  2——输入数组元素        3——配置数组参数\n");
		printf("                  4——清屏                5——排列\n");
		printf("                  6——查找                7——插入、替换\n");
		printf("                  8——删除                9——统计\n");
		printf("                  10——判断               11——排序\n");
		printf("                  12——其他               13——退出\n");
		printf("\n                *********************************************\n\n");
		printf("                  选择主菜单：\n");
		PF("             （温馨提示：初始化数组元素均为0）                  \n");
		PF("             （温馨提示：输入数字后按回车键才能生效哦！）       \n");
		PF("             （温馨提示：输入越界数字或其它字符会返回主菜单哦!）\n");
		scanf("%d", &menu);
		switch (menu)
		{
		case 13:
			return 0; //结束main
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
				printf("数组元素全部相等！！！\n");
			else if (isascending(a, nn))
				printf("严格递增数组！！！\n");
			else if (isdescending(a, nn))
				printf("严格递减数组！！！\n");
			else
				printf("非全部相等也非严格单调数组！！！\n");
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