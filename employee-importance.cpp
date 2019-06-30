#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
	Employee(int id, int importance, const vector<int>& subordinates) {
		this->id = id;
		this->importance = importance;
		this->subordinates = subordinates;
	}
};

class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		vector<int> subordinates;
		int sum = 0;
		queue<int> Q;
		vector<int> visited(2000, 0);
		for (int i = 0; i < employees.size(); ++i) {
			if (employees.at(i)->id == id) {
				sum = employees.at(i)->importance;
				for_each(employees.at(i)->subordinates.begin(), employees.at(i)->subordinates.end(), [&Q, &visited](int n) {
					Q.push(n);
					visited[n] = 1;
				});
				break;
			}
		}
		while (!Q.empty()) {
			auto u = Q.front();
			Q.pop();
			for (int i = 0; i < employees.size(); ++i) {
				if (employees.at(i)->id == u) {
					for_each(employees.at(i)->subordinates.begin(), employees.at(i)->subordinates.end(),
						[&visited, &Q](int n) {
						if (visited[n] == 0) {
							visited[n] = 1;
							Q.push(n);
						}
					});
					
				}
			}
		}

		/*for (int i = 0; i < employees.size(); ++i) {
			if (employees.at(i)->id == id) {
				subordinates = employees.at(i)->subordinates;
				sum = employees.at(i)->importance;
				break;
			}
		}*/

		for (int i = 0; i < employees.size(); ++i) {
			if (visited.at(employees.at(i)->id) == 1)
				sum += employees.at(i)->importance;
		}
		return sum;
	}
};
int main() {
	Solution s;
	int id = 1;
	//auto employees = vector<Employee*>{ new Employee{1,5,vector<int>{2,3}}, new Employee{ 2,3,vector<int>{4} },
	//	new Employee{ 3,4,vector<int>{} }, new Employee{4, 1, vector<int>{}} };
	auto employees = vector<Employee*>{ new Employee{ 2,5,vector<int>{} } };
	auto x = s.getImportance(employees, id);
	return 0;
}