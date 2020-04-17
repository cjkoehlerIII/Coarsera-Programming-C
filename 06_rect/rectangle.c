#include <stdio.h>
#include <stdlib.h>
//I've provided "min" and "max" functions in
//case they are useful to you

int min (int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}

int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

//Declare your rectangle structure here!
struct rectangle{
  int x;
  int y;
  int width;
  int height;
};

typedef struct rectangle rectangle;

struct corners{
  int x;
  int y;
  int width;
  int height;
  int llx;
  int lly;
  int urx;
  int ury;
};



rectangle canonicalize(rectangle r) {
  //WRITE THIS FUNCTION
  if (r.width<0&&r.height<0)
  {
    r.x=r.x+r.width;
    r.width=-1*r.width;
    r.y=r.y+r.height;
    r.height=-1*r.height;
    return r;
  }
  else if (r.width<0&&r.height>0)
    {
    r.x=r.x+r.width;
    r.width=-1*r.width;
    return r;
    }
  else if (r.width>0&&r.height<0)
    {
    r.y=r.y+r.height;
    r.height=-1*r.height;
    return r;
    }
  else
    {
    r.x=r.x;
    r.width=r.width;
    r.y=r.y;
    r.height=r.height;
    }
  return r;
}

rectangle intersection(rectangle r1, rectangle r2)
{

  int r1llx=0;
  int r1lly=0;
  int r1urx=0;
  int r1ury=0;
  int r2llx=0;
  int r2lly=0;
  int r2urx=0;
  int r2ury=0;
  
  //WRITE THIS FUNCTION
  r1=canonicalize(r1);
  r2=canonicalize(r2);

  
  r1llx=r1.x;
  r1lly=r1.y;
  r1urx=r1.x+r1.width;
  r1ury=r1.y+r1.height;

  r2llx=r2.x;
  r2lly=r2.y;
  r2urx=r2.x+r2.width;
  r2ury=r2.y+r2.height;


  if (r2lly>r1ury||r2ury<r1lly)
    {
    r1.width=0;
    r1.height=0;
    return r1;
     }
  else if (r1urx<r2llx||r2urx<r1llx)
    {
    r1.width=0;
    r1.height=0;
    return r1;
    }
  else if (r1ury==r2lly||r1urx==r2llx)
    {
    r1.x=max(r1llx,r2llx);
    r1.y=max(r1ury,r2lly);
    r1.height=min(r1ury,r2ury)-r1.y;
    r1.width=min(r1urx,r2urx)-r1.x;
    return r1;
    }

  else if((r1llx>r2llx)&&(r1urx<r2urx)&&(r1lly>r2lly)&&(r2ury>r1ury))//r2 inside of r3
    {
    return r1;
    }
  else
    {
    r1.x=max(r1llx,r2llx);
    r1.y=max(r1lly,r2lly);
    r1.width=min(r1urx,r2urx)-r1.x;
    r1.height=min(r1ury,r2ury)-r1.y;
    }
      return r1;
}


//You should not need to modify any code below this line
void printRectangle(rectangle r) {
  r = canonicalize(r);
  if (r.width == 0 && r.height == 0) {
    printf("<empty>\n");
  }
  else {
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y, r.x+r.width, r.y+r.height);
  }
}

int main (void) {
  rectangle r1;
  rectangle r2;
  rectangle r3;
  rectangle r4;

  r1.x = 2;
  r1.y = 3;
  r1.width = 5;
  r1.height = 6;
  printf("r1 is ");
  printRectangle(r1);

  r2.x = 4;
  r2.y = 5;
  r2.width = -5;
  r2.height = -7;
  printf("r2 is ");
  printRectangle(r2);
  
  r3.x = -2;
  r3.y = 7;
  r3.width = 7;
  r3.height = -10;
  printf("r3 is ");
  printRectangle(r3);

  r4.x = 0;
  r4.y = 7;
  r4.width = -4;
  r4.height = 2;
  printf("r4 is ");
  printRectangle(r4);

  //test everything with r1
  rectangle i=intersection(r1,r1);
  printf("intersection(r1,r1): ");
  printRectangle(i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  printRectangle(i);
  
  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  printRectangle(i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  printRectangle(i);

  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  printRectangle(i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  printRectangle(i);
  
  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  printRectangle(i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  printRectangle(i);

  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  printRectangle(i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  printRectangle(i);
  
  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  printRectangle(i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  printRectangle(i);

  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  printRectangle(i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  printRectangle(i);
  
  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  printRectangle(i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  printRectangle(i);


  return EXIT_SUCCESS;

}
