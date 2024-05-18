// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class IWebSocket;

class FSentimentAnalysisModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
public:
    void ConnectWebSocket();



    void OnConnected();
    void OnConnectionError(const FString& Error);
    void OnMessage(const FString& Message);
    void OnSentimentReceived(const FString& Sentiment);

    void EvaluateChatMessage(const FString& Message);

    TSharedPtr<IWebSocket> WebSocket;
};
