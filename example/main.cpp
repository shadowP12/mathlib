#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Common.h"
#include "Geometry.h"

void testJacobiIteration();

int main()
{
    testJacobiIteration();
	return 0;
}

void testJacobiIteration()
{
    // 测试jacobi迭代
    int n = 3;
    float* A = new float[n * n];
    float* b = new float[n];
    float* x = new float[n];
    memset(A, 0, sizeof(float) * n * n);
    memset(b, 0, sizeof(float) * n);
    memset(x, 0, sizeof(float) * n);

    A[0] = 8.0f;
    A[1] = -3.0f;
    A[2] = 2.0f;

    A[3] = 4.0f;
    A[4] = 11.0f;
    A[5] = -1.0f;

    A[6] = 2.0f;
    A[7] = 1.0f;
    A[8] = 4.0f;

    b[0] = 20.0f;
    b[1] = 33.0f;
    b[2] = 12.0f;

    jacobiIteration(n, 3, A, b, x);
    printVector(n, x);
}