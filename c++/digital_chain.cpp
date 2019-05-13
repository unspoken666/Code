////#include <iostream>
////#define size 80
////using std::cout;
////using std::cin;
////using std::endl;
////
////int count;
////
////class T
////{
////public:
////	T(int n);
////	void next();
////	int repeat();
////	void print();
////	int check();
////private:
////	int array[size];
////	int *pt;
////};
////
////T::T(int n)
////{
////	array[0] = n;
////	for (int i(1); i < size; i++)
////		array[i] = 0;
////	pt = array;
////}
////
////void T::next()
////{
////	int sum = 0, d = 0, n = *pt;
////	do
////	{
////		d = n % 10;
////		sum += d * d;
////	} while (n = n / 10);
////	pt++;
////	*pt = sum;
////}
////
////int T::repeat()
////{
////	int i(0);
////	while (&array[i] != pt)
////	{
////		if (array[i] == *pt) return 1;
////		i++;
////	}
////	return 0;
////}
////
////void T::print()
////{
////	cout << "->" << *pt;
////}
////
////int T::check()
////{
////	if (*pt == 1) return 1;
////	else return 0;
////}
////
////int  main()
////{
////	int N;
////	cout << "Please input an integer larger than zero!\n";
////	cout << "Start:";
////	cin >> N;
////	while (N)
////	{
////		T d(N);
////		cout << N;
////		do
////		{
////			d.next();
////			if (!d.repeat())
////				d.print();
////			else
////			{
////				if (d.check())
////					count++;
////				break;
////			}
////		} while (1);
////		cout << endl;
////		N--;
////	}
////	cout << "The number of digit-string ending with 1 is: " << count << endl;
////	getchar();
////	getchar();
////
////	return 0;
////}
//
//#include<iostream>
//#include<unordered_map>
//#include<unordered_set>
//
//using namespace std;
//bool is_rowto1(int n, unordered_map<int, int>& map) {
//	unordered_set<int> set;
//	set.insert(n);
//	while (n != 1) {
//		int next = 0;
//		while (n) {
//			next += (n % 10) * (n % 10);
//			n /= 10;
//		}
//		n = next;
//		if (set.find(n) != set.end()) {
//			for (auto e : set) {
//				map[e] = 0;
//			}
//			return false;
//		}
//		else if (map.find(n) != map.end()) {
//			int t = map[n];
//			for (auto e : set) {
//				map[e] = t;
//			}
//			return t == 1;
//		}
//		set.insert(n);
//	}
//	return true;
//}
//int get_ans(int n) {
//	int ret = 0;
//	unordered_map<int, int> map;
//	map[1] = 1;
//	for (int i = 1; i <= n; i++) {
//		if (map.find(i) != map.end()) {
//			ret += map[i];
//		}
//		else if (is_rowto1(i, map))
//		{
//			ret++;
//		}
//	}
//	return ret;
//}
//int main() {
//	int n;
//	cout << "Input your number: ";
//	cin >> n;
//	int count = 0;
//	count = get_ans(n);
//	cout << "the count is: " << count << endl;
//	getchar();
//	getchar();
//	return 0;
//}

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

