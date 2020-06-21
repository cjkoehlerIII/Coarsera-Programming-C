unsigned int power(unsigned x, unsigned y){

  if(x==0&&y==0){
    return 1;
  }else if(y==0){
    return 1;
  }else if(y%2==0){
    return power(x,y/2)*power(x,y/2);
  }else{
    return x*power(x,y/2)*power(x,y/2);
  }
}
