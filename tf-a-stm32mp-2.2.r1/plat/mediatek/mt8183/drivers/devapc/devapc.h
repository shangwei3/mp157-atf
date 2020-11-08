/*
 * Copyright (c) 2019, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef DEVAPC_H
#define DEVAPC_H

#include <stdint.h>

#define DEVAPC_AO_INFRA_BASE      0x1000E000
#define DEVAPC_AO_MM_BASE         0x1001C000
#define DEVAPC_AO_MD_BASE         0x10019000

#define DEVAPC_INFRA_D0_APC_0     (DEVAPC_AO_INFRA_BASE + 0x0000)
#define DEVAPC_INFRA_MAS_DOM_0    (DEVAPC_AO_INFRA_BASE + 0x0A00)
#define DEVAPC_INFRA_MAS_SEC_0    (DEVAPC_AO_INFRA_BASE + 0x0B00)
#define DEVAPC_INFRA_DOM_RMP_0    (DEVAPC_AO_INFRA_BASE + 0x0D00)
#define DEVAPC_INFRA_DOM_RMP_1    (DEVAPC_AO_INFRA_BASE + 0x0D04)
#define DEVAPC_INFRA_APC_CON      (DEVAPC_AO_INFRA_BASE + 0x0F00)

#define DEVAPC_MD_APC_CON         (DEVAPC_AO_MD_BASE + 0x0F00)

#define DEVAPC_MM_D0_APC_0        (DEVAPC_AO_MM_BASE + 0x0000)
#define DEVAPC_MM_DOM_RMP_0       (DEVAPC_AO_MM_BASE + 0x0D00)
#define DEVAPC_MM_APC_CON         (DEVAPC_AO_MM_BASE + 0x0F00)

#define MOD_NO_IN_1_DEVAPC        16
#define MASTER_MOD_NO_IN_1_DEVAPC 8
#define SLAVE_INFRA_MAX_INDEX     195
#define SLAVE_MM_MAX_INDEX        140

enum {
	MASTER_SCP = 0,
	MASTER_SPM = 10,
	MASTER_SSPM = 27
};

enum MASK_DOM {
	DOMAIN_0 = 0,
	DOMAIN_1,
	DOMAIN_2,
	DOMAIN_3,
	DOMAIN_4,
	DOMAIN_5,
	DOMAIN_6,
	DOMAIN_7,
	DOMAIN_8,
	DOMAIN_9,
	DOMAIN_10,
	DOMAIN_11
};

enum TRANSACTION {
	NON_SECURE_TRANSACTION = 0,
	SECURE_TRANSACTION
};

enum DAPC_SLAVE_TYPE {
	DAPC_INFRA_SLAVE = 0,
	DAPC_MM_SLAVE
};

enum APC_ATTR {
	NO_SEC = 0,
	S_RW_ONLY,
	S_RW_NS_R,
	FORBID,
};

struct DEVICE_INFO {
	uint8_t d0_permission;
	uint8_t d1_permission;
	uint8_t d2_permission;
};

#define PERMISSION(DEV_NAME, ATTR1, ATTR2, ATTR3) \
{(uint8_t)ATTR1, (uint8_t)ATTR2, (uint8_t)ATTR3}

static const struct DEVICE_INFO D_APC_INFRA_Devices[] = {
/* module,                                      domain0, domain1, domain2 */

