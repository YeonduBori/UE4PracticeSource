#pragma once
#include "CoreMinimal.h"
// #include "UObject/Class.h"

UENUM(BlueprintType)
enum class EDrawType : uint8
{
	GET UMETA(DisplayName = "Draw card by copy"),
	REMOVE UMETA(DisplayName = "Draw card by remove"),

	COUNT_TYPE
};


template<typename Card>
class TESTPROJECT_API Deck
{
public:
	Deck()
	{
		UE_LOG(LogTemp, Log, TEXT("Deck Initialize"));
	}

	Deck(int32 cardNumber)
	{
		cardContainer.Reserve(cardNumber);
    	UE_LOG(LogTemp, Log, TEXT("Deck Initialize Card capacity: %d"), cardNumber);
	}

	virtual ~Deck()
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

	Card* Draw(int32 cardIndex = 0, EDrawType drawType = EDrawType::REMOVE)
	{
		if(!cardContainer.IsValidIndex(cardIndex))
		{
			UE_LOG(LogTemp, Log, TEXT("Invalid Draw CardCount : %d, index : %d"), cardContainer.Num(), cardIndex);
			return nullptr;
		}

		switch(drawType)
		{
			case EDrawType::GET:
				return cardContainer[cardIndex];
			case EDrawType::REMOVE:
			{
			    Card* result = cardContainer[cardIndex];
				cardContainer.RemoveAt(cardIndex);
				return result;
			}
			default:
				//UE_LOG(LogTemp, Log, TEXT("Wrong Draw type : %s"), EDrawType::GetNameByValue((int64)drawType));
				return nullptr;
		}
	}

	void Shuffle()
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

	void AddCard(Card* card)
	{
		cardContainer.Add(card);
    	UE_LOG(LogTemp, Log, TEXT("AddCard"));
	}

	int32 Num()
	{
		if(cardContainer == nullptr)
			return -1;
		
		return cardContainer.Num();
	}
private:
	TArray<Card*> cardContainer;
};