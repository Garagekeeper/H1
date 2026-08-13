

#pragma once

#include "CoreMinimal.h"
#include "Component/MiniGameActorComponent.h"
#include "StratagemHeroComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCommandSelected, int32, Size);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCommandInput, int32, Index, bool, bIsCorrect);



/**
 * 
 */
UCLASS()
class H1_API UStratagemHeroComponent : public UMiniGameActorComponent
{
	GENERATED_BODY()
	
public:

	UStratagemHeroComponent();

	virtual void GameStart() override;
	virtual void GameEnd() override;

	// 현재 들어온 인풋을 확인하는 함수
	virtual void CheckInput(EDirType Input)override;

	UPROPERTY(BlueprintAssignable, Category = "MiniGame|Delegate")
	FOnCommandSelected OnCommandSelected;
	FOnCommandInput OnCommandInput;
private:
	// 스트라타젬 커맨드를 선택하는 함수
	void SelectCommand();

	// 테스트용으로 스트라타젬 커맨드를 생성하는 함수
	void GenerateCommand();

private:
	int32 CurrentIndex;
	TArray<EDirType> CurrentCommand;

};
