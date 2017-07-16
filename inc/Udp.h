/*
 * Udp.h
 *
 *  Created on: 07-Jun-2016
 *      Author: vinod
 */

#ifndef INC_UDP_H_
#define INC_UDP_H_

struct __Udp;
typedef struct __Udp Udp;

typedef struct
{
	int portNumber; 
}UdpCfg;


EnStatus_t udpCtor(Udp *, UdpCfg const );

EnStatus_t readUdp (Udp * commChannelStruct, int8_t * const data, uint32_t bytesToRead, uint32_t *bytesRead);
EnStatus_t writeUdp (Udp * commChannelStruct, int8_t * const data, uint32_t bytesToWrite);
EnStatus_t flushRxBufferUdp (Udp * commChannelStruct);
EnStatus_t getRxBufferCountUdp (Udp * commChannelStruct, uint32_t *count);


#endif /* INC_SERIAL_H_ */
