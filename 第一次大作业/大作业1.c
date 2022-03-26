
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int A[10005], B[10005], C[10005];
int N = 10;//���鳤��
int width = 5;//�����ӡ���
int M = 10;//���д�ӡ����

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
	printf("��ǰ���鳤��Ϊ%d,�������µ����鳤�ȣ����鳤��Ӧ����10000���ڣ�\n", N);
	scanf("%d", &N);
	printf("��ǰ�����ӡ���Ϊ%d,�������µ������ӡ���\n", width);
	scanf("%d", &width);
	printf("��ǰ���д�ӡ����Ϊ%d,�������µĵ��д�ӡ����\n", M);
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
		printf("ָ��ɾ�����±겻�Ϸ�\n");
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
	else printf("���ȶ������������\n");
}
//������������
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

int bisearch(int a[], int n, int val)//����棬ʵ���ϼ��������߽����ʱ�����������˲��ҵ�ʱ�䡣��
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
//����
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
//������
double standardVariation(int a[], int n)
{
	return sqrt(Variation(a, n));
}
//Լɪ��
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
//n����ȫ������
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
			printf("������ϵͳ����ʹ���鳤�ȡ���ӡ��ȡ����д�ӡ����Ϊ������,�����鳤�Ȳ��ó���10000\n");
			Config();
		}
		printf("���˵�\n0���˳�\n1������ϵͳ����\n2��������������\n3����ʾ����\n4��ɾ��\n5������\n6��ͳ��\n7������\n8���ж�\n9����������Ԫ��\n10�����������Ӧ��\n11��������ѡ����\n");
		printf("������ָ��\n");
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
			printf("�������ѡ��\n1�� ��ָ����Χ��������������\n2�� ��������\n3�� ����������ͬһ��ֵ\n4�� �õȲ�����������飨�������е���ʼֵ��ÿ��Ĳ�ֵ��\n");
			printf("������ָ��\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				printf("��������������ɷ�Χ[s,t](������������s��t)\n");
				scanf("%d%d", &a, &b);
				randFill(A, N, a, b);
				break;
			case 2:
				FillArray(A, N);
				break;
			case 3:
				printf("������Ҫ�������n\n");
				scanf("%d", &a);
				constFill(A, N, a);
				break;
			case 4:
				printf("����������Ȳ����е�����a0�͹���d\n");
				scanf("%d%d", &a, &b);
				arithmaticFill(A, N, a, b);
				break;
			default:
				printf("ָ�����\n");
				break;
			}
			break;
		case  3:
			printarr(A, N);
			break;
		case  4:
			printf("ɾ��ѡ��\n1�� ɾ��ָ���±��Ԫ��\n2�� ɾ��ָ��ֵ��Ԫ��\n3�� ɾ����ָ���±������һ��Ԫ��\n");
			printf("������ָ��\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				printf("������Ҫɾ����Ԫ�ص��±�k\n");
				scanf("%d", &a);
				Delete(A, N, a);
				break;
			case 2:
				printf("������Ҫɾ������n\n");
				scanf("%d", &a);
				b = Search(A, N, a);
				if (b == -1) printf("������û�и���\n");
				else
					while (b != -1)
					{						
						Delete(A, N, b);
						b = Search(A, N, a);
					}
				break;
			case 3:
				printf("������Ҫɾ����Ԫ�ص��±�����[s,t](������������s��t)\n");
				scanf("%d%d", &a, &b);
				DeleteRange(A, N, a, b);
				break;
			default:
				printf("ָ�����\n");
				break;
			}
			break;
		case  5:
			printf("����ѡ��\n1����ָ���±�λ�ò�����Ԫ��\n2�������������в�����Ԫ��\n");
			printf("������ָ��\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				if (N == 10000)
				{
					printf("���鳤�Ȳ��ó���10000\n");
					break;
				}
				printf("������������Ԫ��Ҫ������±�λ�ú���Ԫ�ص�ֵ\n");
				scanf("%d%d", &a, &b);
				Insert(A, N, a, b);
				break;
			case 2:
				if (N == 10000)
				{
					printf("���鳤�Ȳ��ó���10000\n");
					break;
				}
				printf("��������Ԫ�ص�ֵ\n");
				scanf("%d", &a);
				OrderInsert(A, N, a);
				break;
			default:
				printf("ָ�����\n");
				break;
			}
			break;
		case  6:
			printf("ͳ�Ʒֲ˵�\n1�������ֵ\n2������Сֵ\n3����ƽ��ֵ\n4���󷽲�;�����\n");
			printf("������ָ��\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				printf("���ֵΪ%d\n", maximum(A, N));
				break;
			case 2:
				printf("��СֵΪ%d\n", minimum(A, N));
				break;
			case 3:
				printf("ƽ��ֵΪ%f\n", average(A, N));
				break;
			case 4:
				printf("����Ϊ%f��������Ϊ%f\n", Variation(A, N), standardVariation(A, N));
				break;
			default:
				printf("ָ�����\n");
				break;
			}
			break;
		case  7:
			printf("����ѡ��\n1�� ��ͨ����\n2�� ���ֲ���\n");
			printf("������ָ��\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				printf("������Ҫ���ҵ�Ԫ�ص�ֵ\n");
				scanf("%d", &a);
				b = Search(A, N, a);
				if (b == -1) printf("������û�и���\n");
				else printf("���ҵ���%d��Ϊ%d\n", b, a);
				break;
			case 2:
				printf("������Ҫ���ҵ�Ԫ�ص�ֵ\n");
				scanf("%d", &a);
				b = bisearch(A, N, a);
				if (b == -1) printf("������û�и���\n");
				else if (b == -2) printf("���ȶ������������\n");
				else printf("���ҵ���%d��Ϊ%d\n", b, a);
				break;
			default:
				printf("ָ�����\n");
				break;
			}
			break;
		case  8:
			printf("�жϷֲ˵�\n1���Ƿ���������\n2���Ƿ�������\n3���Ƿ�ȫ�����\n");
			printf("������ָ��\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				if (isAsc(A, N)) printf("����������������\n");
				else printf("�����鲻����������\n");
				break;
			case 2:
				if (isDesc(A, N)) printf("�������ǽ�������\n");
				else printf("�����鲻�ǽ�������\n");
				break;
			case 3:
				if (isEqual(A, N)) printf("�������Ԫ��ȫ�����\n");
				else printf("�������Ԫ�ز�ȫ���\n");
				break;
			default:
				printf("ָ�����\n");
				break;
			}
			break;
		case  9:
			printf("��������Ԫ�طֲ˵�\n1������\n2����������\n3����������\n4����������\n");
			printf("������ָ��\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				printf("����ѡ�ȫ��Ϊ��������\na. ð�ݷ�\nb. ѡ��\nc. ������\nq. �˳�\n");
				printf("������ָ��\n");
				scanf("%c", &c);
				if (c != 'a' && c != 'b' && c != 'c')
				{
					while (c != 'q')
					{
						scanf("%c", &c);
						if (c != 'a' && c != 'b' && c != 'c' && c!='q') printf("ָ���������������ָ��\n");
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
				printf("����������λ��n\n");
				scanf("%d", &a);
				LeftRotate(A, N, a);
				break;
			case 4:
				printf("����������λ��n\n");
				scanf("%d", &a);
				RightRotate(A, N, a);
				break;
			default:
				printf("ָ�����\n");
				break;
			}
			break;
		case  10:
			printf("���������Ӧ��\n1��Լɪ��\n2��ɸ��������\n");
			printf("������ָ��\n");
			scanf("%d", &y);
			switch (y)
			{
			case 1:
				printf("��������������n��һ��������m��Ȼ�������Щ�˱�úţ�������ΪһȦ��Ȼ���1�ſ�ʼ����ÿ����m�����˱�ɱ����ǰ�����Ļ��ˣ��������������������������Ⱥ�˳�������߱���ųɵ�nԪ���飩\n");
				scanf("%d%d", &a,&b);
				Josephus(A, a, b);
				break;
			case 2:
				printf("����һ��������nȻ�������������е�n����ȫ������������\n");
				scanf("%d", &a);
				findPrimes(A, a);
				break;
			default:
				printf("ָ�����\n");
				break;
			}
			break;
		case 11:
			printf("��\n");
			break;
		default:
			printf("ָ�����\n");
			break;
		}
	}
	return 0;
}
