#include <stdio.h>
#include <stdlib.h>
#include <apu2_gpio.h>

void usage(char *app_name) {
    printf("Usage:\n\t%s value\n", app_name);
}

int main(int argc, char *argv[]) {

    int status;
    int val;

    status = apu_gpio_init();
    if (status < 0) {
        printf("can't initialize the gpio lib: %d\n", status);
        return -1;
    }

    if (argc < 2) {
        printf("RESET3 current value: %d\n", apu_gpio_get_val(APU_RESET3));
        return 0;
    }

    switch (argv[1][0]) {
        case '1':
            val = 1;
            break;
        case '0':
            val = 0;
            break;
        default:
            usage(argv[0]);
            return -1;
    }

    if (apu_gpio_get_dir(APU_RESET3) != APU_DIR_OUT) {
        printf("changing RESET3 pin direction to out\n");
        status = apu_gpio_set_dir(APU_RESET3, APU_DIR_OUT);
        if (status < 0) {
            printf("can't set the RESET3 direction: %d\n", status);
            return -1;
        }
    }

    status = apu_gpio_set_val(APU_RESET3, val);
    if (status < 0) {
        printf("can't set the RESET3 value: %d\n", status);
    }

    printf("RESET3 current value: %d\n", apu_gpio_get_val(APU_RESET3));

    return 0;
}
