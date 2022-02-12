// Fill out your copyright notice in the Description page of Project Settings.


#include "ResStorage.h"





// Sets default values for this component's properties
UResStorage::UResStorage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UResStorage::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UResStorage::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int UResStorage::CollectResources()
{
	if (MaxStorage==false)          // Check if storage is not full
	{
		CurrentRes++;                  // increment resources
		if (CurrentRes==MaxRes){ 
			MaxStorage=true;            // block increment possibility and return current res (max res)
			return CurrentRes;
		}
				
	}
	return CurrentRes;
}

int UResStorage::DecrementResources(int32 inputCost)
{
	
	int32 localCostout;
	MaxStorage=false;                 //reset increment possibility
	if(CurrentRes-inputCost<=0)
	{
		localCostout=CurrentRes-inputCost;
		CurrentRes=0;
		return abs(localCostout);
	}

	CurrentRes=CurrentRes-inputCost;        // if ResHouse can pay all sum
	return localCostout=0;                  // return 0 will stop "pay" loop operations
		
		
		
}

