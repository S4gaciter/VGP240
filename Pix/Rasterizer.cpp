#include "Rasterizer.h"

Rasterizer* Rasterizer::Get()
{
	static Rasterizer sInstance;
	return &sInstance;
}

void Rasterizer::SetColor(X::Color color)
{
	mColor = color;
}

void Rasterizer::SetFillMode(FillMode mode)
{
	mFillMode = mode;
}

void Rasterizer::DrawPoint(int x, int y)
{
	X::DrawPixel(x, y, mColor);
}

void Rasterizer::DrawPoint(Vertex v)
{
	X::DrawPixel(static_cast<int>(v.pos.x), static_cast<int>(v.pos.y), v.color);
}

void Rasterizer::DrawLine(Vertex a, Vertex b)
{
	int dx = b.pos.x - a.pos.x;
	int dy = b.pos.y - a.pos.y;
	int m = dy / dx;
	int f = a.pos.y - (m * a.pos.x);
	float t = 0.0f;
	for (int x = a.pos.x; x <= b.pos.x; ++x)
	{
		int y = round((m * x) + f);
		X::DrawPixel(x, y, LerpColor(a.color, b.color, t));
	}
}

void Rasterizer::DrawTriangle(Vertex v1, Vertex v2, Vertex v3)
{
	switch (mFillMode)
	{
	case FillMode::Wireframe:
		DrawLine(v1, v2);
		DrawLine(v2, v3);
		DrawLine(v3, v1);
		break;
	case FillMode::Solid:
		break;
	}
}
