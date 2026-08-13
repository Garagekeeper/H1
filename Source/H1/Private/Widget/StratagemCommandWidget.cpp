


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

void UStratagemCommandWidget::InitCommand(int32 Size)
{
	if (Size < 0 || Size >= ArrowArray.Num()) return;
	
	ClearCommand();

	for (int i = 0; i < Size; i++)
	{
		ArrowArray[i]->SetVisibility(ESlateVisibility::Visible);
	}

}

