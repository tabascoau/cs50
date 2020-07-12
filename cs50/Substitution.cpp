#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

const int KEY_SIZE = 26;
const int MAX_ARRAY_SIZE = 1000;
const char* alphabeticText = "abcdefghijklmnopqrstuvwxyz";

class CipherKeyHelper {
public:
	int getCipherKeyLength(char* cipherKey) {
		int index = 0;
		int length = 0;
		while (cipherKey[index + 1] != '\0') {
			index++;
			length++;
		}
		return length;
	}

	bool isCipherKeyAppearExactlyOnce(char* cipherKey) {
		bool checkArr[KEY_SIZE];
		for (int i = 0; i < KEY_SIZE; i++) {
			checkArr[i] = false;
		}

		for (int i = 0; i < KEY_SIZE; i++) {
			for (int j = 0; j < KEY_SIZE; j++) {
				if (tolower(cipherKey[i]) == tolower(alphabeticText[j]) && checkArr[j]) {
					return false;
				}
				else {
					checkArr[j] = true;
				}
			}
		}
		return true;

	}

	bool checkIsCipherKeyAlphabetic(char* cipherKey) {
		for (int i = 0; i < KEY_SIZE; i++) {
			if (!isalpha(cipherKey[i])) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	CipherKeyHelper cipherKeyHelper;
	char key[MAX_ARRAY_SIZE];
	char plainText[MAX_ARRAY_SIZE];
	char cipherText[MAX_ARRAY_SIZE];
	printf("substitution program\n");
	printf("Please input substitution key: ");
	fgets(key, sizeof(key), stdin);
	if (cipherKeyHelper.getCipherKeyLength(key) != KEY_SIZE) {
		printf("ERR: KEY SIZE IS NOT 26");
		return -1;
	}
	if (!cipherKeyHelper.checkIsCipherKeyAlphabetic(key)) {
		printf("ERR: KEY IS NOT ALL ALPHABETIC");;
		return -1;
	}
	if (!cipherKeyHelper.isCipherKeyAppearExactlyOnce(key)) {
		printf("ERR: IS NOT APPEAR EXACTLY ONCE");
		return -1;
	}
	printf("plaintext: ");
	fgets(plainText, sizeof(plainText), stdin);
	for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
		if (plainText[i] == '\n') {
			break;
		}
		bool isUpperCase;
		if (isupper(plainText[i])) {
			isUpperCase = true;
		}
		else {
			isUpperCase = false;
		}
		for (int j = 0; j < KEY_SIZE; j++) {
			if (tolower(plainText[i]) == tolower(key[j])) {
				if (isUpperCase) {
					cipherText[i] = toupper(alphabeticText[j]);
				}
				else {
					cipherText[i] = alphabeticText[j];
				}
				break;
			}
		}
	}
	printf("\n");
	printf("Ciphertext: %s", cipherText);



}