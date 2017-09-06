/*
 * Leonardo Deliyannis Constantin
 * Driver program to test bigint.cpp
 */

#include "bigint.cpp"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
using namespace std;
#define LEN 1123

int main(){
	string s1, s2;
	char buf[LEN];
	fgets(buf, LEN, stdin);
	buf[strlen(buf) - 1] = 0;
	s1 = buf;
	fgets(buf, LEN, stdin);
	buf[strlen(buf) - 1] = 0;
	s2 = buf;
	bigint I1(s1);
	assert(I1.toString() == s1);
	bigint I2(buf);
	assert(I2.toString() == s2);
	printf("Printing bigint I1:\n");
	printf("%s\n\n", I1.toString().c_str());
	printf("Printing bigint I2:\n");
	printf("%s\n\n", I2.toString().c_str());
	/*
	bigint quoc, mod;
	quoc = I1 / I2;
	mod = I1 % I2;
	quoc.print();
	mod.print();
	*/
	return 0;
}
