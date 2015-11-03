#ifndef BDH_H
#define BDH_H

#include <vector>
#include <unordered_map>

#include "mod_n.h"

template<int N>
void dump(std::vector<mod_n<N>> v,int ptr, int edit_ptr=-1){
	for(unsigned i=0;i<v.size();++i){
		if(i==ptr){
			std::cout<<"--->";
		}
		char c;
		if(codeToChar.find(v[i])==codeToChar.end()){
			c=codeToChar[v[i]];
		} else {
			c = '\0';
		}
		std::cout<<"\t"<<i<<"\t"<<v[i]<<"\t"<<c;
		if(i==edit_ptr){
			std::cout<<"  <---";
		}
		std::cout<<std::endl;
	}
}
#endif
