#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WikiCharacterUserWidget_CPP.generated.h"

UCLASS()
class WIKI_API UWikiCharacterUserWidget_CPP : public UUserWidget
{
	GENERATED_BODY()

public:
  virtual void NativeConstruct() override;

public:
 	void OnButtonClicked();
 	void StartAnimation();
  class UWidgetAnimation* GetAnimationByName(FName AnimationName) const;
  bool PlayAnimationByName(class FName AnimationName,	float StartAtTime, int32 NumLoopsToPlay,	EUMGSequencePlayMode::Type PlayMode, float PlaybackSpeed);

protected:
	class TMap<class FName, class UWidgetAnimation*> AnimationsMap;
	void FillAnimationsMap();

public:
  class UTextBlock *TextPoint;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WidgetAnimation, meta = (BindWidgetAnimation))
  class UWidgetAnimation* WidgetAnimation;
  
};
