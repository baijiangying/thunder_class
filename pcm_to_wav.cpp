#include <iostream>
#include "sound.h"

std::string GetName(const char* f) {
	std::string name;
	for (int i = 0; f[i] != '\0' && f[i] != '.'; ++i)
		name += f[i];

	return name;
}

bool GetHeader(std::vector<UCHAR>& buf) {
	//chunk id
	buf[0] = 'R';
	buf[1] = 'I';
	buf[2] = 'F';
	buf[3] = 'F';
	int pcmLen = buf.size() - 44;
	int chunkSize = pcmLen + 36;

	//chunk size
	buf[4] = (UCHAR)(chunkSize & 0xff);
	buf[5] = (UCHAR)((chunkSize >> 8) & 0xff);
	buf[6] = (UCHAR)((chunkSize >> 16) & 0xff);
	buf[7] = (UCHAR)((chunkSize >> 24) & 0xff);

	//format
	buf[8] = 'W';
	buf[9] = 'A';
	buf[10] = 'V';
	buf[11] = 'E';

	//subchunk1 id
	buf[12] = 'f';
	buf[13] = 'm';
	buf[14] = 't';
	buf[15] = ' ';

	//subchunk1 size
	buf[16] = 16;
	buf[17] = 0;
	buf[18] = 0;
	buf[19] = 0;

	//audio format
	buf[20] = 1;
	buf[21] = 0;

	//numChannels
	buf[22] = 1;
	buf[23] = 0;

	//sample rate
	int sampleRate = 10000;
	buf[24] = (UCHAR)(sampleRate & 0xff);
	buf[25] = (UCHAR)((sampleRate >> 8) & 0xff);
	buf[26] = (UCHAR)((sampleRate >> 16) & 0xff);
	buf[27] = (UCHAR)((sampleRate >> 24) & 0xff);

	int blockAlign = 1;
	int byteRate = sampleRate * blockAlign;
	//byte rate
	buf[28] = (UCHAR)(byteRate & 0xff);
	buf[29] = (UCHAR)((byteRate >> 8) & 0xff);
	buf[30] = (UCHAR)((byteRate >> 16) & 0xff);
	buf[31] = (UCHAR)((byteRate >> 24) & 0xff);

	//blockAlign
	buf[32] = blockAlign;
	buf[33] = 0;

	//bits per sample
	int bitPerSample = 8;
	buf[34] = bitPerSample;
	buf[35] = 0;

	//subchunk2 id
	buf[36] = 'd';
	buf[37] = 'a';
	buf[38] = 't';
	buf[39] = 'a';

	//subchunk2 size
	buf[40] = (UCHAR)(pcmLen & 0xff);
	buf[41] = (UCHAR)((pcmLen >> 8) & 0xff);
	buf[42] = (UCHAR)((pcmLen >> 16) & 0xff);
	buf[43] = (UCHAR)((pcmLen >> 24) & 0xff);

	return true;

}


bool PcmToWav(const char* file) {
	std::vector<UCHAR> res(44);
	FILE* f = freopen(file, "r", stdin);
	UCHAR byte;
	while (std::cin >> byte) 
		res.push_back(byte);
	fclose(f);

	GetHeader(res);
	std::string fileName = GetName(file);
	char name[256];
	int cur = 0;
	while (cur != fileName.size()) {
		name[cur] = fileName[cur];
		++cur;
	}
	name[cur++] = '.';
	name[cur++] = 'w';
	name[cur++] = 'a';
	name[cur++] = 'v';
	name[cur] = '\0';

	f = freopen(name, "w", stdout);
	for (int i = 0; i != res.size(); ++i)
		std::cout << res[i];
	std::cout << std::endl;
	fclose(f);
	return true;
}

