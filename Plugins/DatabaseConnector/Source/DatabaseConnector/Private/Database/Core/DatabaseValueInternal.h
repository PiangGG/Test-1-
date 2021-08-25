// Copyright Pandores Marketplace 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include <boost/variant.hpp>
#include "Database/Value.h"

struct FNullValue {};

using FValue = boost::variant
<
	FNullValue, bool, uint8, int32, int64, double, FString, FDatabaseTimestamp, FDatabaseDate
>;

class FDatabaseValueInternal
{
public:
	FValue& Get() { return Value; }

private:
	FValue Value;
};

