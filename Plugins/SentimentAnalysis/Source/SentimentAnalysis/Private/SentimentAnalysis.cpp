#include "SentimentAnalysis.h"
#include "Modules/ModuleManager.h"
#include "WebSocketsModule.h"

IMPLEMENT_MODULE(FSentimentAnalysis, SentimentAnalysis)

void FSentimentAnalysis::StartupModule()
{
    if (!FModuleManager::Get().IsModuleLoaded("WebSockets"))
    {
        FModuleManager::Get().LoadModule("WebSockets");
    }
}

void FSentimentAnalysis::ShutdownModule()
{
    // Cleanup if necessary
}
