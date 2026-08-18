


#include "Widget/StratagemWidget.h"
#include "Widget/StratagemCommandWidget.h"

//TODO 파라미터를 스트라타젬 배열로 받아서 그림도 초기화하기
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
