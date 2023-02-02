#include "CmdSetFillMode.h"
#include "Rasterizer.h"

bool CmdSetFillMode::Execute(const std::vector<std::string>& params)
{
    if (params.size() > 1)
    {
        return false;
    }

    if (params[0] == "wireframe") { Rasterizer::Get()->SetFillMode(FillMode::Wireframe); }
    else { Rasterizer::Get()->SetFillMode(FillMode::Solid); }
}