
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int A[10005], B[10005], C[10005];
int N = 10;//数组长度
int width = 5;//数组打印宽度
int M = 10;//单行打印个数

void printarr(int* a, int n)
{
	int k = 0;
	while (k < n)
	{
		printf("%*d ",width,*(a + k));
		k++;
		if (k % M == 0) printf("\n");
	}
	if (n > 0) printf("\n");
	else printf("function printarr error\n");
}

void FillArray(int a[], int n)
{
	int k = 0;
	while (k < n)
	{
		scanf("%d", a + k);
		k++;
	}
}

void randFill(int a[], int n,int s,int t)
{
	int k = 0;
	while (k < n)
	{
		a[k] = rand() % (t - s + 1) + s;
		k++;
	}
}

void arithmaticFill(int a[], int n, int a0, int d)
{
	int k = 0;
	while (k < n)
	{
		a[k] = a0 + k * d;
		k++;
	}
}

void constFill(int a[], int n,int val)
{
	arithmaticFill(a, n, val, 0);
}

void Config()
{
	printf("当前数组长度为%d,请输入新的数组长度（数组长度应当在10000以内）\n", N);
	scanf("%d", &N);
	printf("当前数组打印宽度为%d,请输入新的数组打印宽度\n", width);
	scanf("%d", &width);
	printf("当前单行打印个数为%d,请输入新的单行打印个数\n", M);
	scanf("%d", &M);
}

void Reverse(int a[], int n)
{
	int k = 0;
	int c;
	while (k < (n / 2))
	{
		c = a[k];
		a[k] = a[n - 1 - k];
		a[n - 1 - k] = c;
		k++;
	}
}

void Insert(int a[], int n, int pos, int val)
{
	int k = n;
	while (k > pos)
	{
		a[k] = a[k - 1];
		k--;
	}
	a[k] = val;
	N++;
}

void DeleteRange(int a[], int n,int s,int t)
{
	int k = s;
	if (0 <= s && s <= t && t < n)
	{
		while (k < (n - t + s - 1))
		{
			a[k] = a[k + t - s + 1];
			k++;
		}
		while (k < n)
		{
			a[k] = 0;
			k++;
		}
		N -= t - s + 1;
	}
	else
	{
		printf("指定删除的下标不合法\n");
	}
}

void Delete(int a[], int n, int id)
{
	DeleteRange(a, n, id, id);
}

int isAsc(int a[], int n)
{
	int k = 1;
	while (k < n)
	{
		if (a[k] < a[k - 1]) return 0;
		k++;
	}
	return 1;
}

int isDesc(int a[], int n)
{
	int k = 1;
	while (k < n)
	{
		if (a[k] > a[k - 1]) return 0;
		k++;
	}
	return 1;
}

int isEqual(int a[], int n)
{
	int k = 1;
	while (k < n)
	{
		if (a[k] != a[k - 1]) return 0;
		k++;
	}
	return 1;
}

double average(int a[], int n)
{
	int k = 0;
	double sum = 0;
	while (k < n)
	{
		sum += a[k];
		k++;
	}
	return sum / n;
}

void OrderInsert(int a[], int n,int val)
{
	int top = n - 1;
	int bottom = 0;
	int mid = (top - bottom) / 2 + bottom;
	if (isAsc(a, n))
	{
		if (a[n - 1] <= val) Insert(a, n, n, val);
		else if (a[0] >= val) Insert(a, n, 0, val);
		else
		{
			while (1)
			{
				if (top == bottom + 1)
				{
					Insert(a, n, top, val);
					break;
				}
				if (a[mid] == val)
				{
					Insert(a, n, mid, val);
					break;
				}
				if (a[mid] > val)
				{
					top = mid;
					mid = (top - bottom) / 2 + bottom;
				}
				else
				{
					bottom = mid;
					mid = (top - bottom) / 2 + bottom;
				}
			}
		}
	}
	else if (isDesc(a, n))
	{
		if (a[n - 1] >= val) Insert(a, n, n, val);
		else if (a[0] <= val) Insert(a, n, 0, val);
		else
		{
			while (1)
			{
				if (top == bottom + 1)
				{
					Insert(a, n, top, val);
					break;
				}
				if (a[mid] == val)
				{
					Insert(a, n, mid, val);
					break;
				}
				if (a[mid] < val)
				{
					top = mid;
					mid = (top - bottom) / 2 + bottom;
				}
				else
				{
					bottom = mid;
					mid = (top - bottom) / 2 + bottom;
				}
			}
		}
	}
	else printf("请先对数组进行排序\n");
}
//都是升序排序
void BubbleSort(int a[], int n)
{
	int i = 0;
	int j;
	int c;
	int m;
	while (i < n)
	{
		j = 1;
		m = 1;
		while (j < n - i)
		{
			if (a[j] < a[j - 1])
			{
				c = a[j - 1];
				a[j - 1] = a[j];
				a[j] = c;
			}
			else m++;
			j++;
		}
		if (m == n - i) break;
		i++;
	}
}

