// Fill out your copyright notice in the Description page of Project Settings.


#include "CardsInfo.h"

FCRCardInfo const& UCardsInfo::GetCardInfoForID(FCardIDType const& cardID)
{
	FCRCardInfo* pFoundElement = CardsList.FindByPredicate([cardID](FCRCardInfo const& currentCard)
	{
		return currentCard.CardIDName == cardID;
	});

	if (pFoundElement)
		return *pFoundElement;

	checkf(!CardsList.IsEmpty(), TEXT("Cards list needs to be filled, this is the main data of the game"));
	return CardsList[0];
}
