#include "stdafx.h"
#include "Encryption.hpp"
#include <fstream>

void Encryption(const char* InputFile, const char* OutputFile, const char* FileWithKey)
{
	char Source{};
	char Key{};
	char Result{};

	std::ifstream inputSource(InputFile, std::ios_base::binary);
	if (!inputSource.is_open())
		return;

	std::ifstream inputKey(FileWithKey, std::ios_base::binary);
	if (!inputKey.is_open())
		return;

	std::ofstream outputCrypted(OutputFile, std::ios_base::binary);
	if (!outputCrypted.is_open())
	{
		inputSource.close();
		return;
	}


	Source = (char)inputSource.get();
	Key = (char)inputKey.get();

	while (!inputSource.eof())
	{
		Result = Source ^ Key;
		outputCrypted.put(Result);
		Source = (char)inputSource.get();
		Key = (char)inputKey.get();
	}

	inputSource.close();
	inputKey.close();
	outputCrypted.close();
}