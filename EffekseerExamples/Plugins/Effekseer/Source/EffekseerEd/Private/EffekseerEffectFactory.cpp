
#include "EffekseerEdPrivatePCH.h"
#include "EffekseerEffectFactory.h"
#include "EffekseerEffect.h"

UEffekseerEffectFactory::UEffekseerEffectFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UEffekseerEffect::StaticClass();
	bCreateNew = false;
	bText = false;
	bEditorImport = true;
	Formats.Add(TEXT("efk;Effekseer"));
}
bool UEffekseerEffectFactory::DoesSupportClass(UClass* Class)
{
	return (Class == UEffekseerEffect::StaticClass());
}
UClass* UEffekseerEffectFactory::ResolveSupportedClass()
{
	return UEffekseerEffect::StaticClass();
}

UObject* UEffekseerEffectFactory::FactoryCreateBinary(
	UClass* InClass,
	UObject* InParent,
	FName InName,
	EObjectFlags Flags,
	UObject* Context,
	const TCHAR* Type,
	const uint8*& Buffer,
	const uint8* BufferEnd,
	FFeedbackContext* Warn)
{
	UEffekseerEffect* NewMyAsset = CastChecked<UEffekseerEffect>(StaticConstructObject(InClass, InParent, InName, Flags));
	
	if (NewMyAsset)
	{
		auto path = NewMyAsset->GetPathName();
		NewMyAsset->Load(Buffer, (int32_t)(BufferEnd - Buffer), *path);
	}
	
	return NewMyAsset;
}
