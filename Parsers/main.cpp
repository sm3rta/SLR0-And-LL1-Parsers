#include "compiler.h"

int number_of_tokens = 0;
map<string, string> words;
pair<string, string> token_pairs[10000];

int main() {

	char ch;

	init_lang();

	read_lines("test.txt");

	while (true) {
		cout << "------------------------------------------------------------\n";
		cout << " 1. to show the lexical analysis output" << endl;
		cout << " 2. to use the top-down parser" << endl;
		cout << " 3. to use the bottom-up parser " << endl;
		cout << " 4. to exit " << endl;
		cin >> ch;
		switch (ch) {
		case '1':
			lex_output();
			break;
		case '2':
			div_and_parse_ll1();
			break;
		case '3':
			div_and_parse_slr0();
			break;
		case '4':
			exit(0);
			break;
		default:
			cout << " invalid choice..." << endl;
		}
	}

	return 0;
}