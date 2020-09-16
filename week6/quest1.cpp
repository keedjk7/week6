#include<iostream>
#include<list>

using namespace std;

list<int>train[20];
bool show[20];
int container, block[20], weight, sum[20], limit;

void Input() {

	cout << "Number Of Container : ";
	cin >> container;
	for (int i = 0; i < container; i++) {
		cout << "\nNumber of Block in Container " << i + 1 << " : ";
		cin >> block[i];
		for (int j = 0; j < block[i]; j++) {
			cout << "Weight in Block " << j + 1 << " Container " << i + 1 << " : ";
			cin >> weight;
			train[i].push_back(weight);
		}
	}
	cout << "\nLimit Weight per Block : ";
	cin >> limit;
}

void process() {
	for (int i = 0; i < container; i++) {
		sum[i] = 0;
		for (list<int>::iterator j = train[i].begin(); j != train[i].end(); j++) {
			sum[i] += *j;
		}
		if (sum[i] > block[i] * limit) {
			show[i] = false;
		}
		else {
			show[i] = true;
		}
	}
}

int main() {
	Input();
	process();
	cout << "\n\nSHOW RESULT\n";
	for (int i = 0; i < container; i++) {
		cout << "CONTAINER " << i + 1 << " --> " << block[i] << " Block" << "\nTotal Weight In This Container = " << sum[i] << " , Limit Weight In This Container = " << block[i] * limit;
		if (show[i] == true) {
			cout << "\nPass.This Container Is Under Weight\n\n";
		}
		else {
			cout << "\nNot Pass.This Container Is Over Weight\n\n";
		}
	}
	return 0;
}