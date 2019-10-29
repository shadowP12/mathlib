#pragma once

template<int N, int M>
class MatrixNxM
{
public:
	MatrixNxM(float data[N * M])
	{
		memcpy(m, data, N * M * sizeof(float));
	}

	MatrixNxM<M, N> transpose() const
	{
		MatrixNxM<M, N> mat_transpose;
		for (uint32_t row = 0; row < N; row++)
		{
			for (uint32_t col = 0; col < M; col++)
				mat_transpose[col][row] = m[row][col];
		}

		return mat_transpose;
	}

	float* operator[] (uint32_t row) const
	{
		assert(row < N);

		return (float*)m[row];
	}

	bool operator== (const MatrixNxM& rhs) const
	{
		for (uint32_t row = 0; row < N; row++)
		{
			for (uint32_t col = 0; col < M; col++)
			{
				if (m[row][col] != rhs.m[row][col])
					return false;
			}
		}

		return true;
	}

	bool operator!= (const MatrixNxM& rhs) const
	{
		return !operator==(rhs);
	}

	float m[N][M];
};