// Copyright Epic Games, Inc. All Rights Reserved.

#include "SentimentAnalysis.h"
#include "IWebSocket.h"
#include "WebSocketsModule.h"
#include "Misc/ConfigCacheIni.h"


#define LOCTEXT_NAMESPACE "FSentimentAnalysisModule"



void FSentimentAnalysisModule::StartupModule()
{
    if (!FModuleManager::Get().IsModuleLoaded("WebSockets"))
    {
        FModuleManager::LoadModuleChecked<FWebSocketsModule>("WebSockets");
    }

    // Create the WebSocket
    WebSocket = FWebSocketsModule::Get().CreateWebSocket("ws://localhost:8765", "ws");

    WebSocket->OnConnected().AddRaw(this, &FSentimentAnalysisModule::OnConnected);
    WebSocket->OnConnectionError().AddRaw(this, &FSentimentAnalysisModule::OnConnectionError);
    WebSocket->OnMessage().AddRaw(this, &FSentimentAnalysisModule::OnMessage);

    WebSocket->Connect();
}

void FSentimentAnalysisModule::ShutdownModule()
{
    if (WebSocket.IsValid())
    {
        WebSocket->Close();
    }
}

void FSentimentAnalysisModule::ConnectWebSocket()
{
    if (WebSocket.IsValid() && !WebSocket->IsConnected())
    {
        WebSocket->Connect();
    }
}


void FSentimentAnalysisModule::OnConnected()
{
    UE_LOG(LogTemp, Log, TEXT("WebSocket connected"));
}

void FSentimentAnalysisModule::OnConnectionError(const FString& Error)
{
    UE_LOG(LogTemp, Error, TEXT("WebSocket connection error: %s"), *Error);
}

void FSentimentAnalysisModule::OnMessage(const FString& Message)
{
    UE_LOG(LogTemp, Log, TEXT("WebSocket message received: %s"), *Message);

    OnSentimentReceived(Message);
}

void FSentimentAnalysisModule::OnSentimentReceived(const FString& Sentiment)
{
    
    UE_LOG(LogTemp, Log, TEXT("Sentiment received: %s"), *Sentiment);
}

void FSentimentAnalysisModule::EvaluateChatMessage(const FString& Message)
{
    if (WebSocket.IsValid() && WebSocket->IsConnected())
    {
        WebSocket->Send(Message);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("WebSocket is not connected"));
    }
}

IMPLEMENT_MODULE(FSentimentAnalysisModule, SentimentAnalysis)
