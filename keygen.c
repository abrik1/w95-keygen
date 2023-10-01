#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int key_mode = 0;

#define randint(min, max) rand() % (max - min + 1) + min

int gen_n1(){
  for(;;){
    int num = key_mode == 0 ? randint(9999, 99999) : randint(999999, 9999999);
    int num2 = num;
    int sum = 0;
    while(num != 0){
      sum += num % 10;
      num /= 10;
    }
    if(sum % 7 == 0){
     return num2; 
    } 
  }
}

int gen_retail_n1(){
  for(;;){
    int num = randint(100, 999);
    if (!num % 111 == 0){
	return num;
    }
  }
}

int main(){
  srand((unsigned int)time(NULL));
  printf("OEM: %d%d-OEM-00%d-%d\n", randint(100, 366), randint(95, 99), gen_n1(), randint(10000, 99999));
  key_mode = 1;
  printf("Retail: %d-%d\n", gen_retail_n1(), gen_n1());
  return 0;
}
