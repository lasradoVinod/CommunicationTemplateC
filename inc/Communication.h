/*
 * Communication.h
 *
 *  Created on: 07-Jun-2016
 *      Author: vinod
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include <stdint.h>
#include "commTypes.h"
#include "commMacros.h"

struct __Communication;
typedef  struct __Communication Communication;

/**
 * \brief function pointer definition for read in Communication channel. All who
 *        wish to use the library need to conform to this format of function pointer.
 *
 * \param commChannelStruct structure of the channel that is to be used
 * \param data pointer to buffer where user wants data to be stored
 * \param bytesToRead no of bytes to be read from the channel
 * \param readBytes No bytes actually read
 *
 * \return Status of read
 * */
typedef EnStatus_t (*Read) (void * commChannelStruct, int8_t * const data, uint32_t bytesToRead, uint32_t *readBytes);

/**
 * \brief function pointer definition for write in void channel. All who
 *        wish to use the library need to conform to this format of function pointer.
 *
 * \param commChannelStruct structure of the channel that is to be used
 * \param data pointer to the data to be sent
 * \param bytesToWrite no of bytes to be read from the channel
 *
 * \return Status of write
 * */
typedef EnStatus_t (*Write) (void * commChannelStruct, int8_t * const data, uint32_t bytesToWrite);

/**
 * \brief function pointer definition for flushing recieve buffer in void channel. All who
 *        wish to use the library need to conform to this format of function pointer.
 *
 * \param commChannelStruct structure of the channel that is to be used
 *
 * \return Status of flushRxBuffer
 * */
typedef EnStatus_t (*FlushRxBuffer) (void * commChannelStruct);

/**
 * \brief function pointer definition for getting elements in receive buffer in Communication channel. All who
 *        wish to use the library need to conform to this format of function pointer.
 *
 * \param commChannelStruct structure of the channel that is to be used
 * \param count      No of bytes of data in buffer
 *
 * \return Status of getRxBufferCount
 */
typedef EnStatus_t (*GetRxBufferCount) (void * commChannelStruct, uint32_t *count);

typedef struct {
	Read read;
	Write write;
	FlushRxBuffer flushRxBuffer;
	GetRxBufferCount getRxBufferCount;
} CommunicationVtbl;

struct __Communication{
	CommunicationVtbl const * vptr;
	char * nameOfLink;
};


EnStatus_t communicationCtor(Communication * channel, CommunicationVtbl *virtualTable, const char * nameOfLink);
EnStatus_t readChannel (void * commChannelStruct, int8_t * const data, uint32_t bytesToRead, uint32_t *bytesRead);
EnStatus_t writeChannel (void * commChannelStruct, int8_t * const data, uint32_t bytesToWrite);
EnStatus_t flushRxBufferChannel (void * commChannelStruct);
EnStatus_t getRxBufferCountChannel (void * commChannelStruct, uint32_t *count);

#endif /* COMMUNICATION_H_ */
