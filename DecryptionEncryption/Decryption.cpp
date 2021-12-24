#include "stdafx.h"
#include "Encryption.hpp"
#include "Decryption.hpp"
#include <fstream>

void Decryption(const char* InputFile, const char* OutputFile, const char* FileWithKey)
{
	Encryption(InputFile, OutputFile, FileWithKey);
}