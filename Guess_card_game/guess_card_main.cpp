/****************************************
 * Magic Card Game: I Guess Your Card   *
 * Written in C++                       *
 * Fri April 24 2020                    *
 * Author: arfanamd           ♠ ♣ ♥ ♦ *
 * **************************************/

#include "i_guess_your_card-NEW-.h"
 
void Play_game(Stack_opt &stack1, Stack_opt &stack2, Stack_opt &stack3) {
	Stack_opt junk;

	char ent_key[1];
	unsigned short int pick = 1;
	unsigned short int stat = 0;

	Clean_screen();

	stack1.Show(); std::puts("\n");
	stack2.Show(); std::puts("\n");
	stack3.Show(); std::puts("\n");

	std::printf("   --: Pick your card! :--\n");
	std::printf("just look at it and press enter");
	std::fgets(ent_key, sizeof(ent_key), stdin);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while( 1 ) {
		if(pick == 1) {
			junk.Shuffle(&stack1, &stack2, &stack3);
		} else if(pick == 2) {
			junk.Shuffle(&stack2, &stack1, &stack3);
		} else if(pick == 3 && stat <= 1) {
			junk.Shuffle(&stack3, &stack1, &stack2);
		} else if(pick == 3 && stat >= 2) {
			break;
		} else {
			std::puts("wth??..");
			Sleep(2);
			std::puts("dude, you have one job.. Damn");
			goto UNEDUCATED_PLAYER;
		}

		Clean_screen();

		stack1.Show(); std::printf(" \e[1;31m(1)\e[0m\n\n");
		stack2.Show(); std::printf(" \e[1;31m(2)\e[0m\n\n");
		stack3.Show(); std::printf(" \e[1;31m(3)\e[0m\n\n");

		Sleep(1);

		std::puts("in wich stack your card is showin' up?");
		std::printf("[1, 2, or 3] ? ");
		std::cin >> pick;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		stat++;
	}

	Clean_screen();
	std::printf("Your card is ");
	Sleep(1);
	stack3.Reveal(0);
	std::putchar('\n');

UNEDUCATED_PLAYER:
	junk.~Stack_opt();
}
int main(void) {
	std::srand(std::time(0));

	Stack_opt stack1, stack2, stack3;
	Play_game(stack1, stack2, stack3);

	stack1.~Stack_opt();
	stack2.~Stack_opt();
	stack3.~Stack_opt();

	return 0;
}
