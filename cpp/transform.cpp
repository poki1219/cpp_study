#include	<iostream>
#include	<vector>
#include	<string>
#include	<algorithm>
#include	<functional>

template <typename Iter>
void print(Iter begin, Iter end){
	while(begin != end){
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;
}

int main(){
	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	std::vector<int> vec2(6, 0);

	print(vec.begin(), vec.end());
	print(vec2.begin(), vec2.end());

	std::transform(vec.begin(), vec.end(), vec2.begin(), [](int i) { return i+1; });

	std::cout << std::endl;
	print(vec.begin(), vec.end());
	print(vec2.begin(), vec2.end());
}
