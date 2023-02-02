#pragma once
#include "Command.h"
class CmdSetFillMode : public Command
{
public:
	const char* GetName(){ return "SetFillMode"; };
	const char* GetDescription() { return "SetFillMode() allows you to choose between wireframe and solid triangles"; };
	
	bool Execute(const std::vector<std::string>& params);
};
