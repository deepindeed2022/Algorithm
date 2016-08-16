/************************************************************************/
/* The program file is a demo for cap socket packet data on the WINDOW  */
/* Following program analysis three type packet: TCP, UDP, ICMP. The    */
/* packet header defined as three struct definitions. Thanks for your   */
/* EVERY suggestion.                                                    */
/* Date: 2016-8-16                                                      */
/* Author: <523814299@qq.com>                                           */
/************************************************************************/

#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOSTNAME_LAN 255
#define SIO_RCVALL _WSAIOW(IOC_VENDOR,1)
#define MAX_ADDR_LEN 16
#pragma comment(lib,"WS2_32.lib")

typedef struct tcpheader
{
	unsigned short int sport;		//source address
	unsigned short int dport;		//destination address
	unsigned int th_seq;			//sequence number
	unsigned int th_ack;			//acknowledge number
	unsigned char th_x2:4;			//header length
	unsigned char th_off:4;			//reserved
	unsigned char  th_flag;			//flags: URG ACK PSH RST SYN FIN
	unsigned short int th_win;		//window size
	unsigned short int th_sum;		//check sum
	unsigned short int th_urp;		//urgent pointer
}TCP_HDR;

struct ipheader
{
	unsigned char h_lenver;              //version & header length
	unsigned char ip_tos;                //tos
	unsigned short int ip_len;           //total length
	unsigned short int ip_id;            //id
	unsigned short int ip_off;           //offset
	unsigned char ip_ttl;                //time to live
	unsigned char ip_p;                  //protocol
	unsigned short int ip_sum;           //check sum
	unsigned int ip_src;                 //source address
	unsigned int ip_dst;                 //destination address
}IP_HDR;
//TODO:
// The UDP and TCP protocol 
typedef struct udphdr
{
	unsigned short sport;                //source port
	unsigned short dport;                //destination port
	unsigned short len;                  //UDP length
	unsigned short cksum;                //check sum(include data)
} UDP_HDR;

typedef struct icmphdr    
{ 
	unsigned short sport;
	unsigned short dport;
	BYTE i_type;           
	BYTE i_code;           
	USHORT i_cksum;         
	USHORT i_id;           
	USHORT i_seq;          
	ULONG timestamp;      
}ICMP_HDR;

