#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
typedef struct Item {
	Item(std::string fruit_, int worker_, int weight_) {
		fruit = fruit_;
		worker = worker_;
		weight = weight_;
	}
	std::string fruit;
	int worker;
	int weight;
} Item;

int main(int argc, char const *argv[])
{
	
	std::vector<Item> input;
	int N = 0, M = 0;
	//std::ifstream cin("input.txt");
	std::map<std::string, int> fruits_ids;


	cin >> N;
	std::string fruit;
	int worker_id;
	int weight;
	int fruit_id = 0;
	for(int i = 0; i < N; i++) {
		cin >> fruit >> worker_id >> weight;
		if(fruits_ids.end() == fruits_ids.find(fruit)) {
			fruits_ids[fruit] = fruit_id;
			fruit_id++;
		}
		input.emplace_back(fruit, worker_id, weight);
	}
	std::sort(input.begin(), input.end(), [&fruits_ids](Item& a, Item& b) { 
		return (fruits_ids[a.fruit] < fruits_ids[b.fruit]
			|| (a.fruit == b.fruit && a.weight < b.weight)
			|| (a.fruit == b.fruit && a.weight == b.weight && a.worker < b.worker)); 
	});

	for(auto& item : input) {
		std::cout << item.fruit << " " << item.worker << " "<< item.weight << std::endl;
	}
	return 0;
}