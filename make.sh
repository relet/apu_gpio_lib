#!/bin/ash 

gcc -I. example/wifi3.c src/apu2_gpio.c -o wifi3
gcc -I. example/reset3.c src/apu2_gpio.c -o reset3
gcc -I. example/wifi2.c src/apu2_gpio.c -o wifi2
gcc -I. example/reset2.c src/apu2_gpio.c -o reset2
gcc -I. example/simswap.c src/apu2_gpio.c -o simswap
