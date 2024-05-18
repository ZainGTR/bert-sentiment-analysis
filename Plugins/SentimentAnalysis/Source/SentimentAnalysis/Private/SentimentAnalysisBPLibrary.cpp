// Copyright Epic Games, Inc. All Rights Reserved.

#include "SentimentAnalysisBPLibrary.h"
#include "SentimentAnalysis.h"


USentimentAnalysisBPLibrary::USentimentAnalysisBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}


TSharedPtr<IWebSocket> USentimentAnalysisBPLibrary::WebSocket = nullptr;
FString USentimentAnalysisBPLibrary::LastSentiment = TEXT("");
FOnSentimentReceived USentimentAnalysisBPLibrary::OnSentimentReceived;

void USentimentAnalysisBPLibrary::ConnectWebSocket(const FString& Url)
{
    if (!WebSocketsModule.IsInitialized())
    {
        WebSocketsModule.Initialize();
    }

    WebSocket = FWebSocketsModule::Get().CreateWebSocket(Url);

    WebSocket->OnMessage().AddStatic(&USentimentAnalysisBPLibrary::OnMessageReceived);

    WebSocket->Connect();
}

void USentimentAnalysisBPLibrary::SendMessage(const FString& Message)
{
    if (WebSocket.IsValid() && WebSocket->IsConnected())
    {
        WebSocket->Send(Message);
    }
}

FString USentimentAnalysisBPLibrary::GetLastSentiment()
{
    return LastSentiment;
}

void USentimentAnalysisBPLibrary::OnMessageReceived(const FString& Message)
{
    LastSentiment = Message;
    OnSentimentReceived.Broadcast(LastSentiment);
}
