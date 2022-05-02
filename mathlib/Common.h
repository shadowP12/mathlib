#pragma once
#include "Vector3.h"

// 判断同边
inline bool sameSide(const Vector3& p1, const Vector3& p2, const Vector3& a, const Vector3& b)
{
	Vector3 v1 = b - a;
	Vector3 v2 = p1 - a;
	Vector3 v3 = v1.cross(v2);

	Vector3 v4 = p2 - a;
	Vector3 v5 = v1.cross(v4);
	// 方向同向
	if (v3.dot(v5) >= 0.0f)
		return true;
	return false;
}

// 判断点是否在一个三角形内
// 该处使用同边法
inline bool pointInTriangle(const Vector3& p, const Vector3& a, const Vector3& b, const Vector3& c)
{
	return sameSide(p, a, b, c) && sameSide(p, b, a, c) && sameSide(p, c, a, b);
}

// 球面坐标系转笛卡尔坐标系
// s.x:r 半径
// s.y:theta 仰角
// s.z:phi 方位角
// note:这里使用右手坐标系
inline Vector3 cartesianCoord2SphericalCoord(const Vector3& s)
{
	Vector3 ret;
	ret.x = s.x * std::sin(s.y) * std::cos(s.z);
	ret.y = s.x * std::cos(s.y);
	ret.z = -(s.x * std::sin(s.y) * std::sin(s.z)); // 注意这里的负号
	return ret;
}

inline Vector3 cartesianCoord2SphericalCoord(float r, float theta, float phi)
{
	Vector3 ret;
	ret.x = r * std::sin(theta) * std::cos(phi);
	ret.y = r * std::cos(theta);
	ret.z = -(r * std::sin(theta) * std::sin(phi)); // 注意这里的负号
	return ret;
}

// 笛卡尔坐标系转球面坐标系
inline Vector3 sphericalCoord2CartesianCoord(const Vector3& c)
{
	Vector3 ret;
	ret.x = std::sqrt(c.x*c.x + c.y*c.y + c.z*c.z); //r
	ret.y = std::atan2(-c.z, c.x); //theta
	ret.z = acos(c.y / ret.x); //phi
	
	return ret;
}

inline Vector2 projectPointToVector(const Vector2& point, const Vector2& proj)
{
    Vector2 ret;
    const float mul = Vector2::dot(point, proj) / Vector2::dot(proj, proj);
    ret.x = mul * proj.x;
    ret.y = mul * proj.y;
    return ret;
}

inline Vector3 projectPointToVector(const Vector3& point, const Vector3& proj)
{
    Vector3 ret;
    const float mul = Vector3::dot(point, proj) / Vector3::dot(proj, proj);
    ret.x = mul * proj.x;
    ret.y = mul * proj.y;
    ret.z = mul * proj.z;
    return ret;
}

void printMatrix(int n, float* m)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int idx = i * n + j;
            printf("%f  ", m[idx]);
        }
        printf("\n");
    }
}

void printVector(int n, float* v)
{
    for (int i = 0; i < n; ++i) {
        printf("%f  ", v[i]);
    }
    printf("\n");
}

// 矩阵乘法(行优先)
void matrixMult(int n, float* m0, float* m1, float*& out)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int idx = i * n + j;
            out[idx] = 0.0f;
            for (int k = 0; k < n; ++k) {
                out[idx] += m0[i * n + k] * m1[k * n + j];
            }
        }
    }
}

// 矩阵向量乘法
void matrixVertorMult(int n, float* m, float* v, float*& out)
{
    for (int i = 0; i < n; ++i) {
        out[i] = 0.0f;
        for (int j = 0; j < n; ++j) {
            out[i] += m[i * n + j] * v[j];
        }
    }
}

// jacobi iteration
inline void jacobiIteration(int n, int tol, float* A, float* b, float*& x)
{
    // 将A分解为D,L,U三个矩阵
    // 对角矩阵求逆方便，所以提前处理
    float* invD = new float[n * n];
    float* LU = new float[n * n];
    memset(invD, 0, sizeof(float) * n * n);
    memset(LU, 0, sizeof(float) * n * n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int idx = i * n + j;
            // 对角
            if (i == j) {
                invD[idx] = 1.0f / A[idx];
            } else {
                LU[idx] = -A[idx];
            }
        }
    }

    // 求jacobi矩阵
    float* Bj = new float[n * n];
    memset(Bj, 0, sizeof(float) * n * n);
    matrixMult(n, invD, LU, Bj);

    // 求f
    float* f = new float[n];
    memset(f, 0, sizeof(float) * n);
    matrixVertorMult(n, invD, b, f);

    // 迭代
    float* t = new float[n];
    for (int i = 0; i < tol; ++i) {
        matrixVertorMult(n, Bj, x, t);

        for (int j = 0; j < n; ++j) {
            x[j] = t[j] + f[j];
        }
    }

    delete [] invD;
    delete [] LU;
    delete [] Bj;
    delete [] f;
    delete [] t;
}

