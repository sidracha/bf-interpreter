#include <filesystem>
#include <iostream>
#include <map>
#include <stack>
#include <fstream>

namespace fs = std::filesystem;


#define MAX_TAPE 10000

void interpret (char* code, size_t len) {

	//first we create the brace map
	
	std::stack<int> stack;

	std::map<int, int> bracket_map; 

	for (int i = 0; i < len; i++) {
		
		if (code[i] == '[') {
			
			stack.push(i);

		}
		else if (code[i] == ']') {
			
			int idx = stack.top(); //get the most recent opened bracket
			stack.pop();

			bracket_map[idx] = i;
			bracket_map[i] = idx;

		}
		
	}

	//now run through the code and interpret
	
	
	uint8_t tape[10000] = {0};	

	int code_ptr = 0;
	int tape_ptr = 0;

	while (code_ptr < len) {
		

		if (tape_ptr > MAX_TAPE) {return;}
		
		switch (code[code_ptr]) {
			
			case '>':
				tape_ptr++;
				break;
			
			case '<':
				tape_ptr--;
				break;

			case '+':
				tape[tape_ptr] += 1;
				break;

			case '-':
				tape[tape_ptr] -= 1;
				break;

			case '.':
				//std::cout << tape[tape_ptr];
				std::cout << static_cast<unsigned char>(tape[tape_ptr]);

				break;

			case ',':
				
				char in;
				in = getchar();

				tape[tape_ptr] = static_cast<int>(in);

				
				break;

			case '[':
				
				if ( (int)tape[tape_ptr] == 0) {
					code_ptr = bracket_map[code_ptr];
					continue;
				}
				break;


			case ']':
				
				if ( (int)tape[tape_ptr] != 0) {
					code_ptr = bracket_map[code_ptr];
				}
				break;
			
		}
		code_ptr++;



	}


}


