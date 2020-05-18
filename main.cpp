#include <iostream>
#include "sound.h"



int main() {
	std::string str;
	std::cin >> str;

	std::vector<int> melody = StrToMelody(str);
	FILE* f = freopen("test.pcm", "w", stdout);
	for (int i = 0; i != melody.size(); ++i) {
		std::vector<UCHAR> bytes = chord(melody[i]);
		for (int i = 0; i != bytes.size(); ++i)
			std::cout << bytes[i];
		std::cout << std::endl;
	}
	fclose(f);

	PcmToWav("test.pcm");

}