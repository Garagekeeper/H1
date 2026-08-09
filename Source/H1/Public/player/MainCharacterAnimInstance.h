

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class H1_API UMainCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	

public:
	inline void SetModuledMeshBool(bool InbModuledMesh)	{	bModuledMesh = InbModuledMesh;	}

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Anims")
	bool bModuledMesh = false;
};
