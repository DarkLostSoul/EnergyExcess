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

    // ������� (�������� ��������� � �������) ���������� UPROPERTY ����� ��������� ��������� ������.
    // ��������� - ���.

    // � �� �� �� �����
    UPROPERTY(EditAnywhere, Category = "MyActor|ChangableVars")
    int32 EditableMember;

    // � �� ���� set/get
    UPROPERTY(EditAnywhere, Category = "MyActor|ChangableVars", BlueprintReadWrite)
    int32 BPEditableMember;

    // ��������� � ���������, ����� �����, ����� ������ � �������� �� BP, ���� set/get
    UPROPERTY(Category = "MyActor|ChangableVars",  EditAnywhere, BlueprintReadWrite)
    int32 BPEditableCatMember;

    // ����� ������ �� ������ BP (EventGraph ��������), �� � ������ ������� ������ ��� �� ������������; ������ ��������
    // ���� ������ get
    UPROPERTY(Category = "MyActor|ReadonlyVars", VisibleAnywhere, BlueprintReadOnly, Transient)
    int32 BPReadOnlyMember;

public:	
	// Sets default values for this actor's properties
	AMyActor();

    UFUNCTION(BlueprintCallable, Category = "MyActor|Funcs")
    bool IsValid();

    //UFUNCTION(BlueprintCallable, Category = MyFuncs)
    //void MyFunc1(bool* _pInternalMember); // ��� ������!

    //UFUNCTION(BlueprintCallable, Category = "MyActor|Funcs")
    //void MyFunc2_ref(int32& _inout, int32 _in) { _inout += _in; }; // �������� ���������


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
    virtual void PostInitProperties() override; // ���������� ����� ������������
	
    // ���������� ��� ��������� ���������� � ���������
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
