/*
 * app_bcd.c
 *
 *  Created on: 1 de may. de 2021
 *      Author: root
 */

#include "../include/app_bcd_display.h"

void deco_bcd(int number, int *segPointer) {

	switch (number) {
	case 0:
		*segPointer = 126;
		break;
	case 1:
		*segPointer = 48;
		break;
	case 2:
		*segPointer = 109;
		break;
	case 3:
		*segPointer = 121;
		break;
	case 4:
		*segPointer = 51;
		break;
	case 5:
		*segPointer = 91;
		break;
	case 6:
		*segPointer = 95;
		break;
	case 7:
		*segPointer = 112;
		break;
	case 8:
		*segPointer = 127;
		break;
	case 9:
		*segPointer = 123;
		break;
	default:
		*segPointer = 123;
		break;

	}
}

void number_to_bcd(int number, int *segPointer1, int *segPointer2) {
	int right = number % 10;
	int left = number / 10;
	deco_bcd(left, segPointer1);
	deco_bcd(right, segPointer2);

}

void display_hour(int number) {
	number_to_bcd(number, seg_h1, seg_h2);
}
void display_minute(int number) {
	number_to_bcd(number, seg_m1, seg_m2);
}
void display_second(int number) {
	alt_putstr("hola\n");
	number_to_bcd(number, seg_s1, seg_s2);
}

void init_display() {
	seg_h2 = (int *) (REG_H2_BASE);
	seg_h1 = (int *) (REG_H1_BASE);
	seg_m1 = (int *) (REG_M2_BASE);
	seg_m2 = (int *) (REG_M1_BASE);
	seg_s2 = (int *) (REG_S2_BASE);
	seg_s1 = (int *) (REG_S1_BASE);
}
