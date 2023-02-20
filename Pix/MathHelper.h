#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix4.h"

namespace MathHelper
{
	bool CheckEqual(float a, float b);

	float Magnitude(Vector2 v);
	float Magnitude(Vector3 v);

	float MagnitudeSquared(Vector2 v);
	float MagnitudeSquared(Vector3 v);

	Vector2 Normalize(Vector2 v);
	Vector3 Normalize(Vector3 v);

	float Dot(Vector2 a, Vector2 b);
	float Dot(Vector3 a, Vector3 b);

	Vector3 Cross(Vector3 a, Vector3 b);

	Vector3 TransformCoord(Vector3 v, Matrix4 m);
	Vector3 TransformNormal(Vector3 v, Matrix4 m);

	float Determinant(Matrix4 m);
	Matrix4 Adjoint(Matrix4 m);
	Matrix4 Transpose(Matrix4 m);
	Matrix4 Inverse(Matrix4 m);
}