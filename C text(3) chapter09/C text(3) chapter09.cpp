#include<stdio.h>

#define _0901


#ifdef _0901
int main(void) {
	int ch = 0;
	char name[20]{};

	printf("名前を入力してください : ");
	scanf_s("%s", &name, 20);

	printf("よろしいですか (Y / N) : ");

	ch = getchar();
	if (ch == 'Y' || ch == 'y') {
		printf("こんにちは%sさん。\n", name);
	}
	return 0;
}
#endif

//Visual Studio 2022では動作しない
#ifdef _0902
int main(void) {
	int ch = 0;
	char name[20]{};

	printf("名前を入力してください : ");
	scanf_s("%s", &name, 20);

	printf("よろしいですか (Y / N) : ");

	fflush(stdin);

	ch = getchar();
	if (ch == 'Y' || ch == 'y') {
		printf("こんにちは%sさん。\n", name);
	}

	return 0;
}
#endif

#ifdef _0903
#include<ctype.h>

int check() {
	int ch = 0;
	while (isspace(ch = getchar()) && ch != EOF);
	return ch;
}

int main(void) {
	int ch = 0;
	char name[20]{};

	printf("名前を入力してください : ");
	scanf_s("%s", &name, 20);

	printf("よろしいですか (Y / N) : ");
	
	ch = check();
	if (ch == 'Y' || ch == 'y') {
		printf("こんにちは%sさん。\n", name);
	}

	return 0;
}
#endif

#ifdef _0904
#include<ctype.h>

int getnschar() {
	int ch = 0;
	while (isspace(ch = getchar()) && ch != EOF);
	return ch;
}

int check() {
	int ch = 0;
	while ((ch = getnschar()) != EOF) {
		if (ch == 'Y' || ch == 'y') return 1;
		if (ch == 'N' || ch == 'n') return 0;
	}

	return EOF;
}

int main(void) {
	int ch = 0;
	char name[20]{};

	printf("名前を入力してください : ");
	scanf_s("%s", &name, 20);

	printf("よろしいですか (Y / N) : ");
	ch = check();
	
	if (ch == 1) {
		printf("こんにちは%sさん。\n", name);
	}

	return 0;
}
#endif

#ifdef _0905
int main(void) {
	FILE* fp = nullptr;
	int no = 514;

	fopen_s(&fp, "TEST_TEXT", "w");
	if (fp != NULL) {
		fprintf(fp, "%d", no);
		fclose(fp);
		printf("○\n");
	}
	else printf("\a×\n");

	return 0;
}
#endif

#ifdef _0906
int main(void) {
	FILE* fp;
	int no = 514;

	fopen_s(&fp, "TEST_BIN", "wb");
	if (fp != NULL) {
		fwrite(&no, sizeof(int), 1, fp);
		fclose(fp);
		printf("○\n");
	}
	else printf("\a×\n");
	
	return 0;
}
#endif

#ifdef _0907
#include<ctype.h>

void dump(FILE* src, FILE* dst) {
	int n = 0;
	unsigned long count = 0;
	unsigned char buf[16]{};

	while ((n = fread(buf, 1, 16, src)) > 0) {
		int i = 0;

		fprintf(dst, "%08lX", count);
		for (i = 0; i < n; i++) fprintf(dst, "%02X ", (unsigned)buf[i]);
		if (n < 16) {
			for (i = n; i < 16; i++) fputs("   ", dst);
		}
		for (i = 0; i < n; i++) fputc(isprint(buf[i]) ? buf[i] : '.', dst);
		fputc('\n', dst);
		count += 16;
	}
	fputc('\n', dst);
}

int main(int argc, char *argv[]) {
	FILE* fp = nullptr;

	if (argc < 2) fputs("ファイルを指定してください。\n", stderr);
	else {
		while (--argc > 0) {
			fopen_s(&fp, *++argv, "rb");
			if (fp == NULL) {
				fprintf(stderr, "ファイル%sが開けませんでした。\n", *argv);
				return 1;
			}
			else {
				dump(fp, stdout);
				fclose(fp);
			}
		}
	}

}
#endif

#ifdef _0908
#define MAX 10

int main(void) {
	FILE* fp = nullptr;
	int x = 2573;
	int y = 12609;
	int a[MAX] = { 0,1,2,3,4,5,6,7,8,9 };

	fopen_s(&fp, "TEMP", "wb");
	if (fp != NULL) {
		fwrite(a, sizeof(int), MAX, fp);
		fwrite(&x, sizeof(int), 1, fp);
		fwrite(&y, sizeof(int), 1, fp);
		fclose(fp);

		x = y = 0;
		for (int i = 0; i < MAX; i++) a[i] = 0;

		fopen_s(&fp, "TEMP", "rb");
		if (fp != NULL) {
			fread(a, sizeof(int), MAX, fp);
			fread(&x, sizeof(int), 1, fp);
			fread(&y, sizeof(int), 1, fp);
			fclose(fp);

			for (int i = 0; i < MAX; i++) printf("a[%d] = %d\n", i, a[i]);
			printf("x = %d\n", x);
			printf("y = %d\n", y);
		}
	}

	return 0;
}
#endif

#ifdef _0909
#define MAX 10

int main(void) {
	FILE* fp = nullptr;
	int x = 0, y = 0;
	int a[MAX]{};

	fopen_s(&fp, "TEMP", "r");
	if (fp != NULL) {
		fread(a, sizeof(int), MAX, fp);
		fread(&x, sizeof(int), 1, fp);
		fread(&y, sizeof(int), 1, fp);
		fclose(fp);

		for (int i = 0; i < MAX; i++) printf("a[%d] = %d\n", i, a[i]);
		printf("x = %d\n", x);
		printf("y = %d\n", y);
	}

	return 0;
}
#endif