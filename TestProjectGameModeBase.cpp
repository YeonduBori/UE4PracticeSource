// Copyright Epic Games, Inc. All Rights Reserved.


#include "TestProjectGameModeBase.h"
#include "Deck.hpp"

void ATestProjectGameModeBase::StartPlay()
{
    if(GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, TEXT("테스트 게임모드 들어왔습니다."));
    }

    Deck<int32> deck(10);//card 10 reserve
    for(int32 count = 0; count < 20; ++count)
    {
        int32* card = new int32(count);
        deck.AddCard(card);
    }

    deck.Shuffle();

    for(int32 count = 0; count < 10; ++count)
    {
        EDrawType type = static_cast<EDrawType>(FMath::RandRange(0,1));
        UE_LOG(LogTemp, Log, TEXT("DrawType : %d"), type);
        int32* card = deck.Draw(0, type);
        UE_LOG(LogTemp, Log, TEXT("Card Num : %d"), *card);
    }
}