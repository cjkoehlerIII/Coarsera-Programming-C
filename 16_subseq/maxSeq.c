#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int *array, size_t n){

  size_t current_seq=1;
  size_t max_seq=1;
  size_t i=1;
  
  int *p;
  p=array;

 if(*(p+0)==1 && n==1){
  max_seq=1;
  return max_seq;}
       
 if(*(p+0)==0 && n==1){
   max_seq=1;
   return max_seq;}
 
 if(n<1||array==NULL){
    max_seq=0;
    return max_seq;}


  while(i<n){

    if(*(p+i)>*(p+i-1)){
      current_seq++;

    if(current_seq>max_seq){
	max_seq=current_seq;}

    else{
      max_seq=1;
          }
    }
    
    i++;
  }
   return max_seq;
}
