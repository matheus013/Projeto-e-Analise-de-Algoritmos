#include <bits/stdc++.h>

using namespace std;

int mdc(int a,int b){
	if(b == 0) return a;
	return mdc(b,a%b);
}

int main(int argc, char const *argv[]) {
	int a,b;
	cin >> a >> b;
	cout << mdc(a,b) << endl;
	return 0;
}