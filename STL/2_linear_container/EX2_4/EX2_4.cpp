#include <algorithm>                             
#include <iostream>                              
#include <forward_list>                          
#include <iterator>                              
#include "Box.h"


template<typename Iter>
void list_elements(Iter begin, Iter end){
  size_t perline {6};                            
  size_t count {};     
  
  while (begin != end){
    std::cout << *begin++;
	
    if (++count % perline == 0){
      std::cout << "\n";
    }
  }
  
  std::cout << std::endl;
}

int main(){
  std::forward_list<Box> boxes;
  std::copy(std::istream_iterator<Box>(std::cin), std::istream_iterator<Box>(),
                                                                std::front_inserter(boxes));

  boxes.sort();                                    
  std::cout << "\n정렬한 순차열:\n";
  
  std::copy(std::begin(boxes), std::end(boxes), std::ostream_iterator<Box>(std::cout, " "));
  std::cout << std::endl;

  
  std::forward_list<Box> more_boxes {Box {3, 3, 3}, Box {5, 5, 5}, Box {4, 4, 4}, Box {2, 2, 2}};
  boxes.insert_after(boxes.before_begin(), std::begin(more_boxes), std::end(more_boxes));
  std::cout << "더 많은 상자를 삽입한 순차열:\n";
  list_elements(std::begin(boxes), std::end(boxes));

  boxes.sort();                                    
  std::cout << std::endl;
  std::cout << "다시 정렬한 순차열:\n";
  list_elements(std::begin(boxes), std::end(boxes));

  more_boxes.sort();
  boxes.merge(more_boxes);                         
  std::cout << "more_boxes를 병합한 순차열:\n";
  list_elements(std::begin(boxes), std::end(boxes));

  boxes.unique();
  std::cout << "중복 삭제를 제거한 순차열:\n";
  list_elements(std::begin(boxes), std::end(boxes));

  
  const double max_v {30.0};
  boxes.remove_if([max_v](const Box& box){ return box.volume() < max_v; });
  std::cout << "부피가 30 미만인 상제를 제거하고 정렬한 순차열:\n";
  list_elements(std::begin(boxes), std::end(boxes));
}
