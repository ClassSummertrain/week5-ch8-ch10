#include<stdio.h>
#include<stdlib.h>
#define MAX 999999
typedef struct
{
	int weight, flag;//权值、访问状态
	int parent, Lchild, Rchild;	//父结点、左孩子、右孩子
}HTNode, *HuffmanTree;

void InitHuffmanTree(HuffmanTree &HT, int N)	//初始化所有结点
{
	if(N > 1)
	{
		int i;
		HT = (HTNode *)malloc(2 * N * sizeof(HTNode));//动态分配空间
		for(i = 1; i < 2 * N; i++)//初始化
		{
			HT[i].parent = 0;
			HT[i].Lchild = 0;
			HT[i].Rchild = 0;
			HT[i].weight = MAX;//初始化权值
			HT[i].flag = 0;//初始化结点未被访问
		}
		for(i = 1; i <= N; i++)//输入权值
			scanf("%d", &HT[i].weight);
	}
}

int Select(HuffmanTree &HT, int N)	//选择最小权值的结点下标
{
	int i, temp, min;
	for(i = 1; i <= N; i++)//设置初始下标和权值
	{
		if(HT[i].flag == 0)
		{
			temp = HT[i].weight;//初始权值
			min = i;//初始下标
			break;
		}
	}
	while(i <= N)//查找最小权值下标
	{
		if(!HT[i].flag && temp > HT[i].weight)
		{
			temp = HT[i].weight;//最小权值
			min = i;//最小权值的小标
		}
		i++;
	}
	HT[min].flag = 1;//最小权值已经被访问
	return min;//返回最小权值下标
}

void CreateHuffmanTree(HuffmanTree &HT, int N)//构建哈夫曼树
{
	int i, s1, s2;
	for(i = N + 1; i < 2 * N; i++)
	{
		s1 = Select(HT, i - 1);
		s2 = Select(HT, i - 1);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].Lchild = s1;
		HT[i].Rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

void DispHuffmanTree(HuffmanTree HT, int N)//打印哈夫曼树的状态表
{
	printf("\n结点i\tweight\tparent\tLchild\tRchild\n");
	for(int i = 1; i < 2 * N; i++)
	{
		printf("%d\t", i);

		if(HT[i].weight == MAX)//用于打印初始状态的判断
			printf("%c\t", '-');
		else
			printf("%d\t", HT[i].weight);
			
		printf("%d\t%d\t%d\n", HT[i].parent, HT[i].Lchild, HT[i].Rchild);
	}
}


int main()
{
	int N;
	HuffmanTree HT;
	printf("请输入构建哈夫曼树的结点数:");
	scanf("%d", &N);
	//测试用例:5 29 7 8 14 23 3 11
	printf("初始化输入%d个结点的权值:", N);	
	InitHuffmanTree(HT, N);

	printf("\n-----哈夫曼树的初始状态表-----");
	DispHuffmanTree(HT, N);

	CreateHuffmanTree(HT, N);

	printf("\n-----哈夫曼树的最终状态表-----");
	DispHuffmanTree(HT, N);

	return 0;
}
