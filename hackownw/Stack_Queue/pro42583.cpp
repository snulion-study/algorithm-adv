#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int bridge(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> on_bridge;
	for (int i = 0; i < bridge_length;i++) on_bridge.push(0);
	int sum=0;
	int started = 0;
	int arrived = 0;
	int count = 0;
	
	while (started != (truck_weights.size())) {
		count++;
		sum -= on_bridge.front();
		if (on_bridge.front() != 0) arrived++;
		on_bridge.pop();
		if (sum + truck_weights[started] <= weight) {
			on_bridge.push(truck_weights[started]);
			sum += truck_weights[started++];
		}
		else {
			on_bridge.push(0);
		}
		
	}

	while (arrived != truck_weights.size()) {
		count++;
		if (on_bridge.front() != 0) arrived++;
		on_bridge.pop();
	}
	return count;
}

int main() {
	int bridge_length;
	int weight;
	vector<int> truck_weights;
	cout << "다리 길이:";
	cin >> bridge_length;
	cout << endl;
	cout << "다리가 견딜 수 있는 무게:";
	cin >> weight;
	cout << endl;
	cout << "트럭 무게:" << endl;
	cin >> component;
	while (component != 0) {
		truck_weights.push_back(component);
		cin >> component;
	}

	cout << bridge(bridge_length, weight, truck_weights) << endl;

	return 0;
}