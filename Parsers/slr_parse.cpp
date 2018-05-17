#include "compiler.h"
#include "init_parser_slr0.h"
#include <stdio.h>
#include <stdlib.h>

string temp_ar2[100];
Node* head;

int rec[100];

void printTree(Node* curr, int depth) {
	int i = 0, j = 0;

	for (i = 0; i < depth; i++)
		if (i == depth - 1)
			printf("%s--- ", rec[depth - 1] ? ">" : "-");
		else
			printf("|   ");

	cout << curr->data << endl;

	rec[depth] = 1;
	while (curr->children[j] != NULL) {
		printTree(curr->children[curr->number_of_children() - j - 1], depth + 1);
		j++;
	}
}

Node* parse_slr0(string input[100]) {
	stack <int> state_stack;
	state_stack.push(0);

	stack <Node*> node_stack;

	int itr = 0;
	string current_token = input[itr];

	while (true) {
		int state = state_stack.top();
		int current_token_index = slr0_terminals[current_token];
		if (ACTION[state][current_token_index][0] == 's') {
			int a = atoi(&ACTION[state][current_token_index][1]);
			state_stack.push(a);

			Node* n = new Node(current_token);
			node_stack.push(n);

			itr++;
			current_token = input[itr];
		}
		else if (ACTION[state][current_token_index][0] == 'r') {

			int rule_index = atoi(&ACTION[state][current_token_index][1]);

			Node* p = new Node(rules[rule_index].first);

			for (int i = 0; i < rules[rule_index].second; i++) {
				state_stack.pop();

				p->add_child(node_stack.top());
				node_stack.pop();
			}
			node_stack.push(p);

			state = state_stack.top();

			int nonterminal_index = slr0_nonterminals[rules[rule_index].first];
			state_stack.push(GOTO[state][nonterminal_index]);
		}
		else if (ACTION[state][current_token_index] == "acc") {
			cout << "------------------------------------------------------------\n";
			printTree(node_stack.top(), 0);

			cout << "------------------------------------------------------------\n                      --- Parsing OK ---                     \n------------------------------------------------------------\n";

			return node_stack.top();
		}
		else {
			cout << "Parsing Error... Input not compatible with grammar\n" << endl;
			return NULL;
		}
	}
}

void div_and_parse_slr0()
{
	cout << "------------------------------------------------------------\n";
	int idx = 0, j = 0;
	bool if_flag = false;

	cout << endl << endl;




	for (int i = 0; (i <= number_of_tokens); i++)
	{

		if ((token_pairs[i - 1].second == ";") && (!if_flag))
		{
			temp_ar2[j] = "$";

			cout << endl;
			head = parse_slr0(temp_ar2);
			j = 0;
		}


		if (token_pairs[i].second == "if" || token_pairs[i].second == "while") {
			if_flag = true;
		}
		else if (token_pairs[i].second == "endif" || token_pairs[i].second == "endwhile") {
			if_flag = false;
			temp_ar2[j] = token_pairs[i].second;
		}



		if (token_pairs[i].first == "identifier")
		{
			temp_ar2[j] = "identifier";
			cout << token_pairs[i].second << " ";
		}
		else if (token_pairs[i].first == "string")
		{
			temp_ar2[j] = "string";
			cout << token_pairs[i].second << " ";
		}
		else if (token_pairs[i].first == "number")
		{
			temp_ar2[j] = "number";
			cout << token_pairs[i].second << " ";
		}
		else {
			temp_ar2[j] = token_pairs[i].second;
			cout << token_pairs[i].second << " ";
		}
		j++;
	}
}