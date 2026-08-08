
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		sum += i;
	}
	cout << sum << endl;
	int c = (n * (1 + n))/2;
	cout << c ;

}
