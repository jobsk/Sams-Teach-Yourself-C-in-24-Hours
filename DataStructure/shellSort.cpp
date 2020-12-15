/* 对顺序表L作希尔排序 */
void ShellSort(int L[], int len)
{
    int i, j;
    int increment = len;
    do
    {
        /* 增量序列 从最大值开始，一直降到1为止 */
        increment = increment / 3 + 1;                
        for (i = increment + 1; i <= len; i++)
        {
            if (L[i] < L[i - increment])
            {                                         
                /* 需将L->r[i]插入有序增量子表 */
                /* 暂存在L->r[0] 由此在r[i]的位置可以看作一个arr_hole*/
                L[0] = L[i];                    
                for (j = i - increment; j > 0 && L[j] > L[0]; j -= increment)
				{
					/* j是需要与r[i]调换的元素的下标 */
					L[j + increment] = L[j];
					/* r[i]不一定确定放在 r[j] 因为r[j-increment]可能比r[i]要大
					 * 这时需要循环比较 r[j] r[j-increment] r[j-2*increment]与r[i]的大小
					 * 所以有终止条件 j<=0或r[j]<r[0]时 停止循环 */
				}
				/* 将暂存的L->r[i]插入有序增量子表 */
				L[j + increment] = L[0];
			}  // if (L[i] < L[i - increment])
		}  // 一趟遍历结束
	} while (increment > 1);

}


int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    int a[10] = {0,9,1,5,8,3,7,4,6,2};
	int n = 9;
    ShellSort(a, n);
    for (int i = 1; i <= n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout << endl;
    return 0;
}
