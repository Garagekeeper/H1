

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interface/MiniGameInterface.h"
#include "StaratagemHeroWidget.generated.h"

class UStratagemWidget;
class UStratagemHeroComponent;

/**
 * 
 */
UCLASS()
class H1_API UStaratagemHeroWidget : public UUserWidget, public IMiniGameInterface
{
	GENERATED_BODY()

public: 
	void BindHeroComponent(class UStratagemHeroComponent* HeroComponent);

protected:
	UFUNCTION()
	void OnCommandInit(const FMinigameUICommand& Command);

	UFUNCTION()
	void OnArrowUpdate(const FMinigameUICommand& Command);


	virtual void NativeConstruct() override;

	virtual void ExecuteUICommand_Implementation(const FMinigameUICommand Command) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UStratagemWidget> StaratagemWidget;

private:
	typedef void (UStaratagemHeroWidget::* FCommandFunctor)(const FMinigameUICommand& Command);
	TMap<EMinigameUICommandType, FCommandFunctor> CommandFuncBindMap;
};
