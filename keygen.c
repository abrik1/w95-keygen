#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int year_format[5] = {95, 96, 97, 98, 99};
int num = 0;
int sum = 0;
int date = 0;
int key_mode = 0; // 0 if OEM.. 1 if retail

int randint(int min, int max){
  for(;;){
    int num = rand() % max + min;
    if(num > max){
      continue;
    } else{
      return num;
    }
  }
}

int gen_n1(){
  for(;;){
    if(key_mode == 0){
      num = randint(9999, 99999);
    } else{
      num = randint(999999, 9999999);
    }
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
    if (num != 111 && num % 111 == 0){
      continue;
    } else{
      return num;
    }
  }
}

int main(){
  srand((unsigned int)time(NULL));
  int n = gen_n1();
  printf("OEM: %d%d-OEM-00%d-%d\n", randint(100, 366), year_format[rand() % 4], n, randint(10000, 99999));
  key_mode = 1;
  printf("Retail: %d-%d\n", gen_retail_n1(), gen_n1());
  return 0;
}
