#pragma once

#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

class PrimitiveManager
{
public:
	static PrimitiveManager *Get();

	bool BeginDraw(Topology topology, bool applyTransform = false);
	void AddVertex(Vertex vertex);
	bool EndDraw();

private:
	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Triangle;
	bool mDrawBegin = false;
	bool mApplyTransform = false;
};

