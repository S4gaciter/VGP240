#pragma once

#include "Command.h"

class CmdPushScaling : public Command
{
public:
	const char* GetName() override
	{
		return "PushScaling";
	}

	const char* GetDescription() override
	{
		return
			"PushScaling(radians)\n"
			"\n"
			"- Pushes a Scaling matrix into the matrix stack.";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
