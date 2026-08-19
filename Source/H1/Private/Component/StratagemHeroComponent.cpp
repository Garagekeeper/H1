


#include "Component/StratagemHeroComponent.h"
#include "Data/StratagemRow.h"
#include "Data/Define.h"

UStratagemHeroComponent::UStratagemHeroComponent()
	:Super()
{
}

void UStratagemHeroComponent::GameStart()
{
	Super::GameStart();
	GenerateCommand();
	SelectCommand();
}

void UStratagemHeroComponent::GameEnd()
{

	Super::GameEnd();
}

void UStratagemHeroComponent::CheckInput(EDirType Input)
{
	Super::CheckInput(Input);
	/*if (Input == EDirType::None)
	{
		UE_LOG(LogTemp, Log, TEXT("Invalid input"));
	}*/

	if (CurrentStratagem.Index == CurrentStratagem.Command.Num())
	{
		UE_LOG(LogTemp, Log, TEXT("SomeThing wrong"));
		return;
	}

	if (CurrentStratagem.Command[CurrentStratagem.Index] == Input)
	{
		//UE_LOG(LogTemp, Log, TEXT("Correct"));
		BroadcastUICommand(FMinigameUICommand::MakeUpdateContainerBool(CurrentStratagem.Index, true));
		CurrentStratagem.Index++;
		if (CurrentStratagem.Index == CurrentStratagem.Command.Num())
		{
			GetWorld()->GetTimerManager().SetTimer(
				CommandEndHandle,
				this,
				&UStratagemHeroComponent::SelectCommand,
				CommandEndDelay,
				false
			);
		}
	}
	else
	{
		for (int32 i = 0; i < CurrentStratagem.Index; ++i)
		{
			BroadcastUICommand(FMinigameUICommand::MakeUpdateContainerBool(i, false));
		}
		CurrentStratagem.Index = 0;
		//TODO Clear brfore 
		// 이 인덱스 이전의 화살표 원복
	}
}

void UStratagemHeroComponent::SelectCommand()
{
	// 데이터 에셋을 통해서 커맨드 가져오기
	// 10개로 제한할거라 앞에서 지워도 괜찮을듯
	if (StratagemQueue.Num() > 0)
	{
		CurrentStratagem = StratagemQueue[0];
		CurrentStratagem.Index = 0;
		BroadcastUICommand(FMinigameUICommand::MakeUpdateCommand(
			CurrentStratagem.Command,
			CurrentStratagem.StratagemIcon,
			CurrentStratagem.StratagemName.ToString()
			));
		StratagemQueue.RemoveAt(0);
		GenerateCommand();
	}
	
}

void UStratagemHeroComponent::GenerateCommand()
{
	TArray<FStratagemRow*> AllRows;
	StratagemDataTable->GetAllRows<FStratagemRow>(TEXT("StratagemContext"), AllRows);

	while(StratagemQueue.Num() <10 )
	{
		if (AllRows.Num() > 0)
		{
			// 2. 무작위 행 선택
			int32 RandomIndex = FMath::RandRange(0, AllRows.Num() - 1);
			FStratagemRow* SelectedRow = AllRows[RandomIndex];

			// 3. FString "WSSAD" -> TArray<EStratagemDirection> 변환
			TSoftObjectPtr<UTexture2D> StratagemIcon = SelectedRow->StratagemIcon.LoadSynchronous();
			TArray<EDirType> Commands = SelectedRow->GetCommandSequence();
			FText StratagemName = SelectedRow->StratagemName;
			StratagemQueue.Add(FStratagem(StratagemIcon, Commands, StratagemName));
		}
		else
		{
			break;
		}
	}
}
