// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
template<class T>
class LFS_API LFSSingleton
{
  public:
  static  TSharedPtr<T> Get();
  private:
  static void Initialize();

  static TSharedRef<T> Create();

  private:
  static TSharedPtr<T> TInstance;	
};

template <class T>
TSharedPtr<T> LFSSingleton<T>::TInstance=NULL;

template <class T>
TSharedPtr<T> LFSSingleton<T>::Get()
{
	Initialize();
	return TInstance;
}

template <class T>
void LFSSingleton<T>::Initialize()
{
	if (!TInstance.IsValid())
	{
		TInstance=Create();
	}
	
}

template <class T>
TSharedRef<T> LFSSingleton<T>::Create()
{
	TSharedRef<T> TRef =MakeShareable(new T());
	return TRef;
}