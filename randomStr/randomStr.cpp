#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

#define MAX_SIZE 100000

size_t
strlcpy(char* dst, const char* src, size_t siz)
{
	char* d = dst;
	const char* s = src;
	size_t n = siz;
	/* Copy as many bytes as will fit */
	if (n != 0) {
		while (--n != 0) {
			if ((*d++ = *s++) == '\0')
				break;
		}
	}
	/* Not enough room in dst, add NUL and traverse rest of src */
	if (n == 0) {
		if (siz != 0)
			* d = '\0';		/* NUL-terminate dst */
		while (*s++)
			;
	}
	return(s - src - 1);	/* count does not include NUL */
}

static const char alphanum[] =
"0123456789"
"!@#$%^&* "
"'.;:,/\|][{}"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()
{
	return alphanum[rand() % stringLength];
}

int main() {
	ofstream outFile("output.txt");

	srand(time(0));
	string Str;
	char carray[30];
	string istrue = "false";

	int trueN = 0, falseN = 0;
	for (int i = 0; i < MAX_SIZE; ++i) {
		int temp = (rand() % 30); // 문자열의 길이는 0 ~ 30
		
		// temp 길이만큼 랜덤 문자열 생성
		for (int j = 0; j < temp; ++j)
		{
			Str += genRandom();
		}

		outFile << "문자열 = " << Str << endl << "길이 = " << Str.length() << endl;
		//// strlcpy 비교 ////
		if (strlcpy(carray, Str.c_str(), sizeof(carray)) == strlen(Str.c_str())) {
			istrue = "true";
			trueN++;
		}
		else {
			istrue = "false";
			falseN++;
		}
		outFile << istrue << endl << endl;

		// 초기화
		Str = "";
		istrue = "false";
	}

	outFile << endl << "if문 true 횟수 : " << trueN << endl << "if문 false 횟수 : " << falseN << endl;

	outFile.close();

	cout << MAX_SIZE << "번 완료" << endl;
	cout << "if문 true 횟수 : " << trueN << endl << "if문 false 횟수 : " << falseN << endl;

	return 0;
}