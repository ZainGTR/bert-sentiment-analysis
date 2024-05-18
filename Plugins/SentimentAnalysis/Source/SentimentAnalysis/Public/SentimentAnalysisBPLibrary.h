#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IWebSocket.h"
#include "SentimentAnalysisBPLibrary.generated.h"

class UWebSocket;
UCLASS()
class SENTIMENTANALYSIS_API USentimentAnalysisBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "SentimentAnalysis")
        static UWebSocket* CreateWebSocket(FString ServerUrl, FString ServerProtocol = TEXT("ws"));

    UFUNCTION(BlueprintCallable, Category = "SentimentAnalysis")
        static UWebSocket* CreateWebSocketWithHeaders(FString ServerUrl, TMap<FString, FString> UpgradeHeaders, FString ServerProtocol = TEXT("ws"));


};
