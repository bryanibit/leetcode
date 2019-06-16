#include <unordered_map>
#include <map>
#include <functional>
#include <vector>
#include <string>
using namespace std;
class Person {
public:
	string name;
	int id;
	Person(int id, string name) {
		this->name = name;
		this->id = id;
	}
public:

	// Use sum of lengths of first and last names 
	// as hash function. 
	bool operator==(const Person& p) const {
		return p.id == this->id && p.name == this->name;
	}
	bool operator<(const Person& p) const {
		return p.id > this->id && p.name > this->name;
	}
};

class myHashFunc{
public:
	size_t operator()(const Person& p) const
	{
		return (hash<int>{}(static_cast<int>(p.name.size())) ^ hash<int>{} (p.id));
	}
};


int main() {
	unordered_map<int, string> un_m;
	un_m.emplace(3, "Mike");

	unordered_map<Person, int, myHashFunc> un_m2;
	un_m2.emplace(Person(3, "Mike"), 3);
	un_m2.emplace(Person(3, "Jack"), 3);

	map<Person, int> un_m3;
	un_m3.emplace(Person(3, "Mike"), 3);
	return 0;
}