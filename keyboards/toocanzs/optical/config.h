/* 
 * Copyright 2022 Bradley Saunders
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#undef VENDOR_ID
#define VENDOR_ID       0x200C
#undef PRODUCT_ID
#define PRODUCT_ID      0x2155
#undef MANUFACTURER
#define MANUFACTURER    Toocanzs
#undef PRODUCT
#define PRODUCT         Optical Keyboard
/* USB Device descriptor parameter */
#define DEVICE_VER 0x0000

/*
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
*/

#undef MATRIX_ROWS
#undef MATRIX_COLS
/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 12

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS

#define FORCE_NKRO
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 4
#define ONESHOT_TIMEOUT 1000