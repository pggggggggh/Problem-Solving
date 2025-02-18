#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	queue<int> q;
	int n = truck_weights.size();
	for (int i = 0; i < bridge_length; i++) q.push(0);
	int time = 0, cur = 0;
	int ptr = 0;
	while (ptr < n || cur > 0) {
		cur -= q.front();
		q.pop();
		if (ptr < n && cur + truck_weights[ptr] <= weight) {
			q.push(truck_weights[ptr]);
			cur += truck_weights[ptr];
			ptr++;
		} else {
			q.push(0);
		}
		time++;
	}
	return time;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << solution(m, k, a);
}