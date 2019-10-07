#pragma once
#include <stdio.h>
#include <cmath>

struct BaseData
{
	float** data;
	int row;
	int col;
};

inline void init_base_data(BaseData& base_data, int row, int col)
{
	base_data.row = row;
	base_data.col = col;
	base_data.data = new float*[base_data.row];
	for (int i = 0; i < base_data.row; i++)
	{
		base_data.data[i] = new float[base_data.col];
	}
	//³õÊ¼»¯¸³Öµ
	for (int i = 0; i < base_data.row; ++i)
	{
		for (int j = 0; j < base_data.col; ++j)
		{
			base_data.data[i][j] = 0.0;
		}
	}
}

inline void release_base_data(BaseData& base_data)
{
	for (int i = 0; i < base_data.row; ++i)
	{
		delete[] base_data.data[i];
	}
	delete[] base_data.data;
}

inline void print_base_data(BaseData& base_data)
{
	for (int i = 0; i < base_data.row; ++i)
	{
		for (int j = 0; j < base_data.col; ++j)
		{
			printf("%f  ", base_data.data[i][j]);
		}
		printf("\n");
	}
}

inline void input_base_data_row(BaseData& base_data, int cur_row, float* data, int data_length)
{
	if (data_length < base_data.col)
		return;
	for (int i = 0; i < base_data.col; ++i)
	{
		base_data.data[cur_row][i] = data[i];
	}
}

inline void input_base_data_col(BaseData& base_data, int cur_col, float* data, int data_length)
{
	if (data_length < base_data.row)
		return;
	for (int i = 0; i < base_data.row; ++i)
	{
		base_data.data[i][cur_col] = data[i];
	}
}