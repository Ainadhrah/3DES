#include <iostream>
//#include <string>
#include <ctime>
using namespace std;

class sheet
{
public:
	int IP[65] = { 0,58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,
							62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,
							57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,
							61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7 };
	int reIP[65] = { 0, 40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,
								38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,
								36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,
								34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25 };
	int PC_1[65] = { 0,57,49,41,33,25,17,9,1,58,50,42,34,26,18,
								10,2,59,51,43,35,27,19,11,3,60,52,44,36,
								63,55,47,39,31,23,15,7,62,54,46,38,30,22,
								14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
	int PC_2[65] = { 0,14,17,11,24,1,5,3,28,15,6,21,10,
								23,19,12,4,26,8,16,7,27,20,13,2,
								41,52,31,37,47,55,30,40,51,45,33,48,
								44,49,39,56,34,53,46,42,50,36,29,32 };
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
	int tmp = a[num];
	for (int R = num; R >= 0; R--) {
		if (R == 1) a[R] = tmp;
		else a[R] = a[R - 1];
	}
	return a;
}


int main()
{
	//check whether the PC sheets are correct or not
	class sheet mySheet;
	for (int i = 1; i <= 64; i++) {
		if ( i != mySheet.reIP[mySheet.IP[i]])cout << mySheet.IP[i]<<'\t'<<mySheet.reIP[i]<<'\t'<<i << "get some trouble" <<endl;
	}

	int m[65] = { 0 };					// m 64bit with a useless bit
	int M[65] = { 0 };					// M 64bit with a useless bit and IP from m

	int K[65] = { 0 };						// K 64bit
	int k_PC[65] = { 0 };				// k_PC 64bit (mixed)
	int k[57] = { 0 };						// k 56bit
	int k1[57] = { 0 };					// k1 56bit (combination of C1 and D1
	int num = 1;							// counter
	int C0[29] = { 0 };					// C0 28bit
	int D0[29] = { 0 };					// D0 28bit
	int* C1 = NULL;						// C1 28bit (right shifted)
	int* D1 = NULL;						// D1 28bit (right shifted)
	
	srand(time(0));						//Initialization of seed

	//Initialization of m with random number
	cout << "m = ";
	for (num = 1; num <= 64; num++) {
		m[num] = rand() % 2;
		cout << m[num];
	}
	cout << endl;

	//Get M from m with PC
	cout << "M = ";
	for (num = 1; num <= 64; num++) {
		M[mySheet.IP[num]] = m[num];
	}
	for (num = 1; num <= 64; num++) {
		cout << M[num];
	}
	cout << endl;
	//The part of M has exceeded successfully



	//initialize K with rand
	cout << "Key( 64bit ) = ";
	for (num = 1; num <= 64; num++) {
		K[num] = rand() % 2;
		cout << K[num];
	}
	cout << endl;
	
	//Initial replacement with PC_1
	for (num = 1; num <= 64; num++) {
		k_PC[mySheet.PC_1[num]] = K[num];
	}
	cout << "k after PC_1 = ";
	for (num = 1; num <= 64; num++) {
		cout << k_PC[num];
	}
	cout << endl;

	//get k from k_PC
	for (int i1 = 1, i2 = 1; i1 <= 64;i2++, i1++) {
		if (i1 % 8 == 0) i2--;
		else {
			k[i2] = k_PC[i1];
		}
	}
	
	//Get C0 and D0
	for (int i3 = 1; i3 <= 28; i3++) {
		C0[i3] = k[i3];
		D0[i3] = k[28 + i3];
	}
	cout << endl;

	cout << "C0 = ";
	for (int i3 = 1; i3 <= 28; i3++) {
		cout << C0[i3];
	}
	cout << "\nD0 = ";
	for (int i3 = 1; i3 <= 28; i3++) {
		cout << D0[i3];
	}
	cout << endl;

	//Right shifting of C0 and D0
	C1 = right(C0, 28);
	cout << "\nC1 = ";
	for (num = 1; num <= 28; num++) {
		cout << C1[num];
	}
	D1 = right(D0, 28);
	cout << "\nD1 = ";
	for (num = 1; num <= 28; num++) {
		cout << D1[num];
	}
	//Combine C1 and D1
	for (num = 1; num <= 28; num++) {
		k1[num] = C1[num];
		k1[num + 28] = D1[num];
	}
	cout << endl;
	for (num = 1; num <= 56; num++) {
		cout << k1[num];
	}

	//for (int i4 = 1; i4 <= 28; i4++) {
	//	cout << C1[i4];
	//}

	cout << endl;
	system("pause");
	return 0;
}