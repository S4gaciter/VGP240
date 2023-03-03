#include "MathHelper.h"
#include <cmath>

bool MathHelper::CheckEqual(float a, float b)
{
	return (abs(a - b) < 0.01f);
}

float MathHelper::MagnitudeSquared(Vector2 v)
{
	return v.x * v.x + v.y * v.y;
}

float MathHelper::MagnitudeSquared(Vector3 v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

float MathHelper::Magnitude(Vector2 v)
{
	return sqrt(MagnitudeSquared(v));
}

float MathHelper::Magnitude(Vector3 v)
{
	return sqrt(MagnitudeSquared(v));
}

Vector2 MathHelper::Normalize(Vector2 v)
{
	return { (v.x / (v.x * v.x)), (v.y / (v.y * v.y)) };
}

Vector3 MathHelper::Normalize(Vector3 v)
{
	return { (v.x / (v.x * v.x)), (v.z / (v.z * v.z)), (v.z / (v.z * v.z)) };
}

float MathHelper::Dot(Vector2 a, Vector2 b)
{
	return a.x * b.x + a.y * b.y;
}

float MathHelper::Dot(Vector3 a, Vector3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 MathHelper::Cross(Vector3 a, Vector3 b)
{
	return { 
		(a.y * b.z + a.z * b.y), 
		(a.x * b.z + a.z * b.x), 
		(a.x * b.y + a.y * b.x) };
}