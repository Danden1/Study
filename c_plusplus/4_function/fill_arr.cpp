#include <iostream>
using namespace std;

const int Max = 10;

int Fill_array(double ar[], int size);
void Show_array(double ar[], int size);
void Reverse-array(double ar[], int size);

int main(){
  double arr[Max};
  int count = Fill_array(arr, Max);
  
  Show_array(arr, count);
  
  Reverse_array(arr,count);
  Show_array(arr, count);
  
  Reverse_array(arr+1, count -2);
  Show_array(arr, count);
  
  return 0;
}


int Fill_array(double ar[], int size){
  int count = 0;
  for (int i = 0; i<count; i++){
    if(!(cin >> ar[i]))
      break;
    count++;
  }
  return count;
}

void Show_array(doublee ar[], int size){
  for (int i = 0; i<size; i++)
    cout << ar[i] << "\t";
  cout << endl;
}


void Reverse_array(double ar[], int size){
  int i, j, tmp;
  for (i=0, j = size -1; i < j; i++, j--){
    tmp = ar[i];
    ar[i] = ar[j];
    ar[j] = tmp;
  }
}
