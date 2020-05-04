using namespace std;
#include <iostream>
#include <ctime>


int main()
{
	setlocale(LC_ALL, "rus");
	int kassa = 0;
	int kupura25 = 0;
	int kupura50 = 0;
	int kupura100 = 0;
	int max_ochered;
	cin >> max_ochered;
	srand(time(0));
	rand(); rand(); rand(); rand(); rand(); rand();

	for(int ochered = 1; ochered < max_ochered; ochered++){

		

		int arr_tubriki[7]{ 25, 25, 50, 100, 50, 25, 25 };
		int dali = arr_tubriki[rand() * 7 / RAND_MAX];
		cout << "кассиру дали-" << dali << " тубриков\n";

		if (dali == 25) {
			kassa += 25;
			kupura25 += 1;
		}
		
		
		
		if (dali == 50 && kupura25 >= 1) {
			kassa -= 25;
			kupura25 -= 1;
			kupura50 += 1;
		}
		else if (dali == 50 && kupura25 < 1) {
			cout << "отказ в обслуживании клиенту-" << ochered << "\n";
			cout << kassa << "-объем выручки\n";
			return 0;
		}

		
		
		
		if (dali == 100 && ((kupura25 >= 3) || (kupura50 >= 1 && kupura25 >= 1))) {
			kassa -= 75;
					if (kupura25 >= 3) {
						kupura25 -= 3;
						kupura100 += 1;
					}
					else if (kupura50 >= 1 && kupura25 >= 1) {
						kupura50 -= 1;
						kupura25 -= 1;
						kupura100 += 1;
					}
			
		}
		else if (dali == 100 && ((kupura25 < 3) || (kupura50 < 1 && kupura25 < 1))) {
			cout << "отказ в обслуживании клиенту-" << ochered << "\n";
			cout << kassa << "-объем выручки\n";
			return 0;
		}


	}
}
