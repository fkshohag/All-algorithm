# include <iostream>
# include <cstdio>
#include <cstdlib> 

using namespace std;

class Dice {
	public:
		int number_of_flip;
		Dice(int flip) {
			number_of_flip = flip;
		}

		void generateDiceFlip() {
			for(int i = 1; i <= 6; i++) {
				for(int j = 1; j <= 6; j++) {
					printf("(%d, %d)", i, j);
				}
				printf("\n");
			}
		}

		int firstTimeOccure(int number) {
			int counter = 0;
			for(int i = 1; i <= 6; i++) {
				for(int j = 1; j <= 6; j++) {
					if(number == i) {
						printf("(%d, %d)", i, j);
						counter++;
					}
				}
				printf("\n");
			}
			return counter;
		}

		int biggerOrEqualSum(int sum) {
			int counter = 0;
			for(int i = 1; i <= 6; i++) {
				for(int j = 1; j <= 6; j++) {
					if((i + j) >= sum) {
						printf("(%d, %d)", i, j);
						counter++;
					}
				}
				printf("\n");
			}
			return counter;
		}

		int differenceInNumberEqual(int number) {
			int counter = 0;
			for(int i = 1; i <= 6; i++) {
				for(int j = 1; j <= 6; j++) {
					if(abs(i - j) == number) {
						printf("(%d, %d)", i, j);
						counter++;
					}
				}
				printf("\n");
			}
			return counter;
		}
};

int main() {
	Dice d(2);
	d.generateDiceFlip();
	printf("..................................End\n");
	int step = 4; 
	int counter = d.firstTimeOccure(step);
	printf("%d occure first time: %d\n", step, counter);
	printf("..................................End\n");

	int sum = 8; 
	counter = d.biggerOrEqualSum(sum);
	printf("%d bigger sum occure: %d\n", sum, counter);
	printf("..................................End\n");

	int diff = 2; 
	counter = d.differenceInNumberEqual(diff);
	printf("%d diff in equal occure: %d\n", diff, counter);
	printf("..................................End\n");
}