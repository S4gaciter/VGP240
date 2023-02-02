#pragma once

#include "Vector3.h"
#include <XEngine.h>

struct Vertex
{
	Vector3 pos;
	X::Color color;
};

inline Vector3 LerpPosition(Vector3 a, Vector3 b, float t)
{
	return Vector3(
		a.x + (b.x - a.x) * t,
		a.y + (b.y - a.y) * t,
		a.z + (b.z - a.z) * t
	);
}
inline X::Color LerpColor(X::Color a, X::Color b, float t)
{
	return X::Color(
		a.r + (b.r - a.r) * t,
		a.g + (b.g - a.g) * t,
		a.b + (b.b - a.b) * t,
		a.w + (b.w - a.w) * t
	);
	
}
inline Vertex LerpVertex(Vertex a, Vertex b, float t)
{
	Vector3 resPos = LerpPosition(a.pos, b.pos, t);
	X::Color resColor = LerpColor(a.color, b.color, t);
	return { resPos, resColor };
}