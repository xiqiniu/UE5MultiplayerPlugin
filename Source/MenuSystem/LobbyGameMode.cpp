// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include"GameFramework/GameStateBase.h"
#include"GameFramework/PlayerState.h"
void ALobbyGameMode::PostLogin(APlayerController *NewPlayer)
{
	Super::PostLogin(NewPlayer);
	GEngine->AddOnScreenDebugMessage(1, 600.f, FColor::Yellow, FString::Printf(TEXT("Players in game: 0")));

	if (GameState)
	{
		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1, 600.f, FColor::Yellow, FString::Printf(TEXT("Players in game: %d"), NumberOfPlayers));

			APlayerState *PlayerState = NewPlayer->GetPlayerState<APlayerState>();
			if (PlayerState)
			{
				FString PlayerName = PlayerState->GetPlayerName();
				GEngine->AddOnScreenDebugMessage(2, 60.f, FColor::Cyan, FString::Printf(TEXT("%s has joined the game!"), *PlayerName));
			}
		}
	}
}

void ALobbyGameMode::Logout(AController *Exiting)
{
	Super::Logout(Exiting);

	APlayerState *PlayerState = Exiting->GetPlayerState<APlayerState>();
	if (PlayerState)
	{
		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
		if (GEngine)
		{
			// 调用logout的时候玩家还在,这里-1只是为了测试,正式项目要换
			GEngine->AddOnScreenDebugMessage(1, 600.f, FColor::Yellow, FString::Printf(TEXT("Players in game: %d"), NumberOfPlayers - 1));
			FString PlayerName = PlayerState->GetPlayerName();
			GEngine->AddOnScreenDebugMessage(2, 60.f, FColor::Cyan, FString::Printf(TEXT("%s has exited the game!"), *PlayerName));
		}
	}
}
