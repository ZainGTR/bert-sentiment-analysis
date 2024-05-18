// Copyright Epic Games, Inc. All Rights Reserved.

#include "SentimentAnalysisBPLibrary.h"
#include "SentimentAnalysis.h"


USentimentAnalysisBPLibrary::USentimentAnalysisBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}


void USentimentAnalysisBPLibrary::ConnectWebSocket()
{
    if (FSentimentAnalysisModule* Module = FModuleManager::GetModulePtr<FSentimentAnalysisModule>("SentimentAnalysisPlugin"))
    {
        Module->ConnectWebSocket();
    }
}

void USentimentAnalysisBPLibrary::SendMessage(const FString& Message)
{
    if (FSentimentAnalysisModule* Module = FModuleManager::GetModulePtr<FSentimentAnalysisModule>("SentimentAnalysisPlugin"))
    {
        Module->EvaluateChatMessage(Message);
    }
}

void USentimentAnalysisBPLibrary::ReceiveMessage(const FString& Message)
{
    if (FSentimentAnalysisModule* Module = FModuleManager::GetModulePtr<FSentimentAnalysisModule>("SentimentAnalysisPlugin"))
    {
        Module->OnSentimentReceived(Message);
    }
    
}