void SelectSort(int a[], int n)
{
	int k = 0;
	int i;
	int c;
	int m;
	while (k < n)
	{
		i = k + 1;
		m = k;
		while (i < n)
		{
			if (a[i] < a[k]) m = i;
			i++;
		}
		if (m != k)
		{
			c = a[k];
			a[k] = a[m];
			a[m] = c;
		}
		k++;
	}
}

void ExchangeSort(int a[], int n)
{
	int k = 0;
	int i;
	int c;
	while (k < n)
	{
		i = k + 1;
		while (i < n)
		{
			if (a[i] < a[k])
			{
				c = a[i];
				a[i] = a[k];
				a[k] = c;
			}
			i++;
		}
		k++;
	}
}

void merge(int* p, int* q, int m, int n)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < m && j < n)
	{
		if (*(p + i) < * (q + j))
		{
			C[k] = *(p + i);
			i++;
		}
		else
		{
			C[k] = *(q + j);
			j++;
		}
		k++;
	}
	while (i < m)
	{
		C[k] = *(p + i);
		i++;
		k++;
	}
	while (j < n)
	{
		C[k] = *(q + j);
		j++;
		k++;
	}
	k = 0;
	while (k < m + n)
	{
		*(p + k) = C[k];
		k++;
	}
}

void mergeSort(int a[], int n)
{
	if (n > 1)
	{
		mergeSort(a, n / 2);
		mergeSort(a + n / 2, n - n / 2);
		merge(a, a + n / 2, n / 2, n - n / 2);
	}
}

int Search(int a[], int n, int val)
{
	int k = 0;
	while (k < n)
	{
		if (a[k] == val) return k;
		k++;
	}
	return -1;
}

int bisearch(int a[], int n, int val)//体验版，实质上检查升序或者降序的时间甚至超过了查找的时间。。
{
	int bottom = 0;
	int top = n - 1;
	int mid = (top - bottom) / 2 + bottom;
	if (isAsc(a, n))
	{
		while (1)
		{
			if (a[mid] == val) return mid;
			else if (top <= bottom) return -1;
			else if (a[mid] > val)
			{
				top = mid - 1;
				mid = (top - bottom) / 2 + bottom;
			}
			else
			{
				bottom = mid + 1;
				mid = (top - bottom) / 2 + bottom;
			}
		}
	}
	if (isDesc(a, n))
	{
		while (1)
		{
			if (a[mid] == val) return mid;
			else if (top <= bottom) return -1;
			else if (a[mid] < val)
			{
				top = mid - 1;
				mid = (top - bottom) / 2 + bottom;
			}
			else
			{
				bottom = mid + 1;
				mid = (top - bottom) / 2 + bottom;
			}
		}
	}
	return -2;
}

void LeftRotate(int a[], int n, int m)
{
	int k = 0;
	m = m % n;
	while (k < n - m)
	{
		C[k] = a[k];
		a[k] = a[k + m];
		k++;
	}
	while (k < n)
	{
		C[k] = a[k];
		a[k] = C[k + m - n];
		k++;
	}
}

void RightRotate(int a[], int n, int m)
{
	int k = n - 1;
	m = m % n;
	while (k >= m)
	{
		C[k] = a[k];
		a[k] = a[k - m];
		k--;
	}
	while (k >= 0)
	{
		C[k] = a[k];

		a[k] = C[k - m + n];
		k--;
	}
}

int maximum(int a[], int n)
{
	int m = a[0];
	int k = 1;
	while (k < n)
	{
		if (a[k] > m) m = a[k];
		k++;
	}
	return m;
}

