

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Data/Define.h"
#include "StratagemCommandWidget.generated.h"

class UImage;
/**
 * 
 */
UCLASS()
class H1_API UStratagemCommandWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// 화살표의 색상을 업데이트하는 함수
	void UpdateArrowColor(int32 Index, bool res);
	// 커맨드 초기화(생성)
	void InitCommand(const TArray<EDirType>& CommandSeq);

protected:
	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;

private:
	// 커맨드를 지우는 함수
	void ClearCommand();


protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> Arrow1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> Arrow2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> Arrow3;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> Arrow4;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> Arrow5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> Arrow6;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> Arrow7;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> Arrow8;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> Arrow9;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> Arrow10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<UImage>> ArrowArray;

	UPROPERTY(EditDefaultsOnly, Category = "UI|Assets")
	TMap<EDirType, UTexture2D*> ArrowTextureMap;
};
