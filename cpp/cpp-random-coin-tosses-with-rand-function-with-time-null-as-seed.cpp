#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n;
    cout << "How many coin tosses?" << endl;
    cin >> n;
    cout << endl;

	// Providing a seed value
	srand((unsigned) time(NULL));

	for (int i = 1; i <= n; i++)
	{
		int current_random_side = rand() % 2;
		if (current_random_side == 1)
        {
            cout << "Heads" <<endl;
        }
        else
        {
            cout << "Tails" <<endl;
        }
	}

	return 0;
}
