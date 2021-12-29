#pragma once
#include <vector>

class disjoint_set {
public:
	disjoint_set();
	disjoint_set(int x);

	void assign(int x);
	int find_set(int x);
	bool union_set(int x, int y);
private:
	std::vector<int> parent_;
	std::vector<int> rank_;
};

disjoint_set::disjoint_set() :
	disjoint_set(0) {}

disjoint_set::disjoint_set(int x) :
	parent_(x), rank_(x, 0) {
	for (int i = 0; i < x; i++) {
		parent_[i] = i;
	}
}

void disjoint_set::assign(int x) {
	parent_.assign(x, 0);
	rank_.assign(x, 0);

	for (int i = 0; i < x; i++) {
		parent_[i] = i;
	}
}

int disjoint_set::find_set(int x) {
	if (x != parent_[x]) {
		return parent_[x] = find_set(parent_[x]);
	}

	return parent_[x];
}

bool disjoint_set::union_set(int x, int y) {
	x = find_set(x);
	y = find_set(y);

	if (x == y) {
		return true;
	}

	if (rank_[x] < rank_[y]) {
		parent_[x] = y;
	}
	else if (rank_[x] > rank_[y]) {
		parent_[y] = x;
	} else {
		parent_[y] = x;
		rank_[x] += 1;
	}

	return false;
}
