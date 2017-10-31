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

void printBigSum(const bigint &n1, const bigint &n2){
	printf("%s + %s = ", n1.toString().c_str(), n2.toString().c_str());
	printf("%s\n", (n1+n2).toString().c_str());
}

void readBigInt(bigint &b){
	char buf[LEN];
	fgets(buf, LEN, stdin);
	buf[strlen(buf) - 1] = 0;
	b.fromString(buf);
}

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
	//assert(I1.toString() == s1);
	bigint I2(buf);
	//assert(I2.toString() == s2);
	printf("Printing bigint I1:\n");
	printf("%s\n\n", I1.toString().c_str());
	printf("Printing bigint I2:\n");
	printf("%s\n\n", I2.toString().c_str());
	printf("I1 < I2: %s\n",  I1  < I2 ? "true" : "false");
	printf("I1 == I2: %s\n", I1 == I2 ? "true" : "false");
	printf("I1 > I2: %s\n\n",  I1  > I2 ? "true" : "false");
	
	assert(I1 == I1);
	assert(I2 == I2);
	
	printf("I2 < I1: %s\n",  I2  < I1 ? "true" : "false");
	printf("I2 == I1: %s\n", I2 == I1 ? "true" : "false");
	printf("I2 > I1: %s\n\n",  I2  > I1 ? "true" : "false");
	
	printf("Copying bigint I1 to I3...\n\n");
	bigint I3 = I1;
	assert(I3 == I1);

	printf("BigInt sum examples\n");
	bigint n1("0000000000000000000000000000000000038291"), n2("342042");
	assert((n1+n2).toString() == "380333");
	printBigSum(n1, n2);
	bigint n3, n4;
	readBigInt(n3);
	readBigInt(n4);
	printBigSum(n3, n4);
	/*
	bigint quoc, mod;
	quoc = I1 / I2;
	mod = I1 % I2;
	quoc.print();
	mod.print();
	*/
	return 0;
}
