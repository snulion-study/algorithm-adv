#include <iostream>
#include <stack>
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

int histogram_func(stack<int> histogram) {
	stack<int> histogram_copy;
	copy_stack(histogram, histogram_copy);
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

int main(){
    cout << "�� ��?";
	int num, component;
	cin >> num;
	cout << endl;
	stack<int> histogram;
	stack<int>histogram_copy;

	for (int i = 0; i < num; i++) {
		cin >> component;
		histogram.push(component);
		//histogram_copy.push(component);
	}
	cout<<histogram_func(histogram)<<endl;
    return 0;
}