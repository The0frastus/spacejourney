// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SJFunctions.generated.h"

template<typename T>
void GetObjectsOfClass(TArray<T*>& OutArray)
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> AssetData;
	AssetRegistryModule.Get().GetAssetsByClass(T::StaticClass()->GetFName(), AssetData);
	for (int i = 0; i < AssetData.Num(); i++) {
		T* Object = Cast<T>(AssetData[i].GetAsset());
		OutArray.Add(Object);
	}
}

/**
 * 
 */
UCLASS()
class SPACEJOURNEY_API USJFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "SpaceJourney")
		static UObject* GetDefaultObject(TSubclassOf<UObject> ObjectClass);
	
	UFUNCTION(BlueprintCallable, Category = "SpaceJourney")
		static TArray<UObject*> GetEvents();
	
	/*
	UFUNCTION(BlueprintCallable, Category = "SpaceJourney")
		static TArray<UObject*> LoadObjectLibrary(TSubclassOf<UObject> cls);
	*/
};
