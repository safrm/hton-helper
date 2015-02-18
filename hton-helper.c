
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
#include <arpa/inet.h>

void printHeader()
{
    printf("\n        int       htons       htonl       ntohs       ntohl\n");
}

void printLine(long number)
{
    printf("%11ld %11u %11ld %11u %11ld\n",number,  htons((uint16_t)number), htonl((uint32_t)number), ntohs((uint16_t)number), ntohl((uint32_t)number));
}

int main(int argc, const char *argv[])
{
    int useConvertor = 0;
    long inputNumber = 0;
    //cmdline
    size_t i;
    for (i = 1; i < argc; i++) {
        char const *arg =  argv[i];
        if (arg[0] == '-') {
            switch (arg[1])
            {
            case 'h':
                printf("usage: hton-helper <number> ... to convert");
                printf("       hton-helper  ........... to see basic table");
                printf("       hton-helper  -h ........ to see help");
                return 0;
                break;
            default:
                printf("not recognised argument %s\n", arg);
                break;
            }
        } else {
            useConvertor = 1;
            inputNumber = atol(arg);
            char buffer[50]  = {'\0'};
            snprintf(buffer, sizeof(buffer)-1, "%ld", inputNumber);
            if (strcmp(buffer, arg) != 0) {
                printf("error: input is not number %s\n", arg);
                return 1;
            } else
                printf("input number: %s\n", arg);
        }
    }

    //byteorder info BE LE
    static long int str[2] = {0x41424344,0x0}; //ASCII "ABCD"
    if(strcmp("DCBA", (char *)str) == 0)
        printf("Running on: little-endian (Least Significant Byte) (PC)\n");
    else if(strcmp("ABCD", (char *)str) == 0)
        printf("Running on: big-endian (Most Significant Byte) (MC,Sun,HP)\n");
    else
        printf("Running on: unknown-endian\n");

    //convertor
    if (useConvertor) {
        printHeader();
        printLine(inputNumber);
    } else {
        //table with basic values
        printHeader();
        printLine(0);
        printLine(1);
        printLine(-1);
        printLine(256);
        printLine(65536);
        printLine(16777215);
        printLine(16777216);
        printLine(4294967295);

    }
    return 0;
}
