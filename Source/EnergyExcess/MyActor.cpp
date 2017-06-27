// Fill out your copyright notice in the Description page of Project Settings.

#include "EnergyExcess.h"
#include "MyActor.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    m_bInternalMember = false;
    EditableMember = 0;
    BPEditableMember = 10;
    BPEditableCatMember = 20;
    BPReadOnlyMember = 1;

    //SetLifeSpan(1.0); // врем€ жизни
    //PrimaryActorTick.TickGroup = TG_EndPhysics; // когда объект "тикает"
}

void AMyActor::UpdateData()
{
    BPReadOnlyMember = BPEditableMember * 2;    
}

bool AMyActor::IsValid()
{
    if (IsPendingKill()) return false; // проверка, не стоит ли объект на удалении —борщиком
    if (BPReadOnlyMember != (BPEditableMember * 2)) return false;
    if (EditableMember <= 0) return false;

    return true;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    EditableMember = 1;
	Super::BeginPlay();
}

void AMyActor::EndPlay(EEndPlayReason::Type reason)
{
    Super::EndPlay(reason);
}

///////////////////////////////////////

void AMyActor::PostInitProperties()
{
    Super::PostInitProperties();
    BPEditableCatMember = 30;

    // можно перебирать пол€ класса (UFunction и/или UProperty) 
    /*TFieldIterator<UField> it = GetClass();
    for (; it; it++) {
        UField* pField = *it;
    }*/

    //UWorld* pWorld = GetWorld();
    //TActorIterator<AMyActor> it(pWorld);

    // перебираем все объекты указанного типа
    /*TObjectIterator<AMyActor> it;
    for (; it; it++) {
        AMyActor* pObj = *it;
    }*/

    UpdateData();
}

#ifdef WITH_EDITOR
void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    UpdateData();
    Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    BPReadOnlyMember = BPEditableMember * 2;
}

