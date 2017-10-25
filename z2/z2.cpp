#include <iostream>
using namespace std;

class MnojinaInt {
public:
	int* mas;
	int n;
	MnojinaInt(int* massiv, int size) {
		mas = massiv;
		n = size;
	}
	MnojinaInt(const MnojinaInt& mnoj) {
		n = mnoj.n;
		mas = new int[n];
		for (int i = 0; i < n; i++) {
			mas[i] = mnoj.mas[i];
		}
	}
	void operator+= (int toAdd) {
		for (int i = 0; i < n; i++) {
			if (toAdd == mas[i])
				return;
		}
		int* newMass = new int[n + 1];
		for (int i = 0; i < n; i++) {
			newMass[i] = mas[i];
		}
		newMass[n] = toAdd;
		delete[] mas;
		mas = newMass;
		++n;
	}
	void operator-= (int toDelete) {
		int index = -1;
		for (int i = 0; i < n; i++) {
			if (toDelete == mas[i])
				index = i;
		}
		if (index < 0)
			return;
		int* newMass = new int[n - 1];
		for (int i = 0; i < index; i++) {
			newMass[i] = mas[i];
		}
		for (int i = index + 1; i < n; i++) {
			newMass[i - 1] = mas[i];
		}
		delete[] mas;
		mas = newMass;
		--n;
	}
	MnojinaInt & operator= (const MnojinaInt & mnoj) {
		return MnojinaInt(mnoj);
	}
	bool operator== (MnojinaInt mnoj) {
		if (n != mnoj.n)
			return false;
		for (int i = 0; i < n; i++) {
			if (mas[i] != mnoj.mas[i])
				return false;
		}
		return true;
	}
	friend ostream& operator<<(ostream& os, const MnojinaInt& dt);


};

ostream& operator<<(ostream& os, const MnojinaInt& dt)
{
	for (int i = 0; i < dt.n; i++) {
		cout << dt.mas[i] << " ";
	}
	cout << endl;
	return os;
}


int main()
{
	int priklad[4] = { 4, 6, 1 ,3 };
	MnojinaInt mnoj1(priklad, 4);
	MnojinaInt mnoj2 = mnoj1;
	mnoj2 += 2;
	cout << mnoj2;
	cout << endl;
	mnoj2 += 2;
	cout << mnoj2;
	cout << endl;
	mnoj2 -= 2;
	cout << mnoj2;
	cout << endl;
	MnojinaInt mnoj3 = mnoj2;
	cout << mnoj3;
	system("pause");
	return 0;
}