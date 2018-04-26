#include <iostream>
#include <string>
#include <algorithm> //swap, copy
#include <vector>
#include <iterator>
using namespace std;

int main(){
  vector<int> words;
  words.reserve(10);
  
  cout << "단어 공백으로 구분해서 입력, 종료는 컨트롤 z" << endl;
  copy(istream_iterator<string> {cin}, istream_iterator<string> {}, back_inserter(words));
  
  cout<< "정렬시작" <<endl;
  
  bool chk {false};
  
  auto last = end(words);
  
  while(1){
    for(auto first = begin(words)+1; first!=last; ++first){
      if(*(first-1) > *first){
        swap(*first, *(first-1));
        chk = true;
      }
    }
  if(!chk)
    break;
  chk = false;
  }
  
  cout << "오름차순" << endl;
  copy(begin(words), end(words), ostream_iterator<string> {cout, " "});
  
  cout <<endl;
  
  vector<string> w_copy{make_move_iterator(begin(words)), make_move_iterator(end(words))};
  
  cout << "\nw_copy\n";
  
  copy(begin(w_copy), end(w_copy), ostream_iterator<string> {cout, " "});
  
  cout << endl;
  
  cout <<"\nwords 원소 개수 : " <<words.size() << endl;
}
