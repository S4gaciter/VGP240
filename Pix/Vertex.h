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
	Vector3 c = a + (b - a) * t;
	return c;
}
inline X::Color LerpColor(X::Color a, X::Color b, float t)
{
	X::Color c;
	c.r = a.r + (b.r - a.r) * t;
	c.g = a.g + (b.g - a.g) * t;
	c.b = a.b + (b.b - a.b) * t;
	return c;
}
inline Vertex LerpVertex(Vertex a, Vertex b, float t)
{
	Vector3 resPos = LerpPosition(a.pos, b.pos, t);
	X::Color resColor = LerpColor(a.color, b.color, t);
	return { resPos, resColor };
}