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

