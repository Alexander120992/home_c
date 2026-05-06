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
	int a, b, c, d, e;
	int max;
	
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	max = a; 
    
    if (b > max) {
        max = b; 
    }
    
    if (c > max) {
        max = c; 
    }
    
    if (d > max) {
        max = d; 
    }
    
    if (e > max) {
        max = e; 
    }
    
    printf("%d\n", max);
		
	return 0;
}
