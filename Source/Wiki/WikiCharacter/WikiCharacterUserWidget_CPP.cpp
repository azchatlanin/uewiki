#include "WikiCharacterUserWidget_CPP.h"
#include "WidgetTree.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Animation/WidgetAnimation.h"

DEFINE_LOG_CATEGORY_STATIC(WikiCharacterUserWidget_CPP, Warning, All);
void UWikiCharacterUserWidget_CPP::NativeConstruct()
{
  Super::NativeConstruct();
  TextPoint = (class UTextBlock*) GetWidgetFromName(FName("TEXT_POINT"));
  FillAnimationsMap();
}

void UWikiCharacterUserWidget_CPP::OnButtonClicked()
{
  TextPoint->SetText(FText::FromString("Can you see your text?"));
}

void UWikiCharacterUserWidget_CPP::StartAnimation()
{
  TextPoint->SetText(FText::FromString("START ANIMATION"));
  PlayAnimationByName(FName("Fire"), 0.f, 1,	EUMGSequencePlayMode::Forward, 1.f);

	// Для использования этого в blueprint ui нужно установить в графах соединение
  // PlayAnimation(WidgetAnimation,  0.f, 3,	EUMGSequencePlayMode::Forward, 1.f);
}

void UWikiCharacterUserWidget_CPP::FillAnimationsMap()
{
	AnimationsMap.Empty();
	
	class UProperty* Prop = GetClass()->PropertyLink;

	while (Prop != nullptr)
	{
		if (Prop->GetClass() == UObjectProperty::StaticClass())
		{
			class UObjectProperty* ObjProp = Cast<class UObjectProperty>(Prop);
			if (ObjProp->PropertyClass == UWidgetAnimation::StaticClass())
			{
				class UObject* Obj = ObjProp->GetObjectPropertyValue_InContainer(this);

				class UWidgetAnimation* WidgetAnim = Cast<class UWidgetAnimation>(Obj);

				if (WidgetAnim != nullptr && WidgetAnim->MovieScene != nullptr)
				{
					class FName AnimName = WidgetAnim->MovieScene->GetFName();
					AnimationsMap.Add(AnimName, WidgetAnim);
				}
			}
		}
		Prop = Prop->PropertyLinkNext;
	}
}

class UWidgetAnimation* UWikiCharacterUserWidget_CPP::GetAnimationByName(class FName AnimationName) const
{
	class UWidgetAnimation* const* WidgetAnim = AnimationsMap.Find(AnimationName);
	if (WidgetAnim)
	{
		return *WidgetAnim;
	}
	return nullptr;
}


bool UWikiCharacterUserWidget_CPP::PlayAnimationByName(class FName AnimationName, float StartAtTime, int32 NumLoopsToPlay,	EUMGSequencePlayMode::Type PlayMode, float PlaybackSpeed)
{
	class UWidgetAnimation* WidgetAnim = GetAnimationByName(AnimationName);
	if (WidgetAnim)
	{
		PlayAnimation(WidgetAnim, StartAtTime, NumLoopsToPlay, PlayMode, PlaybackSpeed);
		return true;
	}
	return false;
}


