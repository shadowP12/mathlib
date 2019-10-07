#pragma once

struct matrix
{
	float** data;
	int row;
	int col;
};

inline void init_matrix(matrix& mat, int row, int col)
{
	mat.row = row;
	mat.col = col;
	mat.data = new float*[mat.row];
	for (int i = 0; i < mat.row; i++)
	{
		mat.data[i] = new float[mat.col];
	}
	//³õÊ¼»¯¸³Öµ
	for (int i = 0; i < mat.row; ++i)
	{
		for (int j = 0; j < mat.col; ++j)
		{
			mat.data[i][j] = 0.0;
		}
	}
}

inline void release_matrix(matrix& mat)
{
	for (int i = 0; i < mat.row; ++i)
	{
		delete[] mat.data[i];
	}
	delete[] mat.data;
}

inline void print_matrix(matrix& mat)
{
	for (int i = 0; i < mat.row; ++i)
	{
		for (int j = 0; j < mat.col; ++j)
		{
			printf("%f  ",mat.data[i][j]);
		}
		printf("\n");
	}
}

inline void input_matrix_row(matrix& mat, int cur_row, float* data, int data_length)
{
	if (data_length < mat.col)
		return;
	for (int i = 0; i < mat.col; ++i)
	{
		mat.data[cur_row][i] = data[i];
	}
}

inline void input_matrix_col(matrix& mat, int cur_col, float* data, int data_length)
{
	if (data_length < mat.row)
		return;
	for (int i = 0; i < mat.row; ++i)
	{
		mat.data[i][cur_col] = data[i];
	}
}