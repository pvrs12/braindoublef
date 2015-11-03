#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include <unistd.h>

//max value in memory cells
//and length of both program & memory tape
#define TAPE_LEN 256
//number of operators (max value of program cells)
#define CHAR_LEN 16

#include "mod_n.h"

std::unordered_map<char,mod_n<CHAR_LEN>> charToCode;
std::unordered_map<mod_n<CHAR_LEN>,char> codeToChar;

#include "bdf.h"

#ifndef DEBUG
#define DEBUG 1
#endif

class bad_program{};

void fill_maps(){
	char chars[] = {'\0','+','-','>','<','[',']','.',',','*','/','^','v','#','~','!'};
	for(int i = 0;i<CHAR_LEN;++i){
		charToCode[chars[i]]=i;
		codeToChar[i]=chars[i];
	}
}

std::vector<mod_n<CHAR_LEN>> read_file(char* filename){
	mod_n<TAPE_LEN> chars_read = 0;
	std::vector<mod_n<CHAR_LEN>> program(TAPE_LEN);

	std::ifstream fin(filename);
	char c;
	while(fin>>c){
		if(charToCode.find(c) == charToCode.end()){
			program[chars_read++]=0;
		} else {
			program[chars_read++]=charToCode[c];
		}
	}
	return program;
}

//finds the matching ]
int find_right(std::vector<mod_n<CHAR_LEN>>& v, mod_n<TAPE_LEN> start){
	mod_n<TAPE_LEN> i(start+1);

	int count= 0;
	while(i != start){
		char c;
		if(codeToChar.find(v[i+1])!=codeToChar.end()){
			c = codeToChar[v[i++]];
		} else {
			c = '\0';
			++i;
			continue;
		}
		if(c=='['){
			count++;
		}
		if(c==']' && count != 0){
			count --;
		}
		if(c==']' && count == 0){
			return i;
		}
	}
	throw bad_program();
	return -1;
}

//finds the matching [
int find_left(std::vector<mod_n<CHAR_LEN>>& v, mod_n<TAPE_LEN> start){
	mod_n<TAPE_LEN> i(start-1);
	
	int count= 0;
	while(i != start){
		char c;
		if(codeToChar.find(v[i-1])!=codeToChar.end()){
			c = codeToChar[v[i--]];
		} else {
			c = '\0';
			--i;
			continue;
		}		
		if(c==']'){
			count++;
		}
		if(c=='[' && count != 0){
			count --;
		}
		if(c=='[' && count == 0){
			return i;
		}
	}
	throw bad_program();
	return -1;
}

void run_program(std::vector<mod_n<CHAR_LEN>>& program,std::vector<mod_n<TAPE_LEN>>& memory, int delay = 0){
	mod_n<TAPE_LEN> pointer = 0;
	mod_n<TAPE_LEN> prog_pointer = 0;

	int i_ptr = 0;
	
	bool quit = false;

	while(!quit){
		int code = program[i_ptr++];
		if(codeToChar.find(code)==codeToChar.end()){
			continue;
		}
#if DEBUG == 1
		std::cout<<"Executing "<<codeToChar[code]<<std::endl;
#endif
		sleep(delay);
		switch(codeToChar[code]){
			case('+'):
				memory[pointer]++;
				break;
			case('-'):
				memory[pointer]--;
				break;
			case('>'):
				pointer++;
				break;
			case('<'):
				pointer--;
				break;
			case('['):
				if(!memory[pointer]){
					i_ptr = find_right(program,i_ptr);
#if DEBUG == 1
					std::cout<<"Jumping forward to "<<i_ptr<<"\t"<<memory[pointer]<<std::endl;
#endif
				}
#if DEBUG == 1
				else{
					std::cout<<"Not taking jump\t"<<memory[pointer]<<std::endl;
				}
#endif
				break;
			case(']'):
				if(memory[pointer]){
					i_ptr = find_left(program,i_ptr)+1;
#if DEBUG == 1
					std::cout<<"Jumping back to "<<i_ptr<<"\t"<<memory[pointer]<<std::endl;
#endif
				}
				break;
			case('.'):
				std::cout<<(char)memory[pointer];
				break;
			case(','):
				char c;
				std::cin>>c;
				memory[pointer] = mod_n<TAPE_LEN>((int)c);
				break;
			case('*'):
				program[prog_pointer]++;
				break;
			case('/'):
				program[prog_pointer]--;
				break;
			case('^'):
				prog_pointer++;
				break;
			case('v'):
				prog_pointer--;
				break;
			case('#'):
				quit = true;
				break;
			case('~'):
				dump(program,i_ptr,prog_pointer);
				break;
			case('!'):
				dump(memory,pointer);
				break;
		}
	}
}

int main(int argc, char* argv[]){
	if(argc < 2){
		std::cerr<<"Usage: "<<argv[0]<<" <bdfProgram>"<<std::endl;
		return 1;
	}
	
	float delay = 0;
	if(argc == 3){
		delay = 1;
	}

	fill_maps();

	char* file = argv[1];
	std::vector<mod_n<CHAR_LEN>> program = read_file(file);
	std::vector<mod_n<TAPE_LEN>> memory(TAPE_LEN);
	run_program(program,memory,delay);

	dump(memory,0);

	return 0;
}
