/*
 * Leonardo Deliyannis Constantin
 * Implementação própria de BigInt
 */

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

typedef unsigned long long ull;

struct bigint{
	vector<ull> V;
	const int BASE = ((int)1e8);
private:
	int cmp(const bigint &other) const{
		int i;
		if(V.size() < other.V.size()) return -1;
		if(V.size() > other.V.size()) return  1;
		for(i = (int)V.size()-1; i >= 0 && V[i] == other.V[i]; i--);
		if(i == -1) return 0;
		return (V[i] < other.V[i]) ? -1 : 1;
	}
public:
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
		return true;
	}
	string toString(){
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
	bigint(){}
	bigint(const string &S){ fromString(S); }
};
