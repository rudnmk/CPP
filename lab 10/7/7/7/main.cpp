#include <iostream>
#include <vector>
#include <list>
#include <chrono>



int main() {
	std::list<int> list{ 1, 2, 3, 4, 5, 6 };
	std::vector<int> vector = { 1, 2, 3, 4, 5, 6 };

	auto listTimeStart = std::chrono::high_resolution_clock::now();
	list.push_back(5);
	std::list<int>::iterator listI1 = list.begin();
	listI1++;
	list.emplace(listI1, 99);
	std::list<int>::iterator listI2 = list.begin();
	listI2++;
	listI2++;
	list.erase(listI2);
	auto listTimeEnd = std::chrono::high_resolution_clock::now();
	auto listTime = std::chrono::duration_cast<std::chrono::nanoseconds>(listTimeEnd - listTimeStart);

	auto vectorTimeStart = std::chrono::high_resolution_clock::now();
	vector.push_back(5);
	std::vector<int>::iterator vectorI1= vector.begin();
	vectorI1++;
	vector.emplace(vectorI1, 99);
	std::vector<int>::iterator vectorI2 = vector.begin();
	vectorI2++;
	vectorI2++;
	vector.erase(vectorI2);
	auto vectorTimeEnd = std::chrono::high_resolution_clock::now();
	auto vectorTime = std::chrono::duration_cast<std::chrono::nanoseconds>(vectorTimeEnd - vectorTimeStart);
	
	std::cout << "list worktime = " << listTime.count() << "; vector worktime = " << vectorTime.count() << std::endl;
	std::cout << "list size = " << sizeof(list) << ";  vector size = " << sizeof(vector) << std::endl;
	return 0;
}