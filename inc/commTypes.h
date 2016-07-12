/** The type representing boolean value */
#ifndef INC_COMMTYPES_H_
#define INC_COMMTYPES_H_

typedef enum
{
    enFalse  = 0, /**< false value */
    enTrue   = 1  /**< true value */
}EnBoolean_t;

/** The type representing boolean value */
typedef enum
{
    enStatusSuccess  = 0, 
    enStatusError,  
    enStatusInvArgs,
	enStatusClassNotInstantiated
} EnStatus_t;

#endif
