// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UDoorController::UDoorController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorController::BeginPlay()
{
	Super::BeginPlay();
	DoorControllerActor = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}

void UDoorController::OpenDoor()
{
	GetOwner()->SetActorRotation(FRotator(0.0f, -90.0f, 0.0f));
}


// Called every frame
void UDoorController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (PressurePlate->IsOverlappingActor(DoorControllerActor))
		OpenDoor();
	// ...
}

