/*
 * Serial.h
 *
 *  Created on: 07-Jun-2016
 *      Author: vinod
 */

#ifndef INC_SERIAL_H_
#define INC_SERIAL_H_

struct __Serial;
typedef struct __Serial Serial;

typedef enum{
    enBaudrate_2400 = 0,       /**< baudrate 2400                  */
    enBaudrate_4800,           /**< baudrate 4800                  */
    enBaudrate_9600,           /**< baudrate 9600                  */
    enBaudrate_19200,          /**< baudrate 19200                 */
    enBaudrate_38400,          /**< baudrate 34800                 */
    enBaudrate_57600,          /**< baudrate 57600                 */
    enBaudrate_115200,         /**< baudrate 115200                */
}EnBaudrate;

typedef struct
{
	int portNumber; // COMx port number.
	EnBaudrate baudrate;
}SerialCfg;


EnStatus_t serialCtor(Serial *, SerialCfg const );

EnStatus_t readSerial (Serial * commChannelStruct, int8_t * const data, uint32_t bytesToRead, uint32_t *bytesRead);
EnStatus_t writeSerial (Serial * commChannelStruct, int8_t * const data, uint32_t bytesToWrite);
EnStatus_t flushRxBufferSerial (Serial * commChannelStruct);
EnStatus_t getRxBufferCountSerial (Serial * commChannelStruct, uint32_t *count);


#endif /* INC_SERIAL_H_ */
