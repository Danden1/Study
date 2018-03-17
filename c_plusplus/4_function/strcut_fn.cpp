#include <iostream>
using namespace std;

struct box{
  char maker[40];
  float height;
  float width;
  float length;
  float volume;
};

void show(box b);
void set(box * b);

int main(){
  box b = {"Ky", 2, 2, 2, 0};
  show(b);
  set(&b);
  show(b);
  return 0;
}

void show(box box){
  cout << "maker: " << b.maker << endl;
  cout << "height: " << b.height << endl;
  cout << "width: " << b.width << endl;
  cout << "length: " << b.length << endl;
  cout << "volume: " << b.volume << endl;
  cout << endl;
}
void set(box *b){
  b->volume = b->height * b->width * b->length;
}