int minimum(int a[], int n)
{
	int m = a[0];
	int k = 1;
	while (k < n)
	{
		if (a[k] < m) m = a[k];
		k++;
	}
	return m;
}
//方差
double Variation(int a[], int n)
{
	double ave = average(a, n);
	double sum = 0;
	int k = 0;
	while (k < n)
	{
		sum += a[k] * a[k];
		k++;
	}
	return sum / n - ave * ave;
}
//均方差
double standardVariation(int a[], int n)
{
	return sqrt(Variation(a, n));
}
//约瑟夫环
void Josephus(int a[], int n,int m)
{
	int k = 0;
	while (k < n)
	{
		B[k] = k + 1;
		k++;
	}
	k = 0;
	while (k < n)
	{
		LeftRotate(B, n - k, m);
		a[k] = B[0];
		Delete(B, n - k, 0);
		k++;
	}
	N = n;
}
//n以内全部素数
void findPrimes(int a[],int n)
{
	int k = 3;
	int m = 0;
	int i;
	if (n >= 2) a[0] = 2;
	while (k <= n)
	{
		i = 0;
		while (a[i] * a[i] <= k && a[i] != 0)
		{
			if (k % a[i] == 0) break;
			i++;
		}
		if (a[i] * a[i] > k || a[i] == 0) a[++m] = k;
		k++;
	}
	N = m + 1;
	if (n < 2) N = 0;
}

