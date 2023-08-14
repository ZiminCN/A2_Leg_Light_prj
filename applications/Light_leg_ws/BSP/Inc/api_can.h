#ifndef __API_CAN_H
#define __API_CAN_H

#ifdef __cplusplus
extern "C" {
#endif

int api_canfd_init();
int c_light_canfd_send();

#ifdef __cplusplus
}
#endif

#endif //__API_CAN_H