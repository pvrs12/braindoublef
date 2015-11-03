#ifndef BDH_H
#define BDH_H

#include <vector>
#include <unordered_map>
#include <string>

#include "mod_n.h"

template<int N>
void dump(const std::string& header,const std::vector<mod_n<N>> v,int ptr, int edit_ptr=-1){
	std::cout<<header<<std::endl;
	for(unsigned i=0;i<v.size();++i){
		if(i==ptr){
			std::cout<<"--->";
		}
		char c = 0;
		if(v[i] < CHAR_LEN) {
			c=codeToChar[v[i]];
		}
		std::cout<<"\t"<<i<<"\t"<<v[i]<<"\t"<<c;
		if(i==edit_ptr){
			std::cout<<"  <---";
		}
		std::cout<<std::endl;
	}
}
#endif
