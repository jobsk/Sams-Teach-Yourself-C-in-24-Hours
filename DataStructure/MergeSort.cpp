/* 对顺序表L作归并排序 */
void MergeSort(SqList *L)
{
    MSort(L->r, L->r, 1, L->length);
}

/**
 * @brief 将SR[s..t]归并排序为TR1[s..t]
 * 
 * @param SR 待排序数组
 * @param TR1 归并后数组
 * @param s 数组起始下标
 * @param t 数组终止下标
 */
void MSort(int SR[], int TR1[], int s, int t)
{
    int m;
    int TR2[MAXSIZE + 1];
    if (s == t)
        TR1[s] = SR[s]; // SR中只有1位 直接对位复制到TR1中
    else
    {
        /* 将SR[s..t]平分为SR[s..m]和SR[m+1..t] */
        m = (s + t) / 2;             
        /* 递归将SR[s..m]归并为有序的TR2[s..m] */
        MSort(SR, TR2, s, m);        
        /* 递归将SR[m+1..t]归并为有序TR2[m+1..t] */
        MSort(SR, TR2, m + 1, t);   
        /* 将TR2[s..m]和TR2[m+1..t] 归并到TR1[s..t] */
        Merge(TR2,TR1, s, m, t);     
    }
}
