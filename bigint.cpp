/*
 * Leonardo Deliyannis Constantin
 * Implementação própria de BigInt
 */

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

struct bigint{
	vector<ull> V;
private:
	const int BASE = ((int)1e8);
	int cmp(const bigint &other) const{
		int i;
		if(V.size() < other.V.size()) return -1;
		if(V.size() > other.V.size()) return  1;
		for(i = (int)V.size()-1; i >= 0 && V[i] == other.V[i]; i--);
		if(i == -1) return 0;
		return (V[i] < other.V[i]) ? -1 : 1;
	}
public:
	void trimZeroes(){
		int i;
		for(i = (int)V.size()-1; i >= 0 && V[i] == 0; i--);
		V.resize((i == -1) ? 1 : (i + 1));
	}
	bool fromString(const string &S){
		int i, j, pot;
		i = (int)S.size() - 1;
		if(S.back() == '\n') i--;
		if(i == -1)
			return false;
		V.clear();
		while(i >= 0){
			pot = 1;
			V.push_back(0);
			for(j = 1; j <= 8 && i >= 0; j++, i--){
				V[V.size()-1] += pot*(S[i] - '0');
				pot *= 10;
			}
		}
		trimZeroes();
		return true;
	}
	bigint(){ fromString("0"); }
	bigint(const string &S){ fromString(S); }
	string toString() const{
		int i;
		char buf[11];
		string ret;
		sprintf(buf, "%llu", V.back());
		ret.append(buf);
		for(i = (int)V.size()-2; i >= 0; i--){
			sprintf(buf, "%08llu", V[i]);
			ret.append(buf);
		}
		return ret;
	}
	bool operator  <(const bigint &other) const{ return cmp(other) < 0; }
	bool operator ==(const bigint &other) const{ return cmp(other) == 0; }
	bool operator  >(const bigint &other) const{ return cmp(other) > 0; }
	void operator  =(const bigint &other){ V = other.V; }
	bigint operator +(const bigint &other) const{
		int i, t1 = (int)V.size(), t2 = (int)other.V.size();
		ull carry = 0, val1, val2;
		bigint ret;
		ret.V.assign(max(t1, t2), 0);
		for(i = 0; i < t1 || i < t2; i++){
			val1 = i < t1 ? V[i] : 0;
			val2 = i < t2 ? other.V[i] : 0;
			ret.V[i] = val1 + val2 + carry;
			carry = ret.V[i] / BASE;
			ret.V[i] %= BASE;
		}
		ret.V[i] = carry;
		ret.trimZeroes();
		return ret;
	}
};
