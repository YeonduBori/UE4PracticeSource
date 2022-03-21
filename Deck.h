#pragma once
#include "CoreMinimal.h"

class TESTPROJECT_API Deck
{
public:
	Deck();
	Deck(int32 cardNumber);
	virtual ~Deck();

	int32* Draw(int32 cardIndex = 0);
	void Shuffle();
	void AddCard(int32* card);
private:
	TArray<int32*> cardContainer;
};
