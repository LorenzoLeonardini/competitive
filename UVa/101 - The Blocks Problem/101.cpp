/**
	UVa 101 - The Blocks Problem
	by Lorenzo Leonardini
	Submitted: 2019-11-14
	Accepted 0.000 C++
*/


#include <iostream>
#include <stack>
#include <string>

int n, position[25];
std::stack<int> stacks[25];
std::stack<int> moving;

int main(void) {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		position[i] = i;
		stacks[i].push(i);
	}
	std::string command, where;
	int a, b;

	std::cin >> command;
	while(command.compare("quit") != 0) {
		std::cin >> a;
		std::cin >> where;
		std::cin >> b;
		if(a == b || position[a] == position[b]) {
			std::cin >> command;
			continue;
		}
		int pile = position[a];
		int el;
		while(stacks[pile].size() && (el = stacks[pile].top()) != a) {
			moving.push(el);
			stacks[pile].pop();
		}
		if(command.compare("move") == 0) {
			while(moving.size()) {
				el = moving.top();
				moving.pop();
				position[el] = el;
				stacks[el].push(el);
			}
		}
		stacks[pile].pop();
		moving.push(a);
		pile = position[b];
		if(where.compare("onto") == 0) {
			while(stacks[pile].size() && (el = stacks[pile].top()) != b) {
				moving.push(el);
				stacks[pile].pop();
			}
			while(moving.size() && (el = moving.top()) != a) {
				position[el] = el;
				stacks[el].push(el);
				moving.pop();
			}
		}
		while(moving.size()) {
			el = moving.top();
			position[el] = position[b];
			stacks[pile].push(el);
			moving.pop();
		}
		std::cin >> command;
	}

	for(int i = 0; i < n; i++) {
		std::cout << i << ":";
		while(stacks[i].size()) {
			moving.push(stacks[i].top());
			stacks[i].pop();
		}
		while(moving.size()) {
			std::cout << " " << moving.top();
			moving.pop();
		}
		std::cout << std::endl;
	}

	return 0;
}
