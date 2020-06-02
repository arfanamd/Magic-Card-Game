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
		
		~Stack_opt(void);
		Stack_opt(void);
	
		bool Compare(void);
		void Shuffle(Stack_opt *stack1, Stack_opt *stack2, Stack_opt *stack3);
		void Show(void);
		void Reveal(unsigned int CARD);
};

void Sleep(int duration);
void Clean_screen(void);

#endif /* I_GUESS_YOUR_CARD */
