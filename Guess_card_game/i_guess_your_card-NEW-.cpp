/****************************************
 * Magic Card Game: I Guess Your Card   *
 * Written in C++                       *
 * Fri April 24 2020                    *
 * Author: arfanamd            ♠ ♣ ♥ ♦ *
 * **************************************/

#include "i_guess_your_card-NEW-.h"

Stack_opt Stack_opt::Shuffle(Stack_opt *stack1, Stack_opt *stack2, Stack_opt *stack3) {
/*-	stack 1 = 1{0, 3}, 2{2}, 3{1}	-*
 *-	stack 2 = 1{1}, 2{0,3}, 3{2}	-*
 *-	stack 3 = 1{2}, 2{1}, 3{0, 3}	-*/

	Stack_opt junk;
	stack1->cards[3] = stack3->cards_bak[2]; stack1->suits[3] = stack3->suits_bak[2];
	stack1->cards[2] = stack2->cards_bak[1]; stack1->suits[2] = stack2->suits_bak[1];
	stack1->cards[1] = stack1->cards_bak[0]; stack1->suits[1] = stack1->suits_bak[0];
	stack1->cards[0] = stack1->cards_bak[3]; stack1->suits[0] = stack1->suits_bak[3];

	stack2->cards[3] = stack3->cards_bak[1]; stack2->suits[3] = stack3->suits_bak[1];
	stack2->cards[2] = stack2->cards_bak[0]; stack2->suits[2] = stack2->suits_bak[0];
	stack2->cards[1] = stack2->cards_bak[3]; stack2->suits[1] = stack2->suits_bak[3];
	stack2->cards[0] = stack1->cards_bak[2]; stack2->suits[0] = stack1->suits_bak[2];

	stack3->cards[3] = stack3->cards_bak[0]; stack3->suits[3] = stack3->suits_bak[0];
	stack3->cards[2] = stack3->cards_bak[3]; stack3->suits[2] = stack3->suits_bak[3];
	stack3->cards[1] = stack2->cards_bak[2]; stack3->suits[1] = stack2->suits_bak[2];
	stack3->cards[0] = stack1->cards_bak[1]; stack3->suits[0] = stack1->suits_bak[1];

	stack1->cards_bak[0] = stack1->cards[0]; stack1->suits_bak[0] = stack1->suits[0];
	stack1->cards_bak[1] = stack1->cards[1]; stack1->suits_bak[1] = stack1->suits[1];
	stack1->cards_bak[2] = stack1->cards[2]; stack1->suits_bak[2] = stack1->suits[2];
	stack1->cards_bak[3] = stack1->cards[3]; stack1->suits_bak[3] = stack1->suits[3];

	stack2->cards_bak[0] = stack2->cards[0]; stack2->suits_bak[0] = stack2->suits[0];
	stack2->cards_bak[1] = stack2->cards[1]; stack2->suits_bak[1] = stack2->suits[1];
	stack2->cards_bak[2] = stack2->cards[2]; stack2->suits_bak[2] = stack2->suits[2];
	stack2->cards_bak[3] = stack2->cards[3]; stack2->suits_bak[3] = stack2->suits[3];

	stack3->cards_bak[0] = stack3->cards[0]; stack3->suits_bak[0] = stack3->suits[0];
	stack3->cards_bak[1] = stack3->cards[1]; stack3->suits_bak[1] = stack3->suits[1];
	stack3->cards_bak[2] = stack3->cards[2]; stack3->suits_bak[2] = stack3->suits[2];
	stack3->cards_bak[3] = stack3->cards[3]; stack3->suits_bak[3] = stack3->suits[3];

	return junk;
}

void Sleep(int duration) {
	std::this_thread::sleep_for(std::chrono::milliseconds(duration * 1000));
}

void Clean_screen(void) {
	system("clear");
}

void Play_game(Stack_opt &stack1, Stack_opt &stack2, Stack_opt &stack3) {
	Stack_opt junk;

	char ent_key[2];
	unsigned short int pick = 1;
	unsigned short int stat = 0;

	Clean_screen();

	stack1.Show(); std::puts("\n");
	stack2.Show(); std::puts("\n");
	stack3.Show(); std::puts("\n");

	std::printf("   --: Pick one card! :--\n");
	std::printf("just remember it and press enter");
	std::fgets(ent_key, sizeof(ent_key), stdin);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	while( 1 ) {
		if(pick == 1) {
			junk = junk.Shuffle(&stack1, &stack2, &stack3);
		} else if(pick == 2) {
			junk = junk.Shuffle(&stack2, &stack1, &stack3);
		} else if(pick == 3 && stat <= 1) {
			junk = junk.Shuffle(&stack3, &stack1, &stack2);
		} else if(pick == 3 && stat >= 2) {
			break;
		} else {
			std::puts("wth dude??..");
			Sleep(2);
			goto UNEDUCATED_PLAYER;
		}

		Clean_screen();

		stack1.Show(); std::printf(" (1)\n\n");
		stack2.Show(); std::printf(" (2)\n\n");
		stack3.Show(); std::printf(" (3)\n\n");

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

