#ifndef NAME_H
#define NAME_H
#include <string>
#include <ostream>
#include <istream>

class Name{
	private:
		std::string first{};
		std::string second{};
	public:
		Name(const std::string& name1, const std::string& name2): first(name1), second(name2){}
		Name() = default;
	
		bool operator<(const Name& name) const{
			return second <name.second || (second == name.second && first < name.first);
		}
		friend std::istream& operator>>(std::istream& in, Name &name);
		friend std::ostream& operator<<(std::ostream& outm, const Name& name);
};

inline std::istream& operator>>(std::istream& in, Name& name){
	in >> name.first >> name.second;
	return in;
}

inline std::ostream& operator<<(std::ostream& out, const Name& name){
	out << name.first +" "+ name.second;
	return out;
}

#endif
