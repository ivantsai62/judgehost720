//uva11995
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int i, ins, num;
		int isStk = 1, isQue = 1, isPriQue = 1;
		stack<int> myStk;
		queue<int> myQue;
		priority_queue<int> myPriQue;

		for (i = 0; i < n; i++) {
			cin >> ins >> num;

			if (ins == 1) {
				myStk.push(num);
				myQue.push(num);
				myPriQue.push(num);
			}
			else if (ins == 2) {
				if (myStk.empty() || myStk.top() != num)
					isStk = 0;
				if (myQue.empty() || myQue.front() != num)
					isQue = 0;
				if (myPriQue.empty() || myPriQue.top() != num)
					isPriQue = 0;

				if (!myStk.empty())
					myStk.pop();
				if (!myQue.empty())
					myQue.pop();
				if (!myPriQue.empty())
					myPriQue.pop();
			}
		}

		if (isStk + isQue + isPriQue > 1)
			cout << "not sure" << endl;
		else if (isStk == 1)
			cout << "stack" << endl;
		else if (isQue == 1)
			cout << "queue" << endl;
		else if (isPriQue == 1)
			cout << "priority queue" << endl;
		else
			cout << "impossible" << endl;
	}
	return 0;
}