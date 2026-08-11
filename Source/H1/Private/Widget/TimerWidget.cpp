


#include "Widget/TimerWidget.h"
#include "Components/ProgressBar.h"

void UTimerWidget::UpdateProgressBar(float CurrentRemain, float InitRemain)
{
	if (InitRemain == 0.0f) return;
		RemainTimeProgressBar->SetPercent( CurrentRemain / InitRemain);
}
