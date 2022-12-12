#include <stdio.h>
#include <string.h>

/*
Function : Extract IP Types
Arguments :
1) source - String pointer that contains the IP address
2) ipAddress - assigned to the IP address in the form of an array of 4 bytes that determine the IP address type
*/
void extraerIpAddress(unsigned char *stringBase, short *ipAddress)
{
    unsigned short len = 0;
    unsigned char oct[4] = {0}, cnt = 0, cnt1 = 0, i, buf[5];

    /* Get the IP type and convert it to a 4 byte matrix. */
    len = strlen(stringBase);
    for (i = 0; i < len; i++)
    {
        if (stringBase[i] != '.')
        {
            buf[cnt++] = stringBase[i];
        }
        if (stringBase[i] == '.' || i == len - 1)
        {
            buf[cnt] = '\0';
            cnt = 0;
            oct[cnt1++] = atoi(buf);
        }
    }
    ipAddress[0] = oct[0];
    ipAddress[1] = oct[1];
    ipAddress[2] = oct[2];
    ipAddress[3] = oct[3];
}

int main()
{                               // variable declaration
    unsigned char ip[20] = {0}; // IP address
    short ipAddress[4];         // IP address in the form of an array of 4 bytes

    printf("Enter ip address (xxx.xxx.xxx.xxx format): "); // ask for IP address
    scanf("%s", ip);                                       // save IP address

    extraerIpAddress(ip, &ipAddress[0]); // extract IP address

    printf("\nIP Address: %03d. %03d. %03d. %03d\n", ipAddress[0], ipAddress[1], ipAddress[2], ipAddress[3]); // show IP address

    if (ipAddress[0] >= 0 && ipAddress[0] <= 127) // determine IP address type
        printf("IP Address Class A.\n");
    if (ipAddress[0] > 127 && ipAddress[0] < 191) // determine IP address type
        printf("IP Address Class B.\n");
    if (ipAddress[0] > 191 && ipAddress[0] < 224) // determine IP address type
        printf("IP Address Class C.\n");
    if (ipAddress[0] > 224 && ipAddress[0] <= 239) // determine IP address type
        printf("IP Address Class D.\n");
    if (ipAddress[0] > 239)
        printf("IP Address Class E.\n");

    return 0;
}