#include <iostream>

typedef struct Point{
  int x,y,z;
}Point;

int dot_Product(Point p1,Point p2){
  int product  = 0;
  product += (p1.x * p2.x);
  procuct += (p1.y * p2.y);
  product += (p1.z * p2.z);
  return product;
}

Point cross_Product(Point p1,Point p2){
  Point result;
  result.x = p1.y*p2.z - p2.y*p1.z;
  result.y = -1*(p1.x*p2.z - p1.z*p2.x)
  result.z = p1.x*p2.y - p1.y*p2.x;
  return result;
}

bool counterClockWise(Point p1,Point p2,Point p3){

}
int main(){

}
