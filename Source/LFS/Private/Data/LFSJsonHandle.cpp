// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/LFSJsonHandle.h"

LFSJsonHandle::LFSJsonHandle()
{
	MainMenuFileName=FString("MainMenu.Json");
	RelativePath = FString("Res/ConfigData/");
}

bool LFSJsonHandle::LoadStringFromFile(const FString& FileName, const FString& RelaPath, FString& ResultString)
{
	if (!FileName.IsEmpty())
	{
		//获取绝对路径
		FString AbsoPath=FPaths::ProjectContentDir()+RelaPath+FileName;
		if (FPaths::FileExists(AbsoPath))
		{
			if (FFileHelper::LoadFileToString(ResultString,*AbsoPath))
			{
				return true;
			}else
			{
				//加载不成功
				UE_LOG(LogTemp,Warning,TEXT("JSON文件加载错误"))
			}
		}else
		{
			UE_LOG(LogTemp,Warning,TEXT("JSON文件不存在"))
		}
	}
	return false;
}

bool LFSJsonHandle::GetFStringInJsonData(const TSharedPtr<FJsonObject>& JsonObj, FString& JsonStr)
{
	if (JsonObj.IsValid()&&JsonObj->Values.Num()>0)
	{
		TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<TCHAR>::Create(&JsonStr);
		//序列化
		FJsonSerializer::Serialize(JsonObj.ToSharedRef(),JsonWriter);
		return true;
	}
	
	return  false;
}

bool LFSJsonHandle::WriteFileWithJsonData(const FString& JsonStr, const FString& RelaPath, const FString& FileName)
{
	if (!JsonStr.IsEmpty())
	{
		if (!FileName.IsEmpty())
		{
			//获取一下绝对路径
			FString AbsoPath = FPaths::ProjectContentDir()+RelativePath+FileName;
			//保存
			if(FFileHelper::SaveStringToFile(JsonStr,*AbsoPath))
			{
				return true;
			}else
			{
				UE_LOG(LogTemp,Warning,TEXT("保存失败"))
			}
		}	
	}
	return  false;
}

void LFSJsonHandle::ConditionMonitoring(TArray<TMap<FString,FString>>& ConditionMonitoringDataList)
{
	FString JsonValue;
	LoadStringFromFile(MainMenuFileName,RelativePath,JsonValue);

	TArray<TSharedPtr<FJsonValue>> JsonParsed;
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValue);

	//解析
	if (FJsonSerializer::Deserialize(JsonReader,JsonParsed))
	{
		TArray<TSharedPtr<FJsonValue>> ConditionMonitoringDataArray=JsonParsed[0]->AsObject()->GetArrayField(FString("ConditionMonitoring"));

		for (int i=0;i<ConditionMonitoringDataArray.Num();i++)
		{
			TArray<TSharedPtr<FJsonValue>> ConditionMonitoringDataName = ConditionMonitoringDataArray[i]->AsObject()->GetArrayField("Status");
			TMap<FString,FString> Status;
			FString percent=ConditionMonitoringDataName[0]->AsObject()->GetStringField("percent");
			FString State=ConditionMonitoringDataName[1]->AsObject()->GetStringField("State");
			Status.Add("percent",percent);
			Status.Add("State",State);
			ConditionMonitoringDataList.Add(Status);
		}
	}
	UE_LOG(LogTemp,Warning,TEXT("%s"),*JsonValue);
}
