#include <stdio.h>

void display_usage(void);
float fahrenheit_to_celcius(float result);
float celcius_to_fahrenheit(float result);

int main(int argc, char *argv[]) {

    // hold if conversion was successful
    typedef enum { false, true } bool;
    bool success = false;

    // make sure argument was passed
    if (argc == 2) {

        float degree;
        char unit;

        // check for float and character
        if (sscanf(argv[1], "%f%c", &degree, &unit) == 2) {

            // convert unit to upper case
            unit = toupper(unit);

            // check for valid unit
            if ((unit == 'C') || (unit == 'F')) {

                float result;
                char resunit;

                // convert to celcius
                if (unit == 'F') {

                    result = fahrenheit_to_celcius(degree);
                    resunit = 'C';

                // convert to fahrenheit
                } else {

                    result = celcius_to_fahrenheit(degree);
                    resunit = 'F';
                }

                success = true;

                // display result
                printf("%g%c\n", result, resunit);
            }
        }
    }

    // display usage if no result
    if (!success) display_usage();

   return 0;
}

float celcius_to_fahrenheit(float degree) {

    return (degree - 32) * (5.0f / 9.0f);
}

float fahrenheit_to_celcius(float degree) {

    return (degree * 1.8f) + 32;
}

void display_usage(void) {

   printf("usage: [number][F, f, C, or c]\n");
   printf("example:  32.98F\n");
}


