#include "CmdEndDraw.h"
#include "PrimitiveManager.h"

bool CmdEndDraw::Execute(const std::vector<std::string>& params)
{
    if (params.size() > 0)
    {
        return false;
    }

    return PrimitiveManager::Get()->EndDraw();
}
