#ifndef WDG_H
#define WDG_H

/*
 * you can choose Time prescaler of the following:
 * 0. 16.3 ms
 * 1. 32.5 ms
 * 2. 65 ms
 * 3. 0.13 s
 * 4. 0.26 s
 * 5. 0.52 s
 * 6. 1 s
 * 7. 2.1 s
 * */
typedef enum
{
	ms_16_3,
	ms_32_5,
	ms_65,
	s_0_13,
	s_0_26,
	s_0_52,
	s_1,
	s_2_1
}WDT_Prescaler;

void WDT_VidInit(void);

void WDT_VidEnable(WDT_Prescaler WDT_SleepTime);

void WDT_VidDisable(void);



#endif
