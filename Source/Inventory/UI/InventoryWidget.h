// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

class UCanvasPanel;
class UBorder;
class UBackgroundBlur;


UCLASS()
class INVENTORY_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	TObjectPtr<UCanvasPanel> Canvas;
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	TObjectPtr<UBorder> BackgroundBorder;
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	TObjectPtr<UBackgroundBlur> Blur;

protected:

	virtual void NativeConstruct() override;
	
};
