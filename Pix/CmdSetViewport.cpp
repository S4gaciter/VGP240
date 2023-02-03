#include "CmdSetViewport.h"
#include "Viewport.h"

bool CmdSetViewport::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 4)
    {
        return false;
    }

    float x = stoi(params[0]);
    float y = stoi(params[1]);
    float width = stoi(params[2]);
    float height = stoi(params[3]);

    Viewport::Get()->SetViewport(x, y, width, height);
    return true;
}
