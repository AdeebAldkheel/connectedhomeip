/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    Copyright (c) 2019 Nest Labs, Inc.
 *
 */

#ifndef CHIP_LWIP_FREERTOS_ARCH_CC_H
#define CHIP_LWIP_FREERTOS_ARCH_CC_H

#include <errno.h>
#include <malloc.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>

#if __cplusplus
extern "C" {
#endif

#ifndef LWIP_NOASSERT
#ifdef DEBUG
#define LWIP_PLATFORM_ASSERT(MSG) assert(MSG);
#else
#define LWIP_PLATFORM_ASSERT(MSG)
#endif
#else
#define LWIP_PLATFORM_ASSERT(message)
#endif

#ifndef BYTE_ORDER
#if defined(__LITTLE_ENDIAN__)
#define BYTE_ORDER LITTLE_ENDIAN
#elif defined(__BIG_ENDIAN__)
#define BYTE_ORDER BIG_ENDIAN
#elif defined(__BYTE_ORDER__)
#define BYTE_ORDER __BYTE_ORDER__
#endif
#endif // BYTE_ORDER

#define PACK_STRUCT_STRUCT __attribute__((__packed__))
#define PACK_STRUCT_FIELD(x) x

extern void LwIPLog(const char * fmt, ...);
#define LWIP_PLATFORM_DIAG(x)                                                                                                      \
    do                                                                                                                             \
    {                                                                                                                              \
        LwIPLog x;                                                                                                                 \
    } while (0)

// Place LwIP pools into their own subsections of .bss to make it easier to see
// their sizes in the linker map file.
extern uint8_t __attribute__((section(".bss.lwip_ND6_QUEUE"))) memp_memory_ND6_QUEUE_base[];
extern uint8_t __attribute__((section(".bss.lwip_IP6_REASSDATA"))) memp_memory_IP6_REASSDATA_base[];
extern uint8_t __attribute__((section(".bss.lwip_RAW_PCB"))) memp_memory_RAW_PCB_base[];
extern uint8_t __attribute__((section(".bss.lwip_TCP_SEG"))) memp_memory_TCP_SEG_base[];
extern uint8_t __attribute__((section(".bss.lwip_PBUF_POOL"))) memp_memory_PBUF_POOL_base[];
extern uint8_t __attribute__((section(".bss.lwip_FRAG_PBUF"))) memp_memory_FRAG_PBUF_base[];
extern uint8_t __attribute__((section(".bss.lwip_PBUF"))) memp_memory_PBUF_base[];
extern uint8_t __attribute__((section(".bss.lwip_TCP_PCB_LISTEN"))) memp_memory_TCP_PCB_LISTEN_base[];
extern uint8_t __attribute__((section(".bss.lwip_REASSDATA"))) memp_memory_REASSDATA_base[];
extern uint8_t __attribute__((section(".bss.lwip_UDP_PCB"))) memp_memory_UDP_PCB_base[];
extern uint8_t __attribute__((section(".bss.lwip_MLD6_GROUP"))) memp_memory_MLD6_GROUP_base[];
extern uint8_t __attribute__((section(".bss.lwip_IGMP_GROUP"))) memp_memory_IGMP_GROUP_base[];
extern uint8_t __attribute__((section(".bss.lwip_TCP_PCB"))) memp_memory_TCP_PCB_base[];
extern uint8_t __attribute__((section(".bss.lwip_SYS_TIMEOUT"))) memp_memory_SYS_TIMEOUT_base[];

#if __cplusplus
}
#endif

#endif /* CHIP_LWIP_FREERTOS_ARCH_CC_H */
