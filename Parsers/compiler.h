#ifndef COMPILER_H_
#define COMPILER_H_

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <utility>
#include <stack>


using namespace std;


enum type { terminal = 0, non_terminal = 1 };

typedef struct {
	string name;
	type ToN; //Terminal or Non-terminal :D
}Sayyed; //name as suggested by Hassan

class Node {
public:
	string data;
	Node* children[8];

	Node() {
		for (int i = 0; i < 8; i++) {
			children[i] = NULL;
		}
	}

	Node(string d) {
		data = d;
		for (int i = 0; i < 8; i++) {
			children[i] = NULL;
		}
	}

	void add_child(Node* d) {
		int i = 0;
		while (children[i] != NULL) {
			i++;
		}
		children[i] = d;
	}

	bool has_children() {
		return children[0] != NULL;
	}

	int number_of_children() {
		int i = 0;
		while (children[i] != NULL) {
			i++;
		}
		return i;
	}
};

extern map<string, string> words;
extern pair<string, string> token_pairs[10000];
extern int number_of_tokens;

void init_lang();
bool add_token_pair(string);
void lex(string);
void read_lines(string);
bool check_id_names_validity();
void lex_output();

int parse_ll1(string input[100]);
void div_and_parse_ll1();

void div_and_parse_slr0();

Node* parse_slr0(string input[100]);

#endif