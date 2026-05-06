/*
 * test.c
 * 
 * Copyright 2026 Akarna <Akarna@DESKTOP-82JJA0E>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>

int main()
{ 
	int a;
	
	scanf("%d", &a);
	
	int a1 = a / 100;
	int a2 = (a / 10) % 10;
	int a3 = a % 10;
	
	int max_a = a1;
	
	if (a2 > max_a) {
        max_a = a2; 
    }
    
    if (a3 > max_a) {
        max_a = a3;  // Обновляем, если третья цифра больше
    }
	
	printf("%d\n", max_a);
		
	return 0;
}
