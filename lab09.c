#include <stdio.h>
#include <stdlib.h>

//Doesn't print but puts bits into a string array
void print_binary(int n, char bits[], int i);
// Puts converted bits into string array
void print_binaryL(long n, int i, char bits[]);

int main(int argc, char * argv[]) {
	if (argv[1][1] == 'f') {
		//Union contains an float a and an int b
		union flt {
			float a;
			int b;
		} flt;
		flt.a = atof(argv[2]);
		char bits[33] = {'0'};
		print_binary(flt.b, bits, 31);
		bits[32] = '\0';
		printf("%f encoded in binary using a 32 bit IEEE 754 encoding is below.\n", flt.a);
		printf("%s\n", bits);
		printf("sign bit:\t\t%c\n", bits[0]);
		int hold = bits[9];
		bits[9] = '\0';
		printf("exponent (8 bit):\t%s\n", bits + 1);
		bits[9] = hold;
		printf("fraction (23 bit):\t%s\n", bits + 9);

	}
	if (argv[1][1] == 'd') {
		// Union contains a double a and a long b
		union dub {
			double a;
			long b;
		} dub;
		dub.a = atof(argv[2]);
		char bits[65] = {'0'};
		print_binaryL(dub.b, 63, bits);
		bits[64] = '\0';
		printf("%lf encoded in binary using a 64 bit IEEE 754 encoding is below.\n", dub.a);
		printf("%s\n", bits);
		printf("sign bit:\t\t%c\n", bits[0]);
		int hold = bits[12];
		bits[12] = '\0';
		printf("exponent (11 bit):\t%s\n", bits + 1);
		bits[12] = hold;
		printf("fraction (52 bit):\t%s\n", bits + 12);

	}
	return 0;
}

// This code was inspired by a comment on stack overflow
// https://stackoverflow.com/a/27627015/22284459
void print_binary(int n, char bits[], int i) {
	if ((unsigned int) n >> 1) {
		print_binary((unsigned int) n >> 1, bits, i - 1);
	}
	bits[i] = n & 1 ? '1' : '0';
}
void print_binaryL(long n, int i, char bits[]) {
	if ((unsigned long) n >> 1) {
		print_binaryL((unsigned long) n >> 1, i - 1, bits);
	}
	bits[i] = n & 1 ? '1' : '0';
}
