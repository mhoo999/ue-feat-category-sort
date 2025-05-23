// © 2024 Hoon. A touch of creativity in every line of code.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyStatPopupWidget.generated.h"

/**
 * 
 */
UCLASS()
class CATEGORYSORT_API UMyStatPopupWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	virtual void ClickApply();

	UFUNCTION()
	virtual void ClickClear();

	void StatArrayInitialize();

	void ChangedValue(FString StatName, FVector2D Value);

	void SpecificClearText(FString InCategory);

	void ClearText();

protected:
	UPROPERTY()
	TObjectPtr<class UObject> ParentWidget;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyButton> FilterButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyButton> ClearButton;

protected:
	UPROPERTY()
	TMap<FString, FVector2D> FilterConditionArray;

	TArray<class UMyStatUnitWidget*> StatArray;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyStatUnitWidget> Level;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyStatUnitWidget> Strength;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyStatUnitWidget> Intelligence;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyStatUnitWidget> Vitality;

public:
	void SetParentWidget(UObject* Object);


};
