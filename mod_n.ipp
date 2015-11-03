template<int N>
int mod_n<N>::operator+(int i) const{
    return (number + i) % N;
}

template<int N>
int mod_n<N>::operator-(int i) const{
	int temp = number;
	for(int j=0;j<i;++j){
		temp--;
		if(temp == -1){
			temp = N - 1;
		}
	}
	return temp;
}

template<int N>
int mod_n<N>::operator++(){
	number += 1;
	number %= N;
	return number;
}

template<int N>
int mod_n<N>::operator--(){
	number -= 1;
	if(number == -1){
		number = N-1;
	}
	return number;
}

template<int N>
int mod_n<N>::operator++(int){
	int temp = number;
	number += 1;
	number %= N;
	return temp;
}

template<int N>
int mod_n<N>::operator--(int){
	int temp = number;
	number -= 1;
	if(number == -1){
		number = N-1;
	}
	return temp;
}

template<int N>
bool mod_n<N>::operator==(mod_n<N> n) const{
	return get_int() == n.get_int();
}

template<int N>
int mod_n<N>::get_int() const{
	return number;
}

template<int N>
int mod_n<N>::get_N() const{
	return N;
}

namespace std {
	template<int N>
	struct hash<mod_n<N>>
	{
		std::size_t operator()(const mod_n<N>& n) const {
			return std::hash<int>()(n.get_int());
		}
	};
}
