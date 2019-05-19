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
	int PC_1[57] = { 0,57,49,41,33,25,17,9,1,58,50,42,34,26,18,
								10,2,59,51,43,35,27,19,11,3,60,52,44,36,
								63,55,47,39,31,23,15,7,62,54,46,38,30,22,
								14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
	int PC_2[49] = { 0,14,17,11,24,1,5,3,28,15,6,21,10,
								23,19,12,4,26,8,16,7,27,20,13,2,
								41,52,31,37,47,55,30,40,51,45,33,48,
								44,49,39,56,34,53,46,42,50,36,29,32 };
	int E[49] = { 0,32,1,2,3,4,5,4,5,6,7,8,9,
						8,9,10,11,12,13,12,13,14,15,16,17,
						16,17,18,19,20,21,20,21,22,23,24,25,
						24,25,26,27,28,29,28,29,30,31,32,1 };
	int P[33] = { 0,16,7,20,21,29,12,28,17,
						1,15,23,26,5,18,31,10,
						2,8,24,14,32,27,3,9,
						19,13,30,6,22,11,4,25 };
};

int* left(int a[], int num)
{
	int tmp = a[1];
	for (int l = 1; l <= num; l++) {
		if (l == num ) a[l] = tmp;
		else a[l] = a[l + 1];
	}
	return a;
}

int* right(int a[], int num)
{
	int tmp = a[num];
	for (int R = num; R >= 0; R--) {
		if (R == 1) a[R] = tmp;
		else a[R] = a[R - 1];
	}
	return a;
}

void half(int* T, int* t1, int* t2, int length)
{
	int num;//counter
	for (num = 1; num <= length / 2; num++) {
		t1[num] = T[num];
		t2[num] = T[num + length / 2];
	}
}

void replacePC_1(int* k, int* K, class sheet mySheet)
{
	int num;
	for (num = 1; num <= 56; num++) {
		k[num] = K[mySheet.PC_1[num]];
	}
}

void replacePC_2(int* k1, int *k2, class sheet mySheet)
{
	int num;
	for (num = 1; num <= 48; num++) {
		k2[num] = k1[mySheet.PC_2[num]];
	}
}

void combine(int* C1, int* D1, int* k1)
{
	int num;
	for (num = 1; num <= 28; num++) {
		k1[num] = C1[num];
		k1[num + 28] = D1[num];
	}
}


int main()
{
	//check whether the PC sheets are correct or not
	class sheet mySheet;
	for (int i = 1; i <= 64; i++) {
		if (i != mySheet.reIP[mySheet.IP[i]])cout << mySheet.IP[i] << '\t' << mySheet.reIP[i] << '\t' << i << "get some trouble" << endl;
	}

	int m[65] = { 0 };					// m 64bit with a useless bit
	int M[65] = { 0 };					// M 64bit with a useless bit and IP from m

	int K[65] = { 0 };						// K 64bit
	int k_PC[65] = { 0 };				// k_PC 64bit (mixed)
	int k[57] = { 0 };						// k 56bit
	int num = 1;							// counter
	int C0[29] = { 0 };					// C0 28bit
	int D0[29] = { 0 };					// D0 28bit
	int* C1 = NULL;						// C1 28bit (right shifted)
	int* D1 = NULL;						// D1 28bit (right shifted)
	int k1[57] = { 0 };					// k1 56bit (combination of C1 and D1
	int k2[49] = { 0 };					// k2 48bit (mixed k1)

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



	//Initialize K with rand
	cout << "Key( 64bit ) = ";
	for (num = 1; num <= 64; num++) {
		K[num] = rand() % 2;
		cout << K[num];
	}
	cout << endl;
	
	//Get k with replacePC_1 function
	replacePC_1(k, K, mySheet);
	cout << "k after PC_1 = ";
	for (num = 1; num <= 56; num++) {
		cout << k[num];
	}
	cout << endl;

	//Get C0 and D0
	half(k, C0, D0, 56);
	cout << "C0 = ";
	for (int i3 = 1; i3 <= 28; i3++) {
		cout << C0[i3];
	}
	cout << "\nD0 = ";
	for (int i3 = 1; i3 <= 28; i3++) {
		cout << D0[i3];
	}

	//Left shifting of C0 and D0
	C1 = left(C0, 28);
	cout << "\nC1 = ";
	for (num = 1; num <= 28; num++) {
		cout << C1[num];
	}
	D1 = left(D0, 28);
	cout << "\nD1 = ";
	for (num = 1; num <= 28; num++) {
		cout << D1[num];
	}

	//Combine C1 and D1
	combine(C1, D1, k1);
	//Output k1
	cout << "\nk1 = ";
	for (num = 1; num <= 56; num++) {
		cout << k1[num];
	}

	//Get k2 by mixing k1 with PC_2
	replacePC_2(k1, k2, mySheet);
	cout << "\nk2 = ";
	for (num = 1; num <= 48; num++) {
		cout << k2[num];
	}












	//issues to be solved(using functions): 1/divide the m into ml and mr	2/xor operation
	cout << endl;
	system("pause");
	return 0;
}