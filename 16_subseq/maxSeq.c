#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int *array, size_t n){

  size_t current_seq=0;
  size_t max_seq=0;
  size_t super_seq=0;
  size_t i=0;
  
  
  int *p=array;

  if(n<1){
    super_seq=0;
    return super_seq=0;
  }
  
  if(array[0]==1 && n==1){
    super_seq=1;
    return super_seq;}
       
  if(array[0]=='\0'){
    super_seq=1;
    return super_seq;}

 
  for(i=0;i<n;i++){

    for(size_t j =0;*(p+i+1)>*(p+i)&&*(p+i)>=0 && i<n; j++){
      current_seq=j+2;
      i++;
    }

    if(current_seq>max_seq)
      {max_seq=current_seq;}
 
    
    if(max_seq>super_seq){
	super_seq=max_seq;};
      
  };

   return super_seq;
  };
  

    
  
