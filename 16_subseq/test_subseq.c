#include <stdio.h>
#include <stdlib.h>

int main (){

size_t maxSeq(int * array, size_t n);


int array1[]={1,2,3};
int array2[]={1};
int array3[]={0};
int array4[]={};
int array5[]={-1,-2,-3};
int array6[]={4294967293,4294967294,4294967295};
int array7[]={-2,-1,0,1,2}; 
int array8[]={1,2,2,3,4,5};
int array9[]={4294967295};

 
if(maxSeq(array1,3)!=3){
  printf("Failed on 1,2,3\n");
  exit(EXIT_FAILURE);}

if(maxSeq(array2,1)!=1){
  printf("Failed on {1}\n");
  exit(EXIT_FAILURE);}

if(maxSeq(array3,1)!=1){
  printf("Failed on {0}\n");
  exit(EXIT_FAILURE);}

if(maxSeq(array4,0)!=0){
  printf("Failed on 0\n");
  exit(EXIT_FAILURE);}
 
if(maxSeq(array5,3)!=0){
  printf("Failed on negative seq\n");
  exit(EXIT_FAILURE);}

 
if(maxSeq(array6,3)!=0){
  printf("Failed on max numbers\n");
  exit(EXIT_FAILURE);}

if(maxSeq(array7,5)!=3){
   printf("array7 failed\n");
   exit(EXIT_FAILURE);}

if(maxSeq(array8,6)!=4){
   printf("Failed on 1,2,2,3,4,5 b\n");
   exit(EXIT_FAILURE);}
  
if(maxSeq(array9,1)!=0){
   printf("Failed on big");
   exit(EXIT_FAILURE);}

return(EXIT_SUCCESS);
}
