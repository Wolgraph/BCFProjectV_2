// Fill out your copyright notice in the Description page of Project Settings.


#include "BCF_Parser.h"
#include <fstream>
#define PROJECT ProjectFile +=
#define VERSION VersionFile +=
#define MARKUP MarkupFile +=
#define VIEW VisualizationFile +=
#define INDENT "\t"






FString UBCF_Parser::FCompileProjectFile(FBCFProjectXMLFile ProjectXMLFile)
{
	FString ProjectFile = TEXT("<?xml version=\"1.0\" encoding=\"UTF-8\"?>") LINE_TERMINATOR;
	PROJECT TEXT("<ProjectExtension>") LINE_TERMINATOR;
	//ProjectID
	PROJECT INDENT + (FString::Printf(TEXT("<Project ProjectId=\"%s\"/>"), *ProjectXMLFile.project.ProjectID)) + LINE_TERMINATOR;
	PROJECT INDENT  TEXT("<ExtensionSchema></ExtensionSchema>") LINE_TERMINATOR;
	PROJECT TEXT("</ProjectExtension>");

	return ProjectFile;
}

FString UBCF_Parser::FCompileVersionFile(FBCFVersionXMLFile VersionXMLFile)
{
	FString VersionFile = TEXT("<?xml version=\"1.0\" encoding=\"UTF-8\"?>") LINE_TERMINATOR;
	VERSION(FString::Printf(TEXT("<Version VersionId=\"%s\" xsi:noNamespaceSchemaLocation=\"version.xsd\" xml:xsi=\"http.www.w3.org/2001/XMLSchema-instance\">"), *VersionXMLFile.VersionId)) + LINE_TERMINATOR;
	if (VersionXMLFile.shouldSerializeDetailedVersion) VersionFile += INDENT + (FString::Printf(TEXT("<DetailedVersion>%s</DetailedVersion>"), *VersionXMLFile.DetailedVersion)) + LINE_TERMINATOR;
	VERSION "</Version>";

	return VersionFile;
}

TArray<FString> UBCF_Parser::FCompileTopicFiles(TArray<FBCFTopicFile> TopicList, bool PerspectiveCamera)
{
	TArray<FString> compiledTopic;
	for (int i = 0; i < TopicList.Num(); i++)
	{
		FBCFTopicFile currentTopicFile = TopicList[i];
		compiledTopic.Add(FCompileMarkup(currentTopicFile.markupFile));
		compiledTopic.Add(FCompileVisualization(currentTopicFile.visualizationFile, PerspectiveCamera));
	}
	return compiledTopic;
}

FString UBCF_Parser::FCompileMarkup(FBCFMarkupXMLFile Topic)
{
	FString MarkupFile = TEXT("<?xml version=\"1.0\" encoding=\"UTF-8\"?>") LINE_TERMINATOR;
	MARKUP TEXT("<Markup>") LINE_TERMINATOR;
	//Scrittura del topic
	MARKUP INDENT + (FString::Printf(TEXT("<Topic Guid=\"%s\" TopicType=\"%s\" TopicStatus=\"%s\">"), *Topic.topic.TopicGUID, *Topic.topic.TopicType, *Topic.topic.TopicStatus)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<Title>%s</Title>"), *Topic.topic.Title)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<Priority>%s</Priority>"), *Topic.topic.Priority)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<Index>%d</Index>"), Topic.topic.index)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<CreationDate>%s</CreationDate>"), *Topic.topic.CreationDate)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<CreationAuthor>%s</CreationAuthor>"), *Topic.topic.CreationAuthor)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<ModifiedDate>%s</ModifiedDate>"), *Topic.topic.ModifiedDate)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<ModifiedAuthor>%s</ModifiedAuthor>"), *Topic.topic.ModifiedAuthor)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<DueDate>%s</DueDate>"), *Topic.topic.DueDate)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<AssignedTo>%s</AssignedTo>"), *Topic.topic.AssignTo)) + LINE_TERMINATOR;
	MARKUP INDENT TEXT("</Topic>") LINE_TERMINATOR;
	//Scrittura del commento
	MARKUP INDENT + (FString::Printf(TEXT("<Comment Guid=\"%s\">"), *Topic.comment.CommentGUID)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<Date>%s</Date>"), *Topic.comment.CreationDate)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<Author>%s</Author>"), *Topic.comment.CreationAuthor)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<Comment>%s</Comment>"), *Topic.comment.Comment)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<Viewpoint Guid=\"%s\"/>"), *Topic.comment.Viewpoint)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<ModifiedDate>%s</ModifiedDate>"), *Topic.comment.ModifiedDate)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<ModifiedAuthor>%s</ModifiedAuthor>"), *Topic.comment.ModifiedAuthor)) + LINE_TERMINATOR;
	MARKUP INDENT TEXT("</Comment>") LINE_TERMINATOR;

	//Scrittura del viewpoint
	MARKUP INDENT + (FString::Printf(TEXT("<Viewpoints Guid=\"%s\">"), *Topic.viewpoint.ViewpointGUID)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<Viewpoint>%s</Viewpoint>"), *Topic.viewpoint.viewpoint)) + LINE_TERMINATOR;
	MARKUP INDENT INDENT + (FString::Printf(TEXT("<Snapshot>%s</Snapshot>"), *Topic.viewpoint.snapshot)) + LINE_TERMINATOR;
	MARKUP INDENT TEXT("</Viewpoints>") LINE_TERMINATOR;
	//Chiusura del file
	MARKUP TEXT("</Markup>");

	return MarkupFile;
}