int main()
{
	int x = 1;
	int y = 1;
	int a, b;
	char c;
	while (1)
	{
		while (N <= 0 || width <= 0 || M <= 0 || N >= 10000)
		{
			printf("请配置系统参数使数组长度、打印宽度、单行打印个数为正整数,且数组长度不得超过10000\n");
			Config();
		}
		printf("主菜单\n0、退出\n1、配置系统参数\n2、生成样本数据\n3、显示数组\n4、删除\n5、插入\n6、统计\n7、查找\n8、判断\n9、排列数组元素\n10、数组的其他应用\n11、其他自选功能\n");
		printf("请输入指令\n");
		scanf("%d", &x);
		if (x == 0) break;
		switch (x)
		{
		case 0:
			break;
		case 1:
			Config();
			break;
		case 2:
			printf("填充数组选项\n1） 用指定范围的随机数填充数组\n2） 键盘输入\n3） 整个数组填同一个值\n4） 用等差序列填充数组（输入序列的起始值和每项的差值）\n");
			printf("请输入指令\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				printf("请输入随机数生成范围[s,t](依次输入整数s和t)\n");
				scanf("%d%d", &a, &b);
				randFill(A, N, a, b);
				break;
			case 2:
				FillArray(A, N);
				break;
			case 3:
				printf("请输入要填的整数n\n");
				scanf("%d", &a);
				constFill(A, N, a);
				break;
			case 4:
				printf("请依次输入等差数列的首项a0和公差d\n");
				scanf("%d%d", &a, &b);
				arithmaticFill(A, N, a, b);
				break;
			default:
				printf("指令错误\n");
				break;
			}
			break;
		case  3:
			printarr(A, N);
			break;
		case  4:
			printf("删除选项\n1） 删除指定下标的元素\n2） 删除指定值的元素\n3） 删除按指定下标区间的一组元素\n");
			printf("请输入指令\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				printf("请输入要删除的元素的下标k\n");
				scanf("%d", &a);
				Delete(A, N, a);
				break;
			case 2:
				printf("请输入要删除的数n\n");
				scanf("%d", &a);
				b = Search(A, N, a);
				if (b == -1) printf("数组中没有该数\n");
				else
					while (b != -1)
					{						
						Delete(A, N, b);
						b = Search(A, N, a);
					}
				break;
			case 3:
				printf("请输入要删除的元素的下标区间[s,t](依次输入整数s和t)\n");
				scanf("%d%d", &a, &b);
				DeleteRange(A, N, a, b);
				break;
			default:
				printf("指令错误\n");
				break;
			}
			break;
		case  5:
			printf("插入选项\n1）按指定下标位置插入新元素\n2）在有序数组中插入新元素\n");
			printf("请输入指令\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				if (N == 10000)
				{
					printf("数组长度不得超过10000\n");
					break;
				}
				printf("请依次输入新元素要插入的下标位置和新元素的值\n");
				scanf("%d%d", &a, &b);
				Insert(A, N, a, b);
				break;
			case 2:
				if (N == 10000)
				{
					printf("数组长度不得超过10000\n");
					break;
				}
				printf("请输入新元素的值\n");
				scanf("%d", &a);
				OrderInsert(A, N, a);
				break;
			default:
				printf("指令错误\n");
				break;
			}
			break;
		case  6:
			printf("统计分菜单\n1）求最大值\n2）求最小值\n3）求平均值\n4）求方差和均方差\n");
			printf("请输入指令\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				printf("最大值为%d\n", maximum(A, N));
				break;
			case 2:
				printf("最小值为%d\n", minimum(A, N));
				break;
			case 3:
				printf("平均值为%f\n", average(A, N));
				break;
			case 4:
				printf("方差为%f，均方差为%f\n", Variation(A, N), standardVariation(A, N));
				break;
			default:
				printf("指令错误\n");
				break;
			}
			break;
		case  7:
			printf("查找选项\n1） 普通查找\n2） 二分查找\n");
			printf("请输入指令\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				printf("请输入要查找的元素的值\n");
				scanf("%d", &a);
				b = Search(A, N, a);
				if (b == -1) printf("数组中没有该数\n");
				else printf("已找到第%d项为%d\n", b, a);
				break;
			case 2:
				printf("请输入要查找的元素的值\n");
				scanf("%d", &a);
				b = bisearch(A, N, a);
				if (b == -1) printf("数组中没有该数\n");
				else if (b == -2) printf("请先对数组进行排序\n");
				else printf("已找到第%d项为%d\n", b, a);
				break;
			default:
				printf("指令错误\n");
				break;
			}
			break;
		case  8:
			printf("判断分菜单\n1）是否升序排列\n2）是否降序排列\n3）是否全部相等\n");
			printf("请输入指令\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				if (isAsc(A, N)) printf("该数组是升序排列\n");
				else printf("该数组不是升序排列\n");
				break;
			case 2:
				if (isDesc(A, N)) printf("该数组是降序排列\n");
				else printf("该数组不是降序排列\n");
				break;
			case 3:
				if (isEqual(A, N)) printf("该数组的元素全部相等\n");
				else printf("该数组的元素不全相等\n");
				break;
			default:
				printf("指令错误\n");
				break;
			}
			break;
		case  9:
			printf("排列数组元素分菜单\n1）排序\n2）逆置数组\n3）左旋数组\n4）右旋数组\n");
			printf("请输入指令\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				printf("排序选项（全部为升序排序）\na. 冒泡法\nb. 选择法\nc. 交换法\nq. 退出\n");
				printf("请输入指令\n");
				scanf("%c", &c);
				if (c != 'a' && c != 'b' && c != 'c')
				{
					while (c != 'q')
					{
						scanf("%c", &c);
						if (c != 'a' && c != 'b' && c != 'c' && c!='q') printf("指令错误，请重新输入指令\n");
						else break;
					}
				}
				switch (c)
				{
				case 'a':
					BubbleSort(A, N);
					break;
				case 'b':
					SelectSort(A, N);
					break;
				case 'c':
					ExchangeSort(A, N);
					break;
				}
				break;
			case 2:
				Reverse(A, N);
				break;
			case 3:
				printf("请输入左旋位数n\n");
				scanf("%d", &a);
				LeftRotate(A, N, a);
				break;
			case 4:
				printf("请输入右旋位数n\n");
				scanf("%d", &a);
				RightRotate(A, N, a);
				break;
			default:
				printf("指令错误\n");
				break;
			}
			break;
		case  10:
			printf("数组的其他应用\n1）约瑟夫环\n2）筛法求素数\n");
			printf("请输入指令\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				printf("请依次输入人数n及一个正整数m，然后程序将这些人编好号，依次排为一圈，然后从1号开始数，每数过m个活人便杀死当前数到的活人，并生成死亡名单（按照死亡先后顺序，由死者编号排成的n元数组）\n");
				scanf("%d%d", &a,&b);
				Josephus(A, a, b);
				break;
			case 2:
				printf("输入一个正整数n然后生成升序排列的n以内全体素数的数组\n");
				scanf("%d", &a);
				findPrimes(A, a);
				break;
			default:
				printf("指令错误\n");
				break;
			}
			break;
		case 11:
			printf("无\n");
			break;
		default:
			printf("指令错误\n");
			break;
		}
	}
	return 0;
}
