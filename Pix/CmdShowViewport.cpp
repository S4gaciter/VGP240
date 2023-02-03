#include "CmdShowViewport.h"
#include "Viewport.h"

bool CmdShowViewport::Execute(const std::vector<std::string>& params)
{
    if (params.size() < 1) 
    {
        return false;
    }

    bool showViewport = params[0] == "true";
    Viewport::Get()->ShowViewport(showViewport);
    return true;
}
