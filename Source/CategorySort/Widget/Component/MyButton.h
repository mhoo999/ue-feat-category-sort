// © 2024 Hoon. A touch of creativity in every line of code.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "MyButton.generated.h"

#define ACTIVATE_COL FLinearColor(0.194618f, 0.445201f, 0.651406f, 1.f)
#define DEACTIVATE_COL FLinearColor(0.068478f, 0.122139f, 0.254152f, 1.f)

DECLARE_DELEGATE_OneParam(FOnClickStringParamDelegate, FString&);
/**
 * 
 */
UCLASS()
class CATEGORYSORT_API UMyButton : public UButton
{
	GENERATED_BODY()
	
public:
	FOnClickStringParamDelegate OnClickStringParamDelegate;

	UFUNCTION()
	void OnClick();

	void AddOnClickEvent();

private:
	FString StringParameter1;

public:
	void SetStringParameter1(const FString& InString) { StringParameter1 = InString; }

	void SetEnable();
	void SetDisable();

};