FString UBCF_Parser::FCompileVisualization(FBCFVisualizationXMLFile Topic, bool PerspectiveCamera)
{
	FString VisualizationFile = TEXT("<?xml version=\"1.0\" encoding=\"UTF-8\"?>") LINE_TERMINATOR;
	VIEW TEXT("<VisualizationInfo>") LINE_TERMINATOR;
	//Scrittura dei components
	if (Topic.component.Num() != 0) {
		VIEW INDENT TEXT("<Components>") LINE_TERMINATOR;
		for (FBCFComponent Component : Topic.component)
		{
			VIEW INDENT INDENT + FString::Printf(TEXT("<Component IfcGuid=\"%s\">"), *Component.ifcGUID) + LINE_TERMINATOR;
			VIEW INDENT INDENT TEXT("</Component>") LINE_TERMINATOR;
		}
		VIEW INDENT TEXT("</Components>") LINE_TERMINATOR;
	}
	if (Topic.isPerspective) {
	//Scrittura della telecamera prospettica
	VIEW INDENT TEXT("<PerspectiveCamera>") LINE_TERMINATOR;
	VIEW INDENT INDENT TEXT("<CameraViewPoint>") LINE_TERMINATOR;
	VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<X>%f</X>"), Topic.perspectiveCamera.position.X)) + LINE_TERMINATOR;
	VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<Y>%f</Y>"), Topic.perspectiveCamera.position.Y)) + LINE_TERMINATOR;
	VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<Z>%f</Z>"), Topic.perspectiveCamera.position.Z)) + LINE_TERMINATOR;
	VIEW INDENT INDENT TEXT("</CameraViewPoint>") LINE_TERMINATOR;

	VIEW INDENT INDENT TEXT("<CameraDirection>") LINE_TERMINATOR;
	VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<X>%f</X>"), Topic.perspectiveCamera.direction.X)) + LINE_TERMINATOR;
	VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<Y>%f</Y>"), Topic.perspectiveCamera.direction.Y)) + LINE_TERMINATOR;
	VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<Z>%f</Z>"), Topic.perspectiveCamera.direction.Z)) + LINE_TERMINATOR;
	VIEW INDENT INDENT TEXT("</CameraDirection>") LINE_TERMINATOR;

	VIEW INDENT INDENT TEXT("<CameraUpVector>") LINE_TERMINATOR;
	VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<X>%f</X>"), Topic.perspectiveCamera.upVector.X)) + LINE_TERMINATOR;
	VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<Y>%f</Y>"), Topic.perspectiveCamera.upVector.Y)) + LINE_TERMINATOR;
	VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<Z>%f</Z>"), Topic.perspectiveCamera.upVector.Z)) + LINE_TERMINATOR;
	VIEW INDENT INDENT TEXT("</CameraUpVector>") LINE_TERMINATOR;

	VIEW INDENT INDENT + (FString::Printf(TEXT("<FieldOfView>%f</FieldOfView>"), Topic.perspectiveCamera.fieldOfView)) + LINE_TERMINATOR;
	VIEW INDENT TEXT("</PerspectiveCamera>") LINE_TERMINATOR;
	}
	else {
		//Scrittura della telecamera ortogonale
		VIEW INDENT TEXT("<OrthogonalCamera>") LINE_TERMINATOR;
		VIEW INDENT INDENT TEXT("<CameraViewPoint>") LINE_TERMINATOR;
		VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<X>%f</X>"), Topic.orthogonalCamera.position.X)) + LINE_TERMINATOR;
		VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<Y>%f</Y>"), Topic.orthogonalCamera.position.Y)) + LINE_TERMINATOR;
		VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<Z>%f</Z>"), Topic.orthogonalCamera.position.Z)) + LINE_TERMINATOR;
		VIEW INDENT INDENT TEXT("</CameraViewPoint>") LINE_TERMINATOR;

		VIEW INDENT INDENT TEXT("<CameraDirection>") LINE_TERMINATOR;
		VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<X>%f</X>"), Topic.orthogonalCamera.direction.X)) + LINE_TERMINATOR;
		VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<Y>%f</Y>"), Topic.orthogonalCamera.direction.Y)) + LINE_TERMINATOR;
		VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<Z>%f</Z>"), Topic.orthogonalCamera.direction.Z)) + LINE_TERMINATOR;
		VIEW INDENT INDENT TEXT("</CameraDirection>") LINE_TERMINATOR;

		VIEW INDENT INDENT TEXT("<CameraUpVector>") LINE_TERMINATOR;
		VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<X>%f</X>"), Topic.orthogonalCamera.upVector.X)) + LINE_TERMINATOR;
		VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<Y>%f</Y>"), Topic.orthogonalCamera.upVector.Y)) + LINE_TERMINATOR;
		VIEW INDENT INDENT INDENT + (FString::Printf(TEXT("<Z>%f</Z>"), Topic.orthogonalCamera.upVector.Z)) + LINE_TERMINATOR;
		VIEW INDENT INDENT TEXT("</CameraUpVector>") LINE_TERMINATOR;

		VIEW INDENT INDENT + (FString::Printf(TEXT("<ViewToWorldScale>%f</ViewToWorldScale>"), Topic.orthogonalCamera.viewScale)) + LINE_TERMINATOR;
		VIEW INDENT TEXT("</OrthogonalCamera>") LINE_TERMINATOR;
	}

	VIEW TEXT("</VisualizationInfo>");
	return VisualizationFile;
}

