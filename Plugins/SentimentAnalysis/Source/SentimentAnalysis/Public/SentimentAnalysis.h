#pragma once

#include "Modules/ModuleManager.h"

class FSentimentAnalysis : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
