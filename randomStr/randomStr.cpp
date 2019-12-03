#include <iostream>
#include <time.h>
using namespace std;

// 개선 전 소스코드
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

// 개선 후 소스코드
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

	for (int j = 0; j < 100; ++j)
	{
		Str += genRandom();
	}

	for (int i = 1; i < 7; i++) {
		cout << "횟수 = " << MAX_SIZE << endl;

		start = clock();

		for (int i = 0; i < MAX_SIZE; ++i) {

			strlcpy(carray, Str.c_str(), sizeof(carray));
		}

		end = clock();
		result = (double)(end - start) / CLOCKS_PER_SEC;

		cout << "기존 strlcpy = " << result << "초" << endl;

		start = clock();

		for (int i = 0; i < MAX_SIZE; ++i) {

			strlcpy2(carray, Str.c_str(), sizeof(carray));
		}

		end = clock();
		result = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "개선 strlcpy = " << result << "초" << endl;

		MAX_SIZE = MAX_SIZE * 5;
		cout << endl;
	}

	system("pause");
	return 0;
}