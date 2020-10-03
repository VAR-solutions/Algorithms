#include<iostream>
#include<string>

// Store the original alphabets and the substitution alphabets
std::string orgAlphabet = "abcdefghijklmnopqrstuvwxyz";
std::string subAlphabet = "yhkqgvxfoluapwmtzecjdbsnri";

// Input text is compared on the basis of index 
// letter by letter , retrieve the index on basis
// of orgAlphabet and substitute it with the index
// at subAlphabet
inline void encryptText(std::string inputText)
{
    std::string output = "";
	if (orgAlphabet.size() != subAlphabet.size())
		return;

	for (uint8_t i = 0; i < inputText.size(); ++i)
	{
		uint8_t orgIdx = orgAlphabet.find(tolower(inputText[i]));

		if (orgIdx >= 0)
			output += isupper(inputText[i]) ? toupper(subAlphabet[orgIdx]) : subAlphabet[orgIdx];
		else
			output += inputText[i];
	}
    std::cout << output << std::endl;
	
}

// Take input text to encrypt as both lowecase and
// uppercase 
// EX: text (input)
//     jgnj (output)
int main()
{
    std::string inputText;
    std::cout << "Enter text to encrypt/Decrypt: " << "\n";
    std::cin >> inputText;
    encryptText(inputText);
    return 0; 
}
