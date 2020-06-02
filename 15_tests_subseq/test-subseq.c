#include <stdio.h>
#include <stdlib.h>

int main (){

size_t maxSeq(int * array, size_t n);


int array1[]={1,2,3};
int array2[]={1};
int array4[]={0};
int array5[]={};
int array6[]={-1,-2,-3};
int array7[]={4294967293,4294967294,4294967295};
int array8[]={-2,-1,0,1,2}; 
int array9[]={1,2,2,3,4,5};
int array10[]={4294967295};
 
 
if(maxSeq(array1,3)!=3){
  printf("Failed on 1,2,3\n");
  exit(EXIT_FAILURE);}

if(maxSeq(array2,1)!=1){
  printf("Failed on 1\n");
  exit(EXIT_FAILURE);}
  
if(maxSeq(array4,1)!=1){
  printf("Failed on 0\n");
  exit(EXIT_FAILURE);}

if(maxSeq(array5,0)!=0){
  printf("Failed on Null\n");
  exit(EXIT_FAILURE);}

if(maxSeq(array6,3)!=1){
  printf("Failed on -1,-2,-3\n");
  exit(EXIT_FAILURE);}

if(maxSeq(array7,3)!=3){
   printf("array7 failed\n");
   exit(EXIT_FAILURE);}

if(maxSeq(array8,5)!=5){
   printf("Failed on -2,-1,0,1,2\n");
   exit(EXIT_FAILURE);}
 
 if(maxSeq(array9,6)!=4){
   printf("Failed on 1,2,2,3,4,5 b\n");
   exit(EXIT_FAILURE);}

 if(maxSeq(array10,1)!=1){
   printf("Failed on big");
   exit(EXIT_FAILURE);}
   
return(EXIT_SUCCESS);
}