bool UBCF_Parser::FSaveFile(FString FileStream, FString OutputPath, FString FileName, bool IsArchiveCreated)
{
	FString FilePath = (FString::Printf(TEXT("%s%s"), *OutputPath, *FileName));
	if (FFileHelper::SaveStringToFile(FileStream, *FilePath, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM))
	{
		FString FzipPath = FPaths::ProjectDir() + "OutputFiles/";
		std::string zipFullPath = TCHAR_TO_UTF8(*FzipPath);
		zipFullPath += "MyProject.bcfzip";

		if (!IsArchiveCreated) {
		ZipArchive::Ptr Archive = ZipFile::Open(zipFullPath);
		ZipFile::SaveAndClose(Archive, zipFullPath);
		}
		ZipFile::AddFile(zipFullPath, TCHAR_TO_UTF8(*FilePath));

		return true;
	}
	else return false;
}

bool UBCF_Parser::FSaveTopic(FString FileStream, FString OutputPath, FString TopicGUID, FString FileName)
{

	FString FilePath = (FString::Printf(TEXT("%s%s/%s"), *OutputPath, *TopicGUID, *FileName));
	if (FFileHelper::SaveStringToFile(FileStream, *FilePath, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM))
	{
		FString FzipPath = FPaths::ProjectDir() + "OutputFiles/";
		std::string zipFullPath = TCHAR_TO_UTF8(*FzipPath);
		zipFullPath += "MyProject.bcfzip";

		if (!ZipFile::IsInArchive(zipFullPath, TCHAR_TO_UTF8(*TopicGUID)))
		{
			ZipArchive::Ptr Archive = ZipFile::Open(zipFullPath);
			std::string TopicDirectory = TCHAR_TO_UTF8(*TopicGUID);
			TopicDirectory += "/";
			Archive->CreateEntry(TopicDirectory);
			
			ZipFile::SaveAndClose(Archive, zipFullPath);
		}
		std::string inArchivePath = TCHAR_TO_UTF8(*TopicGUID);
		inArchivePath += "/";
		inArchivePath += TCHAR_TO_UTF8(*FileName);

		ZipFile::AddFile(zipFullPath, TCHAR_TO_UTF8(*FilePath), inArchivePath);

		return true;
	}
	else return false;
}

//NON RIESCE A LEGGERE I PARAMETRI IN INGRESSO. PROVARE A CENTRALIZZARE ALL'INTERNO DEL GAMEMODE
void UBCF_Parser::FSaveSnapshot(FString OutputPath, FString TopicGUID, FString snapName)
{
	std::string zipFullPath = TCHAR_TO_UTF8(*OutputPath);
	zipFullPath += "MyProject.bcfzip";

	std::string snapshotPath = TCHAR_TO_UTF8(*OutputPath);

	snapshotPath += "Snapshots/";
	snapshotPath += TCHAR_TO_UTF8(*snapName);

	std::string inArchivePath = TCHAR_TO_UTF8(*TopicGUID);
	inArchivePath += "/snapshot.png";

	ZipFile::AddFile(zipFullPath, snapshotPath, inArchivePath);
}
