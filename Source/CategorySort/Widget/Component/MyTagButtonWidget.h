// © 2024 Hoon. A touch of creativity in every line of code.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyTagButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class CATEGORYSORT_API UMyTagButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	

protected:
	UPROPERTY()
	TObjectPtr<class UObject> ParentWidget;

	UPROPERTY(meta =(BindWidget))
	TObjectPtr<class UMyButton> TagButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> TagText;

	FString Condition;

	FVector2D RangeValue;

public:
	void SetParentWidget(UObject* Object);

	void SetDisplayName(FString& Name);
	FString GetDisplayName();

	void SetFilteringCondition(FString InCondition);
	FString GetFilteringCondition();

	void SetValue(FVector2D InRangeValue);
	FVector2D GetValue();

	UMyButton* GetButton();

};
