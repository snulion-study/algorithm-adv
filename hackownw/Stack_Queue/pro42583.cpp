

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
	cout << "�ٸ� ����:";
	cin >> bridge_length;
	cout << endl;
	cout << "������ �� �ִ� ����:";
	cin >> weight;
	cout << endl;
	cout << "Ʈ�� ����:" << endl;
	cin >> component;
	while (component != 0) {
		truck_weights.push_back(component);
		cin >> component;
	}

	cout << bridge(bridge_length, weight, truck_weights) << endl;

	return 0;
}