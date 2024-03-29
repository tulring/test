#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "oled.h"

/************************************************
 ALIENTEK 阿波罗STM32F429开发板实验11
 OLED显示实验-HAL库函数版
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/


int main(void)
{
    u8 t=0; 
    HAL_Init();                     //初始化HAL库   
    Stm32_Clock_Init(360,25,2,8);   //设置时钟,180Mhz
    delay_init(180);                //初始化延时函数
    uart_init(115200);              //初始化USART
    LED_Init();                     //初始化LED 
    OLED_Init();	                //初始化OLED
    OLED_ShowString(0,0,"ALIENTEK",24);  
	OLED_ShowString(0,24, "0.96' OLED TEST",16);  
	OLED_ShowString(0,40,"ATOM 2014/5/4",12);  
	OLED_ShowString(0,52,"ASCII:",12);  
	OLED_ShowString(64,52,"CODE:",12);  
	OLED_Refresh_Gram();//更新显示到OLED	 
    t=' ';  
    while(1)
    {
		OLED_ShowChar(36,52,t,12,1);//显示ASCII字符	
		OLED_ShowNum(94,52,t,3,12);	//显示ASCII字符的码值    
		OLED_Refresh_Gram();        //更新显示到OLED
		t++;
		if(t>'~')t=' ';  
		delay_ms(500);
		LED0=!LED0;
	} 
}
