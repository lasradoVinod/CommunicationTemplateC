/*
 * Serial.c
 *
 *  Created on: 07-Jun-2016
 *      Author: vinod
 */

#include "commTypes.h"
#include "Communication.h"
#include "Serial.h"
#include <stdio.h>
#include <stdlib.h>



struct __Serial
{
	Communication super;
	EnBoolean_t interruptEnable;
	int serialHandle;
};

static CommunicationVtbl serialVtable =
{
		(Read)readSerial,
		(Write)writeSerial,
		(FlushRxBuffer)flushRxBufferSerial,
		(GetRxBufferCount)getRxBufferCountSerial
};

EnStatus_t serialCtor(Serial * serial, SerialCfg const config)
{
	serial = malloc (sizeof(Serial));
	return communicationCtor(&(serial->super),&serialVtable,"Serial");
}


EnStatus_t readSerial (Serial * commChannelStruct, int8_t * const data, uint32_t bytesToRead, uint32_t *bytesRead)
{
	ASSERT_NOT_NULL(commChannelStruct);
	printf("\nIn serial read");
	fflush(stdout);
	return enStatusSuccess;
}
EnStatus_t writeSerial (Serial * commChannelStruct, int8_t * const data, uint32_t bytesToWrite)
{
	ASSERT_NOT_NULL(commChannelStruct);
	printf("\nIn serial write");
	fflush(stdout);
	return enStatusSuccess;
}
EnStatus_t flushRxBufferSerial (Serial * commChannelStruct)
{
	ASSERT_NOT_NULL(commChannelStruct);
	printf("\nIn serial flush Rx");
	fflush(stdout);
	return enStatusSuccess;
}
EnStatus_t getRxBufferCountSerial (Serial * commChannelStruct, uint32_t *count)
{
	ASSERT_NOT_NULL(commChannelStruct);
	printf("\nIn serial buffer count");
	fflush(stdout);
	return enStatusSuccess;
}

EnStatus_t serialDtor(Serial * serial)
{
	ASSERT_NOT_NULL(serial);

	free (serial);
	serial = 0;
	return communicationCtor(&(serial->super),&serialVtable,"Serial");
}
