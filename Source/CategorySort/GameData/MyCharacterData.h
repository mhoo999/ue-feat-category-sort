// © 2024 Hoon. A touch of creativity in every line of code.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MyCharacterData.generated.h"

USTRUCT(BlueprintType)
struct FMyCharacterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FMyCharacterData() :
		Number(0),
		Name(TEXT("Character Name")),
		Strength(0),
		Intelligence(0),
		Vitality(0)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Number;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Strength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Intelligence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Vitality;

};