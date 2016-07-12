/*
 * Communication.c
 *
 *  Created on: 07-Jun-2016
 *      Author: vinod
 */

#include "commMacros.h"
#include "commTypes.h"
#include "Communication.h"
#include <string.h>

EnStatus_t readChannel (void * commChannelStruct, int8_t * const data, uint32_t bytesToRead, uint32_t *bytesRead);
EnStatus_t writeChannel (void * commChannelStruct, int8_t * const data, uint32_t bytesToWrite);
EnStatus_t flushRxBufferChannel (void * commChannelStruct);
EnStatus_t getRxBufferCountChannel (void * commChannelStruct, uint32_t *count);


static CommunicationVtbl Vtable = {
		readChannel,
		writeChannel,
		flushRxBufferChannel,
		getRxBufferCountChannel
};

Communication baseVtable = {&Vtable};


EnStatus_t communicationCtor(Communication * channel, CommunicationVtbl *virtualTable, const char *data)
{
	ASSERT_NOT_NULL(channel);

	if(virtualTable == 0)
		channel = &baseVtable;
	else
		channel->vptr = virtualTable;


	channel->nameOfLink = data;
	return enStatusSuccess;

}

EnStatus_t readChannel (void * commChannelStructp, int8_t * const data, uint32_t bytesToRead, uint32_t *bytesRead)
{
	Communication *commChannelStruct =(Communication* )commChannelStruct;
	ASSERT_NOT_NULL(commChannelStructp);
	ASSERT_NOT_NULL(data);
	ASSERT_NOT_NULL(bytesRead);

	if(commChannelStruct->vptr != 0 )
	{
		return commChannelStruct->vptr->read(commChannelStruct,data,bytesToRead,bytesRead);
	}
	else
	{
		return enStatusClassNotInstantiated;
	}
}

EnStatus_t writeChannel (void * commChannelStructp, int8_t * const data, uint32_t bytesToWrite)
{
	Communication *commChannelStruct =(Communication* )commChannelStruct;
	ASSERT_NOT_NULL(commChannelStruct);
	ASSERT_NOT_NULL(data);

	if(commChannelStruct->vptr != 0 )
	{
		return commChannelStruct->vptr->write(commChannelStruct,data,bytesToWrite);
	}
	else
	{
		return enStatusClassNotInstantiated;
	};
}

EnStatus_t flushRxBufferChannel (void * commChannelStructp)
{
	Communication *commChannelStruct =(Communication* )commChannelStruct;
	ASSERT_NOT_NULL(commChannelStruct);

	if(commChannelStruct->vptr != 0 )
	{
		return commChannelStruct->vptr->flushRxBuffer(commChannelStruct) ;
	}
	else
	{
		return enStatusClassNotInstantiated;
	}
}

EnStatus_t getRxBufferCountChannel (void * commChannelStructp, uint32_t *count)
{
	Communication *commChannelStruct =(Communication* )commChannelStruct;
	ASSERT_NOT_NULL(commChannelStruct);
	ASSERT_NOT_NULL(count);

	if(commChannelStruct->vptr != 0 )
	{
		return commChannelStruct->vptr->getRxBufferCount(commChannelStruct, count) ;
	}
	else
	{
		return enStatusClassNotInstantiated;
	}
}



