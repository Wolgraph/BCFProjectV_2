// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Core/Public/Misc/Paths.h"

#include "ZipArchive.h"
#include "ZipArchiveEntry.h"
#include "ZipFile.h"

#include "BCF_Compiler.generated.h"

/**
 * 
 */
UCLASS()
class BCFPROJECTV_1_API UBCF_Compiler : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		UFUNCTION(BlueprintCallable, Category = "MyFunction")
		static FString FMYStringPrint();
};
