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
