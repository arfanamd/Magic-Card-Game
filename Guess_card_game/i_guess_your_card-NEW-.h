/****************************************
 * Magic Card Game: I Guess Your Card   *
 * Written in C++                       *
 * Fri April 24 2020                    *
 * Author: arfanamd            ♠ ♣ ♥ ♦  *
 * **************************************/

#ifndef I_GUESS_YOUR_CARD
#define I_GUESS_YOUR_CARD

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <limits>
#include <ctime>
#include <ios>

#define CARDS_PER_STACK 4

class Stack_opt {
	private:
		unsigned short int cards[CARDS_PER_STACK] = {0};
		unsigned short int suits[CARDS_PER_STACK] = {0};

		unsigned short int cards_bak[CARDS_PER_STACK] = {0};
		unsigned short int suits_bak[CARDS_PER_STACK] = {0};
	public:
		Stack_opt Shuffle(Stack_opt *stack1, Stack_opt *stack2, Stack_opt *stack3);
		~Stack_opt() {}
		Stack_opt(void) {
			do {
				for(unsigned int SHAKE = 0; SHAKE < CARDS_PER_STACK; SHAKE++) {
					int _seed_ = std::rand();
					cards[SHAKE] = (_seed_ % 13) + 2; 		/* ace trough king */
					suits[SHAKE] = (_seed_ % CARDS_PER_STACK) + 1; 	/* diamond, scope, etc.. */

					cards_bak[SHAKE] = cards[SHAKE];
					suits_bak[SHAKE] = suits[SHAKE];
				}
			} while(Compare());
		}
		bool Compare(void) {
			if(cards[0] == cards[1] && suits[0] == suits[1]) return true;
			if(cards[0] == cards[2] && suits[0] == suits[2]) return true;
			if(cards[0] == cards[3] && suits[0] == suits[3]) return true;

			if(cards[1] == cards[2] && suits[1] == suits[2]) return true;
			if(cards[1] == cards[3] && suits[1] == suits[3]) return true;

			if(cards[2] == cards[3] && suits[2] == suits[3]) return true;

			return false;
		}
		void Show(void) {
			for(unsigned int SHOW = 0; SHOW < CARDS_PER_STACK; SHOW++) {
				Reveal(SHOW);
			}
		}
		void Reveal(unsigned int CARD) {
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
};

void Sleep(int duration);
void Clean_screen(void);
#endif
