// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventoryGridWidget.h"
#include "InventoryCharacter.h"
#include "Components/InventoryComponent.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/WidgetLayoutLibrary.h"

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

	float NewWidth = Columns * TileSize;
	float NewHeight = Rows * TileSize;

	LineStructData = new FLines();
	StartX = {};
	StartY = {};
	EndX = {};
	EndY = {};

	UCanvasPanelSlot* BorderAsCanvasSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(GridBorder);
	BorderAsCanvasSlot->SetSize(FVector2D(NewWidth, NewHeight));

	CreateLineSegment();
}

void UInventoryGridWidget::CreateLineSegment()
{
	for (int32 i = 0; i <= Columns; i++)
	{
		float X{ i * TileSize };

		LineStructData->XLines.Add(FVector2D(X, X));
		LineStructData->YLines.Add(FVector2D(0.0f, Rows * TileSize));
	}
	for (int32 i = 0; i <= Rows; i++)
	{
		float Y{ i * TileSize };

		LineStructData->YLines.Add(FVector2D(Y, Y));
		LineStructData->XLines.Add(FVector2D(0.0f, Columns * TileSize));
	}

	for (const FVector2D Elements : LineStructData->XLines)
	{
		StartX.Add(Elements.X);
		EndX.Add(Elements.Y);
	}

	for (const FVector2D Elements : LineStructData->YLines)
	{
		StartY.Add(Elements.X);
		EndY.Add(Elements.Y);	
	}
}

int32 UInventoryGridWidget::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	FPaintContext PaintContext(AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
	FLinearColor CustomColor(0.5f, 0.5f, 0.5f, 0.5f);
	FVector2D TopLeftCorner = GridBorder->GetCachedGeometry().GetLocalPositionAtCoordinates(FVector2D(0.0f, 0.0f));

	int32 k = 0;
	for (int32 i = 0; i < LineStructData->XLines.Num(); i++)
	{
		for (int32 j = 0; j < LineStructData->YLines.Num(); j++)
		{
			k = i;
		}
		UWidgetBlueprintLibrary::DrawLine(PaintContext, FVector2D(StartX[i], StartY[k]) + TopLeftCorner, FVector2D(EndX[i], EndY[k]) + TopLeftCorner, CustomColor, false, 2.0f);
	}

	return int32();
}
