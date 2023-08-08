// #include <zephyr/device.h>
// #include <zephyr/drivers/can.h>
// #include <zephyr/logging/log.h>
// #include <zephyr/kernel.h>
// #include <zephyr/devicetree.h>

// #include "api_can.h"

// LOG_MODULE_REGISTER(api_can, LOG_LEVEL_INF);

// static const struct device *const CanPort = DEVICE_DT_GET(DT_ALIAS(apican));

// static void any_rx_callback(const struct device *dev, struct can_frame *frame, void *user_data){

//     LOG_INF("FD RECV 0x%03X", frame->id);
//     uint8_t len = can_dlc_to_bytes(frame->dlc);
//     LOG_HEXDUMP_INF(frame->data, len, "RX RAW");
// }

// int c_light_canfd_send(){

//     int ret = 0;

//     struct can_frame frame;
//     // uint8_t *data = frame.data;

//     frame.flags = 0;
//     frame.id = 0x20F;
//     frame.dlc = 8;

//     memset(frame.data, 0, 8);

//     frame.data[0] = 0x01;
//     frame.data[1] = 0x02;
//     frame.data[2] = 0x03;
//     frame.data[3] = 0x04;


//     ret = can_send(CanPort, &frame, K_FOREVER, NULL, NULL);

//     return ret;
// }

// int api_canfd_init(){
//     const struct can_filter any_filter = {
//         .id = 0x000, .mask = 0x000, .flags = CAN_FILTER_DATA};

//     const struct can_filter cf = {
//         .id = 0x200, .mask = 0x000, .flags = CAN_FILTER_DATA};

//     if (!device_is_ready(CanPort)) {
// 		printk("CAN device not ready");
// 		return 0;
// 	}

//     can_add_rx_filter(CanPort, any_rx_callback, (void *)0, &any_filter);

//     can_add_rx_filter(CanPort, any_rx_callback, (void *)0, &cf);

//     can_set_mode(CanPort, CAN_MODE_NORMAL);

//     can_start(CanPort);

//     return 0;
// }