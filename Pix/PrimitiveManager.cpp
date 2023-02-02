#include "PrimitiveManager.h"
#include "Rasterizer.h"

PrimitiveManager* PrimitiveManager::Get()
{
    static PrimitiveManager sInstance;
    return &sInstance;
}

bool PrimitiveManager::BeginDraw(Topology topology)
{
    mDrawBegin = true;
    mTopology = topology;
    mVertexBuffer.clear();
    return true;
}

void PrimitiveManager::AddVertex(Vertex vertex)
{
    if (mDrawBegin)
    {
        mVertexBuffer.push_back(vertex);
    }
}

bool PrimitiveManager::EndDraw()
{
    if (!mDrawBegin)
    {
        return false;
    }

    for (int x = 0; x <= mVertexBuffer.size(); x++)
    {
        switch (mTopology)
        {
        case Topology::Point:
            for (size_t i = 0; i  < mVertexBuffer.size(); ++i)
            {
                Rasterizer::Get()->DrawPoint(mVertexBuffer[i]);
            }
            break;
        case Topology::Line:
            for (size_t i = 1; i < mVertexBuffer.size(); i += 2)
            {
                Rasterizer::Get()->DrawLine(mVertexBuffer[i - 1], mVertexBuffer[i]);
            }
            break;
        case Topology::Triangle:
            for (size_t i = 2; i < mVertexBuffer.size(); i += 3)
            {
                Rasterizer::Get()->DrawTriangle(mVertexBuffer[i - 2], mVertexBuffer[i - 1], mVertexBuffer[i]);
            }
            break;
        default:
            return false;
        }
    }

    mDrawBegin = false;

    return true;
}
