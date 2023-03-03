#include "CmdPushRotationZ.h"
#include "VariableCache.h"
#include "MatrixStack.h"

bool CmdPushRotationZ::Execute(const std::vector<std::string>& params)
{
	// Need at least 1 param for radians
	if (params.size() < 1)
		return false;

	auto vc = VariableCache::Get();
	float rad = vc->GetFloat(params[0]);

	MatrixStack::Get()->PushRotationZ(rad);
	return true;
}