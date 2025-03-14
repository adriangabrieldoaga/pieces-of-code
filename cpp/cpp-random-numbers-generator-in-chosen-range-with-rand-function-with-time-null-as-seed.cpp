#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int lower_limit, higher_limit, n;
    cout << "Lower limit: ";
    cin >> lower_limit;
    cout << "Higher limit: ";
    cin >> higher_limit;
    cout << "How many random numbers?" << endl;
    cin >> n;
    cout << endl;

	// Providing a seed value
	srand((unsigned) time(NULL));

	for (int i = 1; i <= n; i++)
	{
		int current_random_number = lower_limit + (rand() % (higher_limit - lower_limit + 1));
		cout << current_random_number << endl;
	}

	return 0;
}
