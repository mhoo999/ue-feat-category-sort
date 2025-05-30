// © 2024 Hoon. A touch of creativity in every line of code.


#include "Widget/MyStatPopupWidget.h"
#include "Widget/Component/MyButton.h"
#include "Widget/MyStatUnitWidget.h"
#include "Widget/MyCategorySortWidget.h"


void UMyStatPopupWidget::NativeConstruct()
{
	Super::NativeConstruct();

	FilterButton->OnClicked.AddDynamic(this, &UMyStatPopupWidget::ClickApply);
	ClearButton->OnClicked.AddDynamic(this, &UMyStatPopupWidget::ClickClear);

	StatArrayInitialize();
}

void UMyStatPopupWidget::ClickApply()
{
	UMyCategorySortWidget* FilterWidget = Cast<UMyCategorySortWidget>(ParentWidget);

	for (auto& Condition : FilterConditionArray)
	{
		FilterWidget->AddRangeFilter(Condition.Key, Condition.Value);

		for (UMyStatUnitWidget* Stat : StatArray)
		{
			if (Stat->GetName() == Condition.Key)
			{
				Stat->SetMinValue(Condition.Value.X);
				Stat->SetMaxValue(Condition.Value.Y);
			}
		}
	}

	FilterWidget->ClosePopup();
}

void UMyStatPopupWidget::ClickClear()
{
	UMyCategorySortWidget* FilterWidget = Cast<UMyCategorySortWidget>(ParentWidget);

	for (auto& Condition : FilterConditionArray)
	{
		FilterWidget->RemoveFilter(Condition.Key);
	}

	ClearText();
	FilterConditionArray.Reset();

	FilterWidget->RefreshList();
	FilterWidget->ClosePopup();
}

void UMyStatPopupWidget::StatArrayInitialize()
{
	StatArray.Add(Level);
	StatArray.Add(Strength);
	StatArray.Add(Intelligence);
	StatArray.Add(Vitality);

	for (auto& Stat : StatArray)
	{
		Stat->SetParentWidget(this);
	}
}

void UMyStatPopupWidget::ChangedValue(FString StatName, FVector2D Value)
{
	if (Value.X > Value.Y)
	{
		int32 Temp = Value.X;
		Value.X = Value.Y;
		Value.Y = Temp;
	}

	FilterConditionArray.Add(StatName, Value);
}

void UMyStatPopupWidget::SpecificClearText(FString InCategory)
{
	for (UMyStatUnitWidget* Stat : StatArray)
	{
		if (Stat->GetName() == InCategory)
		{
			Stat->ClearText();
		}
	}

	FilterConditionArray.FindAndRemoveChecked(InCategory);
}

void UMyStatPopupWidget::ClearText()
{
	for (UMyStatUnitWidget* Stat : StatArray)
	{
		Stat->ClearText();
	}

	FilterConditionArray.Reset();
}

void UMyStatPopupWidget::SetParentWidget(UObject* Object)
{
	ParentWidget = Object;
}
