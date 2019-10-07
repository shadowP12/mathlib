#pragma once
#include "base.h"

//求逆序数
inline int number_inversions(int* data, int length)
{
	int res = 0;
	for (int i = 0; i < length; i++)
	{
		int cur = data[i];
		for (int j = 0; j < i; j++)
		{
			int pre = data[j];
			if (pre > cur)
				res++;
		}
	}
	return res;
}

//求余子式
inline BaseData cofactor(BaseData& base_data, int cur_row, int cur_col)
{
	BaseData res;
	init_base_data(res, base_data.row - 1, base_data.col - 1);
	for (int i = 0; i < base_data.row; i++)
	{
		for (int j = 0; j < base_data.col; j++)
		{
			if (i == cur_row - 1 || j == cur_col - 1)
			{
			}
			else if (i > cur_row - 1 || j > cur_col - 1)
			{
				int r = i, c = j;
				if (i > cur_row - 1)
					r = i - 1;
				if (j > cur_col - 1)
					c = j - 1;
				res.data[r][c] = base_data.data[i][j];
			}
			else
			{
				res.data[i][j] = base_data.data[i][j];
			}
		}
	}
	return res;
}


//求行列式
inline float determinant(BaseData& base_data)
{
	if (base_data.row != base_data.col)
	{
		printf("rows must be equal to columns \n");
		return 0.0;
	}
	if (base_data.row == 1)
		return base_data.data[0][0];

	float sum = 0.0;
	for (int i = 0; i < base_data.col; i++)
	{
		BaseData tem_data = cofactor(base_data, 1, i+1);
		sum += base_data.data[0][i] * pow(-1, 1+i+1) * determinant(tem_data);
		release_base_data(tem_data);
	}
	return sum;
}