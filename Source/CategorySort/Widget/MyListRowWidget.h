// © 2024 Hoon. A touch of creativity in every line of code.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "MyListRowWidget.generated.h"

/**
 * 
 */
UCLASS()
class CATEGORYSORT_API UMyListRowWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent);

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> Level;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> Name;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> Strength;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> Intelligence;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> Vitality;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UBorder> BackgroundBorder;

	struct FMyCharacterData* CharacterData;

	FLinearColor NormalColor;

	TMap<FString, FString> Attributes;

public:
	void SetData(struct FMyCharacterData* CharacterData);
	struct FMyCharacterData* GetCharacterData() { return CharacterData; }

	FString FindStat(const FString& Stat);

};
