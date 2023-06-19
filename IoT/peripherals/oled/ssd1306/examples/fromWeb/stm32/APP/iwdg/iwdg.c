#include "iwdg.h"

//pre:预分频系数(0-6)
//rlr:重装载值(12位范围0xfff)
//独立看门狗复位时间计算公式：t=(4*2^pre*rlr)/40
void IWDG_Init(u8 pre,u16 rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); //取消寄存器写保护
	IWDG_SetPrescaler(pre);//设置预分频系数 0-6
	IWDG_SetReload(rlr);//设置重装载值
	IWDG_ReloadCounter();  //重装载初值
	IWDG_Enable(); //打开独立看门狗
	
}
void IWDG_FeedDog(void)  //喂狗
{
	IWDG_ReloadCounter();  //重装载初值
}

