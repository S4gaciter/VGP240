#include "MathHelper.h"

float Magnitude(Vector2 v)
{
	return v.x * v.x + v.y * v.y;
}

float Magnitude(Vector3 v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

float MagnitudeSquared(Vector2 v)
{
	return (v.x * v.x + v.y * v.y) * (v.x * v.x + v.y * v.y);
}

float MagnitudeSquared(Vector3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z) * (v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector2 Normalize(Vector2 v)
{
	return { (v.x / (v.x * v.x)), (v.y / (v.y * v.y)) };
}

Vector3 Normalize(Vector3 v)
{
	return { (v.x / (v.x * v.x)), (v.z / (v.z * v.z)), (v.z / (v.z * v.z)) };
}

float Dot(Vector2 a, Vector2 b)
{
	return a.x * b.x + a.y * b.y;
}

float Dot(Vector3 a, Vector3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Cross(Vector3 a, Vector3 b)
{
	return { (a.y * b.z + a.z * b.y), (a.x * b.z + a.z * b.x), (a.x * b.y + a.y * b.x) };
}