#include	<iostream>
#include	<string>
#include	<vector>
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

	std::vector<int>::iterator current = vec.begin();

	while(true){
		current = std::find_if(current, vec.end(), [](int i) { return i % 3 == 2; });
		if(current == vec.end())
			break;
		std::cout << *current << std::endl;
		current++;
	}

	return 0;
}
