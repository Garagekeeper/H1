


#include "Component/StratagemHeroComponent.h"

UStratagemHeroComponent::UStratagemHeroComponent()
	:Super()
{
}

void UStratagemHeroComponent::GameStart()
{
	Super::GameStart();
	GenerateCommand();
}

void UStratagemHeroComponent::GameEnd()
{

	Super::GameEnd();
}

void UStratagemHeroComponent::CheckInput(EDirType Input)
{
	Super::CheckInput(Input);
	if (Input == EDirType::None)
	{
		UE_LOG(LogTemp, Log, TEXT("Invalid input"));
	}

	if (CurrentCommand[CurrentIndex] == Input)
	{
		UE_LOG(LogTemp, Log, TEXT("Correct"));
		OnCommandInput.Broadcast(CurrentIndex, true);
		CurrentIndex++;
		if (CurrentIndex == CurrentCommand.Num())
			GenerateCommand();
	}
	else
	{
		for (int32 i = 0; i < CurrentIndex; ++i)
		{
			OnCommandInput.Broadcast(i, false);
		}
		CurrentIndex = 0;
		//TODO Clear brfore 
		// 이 인덱스 이전의 화살표 원복
	}
}

void UStratagemHeroComponent::SelectCommand()
{
	// 데이터 에셋을 통해서 커맨드 가져오기
}

void UStratagemHeroComponent::GenerateCommand()
{
	CurrentCommand.Empty();
	CurrentIndex = 0;
	CurrentCommand = {
		EDirType::Up,
		EDirType::Right ,
		EDirType::Down ,
		EDirType::Left ,
		EDirType::Up ,
		EDirType::Right ,
		EDirType::Down ,
		EDirType::Left
	};
	// TODO 위젯에 델리게이트보내기

	OnCommandSelected.Broadcast(CurrentCommand.Num());
}
