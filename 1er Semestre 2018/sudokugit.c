/*
 * Sudoku Solver (brute-force).
 * with the purpose of beeing fast as hell. It's pretty fast.
 * 2012 Anton Fagerberg [anton at antonfagerberg dot com]
 * wwww.antonfagerberg.com
 */
#include <stdio.h>
#include <stdint.h>

/* "Near worst case" Sudoku
 * http://en.wikipedia.org/wiki/Sudoku_algorithms#Brute-force_algorithm
 */
uint16_t puzzle[81] = {
	0,0,0,		0,0,0,		0,0,0,
	0,0,0,		0,0,4,		0,128,16,
	0,0,1,		0,2,0,		0,0,0,

	0,0,0,		16,0,64,	0,0,0,
	0,0,8,		0,0,0,		1,0,0,
	0,256,0,	0,0,0,		0,0,0,

	16,0,0,		0,0,0,		0,64,4,
	0,0,2,		0,1,0,		0,0,0,
	0,0,0,		0,8,0,		0,0,256
};

uint8_t solve(uint8_t i) {
	// Solved it!
	if (!(i ^ 81))
		return 1;

	// Skip the positions which are defined from the start.
	if (puzzle[i]) 
		return solve(i + 1);

	uint8_t align = i % 9;
	uint16_t valid_numbers = puzzle[ align ];
	valid_numbers = valid_numbers | puzzle[ align + 9 ];
	valid_numbers = valid_numbers | puzzle[ align + 18 ];
	valid_numbers = valid_numbers | puzzle[ align + 27 ];
	valid_numbers = valid_numbers | puzzle[ align + 36 ];
	valid_numbers = valid_numbers | puzzle[ align + 45 ];
	valid_numbers = valid_numbers | puzzle[ align + 54 ];
	valid_numbers = valid_numbers | puzzle[ align + 63 ];
	valid_numbers = valid_numbers | puzzle[ align + 72 ];

	align = i / 9 * 9;
	valid_numbers = valid_numbers | puzzle[ align ];
	valid_numbers = valid_numbers | puzzle[ align + 1 ];
	valid_numbers = valid_numbers | puzzle[ align + 2 ];
	valid_numbers = valid_numbers | puzzle[ align + 3 ];
	valid_numbers = valid_numbers | puzzle[ align + 4 ];
	valid_numbers = valid_numbers | puzzle[ align + 5 ];
	valid_numbers = valid_numbers | puzzle[ align + 6 ];
	valid_numbers = valid_numbers | puzzle[ align + 7 ];
	valid_numbers = valid_numbers | puzzle[ align + 8 ];
	
	// Check "squares"
	align = 27 * (i / 9 / 3) + 3 * (i / 3 % 3);
	valid_numbers = valid_numbers | puzzle[ align ];
	valid_numbers = valid_numbers | puzzle[ align + 9 ];
	valid_numbers = valid_numbers | puzzle[ align + 18 ];

	valid_numbers = valid_numbers | puzzle[ align + 1 ];
	valid_numbers = valid_numbers | puzzle[ align + 10 ];
	valid_numbers = valid_numbers | puzzle[ align + 19 ];
	
	valid_numbers = valid_numbers | puzzle[ align + 2 ];
	valid_numbers = valid_numbers | puzzle[ align + 11 ];
	valid_numbers = valid_numbers | puzzle[ align + 20 ];

	uint8_t next = i + 1;
	if (!(valid_numbers & 1)) {
		puzzle[i] = 1;
		if (solve(next))
			return 1;
	}
	if (!(valid_numbers & 2)) {
		puzzle[i] = 2;
		if (solve(next))
			return 1;
	}
	if (!(valid_numbers & 4)) {
		puzzle[i] = 4;
		if (solve(next))
			return 1;
	}
	if (!(valid_numbers & 8)) {
		puzzle[i] = 8;
		if (solve(next))
			return 1;
	}
	if (!(valid_numbers & 16)) {
		puzzle[i] = 16;
		if (solve(next))
			return 1;
	}
	if (!(valid_numbers & 32)) {
		puzzle[i] = 32;
		if (solve(next))
			return 1;
	}
	if (!(valid_numbers & 64)) {
		puzzle[i] = 64;
		if (solve(next))
			return 1;
	}
	if (!(valid_numbers & 128)) {
		puzzle[i] = 128;
		if (solve(next))
			return 1;
	}
	if (!(valid_numbers & 256)) {
		puzzle[i] = 256;
		if (solve(next))
			return 1;
	}

	return puzzle[i] = 0;
}

void print_puzzle() {
	uint8_t i;
	for (i = 0; i < 81; i += 1) {
		if (!(i % 27))
			printf("\n+-------+-------+-------+");
		if (!(i % 9))
			printf("\n");
		if (!(i % 3))
			printf("| ");
		int count = 0;
		while (puzzle[i]) {
			puzzle[i] = puzzle[i] >> 1;
			count++;
		}
		printf("%i ", count);
		if (i % 9 == 8)
			printf("|");
	}
	printf("\n+-------+-------+-------+\n");
}

int main() {
	if (solve(0))
		print_puzzle();
	else
	 	printf("Did not solve puzzle. Check input...");
	return 0;
}