void main()
{
	SOCKET sock;
	WSADATA wsd;
	char RecvBuf[65535] = {0};
	DWORD  dwBytesRet;
	int pCount=0;
	unsigned int  optval = 1; //the pointer , which shows us the payload begin
	unsigned char *dataip=NULL;
	unsigned char *datatcp=NULL; //the pointer , which shows us the payload begin
	unsigned char *dataudp=NULL;
	unsigned char *dataicmp=NULL;
	int lentcp=0, lenudp, lenicmp, lenip;
	int k;
	char   TcpFlag[6]={'F','S','R','P','A','U'}; //定义TCP的标志位

	WSAStartup(MAKEWORD(2,1),&wsd);
	// Contribute socket connection
	if((sock = socket(AF_INET, SOCK_RAW, IPPROTO_IP))==SOCKET_ERROR)
	{
		exit(0);
	}

	char FAR name[MAX_HOSTNAME_LAN];
	gethostname(name, MAX_HOSTNAME_LAN);
	struct hostent FAR * pHostent;
	pHostent = (struct hostent * )malloc(sizeof(struct hostent));
	pHostent = gethostbyname(name);

	SOCKADDR_IN sa;
	sa.sin_family = AF_INET;
	sa.sin_port = htons(6000);
	memcpy(&sa.sin_addr.S_un.S_addr, pHostent->h_addr_list[0], pHostent->h_length);

	bind(sock, (SOCKADDR *)&sa, sizeof(sa));
	//if you don't have raw socket support (win 95/98/me/win2kuser) it calls the exit(1) function
	if ((WSAGetLastError())==10013)
		exit(0);
	WSAIoctl(sock, SIO_RCVALL, &optval, sizeof(optval), NULL, 0, &dwBytesRet, NULL, NULL);

	struct udphdr *pUdpheader;
	struct ipheader *pIpheader;
	struct tcpheader *pTcpheader;
	struct icmphdr *pIcmpheader;
	char szSourceIP[MAX_ADDR_LEN], szDestIP[MAX_ADDR_LEN];
	SOCKADDR_IN saSource, saDest;
	pIpheader	= (struct ipheader *)RecvBuf;
	// 
	pTcpheader	= (struct tcpheader *)(RecvBuf+ sizeof(struct ipheader ));
	pUdpheader	= (struct udphdr *) (RecvBuf+ sizeof(struct ipheader ));
	pIcmpheader = (struct icmphdr *) (RecvBuf+ sizeof(struct ipheader ));

	int iIphLen = sizeof(unsigned long) * ( pIpheader->h_lenver & 0x0f );

	while (1)
	{
		// Clear RecvBuf
		memset(RecvBuf, 0, sizeof(RecvBuf));
		// Recv Packet data
		recv(sock, RecvBuf, sizeof(RecvBuf), 0);

		//Check Source and Dest IP
		saSource.sin_addr.s_addr = pIpheader->ip_src;
		saDest.sin_addr.s_addr = pIpheader->ip_dst;
		strncpy(szSourceIP, inet_ntoa(saSource.sin_addr), MAX_ADDR_LEN);
		strncpy(szDestIP, inet_ntoa(saDest.sin_addr), MAX_ADDR_LEN);

		lenip=ntohs(pIpheader->ip_len);
		lentcp =(ntohs(pIpheader->ip_len)-(sizeof(struct ipheader)+sizeof(struct tcpheader))); 

		// TODO:
		// Analysis UDP and ICMP protocol packet data more details
		//
		lenudp =(ntohs(pIpheader->ip_len)-(sizeof(struct ipheader)+sizeof(struct udphdr)));       
		lenicmp =(ntohs(pIpheader->ip_len)-(sizeof(struct ipheader)+sizeof(struct icmphdr)));

		pCount++; 
		if((pIpheader->ip_p) == IPPROTO_TCP && lentcp != 0)
		{
			
			dataip=(unsigned char *) RecvBuf;
			datatcp=(unsigned char *) RecvBuf+sizeof(struct ipheader)+sizeof(struct tcpheader); //data

			printf("\n\n---------数据包[%i]=%d字节数据-------", pCount, lentcp);
			printf("\n*IP协议标识:%i\n",ntohs(pIpheader->ip_id));
			printf("<源IP地址:%s 目的IP地址:%s>",szSourceIP, szDestIP);
			printf("\n总长度:%i",ntohs(pIpheader->ip_len));
			printf(">偏移量:%i\n",ntohs(pIpheader->ip_off));
			printf(">生存时间:%d\n",pIpheader->ip_ttl);
			printf(">服务类型:%d\n",pIpheader->ip_tos);
			printf(">协议类型:%d\n",pIpheader->ip_p);
			printf(">检验和:%i\n",ntohs(pIpheader->ip_sum));
	
			//
			// TCP Proposal header information
			//
			printf("\n*TCP协议头部\n");
			printf(">源端口:%i\n",ntohs(pTcpheader->sport));
			printf(">目的端口:%i\n",ntohs(pTcpheader->dport));
			printf(">序列号:%i\n",ntohs(pTcpheader->th_seq));
			printf(">应答号:%i\n",ntohs(pTcpheader->th_ack));
			printf(">检验和:%i\n",ntohs(pTcpheader->th_sum));
			printf(">标志位：");

			unsigned   char   FlagMask   =   1;
			int t = 0, j, p = 0, i5 = 0;
			int lenhttp = 0; 
			
			for(k = 0; k < 6; k++)  
			{  
				if((pTcpheader->th_flag)   &   FlagMask)  
					printf("%c",TcpFlag[k]);  
				else  
					printf(" ");  
				FlagMask = FlagMask << 1;
			}

			if(ntohs(pTcpheader->sport) == 80 || ntohs(pTcpheader->dport) == 80)
				for(j = 0; j < lentcp; j++)
				{
					if( *(datatcp+j)==0x0d && *(datatcp+j+1)==0x0a 
						&& *(datatcp+j+2)==0x0d && *(datatcp+j+3)==0x0a)
					{
						lenhttp=j;
						printf("\nHTTP协议\n");
						printf("HTTP头部长度:%d\n",lenhttp);
						break;
					}
				}
				for(k = 0; k < lentcp; k++)
				{
					if( *(datatcp+k)==0x42 && *(datatcp+k+1)==0x69
						&& *(datatcp+k+2)==0x74 && *(datatcp+k+3)==0x54
						&& *(datatcp+k+4)==0x6f && *(datatcp+k+5)==0x72
						&& *(datatcp+k+6)==0x72 && *(datatcp+k+7)==0x65 
						&& *(datatcp+k+8)==0x6e)
					{
						printf("\n!!!!!BitTorrent\n");
					}
				}
				for(int i = 0; i < lenhttp; i++)
				{
					if(*(datatcp+i) != 0x0d && *(datatcp+i+1) != 0x0a)
						printf("%c",*(datatcp+i));
					//else
					//	printf("\n");
				}
		}
		else if ((pIpheader->ip_p) == IPPROTO_ICMP && lenicmp != 0 )
		{
			printf("\n\n---------ICMP Packet [%i]=%d Bytes data-------", pCount, lenicmp);
			printf("\n*IP协议标识:%i\n",ntohs(pIpheader->ip_id));
			printf("<源IP地址:%s 目的IP地址:%s>",szSourceIP, szDestIP);
			printf("\n总长度:%i",ntohs(pIpheader->ip_len));
			printf(">偏移量:%i\n",ntohs(pIpheader->ip_off));
			printf(">生存时间:%d\n",pIpheader->ip_ttl);
			printf(">服务类型:%d\n",pIpheader->ip_tos);
			printf(">协议类型:%d\n",pIpheader->ip_p);
			printf(">检验和:%i\n",ntohs(pIpheader->ip_sum));

			dataicmp =(unsigned char *) RecvBuf+sizeof(struct ipheader)+sizeof(struct icmphdr); //data
			if(ntohs(pIcmpheader->sport) == 80 || ntohs(pIcmpheader->dport) == 80)
				for(int i = 0; i < lenicmp; i++)
				{
					if(*(dataicmp+i) != 0x0d && *(dataicmp+i+1) != 0x0a)
						printf("%c",*(dataicmp+i));
				}
		}
		else if((pIpheader->ip_p) == IPPROTO_UDP && lenudp != 0)
		{
			printf("\n\n---------UDP Packet [%i]=%d Bytes data-------", pCount, lenudp);
			printf("\n*IP协议标识:%i\n",ntohs(pIpheader->ip_id));
			printf("<源IP地址:%s 目的IP地址:%s>",szSourceIP, szDestIP);
			printf("\n总长度:%i",ntohs(pIpheader->ip_len));
			printf(">偏移量:%i\n",ntohs(pIpheader->ip_off));
			printf(">生存时间:%d\n",pIpheader->ip_ttl);
			printf(">服务类型:%d\n",pIpheader->ip_tos);
			printf(">协议类型:%d\n",pIpheader->ip_p);
			printf(">检验和:%i\n",ntohs(pIpheader->ip_sum));
			dataudp = (unsigned char *) RecvBuf+sizeof(struct ipheader)+sizeof(struct udphdr); //data
			if(ntohs(pUdpheader->sport) == 80 || ntohs(pUdpheader->dport) == 80)
				for(int i = 0; i < lenudp; i++)
				{
					if(*(dataudp + i) != 0x0d && *(dataudp + i+1) != 0x0a)
						printf("%c",*(dataudp + i));
				}
		}
	}
}  