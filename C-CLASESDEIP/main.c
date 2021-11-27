#include <stdio.h>
#include <string.h>
 
/*
Function : Extraer clases de ip's
Argumentos : 
1) source - String pointer que contiene la ip
2) ipAddress - asigna octetos de ip addresses que usara para resolver clases
*/
void extraerIpAddress(unsigned char *stringFuente,short *ipAddress)
{
    unsigned short len=0;
    unsigned char  oct[4]={0},cnt=0,cnt1=0,i,buf[5];
 
    len=strlen(stringFuente);
    for(i=0;i<len;i++)
    {
        if(stringFuente[i]!='.'){
            buf[cnt++] =stringFuente[i];
        }
        if(stringFuente[i]=='.' || i==len-1){
            buf[cnt]='\0';
            cnt=0;
            oct[cnt1++]=atoi(buf);
        }
    }
    ipAddress[0]=oct[0];
    ipAddress[1]=oct[1];
    ipAddress[2]=oct[2];
    ipAddress[3]=oct[3];
}

int main()
{
    unsigned char ip[20]={0};
    short ipAddress[4];
     
    printf("Ingresar direccion IP (xxx.xxx.xxx.xxx format): ");
    scanf("%s",ip);
     
    extraerIpAddress(ip,&ipAddress[0]);
     
    printf("\nDireccion IP: %03d. %03d. %03d. %03d\n",ipAddress[0],ipAddress[1],ipAddress[2],ipAddress[3]);
    
    if(ipAddress[0]>=0 && ipAddress[0]<=127)
        printf("Direccion IP Clase A.\n");
    if(ipAddress[0]>127 && ipAddress[0]<191)
        printf("Direccion IP Clase B.\n");
    if(ipAddress[0]>191 && ipAddress[0]<224)
        printf("Direccion IP Clase C.\n");
    if(ipAddress[0]>224 && ipAddress[0]<=239)
        printf("Direccion IP Clase D.\n");
    if(ipAddress[0]>239)
        printf("Direccion IP Clase E.\n");
     
    return 0;
}