k#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int year_format[5] = {95, 96, 97, 98, 99};
int num = 0;
int sum = 0;

int gen_n1(){
  while(true){
    int num = rand() % 99999 + 9999;
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

int main(){
  int n = gen_n1();
  printf("%d%d-OEM-00%d-%d\n", rand() % 366, year_format[rand() % 4], n, rand() % 99999 + 9999);
  return 0;
}
