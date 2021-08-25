// Copyright notice

#include "CoreMinimal.h"
#include "Database/Errors.h"
#include "Database/QueryResult.h"
#include "MyClass.generated.h"

// Forward declaration of the pool class.
class UDatabasePool;

UCLASS()
class LFS_API UMyClass : public UObject
{
	GENERATED_BODY()
	public:
	// Connects to the database.
	void ConnectToDatabase();
  
	// We have a connection if the pool is not null.
	// This is pretty basic as it doesn't check the actual connection status.
	inline bool IsConnected() const 
	{
		return Pool != nullptr;
	}
  
	private:
	// Callback called when the pool is created.
	void OnPoolCreated(EDatabaseError Error, UDatabasePool* NewPool);
  
	// Called after our query.
	void OnUserQueried(EDatabaseError Error, const FQueryResult& Results);
  
	private:
	// Our pool kept as UPROPERTY() to prevent garbage collection.
	UPROPERTY()
	UDatabasePool* Pool;
};