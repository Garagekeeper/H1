


#include "Widget/StratagemWidget.h"
#include "Widget/StratagemCommandWidget.h"
#include "Widget/StratagemIconWidget.h"


//TODO 파라미터를 스트라타젬 배열로 받아서 그림도 초기화하기
void UStratagemWidget::InitCommandUI(const TArray<EDirType>& CommandSeq, TSoftObjectPtr<UTexture2D> Icon)
{
	if (CommandWidget)
		CommandWidget->InitCommand(CommandSeq);

	if (IconWidget)
		IconWidget->UpdateStratagemIcon(Icon);
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
