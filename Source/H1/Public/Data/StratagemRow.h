

#pragma once

#include "CoreMinimal.h"
#include "Data/Define.h"
#include "StratagemRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct H1_API FStratagemRow : public FTableRowBase
{
    GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stratagem")
	TSoftObjectPtr<UTexture2D> StratagemIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stratagem")
	FText StratagemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stratagem")
	FString CommandString;

	TArray<EDirType> GetCommandSequence() const
	{
        TArray<EDirType> Sequence;
        for (TCHAR Ch : CommandString.ToUpper())
        {
            switch (Ch)
            {
                case 'W': Sequence.Add(EDirType::Up); break;
                case 'S': Sequence.Add(EDirType::Down); break;
                case 'A': Sequence.Add(EDirType::Left); break;
                case 'D': Sequence.Add(EDirType::Right); break;
            }
        }
        return Sequence;
	}

};
