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
		int temp = (rand() % 30); // ���ڿ��� ���̴� 0 ~ 30
		
		// temp ���̸�ŭ ���� ���ڿ� ����
		for (int j = 0; j < temp; ++j)
		{
			Str += genRandom();
		}

		outFile << "���ڿ� = " << Str << endl << "���� = " << Str.length() << endl;
		//// strlcpy �� ////
		if (strlcpy(carray, Str.c_str(), sizeof(carray)) == strlen(Str.c_str())) {
			istrue = "true";
			trueN++;
		}
		else {
			istrue = "false";
			falseN++;
		}
		outFile << istrue << endl << endl;

		// �ʱ�ȭ
		Str = "";
		istrue = "false";
	}

	outFile << endl << "if�� true Ƚ�� : " << trueN << endl << "if�� false Ƚ�� : " << falseN << endl;

	outFile.close();

	cout << MAX_SIZE << "�� �Ϸ�" << endl;
	cout << "if�� true Ƚ�� : " << trueN << endl << "if�� false Ƚ�� : " << falseN << endl;

	return 0;
}