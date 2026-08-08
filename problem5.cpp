
#include <vector>
#include <iostream>
using namespace std;
//we use template to generate type and dont to recreate code
template <typename T, int N>
struct queue_task {
	T arr[N];

};

int main()
{
	queue_task <int, 100> r;
	

}
