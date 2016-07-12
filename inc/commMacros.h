/*
 * macros.h
 *
 *  Created on: 07-Jun-2016
 *      Author: vinod
 */

#ifndef INC_COMMMACROS_H_
#define INC_COMMMACROS_H_

#include "commTypes.h"

#define WARN_UNUSED __attribute__((warn_unused_result))

#define ASSERT_NOT_NULL(x)   if(x == 0){return enStatusInvArgs; }


#endif /* INC_COMMMACROS_H_ */
