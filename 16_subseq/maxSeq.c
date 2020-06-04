#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int *array, size_t n);

size_t maxSeq(int *array, size_t n){

  size_t current_seq=1;
  size_t max_seq=0;
  size_t super_seq=0;
  int i=0;
  int j=0;
  
  int *p=&array[0];
  
     
  if(*(p+i)=='\0'){
    super_seq=0;
     return super_seq=0;};

  if(n==1 || n==0){
    super_seq=1;
     return super_seq=1;};
  
  for(j=0;j<n;j++){
    current_seq=1;
    max_seq=0;
     
    for(i=j;i<n;i++){

      if(*(p+i)<0){
	continue;}

      if(*(p+i+1)==*(p+i)){
	break;}

      if(*(p+i+1)>*(p+i)){
	current_seq=current_seq+1;};

      if(current_seq>max_seq){
	max_seq=current_seq;};

      if(*(p+i+1)<*(p+i)){
	break;};
  
      if(current_seq>max_seq){
	max_seq=current_seq;};
  
    }

    if(max_seq>super_seq){
      super_seq=max_seq;}
  }

  
   return super_seq;
}
  

    
  
