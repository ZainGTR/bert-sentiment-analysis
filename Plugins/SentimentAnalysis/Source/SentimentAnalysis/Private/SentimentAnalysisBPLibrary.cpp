#include "SentimentAnalysisBPLibrary.h"
#include "WebSocketsModule.h"
#include "IWebSocket.h"
#include "Websocket.h"




UWebSocket* USentimentAnalysisBPLibrary::CreateWebSocket(FString ServerUrl, FString ServerProtocol)
{
    return CreateWebSocketWithHeaders(ServerUrl, {}, ServerProtocol);
}

UWebSocket* USentimentAnalysisBPLibrary::CreateWebSocketWithHeaders(FString ServerUrl, TMap<FString, FString> UpgradeHeaders, FString ServerProtocol /* = TEXT("ws") */)
{
    const TSharedPtr<IWebSocket> ActualSocket = FModuleManager::LoadModuleChecked<FWebSocketsModule>(TEXT("WebSockets")).CreateWebSocket(ServerUrl, ServerProtocol, UpgradeHeaders);
    UWebSocket* const WrapperSocket = NewObject<UWebSocket>();
    WrapperSocket->InitWebSocket(ActualSocket);
    return WrapperSocket;
}