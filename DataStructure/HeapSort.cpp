/* 对顺序表L进行堆排序 */
void HeapSort(SqList *L)
{
    int i;
    /* 把L中的r构建成一个大顶堆 */
    for (i = L->length / 2; i > 0; i--)    
        HeapAdjust(L, i, L->length);
    for (i = L->length; i > 1; i--)
    {
        /* 将堆顶记录和当前未经排序子序列的最后一个记录交换 */
        swap(L, 1, i);                     
        /* 将L->r[1..i-1]重新调整为大顶堆 */
        HeapAdjust(L, 1, i - 1);           
    }
}

/**
 * @brief 已知L->r[s..m]中记录的关键字除L->r[s]之外均满足堆的定义
 * 		  本函数调整L->r[s]的关键字，使L->r[s..m]成为一个大顶堆
 * 
 * @param L 需要排序的序列
 * @param s 需要被调整的关键字r[s]
 * @param m 序列末位r[m]
 */
void HeapAdjust(SqList *L,int s,int m)
{
    int temp, j;
    temp = L->r[s];
    /* 沿关键字较大的孩子结点向下筛选 */
    for (j = 2 * s; j <= m; j *= 2)    
    {
        if (j < m && L->r[j] < L->r[j + 1])
            /* j为关键字中较大的记录的下标 */
            ++j;                       
        if (temp >= L->r[j])
            /* r[s]就是大顶堆的子树根，理应插入在位置s上 */
            break;                     
        L->r[s] = L->r[j];
		/* 子树较大的孩子被调整为根 并把调换为孩子的原根作为新子树的待调整对象*/
        s = j;    
    } // 若最后一次调整的根与孩子处于叶子位置，则j*2>m
    /* 插入 */
    L->r[s] = temp;                    
}

int main()
{
    int a[10] = {0,50,10,90,30,70,40,80,60,20};
	int n = 9;
    HeapSort(a, n);
    for (int i = 1; i <= n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout << endl;
    return 0;
}
