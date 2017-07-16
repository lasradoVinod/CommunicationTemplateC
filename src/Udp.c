/*
 * Udp.c
 *
 *  Created on: 07-Jun-2016
 *      Author: vinod
 */

#include "commTypes.h"
#include "Communication.h"
#include "Udp.h"
#include <stdio.h>
#include <stdlib.h>



struct __Udp
{
	Communication super;
	EnBoolean_t interruptEnable;
	int udpHandle;
};

static CommunicationVtbl udpVtable =
{
		(Read)readUdp,
		(Write)writeUdp,
		(FlushRxBuffer)flushRxBufferUdp,
		(GetRxBufferCount)getRxBufferCountUdp
};

EnStatus_t udpCtor(Udp * udp, UdpCfg const config)
{
	udp = malloc (sizeof(Udp));
	return communicationCtor(&(udp->super),&udpVtable,"Udp");
}


EnStatus_t readUdp (Udp * commChannelStruct, int8_t * const data, uint32_t bytesToRead, uint32_t *bytesRead)
{
	ASSERT_NOT_NULL(commChannelStruct);
	printf("\nIn udp read");
	fflush(stdout);
	return enStatusSuccess;
}
EnStatus_t writeUdp (Udp * commChannelStruct, int8_t * const data, uint32_t bytesToWrite)
{
	ASSERT_NOT_NULL(commChannelStruct);
	printf("\nIn udp write");
	fflush(stdout);
	return enStatusSuccess;
}
EnStatus_t flushRxBufferUdp (Udp * commChannelStruct)
{
	ASSERT_NOT_NULL(commChannelStruct);
	printf("\nIn udp flush Rx");
	fflush(stdout);
	return enStatusSuccess;
}
EnStatus_t getRxBufferCountUdp (Udp * commChannelStruct, uint32_t *count)
{
	ASSERT_NOT_NULL(commChannelStruct);
	printf("\nIn udp buffer count");
	fflush(stdout);
	return enStatusSuccess;
}

EnStatus_t udpDtor(Udp * udp)
{
	ASSERT_NOT_NULL(udp);

	free (udp);
	udp = 0;
	return communicationCtor(&(udp->super),&udpVtable,"Udp");
}
