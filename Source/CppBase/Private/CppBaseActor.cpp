// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "TimerManager.h"


// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}


// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation2 = this->GetActorLocation();
	ShowActorInformation();
	
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppBaseActor::ShowActorInformation()
{
	FString InstanceName = GetName();
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *InstanceName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %d"), IsAlive);
}

FVector ACppBaseActor::SinMovement()
{

	FVector NewLocation;
	NewLocation.X = InitialLocation2.X;
	NewLocation.Y = InitialLocation2.Y;

	NewLocation.Z = (FMath::Sin(GetWorld()->GetTimeSeconds() * Frequency2)) * Amplitude2 + InitialLocation2.Z;
	return NewLocation;
};

