/****************************************
 * Magic Card Game: I Guess Your Card   *
 * Written in C++                       *
 * Fri April 24 2020                    *
 * Author: arfanamd            ♠ ♣ ♥ ♦ *
 * **************************************/

#include "i_guess_your_card-NEW-.h"

Stack_opt::~Stack_opt(void) {}
Stack_opt::Stack_opt(void) {
	do {
		for(unsigned int SHAKE = 0; SHAKE < CARDS_PER_STACK; SHAKE++) {
			int _seed_ = sdt::rand();
			cards[SHAKE] = (_seed_ % 13) + 2;	/* ace through king */
			suits[SHAKE] = (_seed_ % CARDS_PER_STACK) + 1;	/* diamond, scope, etc. */
			
			cards_bak[SHAKE] = cards[SHAKE];
			suits_bak[SHAKE] = suits[SHAKE];
		}
	} while(Compare());
}
bool Stack_opt::Compare(void) {
	if(cards[0] == cards[1] && suits[0] == suits[1]) return true;
	if(cards[0] == cards[2] && suits[0] == suits[2]) return true;
	if(cards[0] == cards[3] && suits[0] == suits[3]) return true;
	
	if(cards[1] == cards[2] && suits[1] == suits[2]) return true;
	if(cards[1] == cards[3] && suits[1] == suits[3]) return true;
	
	if(cards[2] == cards[3] && suits[2] == suits[3]) return true;
	
	return false;
}
void Stack_opt::Shuffle(Stack_opt *stack1, Stack_opt *stack2, Stack_opt *stack3) {
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
void Stack_opt::Show(void) {
	for(unsigned int SHOW = 0; SHOW < CARDS_PER_STACK; SHOW++) {
		Reveal(SHOW);
	}
}
void Stack_opt::Reveal(unsigned int CARD) {
	std::printf("|");
	switch(suits[CARD]) {
		case 1:
			if(cards[CARD] <= 10) {
				std::printf("\e[47;31m%2d♦ \e[0m", cards[CARD]);
			} else {
				switch(cards[CARD]) {
					case 11:
						std::printf("\e[47;31m J♦ \e[0m");
						break;
					case 12:
						std::printf("\e[47;31m Q♦ \e[0m");
						break;
					case 13:
						std::printf("\e[47;31m K♦ \e[0m");
						break;
					case 14:
						std::printf("\e[47;31m A♦ \e[0m");
						break;
				}
			}
			break;
		case 2:
			if(cards[CARD] <= 10) {
				std::printf("\e[47;31m%2d♥ \e[0m", cards[CARD]);
			} else {
				switch(cards[CARD]) {
					case 11:
						std::printf("\e[47;31m J♥ \e[0m");
						break;
					case 12:
						std::printf("\e[47;31m Q♥ \e[0m");
						break;
					case 13:
						std::printf("\e[47;31m K♥ \e[0m");
						break;
					case 14:
						std::printf("\e[47;31m A♥ \e[0m");
						break;
				}
			}
			break;
		case 3:
			if(cards[CARD] <= 10) {
				std::printf("\e[47;30m%2d♣ \e[0m", cards[CARD]);
			} else {
				switch(cards[CARD]) {
					case 11:
						std::printf("\e[47;30m J♣ \e[0m");
						break;
					case 12:
						std::printf("\e[47;30m Q♣ \e[0m");
						break;
					case 13:
						std::printf("\e[47;30m K♣ \e[0m");
						break;
					case 14:
						std::printf("\e[47;30m A♣ \e[0m");
						break;
				}
			}
			break;
		case 4:
			if(cards[CARD] <= 10) {
				std::printf("\e[47;30m%2d♠ \e[0m", cards[CARD]);
			} else {
				switch(cards[CARD]) {
					case 11:
						std::printf("\e[47;30m J♠ \e[0m");
						break;
					case 12:
						std::printf("\e[47;30m Q♠ \e[0m");
						break;
					case 13:
						std::printf("\e[47;30m K♠ \e[0m");
						break;
					case 14:
						std::printf("\e[47;30m A♠ \e[0m");
						break;
				}
			}
			break;
	}
	std::printf("|");
}

void Sleep(int duration) {
	std::this_thread::sleep_for(std::chrono::milliseconds(duration * 1000));
}
void Clean_screen(void) {
	system("clear");
}
