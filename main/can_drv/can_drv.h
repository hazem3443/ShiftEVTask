#ifndef CAN_DRV_H
#define CAN_DRV_H

#include "driver/twai.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

#define PRIORITY_MSG_ID 0x1
#define TX_QUEUE_SIZE 5
#define RX_QUEUE_SIZE 10
#define DLC 8

typedef struct {
    uint32_t    canId;
    uint8_t     canData[DLC];
    uint8_t     dataSize;
} CANMessage;

#define TWAI_FRAME_FORMAT_STANDARD 0x0
#define TWAI_FRAME_FORMAT_EXTENDED 0x1

esp_err_t can_drv_init(void);
esp_err_t can_drv_deinit(void);
void CAN_tx(uint32_t canId, uint8_t *canData, uint8_t dataSize);
bool CAN_rx(uint32_t *canId, uint8_t *canData, uint8_t *dataSize);
esp_err_t can_drv_register_rx_notification(SemaphoreHandle_t *rx_notification);

#endif // CAN_DRV_H