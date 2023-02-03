#pragma once
#include "Command.h"

class CmdShowViewport : public Command
{
public:
	const char* GetName() { return "ShowViewport"; };
	const char* GetDescription() { return "ShowViewport(bool)\n- Set viewport visibililty."; };

	bool Execute(const std::vector<std::string>& params);
};

