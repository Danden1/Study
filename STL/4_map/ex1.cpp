#include <iostream>
#include <iomanip> //스트림 조작자
#include <string>
#include <sstream> //istringstream
#include <algorithm>//repalce,for_each
#include <map>
#include <cctype>
#include <iterator>

using std::string;

int main(){
	std::cout << "Enter some text and enter * to end: \n";
	string text_in {};
	std::getline(std::cin, text_in, '*');
	
	std::replace_if(std::begin(text_in), std::end(text_in), [](const char &ch){return !isalpha(ch);}, ' ');
	
	std::istringstream text(text_in); //텍스트 입력 문자열 -> 스트림
	std::istream_iterator<string> begin(text);
	std::istream_iterator<string> end;
	
	std::map<string, size_t> words;
	size_t max_len {};
	
	std::for_each(begin, end, [&max_len, &words](const string& word){words[word]++; max_len = std::max(max_len, word.length());});
	
	size_t per_line {4}, count{};
	for(const auto& w:words){
		std::cout <<std::left << std::setw(max_len+1) << w.first << std::setw(3) << std::right << w.second << " ";
		if(++count % per_line == 0) std::cout << std::endl;
		
	}
	std::cout <<std::endl;
}
