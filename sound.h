#ifndef SOUND_H
#define SOUND_H

#include <vector>
#include <string>

#include "type_def.h"

const int sampleFrequency = 10000;
const int fre[] = {440, 494, 262, 294, 330, 349, 392};


std::vector<UCHAR> chord(int fre, int volume = 50);
std::vector<int> StrToMelody(std::string& s);

std::string GetName(const char* f);
bool GetHeader(std::vector<UCHAR>& buf);
bool PcmToWav(const char* file);





#endif