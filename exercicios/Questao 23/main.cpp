#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int coin;
	vector<int> coins;
	while(true){
		cin >> coin;
		if(coin <= 0)
			break;
		coins.push_back(coin);
	}
	sort(coins.begin(), coins.end());
	int change;
	cin >> change;

	while(!coins.empty()){
		if(change < coins.back())
			coins.pop_back();
		else{
			change -= coins.back();
			cout << '.' << coins.back();
		}
	}
	cout << endl;
}