/*
 * main.c
 *
 *  Created on: 07-Jun-2016
 *      Author: vinod
 */

#include "main.h"

int main(void)
{
	SerialCfg cfg;
	int8_t data[4];
	Serial * com1 = 0;
	Communication *channel = 0;
	printf("Creating serial");
	serialCtor(com1,cfg);
	channel =(Communication *) &com1;

	writeChannel(channel,data,4);
	flushRxBufferChannel(channel);

	return 0;
}
