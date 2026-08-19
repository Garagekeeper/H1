


#include "Widget/StratagemIconWidget.h"
#include "Components/Image.h"

void UStratagemIconWidget::UpdateStratagemIcon(TSoftObjectPtr<UTexture2D> InTexture)
{
	StratagemIcon->SetBrushFromTexture(InTexture.LoadSynchronous(), false);
}
