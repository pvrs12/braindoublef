#ifndef MOD_N_H
#define MOD_N_H

class mod_n_exception{};

template<int N>
class mod_n {
private:
	int number;

public:
	mod_n<N>():
		number(0) {
	}

	mod_n<N>(int i):
		number(i) {
		if(number < 0){
			throw mod_n_exception();
		}
		number %= N;
	}

	template<int M>
	inline operator mod_n<M>()const {
		return get_int() % M;
	}

	inline operator int() const{
		return get_int();
	}
	
	int operator+(int i) const;
	int operator-(int i) const;

	int operator++();
	int operator--();

	int operator++(int);
	int operator--(int);

	bool operator==(const mod_n<N> n) const;

	int get_N() const;
	int get_int() const;

};

#include "mod_n.ipp"
#endif
