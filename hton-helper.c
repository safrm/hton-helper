
/****************************************************************************
**
** Author: Miroslav Safr <miroslav.safr@gmail.com>
** Source: http://safrm.net/projects/hton-helper
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

void printHeader()
{
    printf("\n        int       htons       htonl       ntohs       ntohl\n");
}

void printLine(long number)
{
    printf("%11ld %11u %11u %11u %11u\n", number, (uint16_t)htons((uint16_t)number), (uint32_t)htonl((uint32_t)number), (uint16_t)ntohs((uint16_t)number), (uint32_t)ntohl((uint32_t)number));
}

int main(int argc, const char *argv[])
{
    int useConvertor = 0;
    long inputNumber = 0;
    int quiet = 0;
    //cmdline
    int i;
    for (i = 1; i < argc; i++) {
        char const *arg =  argv[i];
        if (strcmp(arg, "-h") == 0 ) {
                printf("usage: hton-helper <number> ... to convert\n");
                printf("       hton-helper  ........... to see basic table\n");
                printf("       hton-helper  -h ........ to see help\n");
                printf("       hton-helper  -q ........ quiet mode\n");
                return 0;
        } else if (strcmp(arg, "-q") == 0 ) {
            quiet = 1;
        } else {
            useConvertor = 1;
            inputNumber = atol(arg);
            char buffer[50]  = {'\0'};
            snprintf(buffer, sizeof(buffer)-1, "%ld", inputNumber);
            if (strcmp(buffer, arg) != 0) {
                printf("error: input is not number %s\n", arg);
                return 1;
            } else if (!quiet)
                printf("input number: %s\n", arg);
        }
    }

    //byteorder info BE LE
    if (!quiet)
    {
        static long int str[2] = {0x41424344,0x0}; //ASCII "ABCD"
        if(strcmp("DCBA", (char *)str) == 0)
            printf("Running on: little-endian (Least Significant Byte) (PC)\n");
        else if(strcmp("ABCD", (char *)str) == 0)
            printf("Running on: big-endian (Most Significant Byte) (MC,Sun,HP)\n");
        else
            printf("Running on: unknown-endian\n");
    }

    //convertor
    if (useConvertor) {
        if (!quiet)
        {
            printHeader();
        }
        printLine(inputNumber);
    } else {
        //table with basic values
        printHeader();
        printLine(-32768);
        printLine(0);
        printLine(1);
        printLine(-1);
        printLine(256);
        printLine(32767);
        printLine(65536);
        printLine(16777215);
        printLine(16777216);
        printLine(4294967040);
        printLine(4294967295);
    }
    return 0;
}
