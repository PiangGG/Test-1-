// Copyright notice
#include "Database/MyClass.h"

#include "Database/Pool.h"


// Connects to the database.
void UMyClass::ConnectToDatabase()
{
	UDatabasePool::CreatePool
	(
	TEXT("MySQL ODBC 8.0 Unicode Driver"),
	TEXT("MyUsername"),
	TEXT("root"),
	TEXT("192.168.0.21"),
	3306 /* database port */,
	TEXT("lfsitem"),
	10 /* Pool size */,
    
	// We want to call our member method when the pool is created.
	FDatabasePoolCallback::CreateUObject(this, &ThisClass::OnPoolCreated)
	);  
}

// Callback called when the pool is created.
void UMyClass::OnPoolCreated(EDatabaseError Error, UDatabasePool* NewPool)
{
	if (Error == EDatabaseError::None)
	{
		// We are connected with a valid pool.
		Pool = NewPool;
    
		// We can now query our database.
		Pool->Query(TEXT("SELECT * FROM tb_users WHERE user = ?"), { 1 }, FDatabaseQueryCallback::CreateUObject(this, &ThisClass::OnUserQueried));
		UE_LOG(LogTemp,Warning,TEXT("OnPoolCreated"));
	}
	else
	{
		// An error occured.
		UE_LOG(LogTemp,Warning,TEXT("!OnPoolCreated"));
	}
}

// Called after our query.
void UMyClass::OnUserQueried(EDatabaseError Error, const FQueryResult& Results)
{
	// We can parse Results to get our user.
}