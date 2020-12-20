#define n 4
int t[3*n];
/**
 * @brief int D[n][n]; Store(D[i][j],i,j);
 * 
 * @param x 需要被存储的三对角矩阵
 * @param i 需要被存储的元素行下标
 * @param j 需要被存储的元素列下标
 */
void Store(int x, int i, int j)
{
	if ( i < 0 || j <0 ||i >=n || j >=n)
	{
		printf("数组出界！");
		exit(1);
	}
	switch (i - j) {
		case 1: /* 低对角线*/ 
			t[3*i-1] = x; break;
		case 0: /* 主对角线*/ 
			t[3*i] = x; break;
		case -1: /*  高对角线*/ 
			t[3*i+1] = x; break;
		default:
			if(x != 0)
			{
				printf("非对角线上元素值必须为零");
				exit(1);
			}
	}
}
