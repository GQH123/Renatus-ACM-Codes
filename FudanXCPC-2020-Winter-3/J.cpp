#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	//freopen("J.in", "r", stdin);
	int T;
	scanf("%d", &T);
	int price;
	while (T--){
		scanf("%d", &price);
		double output = price * 1.15;
		cout << fixed << setprecision(2)<< output << endl;
	}
	return 0;
}

