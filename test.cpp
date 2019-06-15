#include <unordered_map>
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

};
int main() {
	unordered_map<int, string> un_m;
	un_m.emplace(3, "Mike");

	unordered_map<Person, int> un_m2;
	un_m2.emplace(Person(3, "Mike"), 3);
	return 0;
}