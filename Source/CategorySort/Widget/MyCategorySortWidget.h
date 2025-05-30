// © 2024 Hoon. A touch of creativity in every line of code.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyCategorySortWidget.generated.h"

/**
 * 
 */
UCLASS()
class CATEGORYSORT_API UMyCategorySortWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UMyCategorySortWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	void SortButtonClickEvent(FString& InSortCondition);

	void Sort(FString& InSortCondition);

	void DisableAllButOne(FString& CurrentSort);

	void ApplyFilter();

	UFUNCTION()
	void ClearFilters();

	void AddTag(FString& InTagName, FString& InCondition, FVector2D InRange = FVector2D(0, 0));

	UFUNCTION()
	void OpenFilterStatsPopup();

	void LoadCharacters(UDataTable* InCharacterData);

protected:
	UPROPERTY()
	TSubclassOf<class UMyListRowWidget> MyListRowWidgetClass;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UHorizontalBox> ColumnContainer;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyButton> Level;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyButton> Name;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyButton> Strength;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyButton> Intelligence;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyButton> Vitality;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UListView> ListView;

	FString CurrentSort;

	bool bAscending;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyButton> StatPopupButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyButton> TagClearButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UScrollBox> TagContainer;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyButton> CloseArea;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UMyStatPopupWidget> StatPopup;

	UPROPERTY()
	TSubclassOf<class UMyTagButtonWidget> TagButtonClass;

public:
	UDataTable* GenerateRows();

	void AddRangeFilter(FString& InCondition, FVector2D InRange);

	UFUNCTION()
	void ClosePopup();

	UFUNCTION()
	virtual void RemoveFilter(FString& InCondition);

	void RefreshList();



};
