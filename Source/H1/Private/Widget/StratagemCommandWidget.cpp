


#include "Widget/StratagemCommandWidget.h"
#include "Components/Image.h"

void UStratagemCommandWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ClearCommand();

}

void UStratagemCommandWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	// 화살표 Array초기화
	ArrowArray.Empty();
	ArrowArray.Add(Arrow1);
	ArrowArray.Add(Arrow2);
	ArrowArray.Add(Arrow3);
	ArrowArray.Add(Arrow4);
	ArrowArray.Add(Arrow5);
	ArrowArray.Add(Arrow6);
	ArrowArray.Add(Arrow7);
	ArrowArray.Add(Arrow8);
	ArrowArray.Add(Arrow9);
	ArrowArray.Add(Arrow10);
}

void UStratagemCommandWidget::ClearCommand()
{
	for (auto& Arrow : ArrowArray)
	{
		Arrow->SetColorAndOpacity(FLinearColor::White);
		Arrow->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UStratagemCommandWidget::UpdateArrowColor(int32 Index, bool Res)
{
	if (Index < 0 || Index >= ArrowArray.Num()) return;
	ArrowArray[Index]->SetColorAndOpacity(Res ? FLinearColor::Yellow : FLinearColor::White);
}

void UStratagemCommandWidget::InitCommand(const TArray<EDirType>& CommandSeq)
{
	if ( (CommandSeq.Num() < 0 ) || (CommandSeq.Num() > ArrowArray.Num())) return;
	
	ClearCommand();

	for (int i = 0; i < CommandSeq.Num(); i++)
	{
		ArrowArray[i]->SetVisibility(ESlateVisibility::Visible);
		if (ArrowTextureMap.Contains(CommandSeq[i]))
		{
			ArrowArray[i]->SetBrushFromTexture(ArrowTextureMap[CommandSeq[i]], false);
		}
	}

}

