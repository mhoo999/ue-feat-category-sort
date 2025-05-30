// © 2024 Hoon. A touch of creativity in every line of code.


#include "Widget/MyListRowWidget.h"

#include "Components/TextBlock.h"
#include "Components/Border.h"

#include "GameData/MyCharacterData.h"
#include "MyListRowWidget.h"

void UMyListRowWidget::NativeConstruct()
{
	NormalColor = BackgroundBorder->GetBrushColor();
}

void UMyListRowWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	UMyListRowWidget* ListRowWIdget = Cast<UMyListRowWidget>(ListItemObject);

	if (!ListRowWIdget) return;

	FMyCharacterData* InCharacterData = ListRowWIdget->GetCharacterData();

	if (InCharacterData)
	{
		CharacterData = InCharacterData;
		Level->SetText(FText::FromString(FString::FromInt(CharacterData->Level)));
		Name->SetText(FText::FromString(CharacterData->Name.ToString()));
		Strength->SetText(FText::FromString(FString::FromInt(CharacterData->Strength)));
		Intelligence->SetText(FText::FromString(FString::FromInt(CharacterData->Intelligence)));
		Vitality->SetText(FText::FromString(FString::FromInt(CharacterData->Vitality)));

		Attributes.Add(TEXT("Level"), FString::FromInt(CharacterData->Level));
		Attributes.Add(TEXT("Name"), CharacterData->Name.ToString());
		Attributes.Add(TEXT("Strength"), FString::FromInt(CharacterData->Strength));
		Attributes.Add(TEXT("Intelligence"), FString::FromInt(CharacterData->Intelligence));
		Attributes.Add(TEXT("Vitality"), FString::FromInt(CharacterData->Vitality));
	}
}

void UMyListRowWidget::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	// 마우스가 로우 위에 올라갔을 때, 색상을 변경하여 목록을 쉽게 볼 수 있도록 시각적 피드백 제공
	BackgroundBorder->SetBrushColor(FLinearColor(0.289125f, 0.466949f, 0.480903f, 1.f));
}

void UMyListRowWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	BackgroundBorder->SetBrushColor(NormalColor);
}

void UMyListRowWidget::SetData(FMyCharacterData* InCharacterData)
{
	CharacterData = InCharacterData;
}

FString UMyListRowWidget::FindStat(const FString& Stat)
{
	FString* FoundValue = Attributes.Find(Stat);

	if (FoundValue)
	{
		return *FoundValue;
	}
	else
	{
		return FString("0");
	}
}
