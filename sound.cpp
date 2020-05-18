#include <cmath>
#include "sound.h"

std::vector<UCHAR> chord(int fre, int volume) {
	std::vector<UCHAR> ans;
	int sample = sampleFrequency / fre;
	for (int i = 0; i != sampleFrequency; ++i) {
		double t = (double)(i % sample) / sample * 2 * M_PI;
		UCHAR altitude = 128 + volume * sin(t);
		ans.push_back(altitude);
	}

	return ans;
}



std::vector<int> StrToMelody(std::string& s) {
	std::vector<int> m;
	for (int i = 0; i != s.size(); ++i) {
		char c = tolower(s[i]);
		m.push_back(fre[c - 'a']);
	}

	return m;
}
