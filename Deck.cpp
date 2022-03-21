// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"

Deck::Deck()
{
    UE_LOG(LogTemp, Log, TEXT("Deck Initialize"));
}

Deck::Deck(int32 cardNumber)
{
    cardContainer.Reserve(cardNumber);
    UE_LOG(LogTemp, Log, TEXT("Deck Initialize Card count : %d"), cardNumber);
    /*Dona*/
    UE_LOG(LogTemp, Log, TEXT("Deck Initialize Card count : %d"), cardContainer.GetAllocatedSize());
}

Deck::~Deck()
{
    UE_LOG(LogTemp, Log, TEXT("Deck Destroy!"));
    for(auto card : cardContainer)
    {
        if(card != nullptr)
        {
            delete card;
            card = nullptr;
        }
            
    }
}

void Deck::Shuffle()
{
    for(int32 count = 0; count < cardContainer.Num(); ++count)
    {
        int32 indexA = 0;
        int32 indexB = 0;
        while(indexA == indexB)
        {
            indexA = FMath::RandRange(0, cardContainer.Num() - 1);
            indexB = FMath::RandRange(0, cardContainer.Num() - 1);
        }
        
        Swap(cardContainer[indexA], cardContainer[indexB]);
    }   

    UE_LOG(LogTemp, Log, TEXT("Shuffle Done"));
}

int32* Deck::Draw(int32 cardIndex)
{
    if(cardContainer.IsValidIndex(cardIndex))
    {
        int32* result = cardContainer[cardIndex];
        cardContainer.RemoveAt(cardIndex);
        return result;
    }
        

    UE_LOG(LogTemp, Log, TEXT("Invalid Draw CardCount : &d, index : %d"), cardContainer.Num(), cardIndex);
    return nullptr;
}

void Deck::AddCard(int32* card)
{
    cardContainer.Add(card);
    UE_LOG(LogTemp, Log, TEXT("AddCard : %d"), *card);
}