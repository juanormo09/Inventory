// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventoryGridWidget.h"
#include "InventoryCharacter.h"
#include "Components/InventoryComponent.h"

void UInventoryGridWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AInventoryCharacter* CharacterReference;
	CharacterReference = Cast<AInventoryCharacter>(GetOwningPlayerPawn());

	UInventoryComponent* InventoryComponent;
	InventoryComponent = CharacterReference->InventoryComponent;

	if (!CharacterReference) 
		return;

	Columns = InventoryComponent->Columns;
	Rows = InventoryComponent->Rows;
	TileSize = InventoryComponent->TilesSize;
}

void UInventoryGridWidget::CreateLineSegment()
{
}

int32 UInventoryGridWidget::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
	return int32();
}
