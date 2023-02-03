#include "PrimitiveManager.h"
#include "Rasterizer.h"
#include "Clipper.h"

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
                if (!Clipper::Get()->ClipPoint(mVertexBuffer[i]))
                {
                    Rasterizer::Get()->DrawPoint(mVertexBuffer[i]);
                }
            }
            break;
        case Topology::Line:
            for (size_t i = 1; i < mVertexBuffer.size(); i += 2)
            {
                if (!Clipper::Get()->ClipLine(mVertexBuffer[i - 1], mVertexBuffer[i]))
                {
                    Rasterizer::Get()->DrawLine(mVertexBuffer[i - 1], mVertexBuffer[i]);
                }
            }
            break;
        case Topology::Triangle:
            for (size_t i = 2; i < mVertexBuffer.size(); i += 3)
            {
                std::vector<Vertex> triangle = { mVertexBuffer[i - 2], mVertexBuffer[i - 1], mVertexBuffer[i] };
                if (!Clipper::Get()->ClipTriangle(triangle))
                {
                    for (size_t v = 2; v < triangle.size(); ++v)
                    {
                        Rasterizer::Get()->DrawTriangle(triangle[0], triangle[v - 1], triangle[v]);
                    }
                }
            }
            break;
        default:
            return false;
        }
    }

    mDrawBegin = false;

    return true;
}
