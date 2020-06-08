#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int *array, size_t n){

  size_t current_seq=0;
  size_t max_seq=0;
  size_t i=0;
  size_t j=0;
  
  int *p;
  p=array;

 if(n<1){
    max_seq=0;
    return max_seq=0;
  }
  
 if(*(p+0)==1 && n==1){
  max_seq=1;
  return max_seq;}
       
 if(*(p+0)=='\0'){
  max_seq=1;
  return max_seq;}

 if(*(p+0)==0&&n==1){
    max_seq=1;
    return max_seq;}
 
  for(i=0;i<n;i++){

    for(j=0;*(p+i+1)>*(p+i)&&*(p+i)>=0 && i<n; j++){
      current_seq=j+2;
      i++;
    }

    if(current_seq>max_seq)
      {max_seq=current_seq;}
 
        
  }

   return max_seq;
}
