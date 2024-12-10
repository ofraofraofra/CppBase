// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};



UCLASS()
class ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ShowActorInformation();

	FVector SinMovement();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	// Properties
	UPROPERTY(EditAnywhere, Category = "Actor Info")
	int32 EnemyNum;

	UPROPERTY(EditAnywhere, Category = "Actor Info")
	bool IsAlive;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent * Mesh;

	UPROPERTY(EditAnywhere)
	float Amplitude2 = 100;

	UPROPERTY(EditAnywhere)
	float Frequency2 = 10;

	UPROPERTY(EditAnywhere)
	FVector InitialLocation2 = FVector::ZeroVector;

};
