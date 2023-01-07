int main()
{
	
	//APB2总线上IO端口B时钟使能
	*(unsigned int *)0x40021018 |= (1 << 3);
	
	
	//控制输出模式为推挽输出10MHz
	//控制CRL寄存器
	*(unsigned int *)0X40010C00 |=  (1 << 0);
		
	//LED通过端口输出数据寄存器来控制
	//控制ODR寄存器
	*(unsigned int *)0X40010C0C &= ~(1 << 0);
	
	

	
	return 0;
}


//未引用固件库
void SystemInit()
{
	//函数体为为空，骗过编译器不报错



}





