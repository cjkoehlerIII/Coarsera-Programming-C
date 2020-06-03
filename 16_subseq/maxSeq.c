#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int *array, size_t n){

  size_t current_seq=0;
  size_t max_seq=0;
  int i=0;
  
  int *p=&array[0];
  
  if(*p=='\0'){
    max_seq=0;
    printf("max_Seq = %zu \n",max_seq);
    return max_seq;};

  if(n==1 || n==0){
    max_seq=1;
    printf("max_Seq = %zu \n",max_seq);
    return max_seq;};

  if(array[0]==0 && n==1){
    max_seq=1;
    printf("max_Seq = %zu \n",max_seq);
  return max_seq;};
  
/*if(array[i]>4294967295){
    exit(EXIT_FAILURE);}
*/

  for(i=0;i<n;i++){
    if(*(p+i)<0){
      continue;}
    if(*(p+i+1)>*(p+i)&&i<n-1){
      current_seq=i+2;}
    if(current_seq>max_seq){
      max_seq=current_seq;}
    if(*(p+i+1)<*(p+i)){
      current_seq=1;
    };
    printf("seq = %zu, i=%d\n",max_seq,i);
  };

  printf("max_seq = %zu \n",max_seq);
  return max_seq;

    };
  

    
  
