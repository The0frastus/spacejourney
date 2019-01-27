// Fill out your copyright notice in the Description page of Project Settings.

#include "SJFunctions.h"
#include "SJEvent.h"
#include "Engine.h"


UObject* USJFunctions::GetDefaultObject(TSubclassOf<UObject> ObjectClass)
{
	
	return ObjectClass.GetDefaultObject();
}

TArray<UObject*> USJFunctions::GetEvents() {
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> AssetData;
	AssetRegistryModule.Get().GetAssetsByClass(USJEvent::StaticClass()->GetFName(), AssetData);
	for (int i = 0; i < AssetData.Num(); i++) {
		USJEvent* Object = Cast<USJEvent>(AssetData[i].GetAsset());
		OutArray.Add(Object);
	}
}

/*
TArray<UObject*> USJFunctions::LoadObjectLibrary(TSubclassOf<UObject> cls)
{
	TArray<UObject> Objects;
	//GetObjectsOfClass<UObject>(Objects);

	return Objects;
}
*/