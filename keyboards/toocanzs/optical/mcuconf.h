/* Copyright 2021 QMK
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

<<<<<<< Updated upstream:keyboards/toocanzs/optical/mcuconf.h
#include_next "mcuconf.h"
=======
#include_next "mcuconf.h"

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE

#undef STM32_PWM_USE_TIM5
#define STM32_PWM_USE_TIM5 TRUE

#undef STM32_ADC_USE_ADC1
#define STM32_ADC_USE_ADC1 TRUE
>>>>>>> Stashed changes:keyboards/toocanzs/onekey/blackpill_f411/mcuconf.h
