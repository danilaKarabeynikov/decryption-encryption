#include "pch.h"
#include <fstream>
#include "..\Let3Karabejnikov\Encryption.hpp"
#include "..\Let3Karabejnikov\Decryption.hpp"

TEST(Encryption, CryptedPhraseShouldBeEqualWithSource)
{
	Encryption("Source.txt", "CryptedPhrase.txt", "Key.txt");
	Decryption("CryptedPhrase.txt", "DecryptedPhrase.txt", "Key.txt");
	std::ifstream inputSource("Source.txt", std::ios_base::binary);
	std::ifstream inputDeCryptedPhrase("DeCryptedPhrase.txt", std::ios_base::binary);

	char c = (char)inputDeCryptedPhrase.get();
	char g = (char)inputSource.get();

	while (!inputSource.eof() && !inputDeCryptedPhrase.eof())
	{
		ASSERT_EQ(c, g);
		c = (char)inputDeCryptedPhrase.get();
		g = (char)inputSource.get();
	}

	inputSource.close();
	inputDeCryptedPhrase.close();
}