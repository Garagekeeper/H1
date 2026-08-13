

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StaratagemHeroWidget.generated.h"

class UStratagemWidget;
class UStratagemHeroComponent;

/**
 * 
 */
UCLASS()
class H1_API UStaratagemHeroWidget : public UUserWidget
{
	GENERATED_BODY()

public: 
	void BindHeroComponent(class UStratagemHeroComponent* HeroComponent);

protected:
	UFUNCTION()
	void OnCommandSelectedCallback(int32 Size);

	UFUNCTION()
	void OnCommandInputCallback(int32 Index, bool bIsCorrect);


	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UStratagemWidget> StaratagemWidget;
};
