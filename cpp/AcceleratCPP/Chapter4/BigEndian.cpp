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
#include <iostream>
void IsBig_Endian(void)
{
    unsigned short test = 0x1234;
    unsigned int lettle = 2;
    std::cout<<"later define value should set the lower memory address: "
    		 <<std::boolalpha<<((int)&test>(int)&lettle)<<std::endl;
    if(2==sizeof(short))
    {
    	if(static_cast<char>(test) == 0x12)
	       std::cout<<"The current data model:Big_Endian\n";
	   else
	       std::cout<<"The current data model:Little-Endian\n";
    }
}
int main()
{
	IsBig_Endian();
	return 1;
}
