#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if(list1 == nullptr && list2 == nullptr) return list1;
		else if(list1 == nullptr) return list2;
		else if(list2 == nullptr) return list1;
		vector<int> tempList{};
		while(list1 != NULL) {
			tempList.push_back(list1->val);
			list1 = list1->next;
		}
		while(list2 != NULL) {
			tempList.push_back(list2->val);
			list2 = list2->next;
		}
		
		sort(tempList.begin(), tempList.end());
		ListNode* res = new ListNode{tempList[0]};
		void* resInit = res;
		tempList.erase(tempList.begin());
		for(int i : tempList) {
			ListNode* tl = new ListNode{i};
			res->next = tl;
			res = res->next;
		}

		return (ListNode*) resInit;
	}

	void generateLN(ListNode* rootLN, vector<int> values) {
		for(int i : values) {
			ListNode* temp = new ListNode{i};
			rootLN->next = temp;
			rootLN = rootLN->next;
		}
	}
};

int main() {
	ListNode l1{ 1 };
	ListNode l2{ 1 };
	Solution so{};
	so.generateLN(&l1, { 2,4 });
	so.generateLN(&l2, { 3,4 });
	ListNode* res = so.mergeTwoLists(&l1,&l2);
	return 0;
}