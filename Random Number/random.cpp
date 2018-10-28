#include <random>
#include <time.h>

int main(){
	srand(time(NULL));

	for(int i = 0; i < 100; i++){
		std::cout<<rand() % 100 << std::endl;
	}
	system("pause");
	exit 0;
}