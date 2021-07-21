// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"

#include "MainSlateWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct LFS_API FMainSlateStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FMainSlateStyle();
	virtual ~FMainSlateStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FMainSlateStyle& GetDefault();

public:
	//Font
	UPROPERTY(EditAnywhere,Category=Font)
	FSlateFontInfo FontInfo_Size_16_White;//白色16号字体
	UPROPERTY(EditAnywhere,Category=Font)
	FSlateFontInfo FontInfo_Size_16_Blue;//蓝色16号字体
	UPROPERTY(EditAnywhere,Category=Font)
	FSlateFontInfo FontInfo_Size_12_White;//白色12号字体
	UPROPERTY(EditAnywhere,Category=Font)
	FSlateFontInfo FontInfo_Size_12_Blue;//蓝色12号字体
	UPROPERTY(EditAnywhere,Category=Font)
	FSlateFontInfo FontInfo_Size_12_Yellow;//黄色12号字体
	UPROPERTY(EditAnywhere,Category=Font)
	FSlateFontInfo FontInfo_Size_36_White;//白色36号字体

	/*
	 * 背景图片
	 */
	//Main Top
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush Main_Top_BG;
	
	//Main Left
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush Main_Left_BG;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush ProbarBGBrush;//进度条图片
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush ProbarFillImageBrush;//进度填充条图片
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush StateIcon_1;//状态图片
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush StateIcon_2;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush StateIcon_3;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush HuanImmageSlateBrush;
	
	//Main Right
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush Main_Right_BG;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush Main_Right_Infotitle;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush Main_Right_Buttom_Icon;
	
	//Main Bottom
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush Main_Bottom_BG;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush ButtomIcon_1;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush ButtomIcon_2;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush ButtomIcon_3;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush ButtomIcon_4;

	//通道
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush TD_BG_LEFT;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush TD_BG_RIGHT;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush TD_LB;
	//Main Windows
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush Main_Window;

	//center window
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush Center_Window1;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush Center_Window2;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush Center_Window3;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush Center_Window4;

	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush LeftBottom_Window1;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush LeftBottom_Window2;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush LeftBottom_Window3;
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush LeftBottom_Window4;
	
	UPROPERTY(EditAnywhere,Category=ButtonStyle)
	FButtonStyle ButtonStyle_DMY;

	//ButtonStyle
	UPROPERTY(EditAnywhere,Category=ButtonStyle)
	FButtonStyle SelecdButtonStyle;
	UPROPERTY(EditAnywhere,Category=ButtonStyle)
	FButtonStyle NotSelecdButtonStyle;
	UPROPERTY(EditAnywhere,Category=ButtonStyle)//下拉框风格
	FButtonStyle ComboBoxButtonStyle;
	UPROPERTY(EditAnywhere,Category=ButtonStyle)
	FComboBoxStyle ComboBoStyle;
	UPROPERTY(EditAnywhere,Category=ButtonStyle)
	FColor ComboBoStyleColor;

	UPROPERTY(EditAnywhere,Category=ButtonStyle)
	FButtonStyle ButtonStyle_Item_Chakan;
		
	
	//InRoom
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush InRoomplan;

	//ObjectActorInfo
	UPROPERTY(EditAnywhere,Category=Image)
	FSlateBrush ObjectActorInfo_BG;
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class UMainSlateWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FMainSlateStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
