#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n;
    cout << "How many dice rolls? ";
    cin >> n;
    cout << endl;

	// Providing a seed value
	srand((unsigned) time(NULL));

	for (int i = 1; i <= n; i++)
	{
		int current_random_side = 1 + (rand() % (6));
		cout << current_random_side << endl;
	}

	return 0;
}
