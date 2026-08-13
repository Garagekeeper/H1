


#include "Widget/StaratagemHeroWidget.h"
#include "Component/StratagemHeroComponent.h"
#include "Widget/StratagemWidget.h"

void UStaratagemHeroWidget::BindHeroComponent(UStratagemHeroComponent* HeroComponent)
{
	if (HeroComponent)
	{
		// 컴포넌트의 델리게이트에 위젯의 콜백 함수를 연결합니다.
		HeroComponent->OnCommandSelected.AddDynamic(this, &UStaratagemHeroWidget::OnCommandSelectedCallback);
		HeroComponent->OnCommandInput.AddDynamic(this, &UStaratagemHeroWidget::OnCommandInputCallback);
	}
}

void UStaratagemHeroWidget::OnCommandSelectedCallback(int32 Size)
{
	if (StaratagemWidget)
	{
		StaratagemWidget->InitCommandUI(Size);
	}
}

void UStaratagemHeroWidget::OnCommandInputCallback(int32 Index, bool bIsCorrect)
{
	if (StaratagemWidget)
	{
		StaratagemWidget->UpdateArrowUI(Index, bIsCorrect);
	}
}

void UStaratagemHeroWidget::NativeConstruct()
{
	UObject* Outer = GetOuter();
}

void UStaratagemHeroWidget::NativePreConstruct()
{

}
