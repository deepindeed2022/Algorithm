#include <iostream>
#include <cstdio>
using namespace std;
bool IsBig_Endian()
{
    unsigned short test = 0x1234;
    cout<<std::hex<<&test<<endl;
    printf("%d\n",*((unsigned char*)(&test+1)));
    if(*((unsigned char*)&test ) == 0x12)
       return true;
   else
       return false;
    printf("%d\n",&test);
}//IsBig_Endian()
int main()
{
	if(IsBig_Endian())
	{
		printf("%s\n", "Big-endian");
	}else
		printf("%s\n","Little-endian" );
	return 1;
}
/******************************************************************************************
	小端：较高的有效字节存放在较高的的存储器地址，较低的有效字节存放在较低的存储器地址。
	大端：较高的有效字节存放在较低的存储器地址，较低的有效字节存放在较高的存储器地址。
	大端模式就是低位存放在高地址上。高位存放在地址上。
	小端模式就是地位存放在低地址上。高位存放在高地址上。
	例如，16bit宽的数0x1234在Little-endian模式CPU内存中的存放方式(假设从地址0x4000开始存放)为:
	内存地址 0x4000 0x4001 
	存放内容 0x34 0x12
	而在Big-endian模式CPU内存中的存放方式则为:
	内存地址 0x4000 0x4001 
	存放内容 0x12 0x34
**********************************************************************************************/