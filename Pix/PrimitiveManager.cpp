#include "PrimitiveManager.h"
#include "Rasterizer.h"

bool PrimitiveManager::BeginDraw(Topology topology)
{
    mVertexBuffer.clear();
    mTopology = topology;
    return true;
}

void PrimitiveManager::AddVertex(Vertex vertex)
{
    mVertexBuffer.push_back(vertex);
}

bool PrimitiveManager::EndDraw()
{
    Rasterizer *rasterizer = Rasterizer::Get();
    Vertex previousVertex{};
    for (int x = 0; x <= mVertexBuffer.size(); x++)
    {
        switch (mTopology)
        {
        case Topology::Point:
            rasterizer->DrawPoint(mVertexBuffer[x]);
            break;
        case Topology::Line:
            if (x < mVertexBuffer.size())
            {
                rasterizer->DrawLine(mVertexBuffer[x], mVertexBuffer[x + 1]);
            }
            break;
        case Topology::Triangle:
            if (x < mVertexBuffer.size() - 1)
            {
                rasterizer->DrawTriangle(mVertexBuffer[x], mVertexBuffer[x + 1], mVertexBuffer[x + 2]);
            }
            break;
        }
    }
    return true;
}

PrimitiveManager *PrimitiveManager::Get()
{
    static PrimitiveManager instance;
    return &instance;
}
