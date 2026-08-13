


#include "Widget/StratagemWidget.h"
#include "Widget/StratagemCommandWidget.h"

void UStratagemWidget::InitCommandUI(int32 Size)
{
	if (CommandWidget)
		CommandWidget->InitCommand(Size);
}

void UStratagemWidget::UpdateArrowUI(int32 Index, bool bIsCorrect)
{
	if (CommandWidget)
		CommandWidget->UpdateArrowColor(Index, bIsCorrect);
}

void UStratagemWidget::NativeConstruct()
{
	
}

void UStratagemWidget::NativePreConstruct()
{

}
