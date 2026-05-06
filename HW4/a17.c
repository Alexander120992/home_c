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

int main() {
    int month;
    
    scanf("%d", &month);
    
    if (month < 1 || month > 12) {
        printf("Invalid month\n");
        return 1;
    }
    
    if (month == 12 || month == 1 || month == 2) {
        printf("winter\n");
    } else if (month >= 3 && month <= 5) {
        printf("spring\n");
    } else if (month >= 6 && month <= 8) {
        printf("summer\n");
    } else if (month >= 9 && month <= 11) {
        printf("autumn\n");
    }
    
    return 0;
}
