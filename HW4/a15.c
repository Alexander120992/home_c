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
	int x1, y1, x2, y2;
	double k, b;
	
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
	if (x1 == x2) {
        k = 0.0;
        b = 0.0;
    } else {
        k = (double)(y2 - y1) / (x2 - x1);
        b = y1 - k * x1;
    }
	
	printf("%.2f %.2f", k, b);
		
	return 0;
}
