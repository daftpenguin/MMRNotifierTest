#include "pch.h"
#include "MMRNotifierTest.h"


BAKKESMOD_PLUGIN(MMRNotifierTest, "write a plugin description here", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void MMRNotifierTest::onLoad()
{
	_globalCvarManager = cvarManager;
	token = gameWrapper->GetMMRWrapper().RegisterMMRNotifier([this](UniqueIDWrapper id) {
        auto user = (id == gameWrapper->GetUniqueID() ? "local" : "non-local");
        LOG("Got MMR update for {} user: {}", user, id.GetIdString());
        });
}

void MMRNotifierTest::onUnload()
{
}