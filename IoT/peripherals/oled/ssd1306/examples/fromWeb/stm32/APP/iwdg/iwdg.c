#include "iwdg.h"

//pre:Ԥ��Ƶϵ��(0-6)
//rlr:��װ��ֵ(12λ��Χ0xfff)
//�������Ź���λʱ����㹫ʽ��t=(4*2^pre*rlr)/40
void IWDG_Init(u8 pre,u16 rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); //ȡ���Ĵ���д����
	IWDG_SetPrescaler(pre);//����Ԥ��Ƶϵ�� 0-6
	IWDG_SetReload(rlr);//������װ��ֵ
	IWDG_ReloadCounter();  //��װ�س�ֵ
	IWDG_Enable(); //�򿪶������Ź�
	
}
void IWDG_FeedDog(void)  //ι��
{
	IWDG_ReloadCounter();  //��װ�س�ֵ
}
