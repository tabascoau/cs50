#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


const char* alphabet = "abcdefghijklmnopqrstuvwxyz";
const int TEXT_MAX_LENGTH = 1000;
const int ALPHABET_MAX_LENGTH = 26;

class NumberHelper {
public:
	bool isPositive(int number) {
		bool result;
		return number > 0 ? result = true: result = false;
		return result;
	}

};

class CharacterHelper {
public:
	bool isCapitalLetter(char c) {
		return isupper(c) ? true : false;
	}
};

int main() {
	NumberHelper numberHelper;
	CharacterHelper characterHelper;
	char plaintext[TEXT_MAX_LENGTH];
	char ciphertext[TEXT_MAX_LENGTH];;
	int key = 1;
	printf("Please input key: ");
	scanf("%d", &key);
	getchar();
	if (!numberHelper.isPositive(key)) {
		printf("Input key is not a positive value");
		return -1;
	}
	
	printf("Please input plaintext: ");
	
	fgets(plaintext, sizeof(plaintext), stdin);
	for (int i = 0; i < TEXT_MAX_LENGTH; i++) {
		if (plaintext[i] == '\n') {
			break;
		}
		bool isUpperCase;
		if (characterHelper.isCapitalLetter(plaintext[i])) {
			isUpperCase = true;
		} else {
			isUpperCase = false;
		}
		for (int j = 0; j < ALPHABET_MAX_LENGTH; j++) {
			if (tolower(plaintext[i]) == tolower(alphabet[j])) {
				ciphertext[i] = alphabet[(j + key) % 26];
				break;
			}
		}
	}
	printf("Ciphertext: %s", ciphertext);

}