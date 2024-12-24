// Fill out your copyright notice in the Description page of Project Settings.


#include "CRPlayerState.h"

#include "CRPlayerController.h"

#include "ChristmasReigns/GameplayAbilitySystem/AttributeSet/CRAttributeSet.h"
#include "ChristmasReigns/UI/CRHud.h"

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
ACRPlayerState::ACRPlayerState()
{
	// Create ability system component, and set it to be explicitly replicated
	AbilitySystemComponent = CreateDefaultSubobject<UCRAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	// Create the attribute set, this replicates by default
	// Adding it as a subobject of the owning actor of an AbilitySystemComponent
	// automatically registers the AttributeSet with the AbilitySystemComponent
	AttributeSet = CreateDefaultSubobject<UCRAttributeSet>(TEXT("AttributeSet"));

	// Set PlayerState's NetUpdateFrequency to the same as the Character.
	// Default is very low for PlayerStates and introduces perceived lag in the ability system.
	// 100 is probably way too high for a shipping game, you can adjust to fit your needs.
	SetNetUpdateFrequency(100.0f);
}

//----------------------------------------------------------------------------------------------------------------------
void ACRPlayerState::BeginPlay()
{
	Super::BeginPlay();

	InitializeASC();
	InitializeAttributes();
	InitializeHUD();
}

//----------------------------------------------------------------------------------------------------------------------
void ACRPlayerState::InitializeAttributes() const
{
	check(IsValid(AbilitySystemComponent))

	if (!IsValid(DefaultAttributes))
	{
		UE_LOG(LogEngine, Error, TEXT("%s() Missing DefaultAttributes for %s. Please fill in the player state's Blueprint."), *FString(__FUNCTION__), *GetName());
		return;
	}

	// Can run on Server and Client
	ApplyEffectToSelf(DefaultAttributes, 1.0f);
}

// ---------------------------------------------------------------------------------------------------------------------
void ACRPlayerState::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> const& gameplayEffectClass, float level) const
{
	if (!IsValid(AbilitySystemComponent))
		return;
	
	FGameplayEffectContextHandle effectContextHandle = AbilitySystemComponent->MakeEffectContext();
	effectContextHandle.AddSourceObject(this);

	const FGameplayEffectSpecHandle specHandle = AbilitySystemComponent->MakeOutgoingSpec(gameplayEffectClass, level, effectContextHandle);
	if (specHandle.IsValid())
	{
		AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*specHandle.Data.Get(), AbilitySystemComponent);
	}
}

// ---------------------------------------------------------------------------------------------------------------------
void ACRPlayerState::InitializeASC()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	if (IsValid(AttributeSet))
	{
		//AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetFearAttribute()).
		//AddUObject(this, &AMMCharacterHero::OnFearChanged);
		//AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxFearAttribute()).
		//AddUObject(this, &AMMCharacterHero::OnFearChanged);
	}
}

// ---------------------------------------------------------------------------------------------------------------------
void ACRPlayerState::InitializeHUD()
{
	// Player controllers of other players are only present on server. Expect null pointers here
	if (ACRPlayerController* pPlayerController = Cast<ACRPlayerController>(GetOwner()))
	{
		// Hud only present locally
		if (ACRHud* pHud = Cast<ACRHud>(pPlayerController->GetHUD()))
		{
			pHud->InitOverlay(pPlayerController, this, AbilitySystemComponent, AttributeSet);
		}
	}
}
