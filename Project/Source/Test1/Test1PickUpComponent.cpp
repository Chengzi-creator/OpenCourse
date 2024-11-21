// Copyright Epic Games, Inc. All Rights Reserved.

#include "Test1PickUpComponent.h"

UTest1PickUpComponent::UTest1PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UTest1PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UTest1PickUpComponent::OnSphereBeginOverlap);
}

void UTest1PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	ATest1Character* Character = Cast<ATest1Character>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
