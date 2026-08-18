


#include "Widget/StaratagemHeroWidget.h"
#include "Component/StratagemHeroComponent.h"
#include "Widget/StratagemWidget.h"

void UStaratagemHeroWidget::OnCommandInit(const FMinigameUICommand& Command)
{
	if (StaratagemWidget)
	{
		int32 Size = Command.CommandSequence.Num();
		StaratagemWidget->InitCommandUI(Size);
	}
}

void UStaratagemHeroWidget::OnArrowUpdate(const FMinigameUICommand& Command)
{
	if (StaratagemWidget)
	{
		int32 Index = Command.NumericValue;
		bool bVal = Command.BoolValue;
		StaratagemWidget->UpdateArrowUI(Index, bVal);
	}
}

void UStaratagemHeroWidget::NativeConstruct()
{
	CommandFuncBindMap.Add(EMinigameUICommandType::UpdateCommands, &UStaratagemHeroWidget::OnCommandInit);
	CommandFuncBindMap.Add(EMinigameUICommandType::UpdateContainer, &UStaratagemHeroWidget::OnArrowUpdate);
}

void UStaratagemHeroWidget::ExecuteUICommand_Implementation(const FMinigameUICommand Command)
{
	if (CommandFuncBindMap.Contains(Command.CommandType))
	{
		(this->*CommandFuncBindMap[Command.CommandType])(Command);
	}
}
