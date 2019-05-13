

//根据输入的数字 N，计算 N 以内（包括 N）数据链并统计数据链末尾数字是 1 的数
//据个数。例如 N=44，则数字链为：44->32->13->10->1，其规则为：4*4+4*4=32，
//3*3+2*2=13，
//1*1+3*3=10，1*1+0*0=1

#include<iostream>
//#include<unordered_map>
#include<unordered_set>
using namespace std;
bool is_rowto1(int n) {//, unordered_map<int,int>& map){
	unordered_set<int> set;
	set.insert(n);
	cout << n << ": " << n;
	while (n != 1) {
		int next = 0;
		while (n) {
			next += (n % 10) * (n % 10);
			n /= 10;
		}
		n = next;
		//if (set.find(n) != set.end()){
		//	for (auto e : set){
		//		map[e] = 0;
		//	}
		//	return false;
		//}
		//else if (map.find(n) != map.end()){
		//	int t = map[n];
		//	for (auto e : set){
		//		map[e] = t;
		//	}
		//	return t == 1;
		//}
		cout << "->" << n;
		if (set.find(n) != set.end())
		{
			cout << endl;
			return false;
		}
		set.insert(n);
	}
	cout << endl;
	return true;
}
int get_ans(int n) {
	int ret = 0;
	//unordered_map<int, int> map;
	//map[1] = 1;
	for (int i = 1; i <= n; i++) {
		//if (map.find(i) != map.end()){
			//ret += map[i];
		//}
		//else
		if (is_rowto1(i))//map))
		{
			ret++;
		}
	}
	return ret;
}
int main() {
	int n;
	cout << "Input your number: ";
	cin >> n;
	int count = 0;
	count = get_ans(n);
	cout << "the count is: " << count << endl;
	getchar();
	getchar();
	return 0;
}

