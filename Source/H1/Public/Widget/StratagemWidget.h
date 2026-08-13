

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StratagemWidget.generated.h"

class UStratagemCommandWidget;

/**
 * 
 */
UCLASS()
class H1_API UStratagemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void InitCommandUI(int32 Size);
	void UpdateArrowUI(int32 Index, bool bIsCorrect);

protected:
	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UStratagemCommandWidget> CommandWidget;

	
};
