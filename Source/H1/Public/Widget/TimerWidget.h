

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TimerWidget.generated.h"

class UProgressBar;

/**
 * 
 */
UCLASS()
class H1_API UTimerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateProgressBar(float CurrentRemain, float InitRemain);

protected:
	UPROPERTY(VisibleDefaultsOnly, meta = (BindWidget))
	TObjectPtr<UProgressBar> RemainTimeProgressBar;
};
