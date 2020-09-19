#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

void copy_stack(stack<int>& one, stack<int>& two) {
	vector<int> temp;
	while (!one.empty()) {
		temp.push_back(one.top());
		one.pop();
	}
	for (int i = temp.size() - 1; i >= 0;i--) {
		one.push(temp[i]);
		two.push(temp[i]);
	}
}

int get_big(stack<int> histogram_copy) {
	vector<int> trash;

	int biggest = histogram_copy.top();
	int top = histogram_copy.top();
	int new_big = 0;

	while (!histogram_copy.empty()) {
		while (!histogram_copy.empty() && top <= histogram_copy.top()) {
			new_big += top;
			trash.push_back(histogram_copy.top());
			histogram_copy.pop();
		}

		biggest = (biggest > new_big) ? biggest : new_big;
		if (!histogram_copy.empty()) {
			top = histogram_copy.top();
			int count = 0;
			for (int i = trash.size() - 1; i >= 0; i--) {
				if (trash[i] >= top) count++;
			}
			new_big = top * (count);
			biggest = (biggest > new_big) ? biggest : new_big;
		}
	}
	return biggest;
}

int histogram_func(stack<int> histogram, stack<int> histogram_copy) {
	int final = 0;
	while (!histogram.empty() &&!histogram_copy.empty()) {
		
		int new_big = get_big(histogram_copy);
		
		histogram.pop();
		while (!histogram_copy.empty()) {
			histogram_copy.pop();
		}
		copy_stack(histogram, histogram_copy);
		final = (final > new_big) ? final : new_big;
	}
	return final;
}

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
	/*cout << "몇 개?";
	int num, component;
	cin >> num;
	cout << endl;
	stack<int> histogram;
	stack<int>histogram_copy;

	for (int i = 0; i < num; i++) {
		cin >> component;
		histogram.push(component);
		histogram_copy.push(component);
	}
	cout<<histogram_func(histogram,histogram_copy)<<endl;*/

	int bridge_length;
	int weight;
	vector<int> truck_weights;
	int component;
	cout << "다리 길이:";
	cin >> bridge_length;
	cout << endl;
	cout << "지탱할 수 있는 무게:";
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