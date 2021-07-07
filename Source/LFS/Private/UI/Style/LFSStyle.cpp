// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Style/LFSStyle.h"

#include "Slate/SlateGameResources.h"
#include "Styling/SlateStyleRegistry.h"

TSharedPtr<FSlateStyleSet> LFSStyle::LFSStyleInstance = NULL;

void LFSStyle::Initialze()
{
	if (!LFSStyleInstance.IsValid())
	{
		LFSStyleInstance = Create();
		//注册进注册表
		FSlateStyleRegistry::RegisterSlateStyle(*LFSStyleInstance);
	}
}

FName LFSStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("LFSStyle"));
	return StyleSetName;
	
}

void LFSStyle::ShutDown()
{
	//关闭时调用
	FSlateStyleRegistry::UnRegisterSlateStyle(*LFSStyleInstance);
	//确保唯一
	ensure(LFSStyleInstance.IsUnique());
	LFSStyleInstance.Reset();
}

const ISlateStyle& LFSStyle::Get()
{
	if (!LFSStyleInstance)
	{
		Initialze();
	}
	return *LFSStyleInstance;
}

TSharedRef<class FSlateStyleSet> LFSStyle::Create()
{
	//"/Game/UI/Style"|在content路径下的Style文件
	TSharedRef<FSlateStyleSet> StyleRef  = FSlateGameResources::New(LFSStyle::GetStyleSetName(),"/Game/UI/Style","/Game/UI/Style");

	return StyleRef;
}