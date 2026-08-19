

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StratagemIconWidget.generated.h"

class UImage;
/**
 * 
 */
UCLASS()
class H1_API UStratagemIconWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateStratagemIcon(TSoftObjectPtr<UTexture2D> InTexture);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> StratagemIcon;
};
