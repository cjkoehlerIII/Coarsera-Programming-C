#include <stdlib.h>
#include <stdio.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void retirement ( int startAge, double initial,retire_info working, retire_info retired);
void age(int startAge, int *add_years, int *add_months);

retire_info working = {.months = 489, .contribution = 1000, .rate_of_return=0.045/12};
retire_info retired = {.months = 384, .contribution = -4000, .rate_of_return=0.01/12};

/*void age(int startAge, int *add_years, int *add_months)
{
  *add_years = startAge/12;
  *add_months = startAge%12;
}
*/


void retirement(int startAge,double initial,retire_info working, retire_info retired)
{
  int years=0;
  int months=0;


  do{
    years = startAge/12;
    months = startAge%12;
    printf("Age %3d month %2d you have $%.2lf\n",years,months,initial);
    initial=initial+(initial*working.rate_of_return);
    initial=initial+working.contribution;
    startAge=startAge+1;
    working.months=working.months-1;
        
      
    }while(working.months>0);
  
  do{
    years = startAge/12;
    months = startAge%12;
    
    printf("Age %3d month %2d you have $%.2lf\n",years,months,initial);
    initial=initial+retired.contribution+initial*retired.rate_of_return;
    startAge=startAge+1;
    retired.months=retired.months-1;
   
    }while(retired.months>0);
}

  int startAge=327;
  double initial=21345;



int main(){

  
 
  retirement(startAge,initial,working,retired);


  return 0;
  }

