// © 2024 Hoon. A touch of creativity in every line of code.


#include "Widget/Component/MyTagButtonWidget.h"
#include "Widget/Component/MyButton.h"

#include "Components/TextBlock.h"

void UMyTagButtonWidget::SetParentWidget(UObject* Object)
{
	ParentWidget = Object;
}

void UMyTagButtonWidget::SetDisplayName(FString& Name)
{
	TagText->SetText(FText::FromString(Name));
}

FString UMyTagButtonWidget::GetDisplayName()
{
	return TagText->GetText().ToString();
}

void UMyTagButtonWidget::SetFilteringCondition(FString InCondition)
{
	Condition = InCondition;
}

FString UMyTagButtonWidget::GetFilteringCondition()
{
	return Condition;
}

void UMyTagButtonWidget::SetValue(FVector2D InRangeValue)
{
	RangeValue = InRangeValue;
}

FVector2D UMyTagButtonWidget::GetValue()
{
	return RangeValue;
}

UMyButton* UMyTagButtonWidget::GetButton()
{
	return TagButton;
}
