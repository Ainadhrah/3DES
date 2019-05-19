#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class sheet
{
public:
	int PC_1[65] ={0,58,50,42,34,26,18,10,2,
							60,52,44,36,28,20,12,4,
							62,54,46,38,30,22,14,6,
							64,56,48,40,32,24,16,8,
							57,49,41,33,25,17,9,1,
							59,51,43,35,27,19,11,3,
							61,53,45,37,29,21,13,5,
							63,55,47,39,31,23,15,7	};
	int PC_1_1[65]={0, 40,8,48,16,56,24,64,32,
								39,7,47,15,55,23,63,31,
								38,6,46,14,54,22,62,30,
								37,5,45,13,53,21,61,29,
								36,4,44,12,52,20,60,28,
								35,3,43,11,51,19,59,27,
								34,2,42,10,50,18,58,26,
								33,1,41,9,49,17,57,25 };
};

int* left(int a[],int num)
{
	int tmp = a[0];
	for (int l = 0; l < num; l++) {
		if (l == num - 1) a[l] = tmp;
		else a[l] = a[l + 1];
	}
	return a;
}

int* right(int a[],int num)
{
	int tmp = a[num-1];
	for (int R = num-1; R >= 0; R--) {
		if (R == 0) a[R] = tmp;
		else a[R] = a[R - 1];
	}
	return a;
}


int main()
{
	//check whether the PC sheets are correct or not
	class sheet mySheet;
	for (int i = 1; i <= 64; i++) {
		if ( i != mySheet.PC_1_1[mySheet.PC_1[i]])cout << mySheet.PC_1[i]<<'\t'<<mySheet.PC_1_1[i]<<'\t'<<i<<endl;
	}

	int K[65] = { 0 };						// K 64
	int k[56] = { 0 };						// k 56
	int num = 1;							// counter
	int C0[28] = { 0 };					// C0 28
	int D0[28] = { 0 };					// D0 28
	
	
	srand(time(0));

	//initialize K with rand
	while (num++<=64) {
		K[num] = rand() % 2;
		cout << K[num];
	}
	cout << endl;
	
	//get k from K
	for (int i1 = 1, i2 = 0; i1 <= 64;i2++, i1++) {
		if (i1 == 8 || i1 == 16 || i1 == 24 || i1 == 32 || i1 == 40 || i1 == 48 || i1 == 56 || i1 == 64) i2--;
		else {
			k[i2] = K[i1];
			cout <<i2 <<'\t'<<k[i2]<<endl;
		}
	}

	//get C0 and D0
	for (int i3 = 0; i3 < 28; i3++) {
		C0[i3] = k[i3];
		cout << C0[i3];
		D0[i3] = k[28 + i3];
	}
	cout << endl;
	int* C1 = right(C0,28);
	for (int i4 = 0; i4 < 28; i4++) {
		cout << C1[i4];
	}

	system("pause");
	return 0;
}