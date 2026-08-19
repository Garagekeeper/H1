

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Data/Define.h"
#include "StratagemWidget.generated.h"

class UStratagemCommandWidget;
class UStratagemIconWidget;

/**
 * 
 */
UCLASS()
class H1_API UStratagemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void InitCommandUI(const TArray<EDirType>& CommandSeq, TSoftObjectPtr<UTexture2D> Icon);
	void UpdateArrowUI(int32 Index, bool bIsCorrect);

protected:
	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UStratagemCommandWidget> CommandWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UStratagemIconWidget> IconWidget;

	
};