/* 0 */
PERMISSION("INFRA_AO_TOPCKGEN",                    NO_SEC, NO_SEC, NO_SEC),
PERMISSION("INFRA_AO_INFRASYS_CONFIG_REGS",        NO_SEC, FORBID, NO_SEC),
PERMISSION("IO_CFG",                               NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_PERICFG",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_EFUSE_AO_DEBUG",              NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_GPIO",                        NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_SLEEP_CONTROLLER",            NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_TOPRGU",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_APXGPT",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_RESERVE",                     NO_SEC, FORBID, NO_SEC),

/* 10 */
PERMISSION("INFRA_AO_SEJ",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_AP_CIRQ_EINT",                NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_APMIXEDSYS",                  NO_SEC, NO_SEC, NO_SEC),
PERMISSION("INFRA_AO_PMIC_WRAP",                   NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_DEVICE_APC_AO_INFRA_PERI",    NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_SLEEP_CONTROLLER_MD",         NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_KEYPAD",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_TOP_MISC",                    NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_DVFS_CTRL_PROC",              NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_MBIST_AO_REG",                NO_SEC, FORBID, NO_SEC),

/* 20 */
PERMISSION("INFRA_AO_CLDMA_AO_AP",                 NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_DEVICE_MPU",                  NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_AES_TOP_0",                   NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_SYS_TIMER",                   NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_MDEM_TEMP_SHARE",             NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_DEVICE_APC_AO_MD",            NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_SECURITY_AO",                 NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_TOPCKGEN_REG",                NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_DEVICE_APC_AO_MM",            NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_RESERVE",                     NO_SEC, FORBID, NO_SEC),

/* 30 */
PERMISSION("INFRASYS_RESERVE",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_RESERVE",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_RESERVE",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_SYS_CIRQ",                    NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_MM_IOMMU",                    NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_EFUSE_PDN_DEBUG",             NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DEVICE_APC",                  NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DBG_TRACKER",                 NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_CCIF0_AP",                    NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_CCIF0_MD",                    NO_SEC, FORBID, NO_SEC),

/* 40 */
PERMISSION("INFRASYS_CCIF1_AP",                    NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_CCIF1_MD",                    NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_MBIST",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_INFRA_PDN_REGISTER",          NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_TRNG",                        NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DX_CC",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("MD_CCIF_MD1",                          NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_CQ_DMA",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("MD_CCIF_MD2",                          NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_SRAMROM",                     NO_SEC, FORBID, NO_SEC),

/* 50 */
PERMISSION("ANA_MIPI_DSI0",                        NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_RESERVE",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("ANA_MIPI_CSI0",                        NO_SEC, FORBID, NO_SEC),
PERMISSION("ANA_MIPI_CSI1",                        NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_EMI",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_RESERVE",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_CLDMA_PDN",                   NO_SEC, FORBID, NO_SEC),
PERMISSION("CLDMA_PDN_MD_MISC",                    NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_MD",                             NO_SEC, FORBID, NO_SEC),
PERMISSION("BPI_BSI_SLV0",                         NO_SEC, FORBID, NO_SEC),

/* 60 */
PERMISSION("BPI_BSI_SLV1",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("BPI_BSI_SLV2",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_EMI_MPU",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DVFS_PROC",                   NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DRAMC_CH0_TOP0",              NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DRAMC_CH0_TOP1",              NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DRAMC_CH0_TOP2",              NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DRAMC_CH0_TOP3",              NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DRAMC_CH0_TOP4",              NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DRAMC_CH1_TOP0",              NO_SEC, FORBID, NO_SEC),

/* 70 */
PERMISSION("INFRASYS_DRAMC_CH1_TOP1",              NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DRAMC_CH1_TOP2",              NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DRAMC_CH1_TOP3",              NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DRAMC_CH1_TOP4",              NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_GCE",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_CCIF2_AP",                    NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_CCIF2_MD",                    NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_CCIF3_AP",                    NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_CCIF3_MD",                    NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRA_AO_PWRMCU Partition 1",          S_RW_NS_R, FORBID, NO_SEC),

/* 80 */
PERMISSION("INFRA_AO_PWRMCU Partition 2",          S_RW_NS_R, FORBID, NO_SEC),
PERMISSION("INFRA_AO_PWRMCU Partition 3",          S_RW_NS_R, FORBID, NO_SEC),
PERMISSION("INFRA_AO_PWRMCU Partition 4",          S_RW_NS_R, FORBID, NO_SEC),
PERMISSION("INFRA_AO_PWRMCU Partition 5",          S_RW_NS_R, FORBID, NO_SEC),
PERMISSION("INFRA_AO_PWRMCU Partition 6",          S_RW_NS_R, FORBID, NO_SEC),
PERMISSION("INFRA_AO_PWRMCU Partition 7",          S_RW_NS_R, FORBID, NO_SEC),
PERMISSION("INFRA_AO_PWRMCU Partition 8",          S_RW_NS_R, FORBID, NO_SEC),
PERMISSION("INFRA_AO_SCP",                         NO_SEC, NO_SEC, NO_SEC),
PERMISSION("INFRA_AO_MCUCFG",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("INFRASYS_DBUGSYS",                     NO_SEC, FORBID, NO_SEC),

/* 90 */
PERMISSION("PERISYS_APDMA",                        NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_AUXADC",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_UART0",                        NO_SEC, NO_SEC, NO_SEC),
PERMISSION("PERISYS_UART1",                        NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_UART2",                        NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_I2C6",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_PWM",                          NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_I2C0",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_I2C1",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_I2C2",                         NO_SEC, FORBID, NO_SEC),

/* 100 */
PERMISSION("PERISYS_SPI0",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_PTP",                          NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_BTIF",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("RESERVE",                              NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_DISP_PWM",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_I2C3",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_SPI1",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_I2C4",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_SPI2",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_SPI3",                         NO_SEC, FORBID, NO_SEC),

/* 110 */
PERMISSION("PERISYS_I2C1_IMM",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_I2C2_IMM",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_I2C5",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_I2C5_IMM",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_SPI4",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_SPI5",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_I2C7",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_I2C8",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_USB",                          NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_USB_2_0_SUB",                  NO_SEC, FORBID, NO_SEC),

/* 120 */
PERMISSION("PERISYS_AUDIO",                        NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_MSDC0",                        NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_MSDC1",                        NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_MSDC2",                        NO_SEC, FORBID, NO_SEC),
PERMISSION("RESERVE",                              NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_UFS",                          NO_SEC, FORBID, NO_SEC),
PERMISSION("RESERVE",                              NO_SEC, FORBID, NO_SEC),
PERMISSION("RESERVE",                              NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_RESERVE",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("EAST_RESERVE_0",                       NO_SEC, FORBID, NO_SEC),

/* 130 */
PERMISSION("EAST_RESERVE_1",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("EAST_RESERVE_2",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("EAST_RESERVE_3",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("EAST_RESERVE_4",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("EAST_IO_CFG_RT",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("EAST_RESERVE_6",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("EAST_RESERVE_7",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("EAST_CSI0_TOP_AO",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("RESERVE",                              NO_SEC, FORBID, NO_SEC),
PERMISSION("EAST_RESERVE_A",                       NO_SEC, FORBID, NO_SEC),

/* 140 */
PERMISSION("EAST_RESERVE_B",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("EAST_RESERVE_C",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("EAST_RESERVE_D",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("EAST_RESERVE_E",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("EAST_RESERVE_F",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_RESERVE_0",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_RESERVE_1",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_IO_CFG_RM",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_IO_CFG_RB",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_EFUSE",                          NO_SEC, FORBID, NO_SEC),

/* 150 */
PERMISSION("SOUTH_RESERVE_5",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_RESERVE_6",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_RESERVE_7",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_RESERVE_8",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_RESERVE_9",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_RESERVE_A",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_RESERVE_B",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_RESERVE_C",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_RESERVE_D",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("SOUTH_RESERVE_E",                      NO_SEC, FORBID, NO_SEC),

/* 160 */
PERMISSION("SOUTH_RESERVE_F",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_RESERVE_0",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_MSDC1_PAD_MACRO",                 NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_RESERVE_2",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_RESERVE_3",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_RESERVE_4",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_MIPI_TX_CONFIG",                  NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_RESERVE_6",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_IO_CFG_LB",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_IO_CFG_LM",                       NO_SEC, FORBID, NO_SEC),

/* 170 */
PERMISSION("WEST_IO_CFG_BL",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_RESERVE_A",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_RESERVE_B",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_RESERVE_C",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_RESERVE_D",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_RESERVE_E",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("WEST_RESERVE_F",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("NORTH_RESERVE_0",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("EFUSE_TOP",                            NO_SEC, FORBID, NO_SEC),
PERMISSION("NORTH_IO_CFG_LT",                      NO_SEC, FORBID, NO_SEC),

/* 180 */
PERMISSION("NORTH_IO_CFG_TL",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("NORTH_USB20 PHY",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("NORTH_MSDC0 PAD MACRO",                NO_SEC, FORBID, NO_SEC),
PERMISSION("NORTH_RESERVE_6",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("NORTH_RESERVE_7",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("NORTH_RESERVE_8",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("NORTH_RESERVE_9",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("NORTH_UFS_MPHY",                       NO_SEC, FORBID, NO_SEC),
PERMISSION("NORTH_RESERVE_B",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("NORTH_RESERVE_C",                      NO_SEC, FORBID, NO_SEC),

/* 190 */
PERMISSION("NORTH_RESERVE_D",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("NORTH_RESERVE_E",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("NORTH_RESERVE_F",                      NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_CONN",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_MD_VIOLATION",                 NO_SEC, FORBID, NO_SEC),
PERMISSION("PERISYS_RESERVE",                      NO_SEC, FORBID, NO_SEC)
};

static const struct DEVICE_INFO D_APC_MM_Devices[] = {
/* module,                             domain0, domain1, domain2 */

/* 0 */
PERMISSION("G3D_CONFIG",                  NO_SEC, FORBID, NO_SEC),
PERMISSION("MFG VAD",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("SC0 VAD",                     NO_SEC, FORBID, NO_SEC),
PERMISSION("MFG_OTHERS",                  NO_SEC, FORBID, NO_SEC),
PERMISSION("MMSYS_CONFIG",                NO_SEC, NO_SEC, NO_SEC),
PERMISSION("MDP_RDMA0",                   NO_SEC, NO_SEC, NO_SEC),
PERMISSION("MDP_RDMA1",                   NO_SEC, NO_SEC, NO_SEC),
PERMISSION("MDP_RSZ0",                    NO_SEC, NO_SEC, NO_SEC),
PERMISSION("MDP_RSZ1",                    NO_SEC, NO_SEC, NO_SEC),
PERMISSION("MDP_WROT0",                   NO_SEC, NO_SEC, NO_SEC),

/* 10 */
PERMISSION("MDP_WDMA",                    NO_SEC, NO_SEC, NO_SEC),
PERMISSION("MDP_TDSHP",                   NO_SEC, FORBID, NO_SEC),
PERMISSION("DISP_OVL0",                   NO_SEC, FORBID, NO_SEC),
PERMISSION("DISP_OVL0_2L",                NO_SEC, FORBID, NO_SEC),
PERMISSION("DISP_OVL1_2L",                NO_SEC, FORBID, NO_SEC),
PERMISSION("DISP_RDMA0",                  NO_SEC, FORBID, NO_SEC),
PERMISSION("DISP_RDMA1",                  NO_SEC, FORBID, NO_SEC),
PERMISSION("DISP_WDMA0",                  NO_SEC, FORBID, NO_SEC),
PERMISSION("DISP_COLOR0",                 NO_SEC, FORBID, NO_SEC),
PERMISSION("DISP_CCORR0",                 NO_SEC, FORBID, NO_SEC),

/* 20 */
PERMISSION("DISP_AAL0",                   NO_SEC, FORBID, NO_SEC),
PERMISSION("DISP_GAMMA0",                 NO_SEC, FORBID, NO_SEC),
PERMISSION("DISP_DITHER0",                NO_SEC, FORBID, NO_SEC),
PERMISSION("DSI_SPLIT",                   NO_SEC, FORBID, NO_SEC),
PERMISSION("DSI0",                        NO_SEC, FORBID, NO_SEC),
PERMISSION("DPI",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("MM_MUTEX",                    NO_SEC, FORBID, NO_SEC),
PERMISSION("SMI_LARB0",                   NO_SEC, FORBID, NO_SEC),
PERMISSION("SMI_LARB1",                   NO_SEC, FORBID, NO_SEC),
PERMISSION("SMI_COMMON",                  NO_SEC, FORBID, NO_SEC),

/* 30 */
PERMISSION("DISP_RSZ",                    NO_SEC, FORBID, NO_SEC),
PERMISSION("MDP_AAL",                     NO_SEC, NO_SEC, NO_SEC),
PERMISSION("MDP_CCORR",                   NO_SEC, NO_SEC, NO_SEC),
PERMISSION("DBI",                         NO_SEC, FORBID, NO_SEC),
PERMISSION("MMSYS_OTHERS",                NO_SEC, FORBID, NO_SEC),
PERMISSION("IMGSYS_CONFIG",               NO_SEC, NO_SEC, NO_SEC),
PERMISSION("IMGSYS_SMI_LARB1",            NO_SEC, FORBID, NO_SEC),
PERMISSION("IMGSYS_DISP_A0",              NO_SEC, NO_SEC, NO_SEC),
PERMISSION("IMGSYS_DISP_A1",              NO_SEC, FORBID, NO_SEC),
PERMISSION("IMGSYS_DISP_A2",              NO_SEC, FORBID, NO_SEC),

/* 40 */
PERMISSION("IMGSYS_DISP_A3",              NO_SEC, FORBID, NO_SEC),
PERMISSION("IMGSYS_DISP_A4",              NO_SEC, FORBID, NO_SEC),
PERMISSION("IMGSYS_DISP_A5",              NO_SEC, FORBID, NO_SEC),
PERMISSION("IMGSYS_DPE",                  NO_SEC, FORBID, NO_SEC),
PERMISSION("IMGSYS_RSC",                  NO_SEC, FORBID, NO_SEC),
PERMISSION("IMGSYS_WPEA",                 NO_SEC, FORBID, NO_SEC),
PERMISSION("IMGSYS_FDVT",                 NO_SEC, NO_SEC, NO_SEC),
PERMISSION("IMGSYS_OWE",                  NO_SEC, FORBID, NO_SEC),
PERMISSION("IMGSYS_WPEB",                 NO_SEC, FORBID, NO_SEC),
PERMISSION("IMGSYS_MFB",                  NO_SEC, FORBID, NO_SEC),

/* 50 */
PERMISSION("IMGSYS_SMI_LARB2",            NO_SEC, FORBID, NO_SEC),
PERMISSION("IMGSYS_OTHERS",               NO_SEC, FORBID, NO_SEC),
PERMISSION("VENCSYS_GLOBAL_CON",          NO_SEC, NO_SEC, NO_SEC),
PERMISSION("VENCSYSSYS_SMI_LARB4",        NO_SEC, NO_SEC, NO_SEC),
PERMISSION("VENCSYS_VENC",                NO_SEC, NO_SEC, NO_SEC),
PERMISSION("VENCSYS_JPGENC",              NO_SEC, FORBID, NO_SEC),
PERMISSION("VENCSYS_MBIST_CTRL",          NO_SEC, FORBID, NO_SEC),
PERMISSION("VENCSYS_OTHERS",              NO_SEC, FORBID, NO_SEC),
PERMISSION("VDECSYS_GLOBAL_CON",          NO_SEC, NO_SEC, NO_SEC),
PERMISSION("VDECSYS_SMI_LARB1",           NO_SEC, FORBID, NO_SEC),

/* 60 */
PERMISSION("VDECSYS_FULL_TOP",            NO_SEC, NO_SEC, NO_SEC),
PERMISSION("VDECSYS_OTHERS",              NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAMSYS_TOP",           NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_LARB6",                NO_SEC, NO_SEC, NO_SEC),
PERMISSION("CAMSYS_LARB3",                NO_SEC, NO_SEC, NO_SEC),
PERMISSION("CAMSYS_CAM_TOP",              NO_SEC, NO_SEC, NO_SEC),
PERMISSION("CAMSYS_CAM_A",                NO_SEC, NO_SEC, NO_SEC),
PERMISSION("CAMSYS_CAM_A",                NO_SEC, NO_SEC, NO_SEC),
PERMISSION("CAMSYS_CAM_B",                NO_SEC, NO_SEC, NO_SEC),
PERMISSION("CAMSYS_CAM_B",                NO_SEC, NO_SEC, NO_SEC),

/* 70 */
PERMISSION("CAMSYS_CAM_C",                NO_SEC, NO_SEC, NO_SEC),
PERMISSION("CAMSYS_CAM_C",                NO_SEC, NO_SEC, NO_SEC),
PERMISSION("CAMSYS_CAM_TOP_SET",          NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_A_SET",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_A_SET",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_B_SET",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_B_SET",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_C_SET",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_C_SET",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_TOP_INNER",        NO_SEC, FORBID, NO_SEC),

/* 80 */
PERMISSION("CAMSYS_CAM_A_INNER",          NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_A_INNER",          NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_B_INNER",          NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_B_INNER",          NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_C_INNER",          NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_C_INNER",          NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_A_EXT",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_B_EXT",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_C_EXT",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_TOP_CLR",          NO_SEC, FORBID, NO_SEC),

/* 90 */
PERMISSION("CAMSYS_CAM_A_CLR",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_A_CLR",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_B_CLR",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_B_CLR",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_C_CLR",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_C_CLR",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_A_EXT",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_B_EXT",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_C_EXT",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAM_RESERVE",          NO_SEC, FORBID, NO_SEC),

/* 100 */
PERMISSION("CAMSYS_SENINF_A",             NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_SENINF_B",             NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_SENINF_C",             NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_SENINF_D",             NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_SENINF_E",             NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_SENINF_F",             NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_SENINF_G",             NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_SENINF_H",             NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAMSV_A",              NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAMSV_B",              NO_SEC, FORBID, NO_SEC),

/* 110 */
PERMISSION("CAMSYS_CAMSV_C",              NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CAMSV_D",              NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_MD32 DMEM_12",         NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_RESEVE",               NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CCU_CTL",              NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CCU_H2T_A",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CCU_T2H_A",            NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_RESERVE",              NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_RESERVE",              NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_CCU_DMA",              NO_SEC, FORBID, NO_SEC),

/* 120 */
PERMISSION("CAMSYS_TSF",                  NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_MD32_PMEM_24",         NO_SEC, FORBID, NO_SEC),
PERMISSION("CAMSYS_OTHERS",               NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_CFG",                  NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_ADL_CTRL",             NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREA_DMEM_0_128KB",   NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREA_DMEM_128_256KB", NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREA_IMEM_256KB",     NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREA_CONTROL",        NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREA_DEBUG",          NO_SEC, FORBID, NO_SEC),

/* 130 */
PERMISSION("VPUSYS_COREB_DMEM_0_128KB",   NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREB_DMEM_128_256KB", NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREB_IMEM_256KB",     NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREB_CONTROL",        NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREB_DEBUG",          NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREC_DMEM_0_128KB",   NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREC_DMEM_128_256KB", NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREC_IMEM_256KB",     NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREC_CONTROL",        NO_SEC, FORBID, NO_SEC),
PERMISSION("VPUSYS_COREC_DEBUG",          NO_SEC, FORBID, NO_SEC),

/* 140 */
PERMISSION("VPUSYS_OTHERS",               NO_SEC, FORBID, NO_SEC)
};

void devapc_init(void);

#endif /* DEVAPC_H */

