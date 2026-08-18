

#pragma once

#include "CoreMinimal.h"
#include "Component/MiniGameActorComponent.h"
#include "StratagemHeroComponent.generated.h"



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
private:
	// 스트라타젬 커맨드를 선택하는 함수
	void SelectCommand();

	// 테스트용으로 스트라타젬 커맨드를 생성하는 함수
	void GenerateCommand();

protected:
	// 에디터/블루프린트 디테일 패널에서 데이터 테이블을 할당받음
	UPROPERTY(EditDefaultsOnly, Category = "Minigame|Data")
	UDataTable* StratagemDataTable;

	TArray<TArray<EDirType>> SeqQueue;

private:
	int32 CurrentIndex;
	TArray<EDirType> CurrentCommand;

	FTimerHandle CommandEndHandle;
	float CommandEndDelay = 0.3f;

};
