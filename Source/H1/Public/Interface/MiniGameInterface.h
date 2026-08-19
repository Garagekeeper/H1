
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Data/Define.h"
#include "MiniGameInterface.generated.h"



UENUM(BlueprintType)
enum class EMinigameUICommandType : uint8
{
    SetScore,
    SetTime,
    UpdateCommands,
    UpdateContainer,
    GameOver
};

USTRUCT(BlueprintType)
struct FMinigameUICommand
{
    GENERATED_BODY()

public:
    static FMinigameUICommand MakeSetScore(const int32 InScore)
    {
        FMinigameUICommand Command;
        Command.CommandType = EMinigameUICommandType::SetScore;
        Command.NumericValue = InScore;
        return Command;
    }

    static FMinigameUICommand MakeSetTime(const int32 InTimme)
    {
        FMinigameUICommand Command;
        Command.CommandType = EMinigameUICommandType::SetTime;
        Command.FloatValue = InTimme;
        return Command;
    }

    static FMinigameUICommand MakeUpdateCommand(TArray<EDirType> InCommandSequence, TSoftObjectPtr<UTexture2D> InIcon, FString InName)
    {
        FMinigameUICommand Command;
        Command.CommandType = EMinigameUICommandType::UpdateCommands;
        Command.CommandSequence = InCommandSequence;
        Command.StratagemIcon = InIcon;
        Command.StratagemName;
        return Command;
    }

    static FMinigameUICommand MakeUpdateContainerBool(const int32 InIndex, const bool InVal)
    {
        FMinigameUICommand Command;
        Command.CommandType = EMinigameUICommandType::UpdateContainer;
        Command.NumericValue = InIndex;
        Command.BoolValue = InVal;
        return Command;
    }

    static FMinigameUICommand MakeUpdateContainerInt(const int32 InIndex, const int32 InVal)
    {
        FMinigameUICommand Command;
        Command.CommandType = EMinigameUICommandType::UpdateContainer;
        Command.NumericValue = InVal;
        return Command;
    }

    static FMinigameUICommand MakeUpdateContainerflaot(const int32 InIndex, const float InVal)
    {
        FMinigameUICommand Command;
        Command.CommandType = EMinigameUICommandType::UpdateContainer;
        Command.FloatValue = InVal;
        return Command;
    }

    static FMinigameUICommand MakeGameOver()
    {
        FMinigameUICommand Command;
        Command.CommandType = EMinigameUICommandType::GameOver;
        return Command;
    }


public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Command")
    EMinigameUICommandType CommandType = EMinigameUICommandType::SetScore;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Command")
    int32 NumericValue = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Command")
    float FloatValue = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Command")
    int32 TargetIndex = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Command")
    bool BoolValue = false;

    // 스트라타젬 화살표 방향 데이터 (0: Up, 1: Down, 2: Left, 3: Right 등)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Command")
    TArray<EDirType> CommandSequence;

    // 스트라타젬 화살표 방향 데이터 (0: Up, 1: Down, 2: Left, 3: Right 등)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Command")
    TSoftObjectPtr<UTexture2D> StratagemIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Command")
    FString StratagemName;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMiniGameInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class H1_API IMiniGameInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void ExecuteUICommand(const FMinigameUICommand Command);

protected:
};
