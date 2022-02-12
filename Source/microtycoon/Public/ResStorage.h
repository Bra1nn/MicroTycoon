// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ResStorage.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MICROTYCOON_API UResStorage : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool MaxStorage;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 CurrentRes;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 MaxRes=20;
	
	// Sets default values for this component's properties
	UResStorage();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	
	UFUNCTION(BlueprintCallable) // collecting resource math
	int CollectResources();

	UFUNCTION(BlueprintCallable, Category="Resources")
	int DecrementResources (int32 inputCost);
};
