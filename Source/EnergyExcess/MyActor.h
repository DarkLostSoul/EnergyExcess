// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class ENERGYEXCESS_API AMyActor: public AActor
{
	GENERATED_BODY()
	
public:
    bool m_bInternalMember;

    // Мемберы (особенно указатели и объекты) отмеченные UPROPERTY будут удаляться сборщиком мусора.
    // Остальные - нет.

    // в ВР ее не видно
    UPROPERTY(EditAnywhere, Category = "MyActor|ChangableVars")
    int32 EditableMember;

    // в ВР есть set/get
    UPROPERTY(EditAnywhere, Category = "MyActor|ChangableVars", BlueprintReadWrite)
    int32 BPEditableMember;

    // находится в категории, видна везде, можно читать и изменять из BP, есть set/get
    UPROPERTY(Category = "MyActor|ChangableVars",  EditAnywhere, BlueprintReadWrite)
    int32 BPEditableCatMember;

    // можно читать ее внутри BP (EventGraph например), но в списке свойств класса она не отображается; нельзя изменять
    // есть только get
    UPROPERTY(Category = "MyActor|ReadonlyVars", VisibleAnywhere, BlueprintReadOnly, Transient)
    int32 BPReadOnlyMember;

public:	
	// Sets default values for this actor's properties
	AMyActor();

    UFUNCTION(BlueprintCallable, Category = "MyActor|Funcs")
    bool IsValid();

    //UFUNCTION(BlueprintCallable, Category = MyFuncs)
    //void MyFunc1(bool* _pInternalMember); // так нельзя!

    //UFUNCTION(BlueprintCallable, Category = "MyActor|Funcs")
    //void MyFunc2_ref(int32& _inout, int32 _in) { _inout += _in; }; // странное поведение


    UFUNCTION(BlueprintCallable, Category = "MyActor|Funcs")
    void MyFunc3(int32 _in_a, int32 _in_b) { BPReadOnlyMember = (_in_a + _in_b); };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    virtual void EndPlay(EEndPlayReason::Type reason) override;

private:
    UFUNCTION(BlueprintCallable, Category = "MyActor|Funcs")
    void UpdateData();
    
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    virtual void PostInitProperties() override; // вызывается после конструктора
	
    // вызывается при изменении параметров в редакторе
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
