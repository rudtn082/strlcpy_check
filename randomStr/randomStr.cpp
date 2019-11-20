#include <iostream>
#include <string>
#include <time.h>
#include <Math.h>
//#define MAX_SIZE 10000
using namespace std;

size_t
strlcpy(char *dst, const char *src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;

	if (n != 0) {
		while (--n != 0) {
			if ((*d++ = *s++) == '\0')
				break;
		}
	}

	if (n == 0) {
		if (siz != 0)
			*d = '\0';
		while (*s++)
			;
	}

	return(s - src - 1);
}

size_t
strlcpy2(char* dst, const char* src, size_t siz)
{
	size_t srclen, returnV = strlen(src);

	siz--;

	srclen = returnV;

	if (srclen > siz)
		srclen = siz;

	memcpy(dst, src, srclen);
	dst[srclen] = '\0';

	return returnV;
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
	time_t start, end;
	double result;

	int MAX_SIZE = 1000;


	string Str;
	char carray[100];

	for (int j = 0; j < 100; ++j) // 문자열의 길이는 10000
	{
		Str += genRandom();
	}

	for (int i = 1; i < 7; i++) {
		cout << "횟수 = " << MAX_SIZE << endl;

		start = clock(); //시간 측정 시작

		for (int i = 0; i < MAX_SIZE; ++i) {

			strlcpy(carray, Str.c_str(), sizeof(carray));
		}

		end = clock(); //시간 측정 끝
		result = (double)(end - start) / CLOCKS_PER_SEC;

		cout << "기존 strlcpy = " << result << "초" << endl;

		////////////////////////////////////////////////// 2번째 방법

		start = clock(); //시간 측정 시작

		for (int i = 0; i < MAX_SIZE; ++i) {

			strlcpy2(carray, Str.c_str(), sizeof(carray));
		}

		end = clock(); //시간 측정 끝
		result = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "변경 strlcpy = " << result << "초" << endl;



		MAX_SIZE = MAX_SIZE * 5;
		cout << endl;
	}

	system("pause");
	return 0;
}