#include <stdlib.h>
#include <stdio.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

  
retire_info working = {.months = 489, .contribution = 1000, .rate_of_return=0.045/12};
retire_info retired = {.months = 384, .contribution = -4000, .rate_of_return=0.01/12};



void age(int totalmonths, int *add_years, int *add_months)
{
  *add_years = totalmonths/12;
  *add_months = totalmonths%12;
}

int main(){
  int years;
  int months;
    
  int totalmonths=327;
  double balance=21345;

  do{
  age(totalmonths,&years,&months);
  printf("Age %3d month %2d you have $%.2lf\n",years,months,balance);
  balance=balance+balance*working.rate_of_return;
  balance=balance+working.contribution;

  totalmonths=totalmonths+1;
  working.months=working.months-1;
  }while (working.months>0);

  do{
  age(totalmonths,&years,&months);
 

  printf("Age %3d month %2d you have $%.2lf\n",years,months,balance);
  balance=balance+retired.contribution+balance*retired.rate_of_return;
  // balance=balance+retired.contribution;
  totalmonths=totalmonths+1;
  retired.months=retired.months-1;
  }while (retired.months>0);
  
  return 0;
}
