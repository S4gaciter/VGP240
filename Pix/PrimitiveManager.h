#pragma once

#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

enum class CullMode
{
	None,
	Front, // Cull front-facing objects
	Back // Cull objects facing away from the camera
};

class PrimitiveManager
{
public:
	static PrimitiveManager *Get();

	void SetCullMode(CullMode cullMode);

	bool BeginDraw(Topology topology, bool applyTransform = false);
	void AddVertex(Vertex vertex);
	bool EndDraw();

private:
	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Triangle;
	CullMode mCullMode = CullMode::None;
	bool mDrawBegin = false;
	bool mApplyTransform = false;
};

