// SPDX-License-Identifier: GPL-2.0
/*
 * SH7785 Pinmux
 *
 *  Copyright (C) 2008  Magnus Damm
 */

#include <linux/kernel.h>
#include <cpu/sh7785.h>

#include "sh_pfc.h"

enum {
	PINMUX_RESERVED = 0,

	PINMUX_DATA_BEGIN,
	PA7_DATA, PA6_DATA, PA5_DATA, PA4_DATA,
	PA3_DATA, PA2_DATA, PA1_DATA, PA0_DATA,
	PB7_DATA, PB6_DATA, PB5_DATA, PB4_DATA,
	PB3_DATA, PB2_DATA, PB1_DATA, PB0_DATA,
	PC7_DATA, PC6_DATA, PC5_DATA, PC4_DATA,
	PC3_DATA, PC2_DATA, PC1_DATA, PC0_DATA,
	PD7_DATA, PD6_DATA, PD5_DATA, PD4_DATA,
	PD3_DATA, PD2_DATA, PD1_DATA, PD0_DATA,
	PE5_DATA, PE4_DATA, PE3_DATA, PE2_DATA, PE1_DATA, PE0_DATA,
	PF7_DATA, PF6_DATA, PF5_DATA, PF4_DATA,
	PF3_DATA, PF2_DATA, PF1_DATA, PF0_DATA,
	PG7_DATA, PG6_DATA, PG5_DATA, PG4_DATA,
	PG3_DATA, PG2_DATA, PG1_DATA, PG0_DATA,
	PH7_DATA, PH6_DATA, PH5_DATA, PH4_DATA,
	PH3_DATA, PH2_DATA, PH1_DATA, PH0_DATA,
	PJ7_DATA, PJ6_DATA, PJ5_DATA, PJ4_DATA,
	PJ3_DATA, PJ2_DATA, PJ1_DATA, PJ0_DATA,
	PK7_DATA, PK6_DATA, PK5_DATA, PK4_DATA,
	PK3_DATA, PK2_DATA, PK1_DATA, PK0_DATA,
	PL7_DATA, PL6_DATA, PL5_DATA, PL4_DATA,
	PL3_DATA, PL2_DATA, PL1_DATA, PL0_DATA,
	PM1_DATA, PM0_DATA,
	PN7_DATA, PN6_DATA, PN5_DATA, PN4_DATA,
	PN3_DATA, PN2_DATA, PN1_DATA, PN0_DATA,
	PP5_DATA, PP4_DATA, PP3_DATA, PP2_DATA, PP1_DATA, PP0_DATA,
	PQ4_DATA, PQ3_DATA, PQ2_DATA, PQ1_DATA, PQ0_DATA,
	PR3_DATA, PR2_DATA, PR1_DATA, PR0_DATA,
	PINMUX_DATA_END,

	PINMUX_INPUT_BEGIN,
	PA7_IN, PA6_IN, PA5_IN, PA4_IN,
	PA3_IN, PA2_IN, PA1_IN, PA0_IN,
	PB7_IN, PB6_IN, PB5_IN, PB4_IN,
	PB3_IN, PB2_IN, PB1_IN, PB0_IN,
	PC7_IN, PC6_IN, PC5_IN, PC4_IN,
	PC3_IN, PC2_IN, PC1_IN, PC0_IN,
	PD7_IN, PD6_IN, PD5_IN, PD4_IN,
	PD3_IN, PD2_IN, PD1_IN, PD0_IN,
	PE5_IN, PE4_IN, PE3_IN, PE2_IN, PE1_IN, PE0_IN,
	PF7_IN, PF6_IN, PF5_IN, PF4_IN,
	PF3_IN, PF2_IN, PF1_IN, PF0_IN,
	PG7_IN, PG6_IN, PG5_IN, PG4_IN,
	PG3_IN, PG2_IN, PG1_IN, PG0_IN,
	PH7_IN, PH6_IN, PH5_IN, PH4_IN,
	PH3_IN, PH2_IN, PH1_IN, PH0_IN,
	PJ7_IN, PJ6_IN, PJ5_IN, PJ4_IN,
	PJ3_IN, PJ2_IN, PJ1_IN, PJ0_IN,
	PK7_IN, PK6_IN, PK5_IN, PK4_IN,
	PK3_IN, PK2_IN, PK1_IN, PK0_IN,
	PL7_IN, PL6_IN, PL5_IN, PL4_IN,
	PL3_IN, PL2_IN, PL1_IN, PL0_IN,
	PM1_IN, PM0_IN,
	PN7_IN, PN6_IN, PN5_IN, PN4_IN,
	PN3_IN, PN2_IN, PN1_IN, PN0_IN,
	PP5_IN, PP4_IN, PP3_IN, PP2_IN, PP1_IN, PP0_IN,
	PQ4_IN, PQ3_IN, PQ2_IN, PQ1_IN, PQ0_IN,
	PR3_IN, PR2_IN, PR1_IN, PR0_IN,
	PINMUX_INPUT_END,

	PINMUX_OUTPUT_BEGIN,
	PA7_OUT, PA6_OUT, PA5_OUT, PA4_OUT,
	PA3_OUT, PA2_OUT, PA1_OUT, PA0_OUT,
	PB7_OUT, PB6_OUT, PB5_OUT, PB4_OUT,
	PB3_OUT, PB2_OUT, PB1_OUT, PB0_OUT,
	PC7_OUT, PC6_OUT, PC5_OUT, PC4_OUT,
	PC3_OUT, PC2_OUT, PC1_OUT, PC0_OUT,
	PD7_OUT, PD6_OUT, PD5_OUT, PD4_OUT,
	PD3_OUT, PD2_OUT, PD1_OUT, PD0_OUT,
	PE5_OUT, PE4_OUT, PE3_OUT, PE2_OUT, PE1_OUT, PE0_OUT,
	PF7_OUT, PF6_OUT, PF5_OUT, PF4_OUT,
	PF3_OUT, PF2_OUT, PF1_OUT, PF0_OUT,
	PG7_OUT, PG6_OUT, PG5_OUT, PG4_OUT,
	PG3_OUT, PG2_OUT, PG1_OUT, PG0_OUT,
	PH7_OUT, PH6_OUT, PH5_OUT, PH4_OUT,
	PH3_OUT, PH2_OUT, PH1_OUT, PH0_OUT,
	PJ7_OUT, PJ6_OUT, PJ5_OUT, PJ4_OUT,
	PJ3_OUT, PJ2_OUT, PJ1_OUT, PJ0_OUT,
	PK7_OUT, PK6_OUT, PK5_OUT, PK4_OUT,
	PK3_OUT, PK2_OUT, PK1_OUT, PK0_OUT,
	PL7_OUT, PL6_OUT, PL5_OUT, PL4_OUT,
	PL3_OUT, PL2_OUT, PL1_OUT, PL0_OUT,
	PM1_OUT, PM0_OUT,
	PN7_OUT, PN6_OUT, PN5_OUT, PN4_OUT,
	PN3_OUT, PN2_OUT, PN1_OUT, PN0_OUT,
	PP5_OUT, PP4_OUT, PP3_OUT, PP2_OUT, PP1_OUT, PP0_OUT,
	PQ4_OUT, PQ3_OUT, PQ2_OUT, PQ1_OUT, PQ0_OUT,
	PR3_OUT, PR2_OUT, PR1_OUT, PR0_OUT,
	PINMUX_OUTPUT_END,

	PINMUX_FUNCTION_BEGIN,
	PA7_FN, PA6_FN, PA5_FN, PA4_FN,
	PA3_FN, PA2_FN, PA1_FN, PA0_FN,
	PB7_FN, PB6_FN, PB5_FN, PB4_FN,
	PB3_FN, PB2_FN, PB1_FN, PB0_FN,
	PC7_FN, PC6_FN, PC5_FN, PC4_FN,
	PC3_FN, PC2_FN, PC1_FN, PC0_FN,
	PD7_FN, PD6_FN, PD5_FN, PD4_FN,
	PD3_FN, PD2_FN, PD1_FN, PD0_FN,
	PE5_FN, PE4_FN, PE3_FN, PE2_FN, PE1_FN, PE0_FN,
	PF7_FN, PF6_FN, PF5_FN, PF4_FN,
	PF3_FN, PF2_FN, PF1_FN, PF0_FN,
	PG7_FN, PG6_FN, PG5_FN, PG4_FN,
	PG3_FN, PG2_FN, PG1_FN, PG0_FN,
	PH7_FN, PH6_FN, PH5_FN, PH4_FN,
	PH3_FN, PH2_FN, PH1_FN, PH0_FN,
	PJ7_FN, PJ6_FN, PJ5_FN, PJ4_FN,
	PJ3_FN, PJ2_FN, PJ1_FN, PJ0_FN,
	PK7_FN, PK6_FN, PK5_FN, PK4_FN,
	PK3_FN, PK2_FN, PK1_FN, PK0_FN,
	PL7_FN, PL6_FN, PL5_FN, PL4_FN,
	PL3_FN, PL2_FN, PL1_FN, PL0_FN,
	PM1_FN, PM0_FN,
	PN7_FN, PN6_FN, PN5_FN, PN4_FN,
	PN3_FN, PN2_FN, PN1_FN, PN0_FN,
	PP5_FN, PP4_FN, PP3_FN, PP2_FN, PP1_FN, PP0_FN,
	PQ4_FN, PQ3_FN, PQ2_FN, PQ1_FN, PQ0_FN,
	PR3_FN, PR2_FN, PR1_FN, PR0_FN,
	P1MSEL15_0, P1MSEL15_1,
	P1MSEL14_0, P1MSEL14_1,
	P1MSEL13_0, P1MSEL13_1,
	P1MSEL12_0, P1MSEL12_1,
	P1MSEL11_0, P1MSEL11_1,
	P1MSEL10_0, P1MSEL10_1,
	P1MSEL9_0, P1MSEL9_1,
	P1MSEL8_0, P1MSEL8_1,
	P1MSEL7_0, P1MSEL7_1,
	P1MSEL6_0, P1MSEL6_1,
	P1MSEL5_0,
	P1MSEL4_0, P1MSEL4_1,
	P1MSEL3_0, P1MSEL3_1,
	P1MSEL2_0, P1MSEL2_1,
	P1MSEL1_0, P1MSEL1_1,
	P1MSEL0_0, P1MSEL0_1,
	P2MSEL2_0, P2MSEL2_1,
	P2MSEL1_0, P2MSEL1_1,
	P2MSEL0_0, P2MSEL0_1,
	PINMUX_FUNCTION_END,

	PINMUX_MARK_BEGIN,
	D63_AD31_MARK,
	D62_AD30_MARK,
	D61_AD29_MARK,
	D60_AD28_MARK,
	D59_AD27_MARK,
	D58_AD26_MARK,
	D57_AD25_MARK,
	D56_AD24_MARK,
	D55_AD23_MARK,
	D54_AD22_MARK,
	D53_AD21_MARK,
	D52_AD20_MARK,
	D51_AD19_MARK,
	D50_AD18_MARK,
	D49_AD17_DB5_MARK,
	D48_AD16_DB4_MARK,
	D47_AD15_DB3_MARK,
	D46_AD14_DB2_MARK,
	D45_AD13_DB1_MARK,
	D44_AD12_DB0_MARK,
	D43_AD11_DG5_MARK,
	D42_AD10_DG4_MARK,
	D41_AD9_DG3_MARK,
	D40_AD8_DG2_MARK,
	D39_AD7_DG1_MARK,
	D38_AD6_DG0_MARK,
	D37_AD5_DR5_MARK,
	D36_AD4_DR4_MARK,
	D35_AD3_DR3_MARK,
	D34_AD2_DR2_MARK,
	D33_AD1_DR1_MARK,
	D32_AD0_DR0_MARK,
	REQ1_MARK,
	REQ2_MARK,
	REQ3_MARK,
	GNT1_MARK,
	GNT2_MARK,
	GNT3_MARK,
	MMCCLK_MARK,
	D31_MARK,
	D30_MARK,
	D29_MARK,
	D28_MARK,
	D27_MARK,
	D26_MARK,
	D25_MARK,
	D24_MARK,
	D23_MARK,
	D22_MARK,
	D21_MARK,
	D20_MARK,
	D19_MARK,
	D18_MARK,
	D17_MARK,
	D16_MARK,
	SCIF1_SCK_MARK,
	SCIF1_RXD_MARK,
	SCIF1_TXD_MARK,
	SCIF0_CTS_MARK,
	INTD_MARK,
	FCE_MARK,
	SCIF0_RTS_MARK,
	HSPI_CS_MARK,
	FSE_MARK,
	SCIF0_SCK_MARK,
	HSPI_CLK_MARK,
	FRE_MARK,
	SCIF0_RXD_MARK,
	HSPI_RX_MARK,
	FRB_MARK,
	SCIF0_TXD_MARK,
	HSPI_TX_MARK,
	FWE_MARK,
	SCIF5_TXD_MARK,
	HAC1_SYNC_MARK,
	SSI1_WS_MARK,
	SIOF_TXD_PJ_MARK,
	HAC0_SDOUT_MARK,
	SSI0_SDATA_MARK,
	SIOF_RXD_PJ_MARK,
	HAC0_SDIN_MARK,
	SSI0_SCK_MARK,
	SIOF_SYNC_PJ_MARK,
	HAC0_SYNC_MARK,
	SSI0_WS_MARK,
	SIOF_MCLK_PJ_MARK,
	HAC_RES_MARK,
	SIOF_SCK_PJ_MARK,
	HAC0_BITCLK_MARK,
	SSI0_CLK_MARK,
	HAC1_BITCLK_MARK,
	SSI1_CLK_MARK,
	TCLK_MARK,
	IOIS16_MARK,
	STATUS0_MARK,
	DRAK0_PK3_MARK,
	STATUS1_MARK,
	DRAK1_PK2_MARK,
	DACK2_MARK,
	SCIF2_TXD_MARK,
	MMCCMD_MARK,
	SIOF_TXD_PK_MARK,
	DACK3_MARK,
	SCIF2_SCK_MARK,
	MMCDAT_MARK,
	SIOF_SCK_PK_MARK,
	DREQ0_MARK,
	DREQ1_MARK,
	DRAK0_PK1_MARK,
	DRAK1_PK0_MARK,
	DREQ2_MARK,
	INTB_MARK,
	DREQ3_MARK,
	INTC_MARK,
	DRAK2_MARK,
	CE2A_MARK,
	IRL4_MARK,
	FD4_MARK,
	IRL5_MARK,
	FD5_MARK,
	IRL6_MARK,
	FD6_MARK,
	IRL7_MARK,
	FD7_MARK,
	DRAK3_MARK,
	CE2B_MARK,
	BREQ_BSACK_MARK,
	BACK_BSREQ_MARK,
	SCIF5_RXD_MARK,
	HAC1_SDIN_MARK,
	SSI1_SCK_MARK,
	SCIF5_SCK_MARK,
	HAC1_SDOUT_MARK,
	SSI1_SDATA_MARK,
	SCIF3_TXD_MARK,
	FCLE_MARK,
	SCIF3_RXD_MARK,
	FALE_MARK,
	SCIF3_SCK_MARK,
	FD0_MARK,
	SCIF4_TXD_MARK,
	FD1_MARK,
	SCIF4_RXD_MARK,
	FD2_MARK,
	SCIF4_SCK_MARK,
	FD3_MARK,
	DEVSEL_DCLKOUT_MARK,
	STOP_CDE_MARK,
	LOCK_ODDF_MARK,
	TRDY_DISPL_MARK,
	IRDY_HSYNC_MARK,
	PCIFRAME_VSYNC_MARK,
	INTA_MARK,
	GNT0_GNTIN_MARK,
	REQ0_REQOUT_MARK,
	PERR_MARK,
	SERR_MARK,
	WE7_CBE3_MARK,
	WE6_CBE2_MARK,
	WE5_CBE1_MARK,
	WE4_CBE0_MARK,
	SCIF2_RXD_MARK,
	SIOF_RXD_MARK,
	MRESETOUT_MARK,
	IRQOUT_MARK,
	PINMUX_MARK_END,
};

static const u16 pinmux_data[] = {
	/* PA GPIO */
	PINMUX_DATA(PA7_DATA, PA7_IN, PA7_OUT),
	PINMUX_DATA(PA6_DATA, PA6_IN, PA6_OUT),
	PINMUX_DATA(PA5_DATA, PA5_IN, PA5_OUT),
	PINMUX_DATA(PA4_DATA, PA4_IN, PA4_OUT),
	PINMUX_DATA(PA3_DATA, PA3_IN, PA3_OUT),
	PINMUX_DATA(PA2_DATA, PA2_IN, PA2_OUT),
	PINMUX_DATA(PA1_DATA, PA1_IN, PA1_OUT),
	PINMUX_DATA(PA0_DATA, PA0_IN, PA0_OUT),

	/* PB GPIO */
	PINMUX_DATA(PB7_DATA, PB7_IN, PB7_OUT),
	PINMUX_DATA(PB6_DATA, PB6_IN, PB6_OUT),
	PINMUX_DATA(PB5_DATA, PB5_IN, PB5_OUT),
	PINMUX_DATA(PB4_DATA, PB4_IN, PB4_OUT),
	PINMUX_DATA(PB3_DATA, PB3_IN, PB3_OUT),
	PINMUX_DATA(PB2_DATA, PB2_IN, PB2_OUT),
	PINMUX_DATA(PB1_DATA, PB1_IN, PB1_OUT),
	PINMUX_DATA(PB0_DATA, PB0_IN, PB0_OUT),

	/* PC GPIO */
	PINMUX_DATA(PC7_DATA, PC7_IN, PC7_OUT),
	PINMUX_DATA(PC6_DATA, PC6_IN, PC6_OUT),
	PINMUX_DATA(PC5_DATA, PC5_IN, PC5_OUT),
	PINMUX_DATA(PC4_DATA, PC4_IN, PC4_OUT),
	PINMUX_DATA(PC3_DATA, PC3_IN, PC3_OUT),
	PINMUX_DATA(PC2_DATA, PC2_IN, PC2_OUT),
	PINMUX_DATA(PC1_DATA, PC1_IN, PC1_OUT),
	PINMUX_DATA(PC0_DATA, PC0_IN, PC0_OUT),

	/* PD GPIO */
	PINMUX_DATA(PD7_DATA, PD7_IN, PD7_OUT),
	PINMUX_DATA(PD6_DATA, PD6_IN, PD6_OUT),
	PINMUX_DATA(PD5_DATA, PD5_IN, PD5_OUT),
	PINMUX_DATA(PD4_DATA, PD4_IN, PD4_OUT),
	PINMUX_DATA(PD3_DATA, PD3_IN, PD3_OUT),
	PINMUX_DATA(PD2_DATA, PD2_IN, PD2_OUT),
	PINMUX_DATA(PD1_DATA, PD1_IN, PD1_OUT),
	PINMUX_DATA(PD0_DATA, PD0_IN, PD0_OUT),

	/* PE GPIO */
	PINMUX_DATA(PE5_DATA, PE5_IN, PE5_OUT),
	PINMUX_DATA(PE4_DATA, PE4_IN, PE4_OUT),
	PINMUX_DATA(PE3_DATA, PE3_IN, PE3_OUT),
	PINMUX_DATA(PE2_DATA, PE2_IN, PE2_OUT),
	PINMUX_DATA(PE1_DATA, PE1_IN, PE1_OUT),
	PINMUX_DATA(PE0_DATA, PE0_IN, PE0_OUT),

	/* PF GPIO */
	PINMUX_DATA(PF7_DATA, PF7_IN, PF7_OUT),
	PINMUX_DATA(PF6_DATA, PF6_IN, PF6_OUT),
	PINMUX_DATA(PF5_DATA, PF5_IN, PF5_OUT),
	PINMUX_DATA(PF4_DATA, PF4_IN, PF4_OUT),
	PINMUX_DATA(PF3_DATA, PF3_IN, PF3_OUT),
	PINMUX_DATA(PF2_DATA, PF2_IN, PF2_OUT),
	PINMUX_DATA(PF1_DATA, PF1_IN, PF1_OUT),
	PINMUX_DATA(PF0_DATA, PF0_IN, PF0_OUT),

	/* PG GPIO */
	PINMUX_DATA(PG7_DATA, PG7_IN, PG7_OUT),
	PINMUX_DATA(PG6_DATA, PG6_IN, PG6_OUT),
	PINMUX_DATA(PG5_DATA, PG5_IN, PG5_OUT),
	PINMUX_DATA(PG4_DATA, PG4_IN, PG4_OUT),
	PINMUX_DATA(PG3_DATA, PG3_IN, PG3_OUT),
	PINMUX_DATA(PG2_DATA, PG2_IN, PG2_OUT),
	PINMUX_DATA(PG1_DATA, PG1_IN, PG1_OUT),
	PINMUX_DATA(PG0_DATA, PG0_IN, PG0_OUT),

	/* PH GPIO */
	PINMUX_DATA(PH7_DATA, PH7_IN, PH7_OUT),
	PINMUX_DATA(PH6_DATA, PH6_IN, PH6_OUT),
	PINMUX_DATA(PH5_DATA, PH5_IN, PH5_OUT),
	PINMUX_DATA(PH4_DATA, PH4_IN, PH4_OUT),
	PINMUX_DATA(PH3_DATA, PH3_IN, PH3_OUT),
	PINMUX_DATA(PH2_DATA, PH2_IN, PH2_OUT),
	PINMUX_DATA(PH1_DATA, PH1_IN, PH1_OUT),
	PINMUX_DATA(PH0_DATA, PH0_IN, PH0_OUT),

	/* PJ GPIO */
	PINMUX_DATA(PJ7_DATA, PJ7_IN, PJ7_OUT),
	PINMUX_DATA(PJ6_DATA, PJ6_IN, PJ6_OUT),
	PINMUX_DATA(PJ5_DATA, PJ5_IN, PJ5_OUT),
	PINMUX_DATA(PJ4_DATA, PJ4_IN, PJ4_OUT),
	PINMUX_DATA(PJ3_DATA, PJ3_IN, PJ3_OUT),
	PINMUX_DATA(PJ2_DATA, PJ2_IN, PJ2_OUT),
	PINMUX_DATA(PJ1_DATA, PJ1_IN, PJ1_OUT),
	PINMUX_DATA(PJ0_DATA, PJ0_IN, PJ0_OUT),

	/* PK GPIO */
	PINMUX_DATA(PK7_DATA, PK7_IN, PK7_OUT),
	PINMUX_DATA(PK6_DATA, PK6_IN, PK6_OUT),
	PINMUX_DATA(PK5_DATA, PK5_IN, PK5_OUT),
	PINMUX_DATA(PK4_DATA, PK4_IN, PK4_OUT),
	PINMUX_DATA(PK3_DATA, PK3_IN, PK3_OUT),
	PINMUX_DATA(PK2_DATA, PK2_IN, PK2_OUT),
	PINMUX_DATA(PK1_DATA, PK1_IN, PK1_OUT),
	PINMUX_DATA(PK0_DATA, PK0_IN, PK0_OUT),

	/* PL GPIO */
	PINMUX_DATA(PL7_DATA, PL7_IN, PL7_OUT),
	PINMUX_DATA(PL6_DATA, PL6_IN, PL6_OUT),
	PINMUX_DATA(PL5_DATA, PL5_IN, PL5_OUT),
	PINMUX_DATA(PL4_DATA, PL4_IN, PL4_OUT),
	PINMUX_DATA(PL3_DATA, PL3_IN, PL3_OUT),
	PINMUX_DATA(PL2_DATA, PL2_IN, PL2_OUT),
	PINMUX_DATA(PL1_DATA, PL1_IN, PL1_OUT),
	PINMUX_DATA(PL0_DATA, PL0_IN, PL0_OUT),

	/* PM GPIO */
	PINMUX_DATA(PM1_DATA, PM1_IN, PM1_OUT),
	PINMUX_DATA(PM0_DATA, PM0_IN, PM0_OUT),

	/* PN GPIO */
	PINMUX_DATA(PN7_DATA, PN7_IN, PN7_OUT),
	PINMUX_DATA(PN6_DATA, PN6_IN, PN6_OUT),
	PINMUX_DATA(PN5_DATA, PN5_IN, PN5_OUT),
	PINMUX_DATA(PN4_DATA, PN4_IN, PN4_OUT),
	PINMUX_DATA(PN3_DATA, PN3_IN, PN3_OUT),
	PINMUX_DATA(PN2_DATA, PN2_IN, PN2_OUT),
	PINMUX_DATA(PN1_DATA, PN1_IN, PN1_OUT),
	PINMUX_DATA(PN0_DATA, PN0_IN, PN0_OUT),

	/* PP GPIO */
	PINMUX_DATA(PP5_DATA, PP5_IN, PP5_OUT),
	PINMUX_DATA(PP4_DATA, PP4_IN, PP4_OUT),
	PINMUX_DATA(PP3_DATA, PP3_IN, PP3_OUT),
	PINMUX_DATA(PP2_DATA, PP2_IN, PP2_OUT),
	PINMUX_DATA(PP1_DATA, PP1_IN, PP1_OUT),
	PINMUX_DATA(PP0_DATA, PP0_IN, PP0_OUT),

	/* PQ GPIO */
	PINMUX_DATA(PQ4_DATA, PQ4_IN, PQ4_OUT),
	PINMUX_DATA(PQ3_DATA, PQ3_IN, PQ3_OUT),
	PINMUX_DATA(PQ2_DATA, PQ2_IN, PQ2_OUT),
	PINMUX_DATA(PQ1_DATA, PQ1_IN, PQ1_OUT),
	PINMUX_DATA(PQ0_DATA, PQ0_IN, PQ0_OUT),

	/* PR GPIO */
	PINMUX_DATA(PR3_DATA, PR3_IN, PR3_OUT),
	PINMUX_DATA(PR2_DATA, PR2_IN, PR2_OUT),
	PINMUX_DATA(PR1_DATA, PR1_IN, PR1_OUT),
	PINMUX_DATA(PR0_DATA, PR0_IN, PR0_OUT),

	/* PA FN */
	PINMUX_DATA(D63_AD31_MARK, PA7_FN),
	PINMUX_DATA(D62_AD30_MARK, PA6_FN),
	PINMUX_DATA(D61_AD29_MARK, PA5_FN),
	PINMUX_DATA(D60_AD28_MARK, PA4_FN),
	PINMUX_DATA(D59_AD27_MARK, PA3_FN),
	PINMUX_DATA(D58_AD26_MARK, PA2_FN),
	PINMUX_DATA(D57_AD25_MARK, PA1_FN),
	PINMUX_DATA(D56_AD24_MARK, PA0_FN),

	/* PB FN */
	PINMUX_DATA(D55_AD23_MARK, PB7_FN),
	PINMUX_DATA(D54_AD22_MARK, PB6_FN),
	PINMUX_DATA(D53_AD21_MARK, PB5_FN),
	PINMUX_DATA(D52_AD20_MARK, PB4_FN),
	PINMUX_DATA(D51_AD19_MARK, PB3_FN),
	PINMUX_DATA(D50_AD18_MARK, PB2_FN),
	PINMUX_DATA(D49_AD17_DB5_MARK, PB1_FN),
	PINMUX_DATA(D48_AD16_DB4_MARK, PB0_FN),

	/* PC FN */
	PINMUX_DATA(D47_AD15_DB3_MARK, PC7_FN),
	PINMUX_DATA(D46_AD14_DB2_MARK, PC6_FN),
	PINMUX_DATA(D45_AD13_DB1_MARK, PC5_FN),
	PINMUX_DATA(D44_AD12_DB0_MARK, PC4_FN),
	PINMUX_DATA(D43_AD11_DG5_MARK, PC3_FN),
	PINMUX_DATA(D42_AD10_DG4_MARK, PC2_FN),
	PINMUX_DATA(D41_AD9_DG3_MARK, PC1_FN),
	PINMUX_DATA(D40_AD8_DG2_MARK, PC0_FN),

	/* PD FN */
	PINMUX_DATA(D39_AD7_DG1_MARK, PD7_FN),
	PINMUX_DATA(D38_AD6_DG0_MARK, PD6_FN),
	PINMUX_DATA(D37_AD5_DR5_MARK, PD5_FN),
	PINMUX_DATA(D36_AD4_DR4_MARK, PD4_FN),
	PINMUX_DATA(D35_AD3_DR3_MARK, PD3_FN),
	PINMUX_DATA(D34_AD2_DR2_MARK, PD2_FN),
	PINMUX_DATA(D33_AD1_DR1_MARK, PD1_FN),
	PINMUX_DATA(D32_AD0_DR0_MARK, PD0_FN),

	/* PE FN */
	PINMUX_DATA(REQ1_MARK, PE5_FN),
	PINMUX_DATA(REQ2_MARK, PE4_FN),
	PINMUX_DATA(REQ3_MARK, P2MSEL0_0, PE3_FN),
	PINMUX_DATA(GNT1_MARK, PE2_FN),
	PINMUX_DATA(GNT2_MARK, PE1_FN),
	PINMUX_DATA(GNT3_MARK, P2MSEL0_0, PE0_FN),
	PINMUX_DATA(MMCCLK_MARK, P2MSEL0_1, PE0_FN),

	/* PF FN */
	PINMUX_DATA(D31_MARK, PF7_FN),
	PINMUX_DATA(D30_MARK, PF6_FN),
	PINMUX_DATA(D29_MARK, PF5_FN),
	PINMUX_DATA(D28_MARK, PF4_FN),
	PINMUX_DATA(D27_MARK, PF3_FN),
	PINMUX_DATA(D26_MARK, PF2_FN),
	PINMUX_DATA(D25_MARK, PF1_FN),
	PINMUX_DATA(D24_MARK, PF0_FN),

	/* PF FN */
	PINMUX_DATA(D23_MARK, PG7_FN),
	PINMUX_DATA(D22_MARK, PG6_FN),
	PINMUX_DATA(D21_MARK, PG5_FN),
	PINMUX_DATA(D20_MARK, PG4_FN),
	PINMUX_DATA(D19_MARK, PG3_FN),
	PINMUX_DATA(D18_MARK, PG2_FN),
	PINMUX_DATA(D17_MARK, PG1_FN),
	PINMUX_DATA(D16_MARK, PG0_FN),

	/* PH FN */
	PINMUX_DATA(SCIF1_SCK_MARK, PH7_FN),
	PINMUX_DATA(SCIF1_RXD_MARK, PH6_FN),
	PINMUX_DATA(SCIF1_TXD_MARK, PH5_FN),
	PINMUX_DATA(SCIF0_CTS_MARK, PH4_FN),
	PINMUX_DATA(INTD_MARK, P1MSEL7_1, PH4_FN),
	PINMUX_DATA(FCE_MARK, P1MSEL8_1, P1MSEL7_0, PH4_FN),
	PINMUX_DATA(SCIF0_RTS_MARK, P1MSEL8_0, P1MSEL7_0, PH3_FN),
	PINMUX_DATA(HSPI_CS_MARK, P1MSEL8_0, P1MSEL7_1, PH3_FN),
	PINMUX_DATA(FSE_MARK, P1MSEL8_1, P1MSEL7_0, PH3_FN),
	PINMUX_DATA(SCIF0_SCK_MARK, P1MSEL8_0, P1MSEL7_0, PH2_FN),
	PINMUX_DATA(HSPI_CLK_MARK, P1MSEL8_0, P1MSEL7_1, PH2_FN),
	PINMUX_DATA(FRE_MARK, P1MSEL8_1, P1MSEL7_0, PH2_FN),
	PINMUX_DATA(SCIF0_RXD_MARK, P1MSEL8_0, P1MSEL7_0, PH1_FN),
	PINMUX_DATA(HSPI_RX_MARK, P1MSEL8_0, P1MSEL7_1, PH1_FN),
	PINMUX_DATA(FRB_MARK, P1MSEL8_1, P1MSEL7_0, PH1_FN),
	PINMUX_DATA(SCIF0_TXD_MARK, P1MSEL8_0, P1MSEL7_0, PH0_FN),
	PINMUX_DATA(HSPI_TX_MARK, P1MSEL8_0, P1MSEL7_1, PH0_FN),
	PINMUX_DATA(FWE_MARK, P1MSEL8_1, P1MSEL7_0, PH0_FN),

	/* PJ FN */
	PINMUX_DATA(SCIF5_TXD_MARK, P1MSEL2_0, P1MSEL1_0, PJ7_FN),
	PINMUX_DATA(HAC1_SYNC_MARK, P1MSEL2_0, P1MSEL1_1, PJ7_FN),
	PINMUX_DATA(SSI1_WS_MARK, P1MSEL2_1, P1MSEL1_0, PJ7_FN),
	PINMUX_DATA(SIOF_TXD_PJ_MARK, P2MSEL1_0, P1MSEL4_0, P1MSEL3_0, PJ6_FN),
	PINMUX_DATA(HAC0_SDOUT_MARK, P1MSEL4_0, P1MSEL3_1, PJ6_FN),
	PINMUX_DATA(SSI0_SDATA_MARK, P1MSEL4_1, P1MSEL3_0, PJ6_FN),
	PINMUX_DATA(SIOF_RXD_PJ_MARK, P2MSEL1_0, P1MSEL4_0, P1MSEL3_0, PJ5_FN),
	PINMUX_DATA(HAC0_SDIN_MARK, P1MSEL4_0, P1MSEL3_1, PJ5_FN),
	PINMUX_DATA(SSI0_SCK_MARK, P1MSEL4_1, P1MSEL3_0, PJ5_FN),
	PINMUX_DATA(SIOF_SYNC_PJ_MARK, P2MSEL1_0, P1MSEL4_0, P1MSEL3_0, PJ4_FN),
	PINMUX_DATA(HAC0_SYNC_MARK, P1MSEL4_0, P1MSEL3_1, PJ4_FN),
	PINMUX_DATA(SSI0_WS_MARK, P1MSEL4_1, P1MSEL3_0, PJ4_FN),
	PINMUX_DATA(SIOF_MCLK_PJ_MARK, P2MSEL1_0, P1MSEL4_0, P1MSEL3_0, PJ3_FN),
	PINMUX_DATA(HAC_RES_MARK, P1MSEL4_0, P1MSEL3_1, PJ3_FN),
	PINMUX_DATA(SIOF_SCK_PJ_MARK, P2MSEL1_0, P1MSEL4_0, P1MSEL3_0, PJ2_FN),
	PINMUX_DATA(HAC0_BITCLK_MARK, P1MSEL4_0, P1MSEL3_1, PJ2_FN),
	PINMUX_DATA(SSI0_CLK_MARK, P1MSEL4_1, P1MSEL3_0, PJ2_FN),
	PINMUX_DATA(HAC1_BITCLK_MARK, P1MSEL2_0, PJ1_FN),
	PINMUX_DATA(SSI1_CLK_MARK, P1MSEL2_1, P1MSEL1_0, PJ1_FN),
	PINMUX_DATA(TCLK_MARK, P1MSEL9_0, PJ0_FN),
	PINMUX_DATA(IOIS16_MARK, P1MSEL9_1, PJ0_FN),

	/* PK FN */
	PINMUX_DATA(STATUS0_MARK, P1MSEL15_0, PK7_FN),
	PINMUX_DATA(DRAK0_PK3_MARK, P1MSEL15_1, PK7_FN),
	PINMUX_DATA(STATUS1_MARK, P1MSEL15_0, PK6_FN),
	PINMUX_DATA(DRAK1_PK2_MARK, P1MSEL15_1, PK6_FN),
	PINMUX_DATA(DACK2_MARK, P1MSEL12_0, P1MSEL11_0, PK5_FN),
	PINMUX_DATA(SCIF2_TXD_MARK, P1MSEL12_1, P1MSEL11_0, PK5_FN),
	PINMUX_DATA(MMCCMD_MARK, P1MSEL12_1, P1MSEL11_1, PK5_FN),
	PINMUX_DATA(SIOF_TXD_PK_MARK, P2MSEL1_1,
		    P1MSEL12_0, P1MSEL11_1, PK5_FN),
	PINMUX_DATA(DACK3_MARK, P1MSEL12_0, P1MSEL11_0, PK4_FN),
	PINMUX_DATA(SCIF2_SCK_MARK, P1MSEL12_1, P1MSEL11_0, PK4_FN),
	PINMUX_DATA(MMCDAT_MARK, P1MSEL12_1, P1MSEL11_1, PK4_FN),
	PINMUX_DATA(SIOF_SCK_PK_MARK, P2MSEL1_1,
		    P1MSEL12_0, P1MSEL11_1, PK4_FN),
	PINMUX_DATA(DREQ0_MARK, PK3_FN),
	PINMUX_DATA(DREQ1_MARK, PK2_FN),
	PINMUX_DATA(DRAK0_PK1_MARK, PK1_FN),
	PINMUX_DATA(DRAK1_PK0_MARK, PK0_FN),

	/* PL FN */
	PINMUX_DATA(DREQ2_MARK, P1MSEL13_0, PL7_FN),
	PINMUX_DATA(INTB_MARK, P1MSEL13_1, PL7_FN),
	PINMUX_DATA(DREQ3_MARK, P1MSEL13_0, PL6_FN),
	PINMUX_DATA(INTC_MARK, P1MSEL13_1, PL6_FN),
	PINMUX_DATA(DRAK2_MARK, P1MSEL10_0, PL5_FN),
	PINMUX_DATA(CE2A_MARK, P1MSEL10_1, PL5_FN),
	PINMUX_DATA(IRL4_MARK, P1MSEL14_0, PL4_FN),
	PINMUX_DATA(FD4_MARK, P1MSEL14_1, PL4_FN),
	PINMUX_DATA(IRL5_MARK, P1MSEL14_0, PL3_FN),
	PINMUX_DATA(FD5_MARK, P1MSEL14_1, PL3_FN),
	PINMUX_DATA(IRL6_MARK, P1MSEL14_0, PL2_FN),
	PINMUX_DATA(FD6_MARK, P1MSEL14_1, PL2_FN),
	PINMUX_DATA(IRL7_MARK, P1MSEL14_0, PL1_FN),
	PINMUX_DATA(FD7_MARK, P1MSEL14_1, PL1_FN),
	PINMUX_DATA(DRAK3_MARK, P1MSEL10_0, PL0_FN),
	PINMUX_DATA(CE2B_MARK, P1MSEL10_1, PL0_FN),

	/* PM FN */
	PINMUX_DATA(BREQ_BSACK_MARK, PM1_FN),
	PINMUX_DATA(BACK_BSREQ_MARK, PM0_FN),

	/* PN FN */
	PINMUX_DATA(SCIF5_RXD_MARK, P1MSEL2_0, P1MSEL1_0, PN7_FN),
	PINMUX_DATA(HAC1_SDIN_MARK, P1MSEL2_0, P1MSEL1_1, PN7_FN),
	PINMUX_DATA(SSI1_SCK_MARK, P1MSEL2_1, P1MSEL1_0, PN7_FN),
	PINMUX_DATA(SCIF5_SCK_MARK, P1MSEL2_0, P1MSEL1_0, PN6_FN),
	PINMUX_DATA(HAC1_SDOUT_MARK, P1MSEL2_0, P1MSEL1_1, PN6_FN),
	PINMUX_DATA(SSI1_SDATA_MARK, P1MSEL2_1, P1MSEL1_0, PN6_FN),
	PINMUX_DATA(SCIF3_TXD_MARK, P1MSEL0_0, PN5_FN),
	PINMUX_DATA(FCLE_MARK, P1MSEL0_1, PN5_FN),
	PINMUX_DATA(SCIF3_RXD_MARK, P1MSEL0_0, PN4_FN),
	PINMUX_DATA(FALE_MARK, P1MSEL0_1, PN4_FN),
	PINMUX_DATA(SCIF3_SCK_MARK, P1MSEL0_0, PN3_FN),
	PINMUX_DATA(FD0_MARK, P1MSEL0_1, PN3_FN),
	PINMUX_DATA(SCIF4_TXD_MARK, P1MSEL0_0, PN2_FN),
	PINMUX_DATA(FD1_MARK, P1MSEL0_1, PN2_FN),
	PINMUX_DATA(SCIF4_RXD_MARK, P1MSEL0_0, PN1_FN),
	PINMUX_DATA(FD2_MARK, P1MSEL0_1, PN1_FN),
	PINMUX_DATA(SCIF4_SCK_MARK, P1MSEL0_0, PN0_FN),
	PINMUX_DATA(FD3_MARK, P1MSEL0_1, PN0_FN),

	/* PP FN */
	PINMUX_DATA(DEVSEL_DCLKOUT_MARK, PP5_FN),
	PINMUX_DATA(STOP_CDE_MARK, PP4_FN),
	PINMUX_DATA(LOCK_ODDF_MARK, PP3_FN),
	PINMUX_DATA(TRDY_DISPL_MARK, PP2_FN),
	PINMUX_DATA(IRDY_HSYNC_MARK, PP1_FN),
	PINMUX_DATA(PCIFRAME_VSYNC_MARK, PP0_FN),

	/* PQ FN */
	PINMUX_DATA(INTA_MARK, PQ4_FN),
	PINMUX_DATA(GNT0_GNTIN_MARK, PQ3_FN),
	PINMUX_DATA(REQ0_REQOUT_MARK, PQ2_FN),
	PINMUX_DATA(PERR_MARK, PQ1_FN),
	PINMUX_DATA(SERR_MARK, PQ0_FN),

	/* PR FN */
	PINMUX_DATA(WE7_CBE3_MARK, PR3_FN),
	PINMUX_DATA(WE6_CBE2_MARK, PR2_FN),
	PINMUX_DATA(WE5_CBE1_MARK, PR1_FN),
	PINMUX_DATA(WE4_CBE0_MARK, PR0_FN),

	/* MISC FN */
	PINMUX_DATA(SCIF2_RXD_MARK, P1MSEL6_0, P1MSEL5_0),
	PINMUX_DATA(SIOF_RXD_MARK, P2MSEL1_1, P1MSEL6_1, P1MSEL5_0),
	PINMUX_DATA(MRESETOUT_MARK, P2MSEL2_0),
	PINMUX_DATA(IRQOUT_MARK, P2MSEL2_1),
};

static const struct sh_pfc_pin pinmux_pins[] = {
	/* PA */
	PINMUX_GPIO(PA7),
	PINMUX_GPIO(PA6),
	PINMUX_GPIO(PA5),
	PINMUX_GPIO(PA4),
	PINMUX_GPIO(PA3),
	PINMUX_GPIO(PA2),
	PINMUX_GPIO(PA1),
	PINMUX_GPIO(PA0),

	/* PB */
	PINMUX_GPIO(PB7),
	PINMUX_GPIO(PB6),
	PINMUX_GPIO(PB5),
	PINMUX_GPIO(PB4),
	PINMUX_GPIO(PB3),
	PINMUX_GPIO(PB2),
	PINMUX_GPIO(PB1),
	PINMUX_GPIO(PB0),

	/* PC */
	PINMUX_GPIO(PC7),
	PINMUX_GPIO(PC6),
	PINMUX_GPIO(PC5),
	PINMUX_GPIO(PC4),
	PINMUX_GPIO(PC3),
	PINMUX_GPIO(PC2),
	PINMUX_GPIO(PC1),
	PINMUX_GPIO(PC0),

	/* PD */
	PINMUX_GPIO(PD7),
	PINMUX_GPIO(PD6),
	PINMUX_GPIO(PD5),
	PINMUX_GPIO(PD4),
	PINMUX_GPIO(PD3),
	PINMUX_GPIO(PD2),
	PINMUX_GPIO(PD1),
	PINMUX_GPIO(PD0),

	/* PE */
	PINMUX_GPIO(PE5),
	PINMUX_GPIO(PE4),
	PINMUX_GPIO(PE3),
	PINMUX_GPIO(PE2),
	PINMUX_GPIO(PE1),
	PINMUX_GPIO(PE0),

	/* PF */
	PINMUX_GPIO(PF7),
	PINMUX_GPIO(PF6),
	PINMUX_GPIO(PF5),
	PINMUX_GPIO(PF4),
	PINMUX_GPIO(PF3),
	PINMUX_GPIO(PF2),
	PINMUX_GPIO(PF1),
	PINMUX_GPIO(PF0),

	/* PG */
	PINMUX_GPIO(PG7),
	PINMUX_GPIO(PG6),
	PINMUX_GPIO(PG5),
	PINMUX_GPIO(PG4),
	PINMUX_GPIO(PG3),
	PINMUX_GPIO(PG2),
	PINMUX_GPIO(PG1),
	PINMUX_GPIO(PG0),

	/* PH */
	PINMUX_GPIO(PH7),
	PINMUX_GPIO(PH6),
	PINMUX_GPIO(PH5),
	PINMUX_GPIO(PH4),
	PINMUX_GPIO(PH3),
	PINMUX_GPIO(PH2),
	PINMUX_GPIO(PH1),
	PINMUX_GPIO(PH0),

	/* PJ */
	PINMUX_GPIO(PJ7),
	PINMUX_GPIO(PJ6),
	PINMUX_GPIO(PJ5),
	PINMUX_GPIO(PJ4),
	PINMUX_GPIO(PJ3),
	PINMUX_GPIO(PJ2),
	PINMUX_GPIO(PJ1),
	PINMUX_GPIO(PJ0),

	/* PK */
	PINMUX_GPIO(PK7),
	PINMUX_GPIO(PK6),
	PINMUX_GPIO(PK5),
	PINMUX_GPIO(PK4),
	PINMUX_GPIO(PK3),
	PINMUX_GPIO(PK2),
	PINMUX_GPIO(PK1),
	PINMUX_GPIO(PK0),

	/* PL */
	PINMUX_GPIO(PL7),
	PINMUX_GPIO(PL6),
	PINMUX_GPIO(PL5),
	PINMUX_GPIO(PL4),
	PINMUX_GPIO(PL3),
	PINMUX_GPIO(PL2),
	PINMUX_GPIO(PL1),
	PINMUX_GPIO(PL0),

	/* PM */
	PINMUX_GPIO(PM1),
	PINMUX_GPIO(PM0),

	/* PN */
	PINMUX_GPIO(PN7),
	PINMUX_GPIO(PN6),
	PINMUX_GPIO(PN5),
	PINMUX_GPIO(PN4),
	PINMUX_GPIO(PN3),
	PINMUX_GPIO(PN2),
	PINMUX_GPIO(PN1),
	PINMUX_GPIO(PN0),

	/* PP */
	PINMUX_GPIO(PP5),
	PINMUX_GPIO(PP4),
	PINMUX_GPIO(PP3),
	PINMUX_GPIO(PP2),
	PINMUX_GPIO(PP1),
	PINMUX_GPIO(PP0),

	/* PQ */
	PINMUX_GPIO(PQ4),
	PINMUX_GPIO(PQ3),
	PINMUX_GPIO(PQ2),
	PINMUX_GPIO(PQ1),
	PINMUX_GPIO(PQ0),

	/* PR */
	PINMUX_GPIO(PR3),
	PINMUX_GPIO(PR2),
	PINMUX_GPIO(PR1),
	PINMUX_GPIO(PR0),
};

#define PINMUX_FN_BASE	ARRAY_SIZE(pinmux_pins)

static const struct pinmux_func pinmux_func_gpios[] = {
	/* FN */
	GPIO_FN(D63_AD31),
	GPIO_FN(D62_AD30),
	GPIO_FN(D61_AD29),
	GPIO_FN(D60_AD28),
	GPIO_FN(D59_AD27),
	GPIO_FN(D58_AD26),
	GPIO_FN(D57_AD25),
	GPIO_FN(D56_AD24),
	GPIO_FN(D55_AD23),
	GPIO_FN(D54_AD22),
	GPIO_FN(D53_AD21),
	GPIO_FN(D52_AD20),
	GPIO_FN(D51_AD19),
	GPIO_FN(D50_AD18),
	GPIO_FN(D49_AD17_DB5),
	GPIO_FN(D48_AD16_DB4),
	GPIO_FN(D47_AD15_DB3),
	GPIO_FN(D46_AD14_DB2),
	GPIO_FN(D45_AD13_DB1),
	GPIO_FN(D44_AD12_DB0),
	GPIO_FN(D43_AD11_DG5),
	GPIO_FN(D42_AD10_DG4),
	GPIO_FN(D41_AD9_DG3),
	GPIO_FN(D40_AD8_DG2),
	GPIO_FN(D39_AD7_DG1),
	GPIO_FN(D38_AD6_DG0),
	GPIO_FN(D37_AD5_DR5),
	GPIO_FN(D36_AD4_DR4),
	GPIO_FN(D35_AD3_DR3),
	GPIO_FN(D34_AD2_DR2),
	GPIO_FN(D33_AD1_DR1),
	GPIO_FN(D32_AD0_DR0),
	GPIO_FN(REQ1),
	GPIO_FN(REQ2),
	GPIO_FN(REQ3),
	GPIO_FN(GNT1),
	GPIO_FN(GNT2),
	GPIO_FN(GNT3),
	GPIO_FN(MMCCLK),
	GPIO_FN(D31),
	GPIO_FN(D30),
	GPIO_FN(D29),
	GPIO_FN(D28),
	GPIO_FN(D27),
	GPIO_FN(D26),
	GPIO_FN(D25),
	GPIO_FN(D24),
	GPIO_FN(D23),
	GPIO_FN(D22),
	GPIO_FN(D21),
	GPIO_FN(D20),
	GPIO_FN(D19),
	GPIO_FN(D18),
	GPIO_FN(D17),
	GPIO_FN(D16),
	GPIO_FN(SCIF1_SCK),
	GPIO_FN(SCIF1_RXD),
	GPIO_FN(SCIF1_TXD),
	GPIO_FN(SCIF0_CTS),
	GPIO_FN(INTD),
	GPIO_FN(FCE),
	GPIO_FN(SCIF0_RTS),
	GPIO_FN(HSPI_CS),
	GPIO_FN(FSE),
	GPIO_FN(SCIF0_SCK),
	GPIO_FN(HSPI_CLK),
	GPIO_FN(FRE),
	GPIO_FN(SCIF0_RXD),
	GPIO_FN(HSPI_RX),
	GPIO_FN(FRB),
	GPIO_FN(SCIF0_TXD),
	GPIO_FN(HSPI_TX),
	GPIO_FN(FWE),
	GPIO_FN(SCIF5_TXD),
	GPIO_FN(HAC1_SYNC),
	GPIO_FN(SSI1_WS),
	GPIO_FN(SIOF_TXD_PJ),
	GPIO_FN(HAC0_SDOUT),
	GPIO_FN(SSI0_SDATA),
	GPIO_FN(SIOF_RXD_PJ),
	GPIO_FN(HAC0_SDIN),
	GPIO_FN(SSI0_SCK),
	GPIO_FN(SIOF_SYNC_PJ),
	GPIO_FN(HAC0_SYNC),
	GPIO_FN(SSI0_WS),
	GPIO_FN(SIOF_MCLK_PJ),
	GPIO_FN(HAC_RES),
	GPIO_FN(SIOF_SCK_PJ),
	GPIO_FN(HAC0_BITCLK),
	GPIO_FN(SSI0_CLK),
	GPIO_FN(HAC1_BITCLK),
	GPIO_FN(SSI1_CLK),
	GPIO_FN(TCLK),
	GPIO_FN(IOIS16),
	GPIO_FN(STATUS0),
	GPIO_FN(DRAK0_PK3),
	GPIO_FN(STATUS1),
	GPIO_FN(DRAK1_PK2),
	GPIO_FN(DACK2),
	GPIO_FN(SCIF2_TXD),
	GPIO_FN(MMCCMD),
	GPIO_FN(SIOF_TXD_PK),
	GPIO_FN(DACK3),
	GPIO_FN(SCIF2_SCK),
	GPIO_FN(MMCDAT),
	GPIO_FN(SIOF_SCK_PK),
	GPIO_FN(DREQ0),
	GPIO_FN(DREQ1),
	GPIO_FN(DRAK0_PK1),
	GPIO_FN(DRAK1_PK0),
	GPIO_FN(DREQ2),
	GPIO_FN(INTB),
	GPIO_FN(DREQ3),
	GPIO_FN(INTC),
	GPIO_FN(DRAK2),
	GPIO_FN(CE2A),
	GPIO_FN(IRL4),
	GPIO_FN(FD4),
	GPIO_FN(IRL5),
	GPIO_FN(FD5),
	GPIO_FN(IRL6),
	GPIO_FN(FD6),
	GPIO_FN(IRL7),
	GPIO_FN(FD7),
	GPIO_FN(DRAK3),
	GPIO_FN(CE2B),
	GPIO_FN(BREQ_BSACK),
	GPIO_FN(BACK_BSREQ),
	GPIO_FN(SCIF5_RXD),
	GPIO_FN(HAC1_SDIN),
	GPIO_FN(SSI1_SCK),
	GPIO_FN(SCIF5_SCK),
	GPIO_FN(HAC1_SDOUT),
	GPIO_FN(SSI1_SDATA),
	GPIO_FN(SCIF3_TXD),
	GPIO_FN(FCLE),
	GPIO_FN(SCIF3_RXD),
	GPIO_FN(FALE),
	GPIO_FN(SCIF3_SCK),
	GPIO_FN(FD0),
	GPIO_FN(SCIF4_TXD),
	GPIO_FN(FD1),
	GPIO_FN(SCIF4_RXD),
	GPIO_FN(FD2),
	GPIO_FN(SCIF4_SCK),
	GPIO_FN(FD3),
	GPIO_FN(DEVSEL_DCLKOUT),
	GPIO_FN(STOP_CDE),
	GPIO_FN(LOCK_ODDF),
	GPIO_FN(TRDY_DISPL),
	GPIO_FN(IRDY_HSYNC),
	GPIO_FN(PCIFRAME_VSYNC),
	GPIO_FN(INTA),
	GPIO_FN(GNT0_GNTIN),
	GPIO_FN(REQ0_REQOUT),
	GPIO_FN(PERR),
	GPIO_FN(SERR),
	GPIO_FN(WE7_CBE3),
	GPIO_FN(WE6_CBE2),
	GPIO_FN(WE5_CBE1),
	GPIO_FN(WE4_CBE0),
	GPIO_FN(SCIF2_RXD),
	GPIO_FN(SIOF_RXD),
	GPIO_FN(MRESETOUT),
	GPIO_FN(IRQOUT),
};

static const struct pinmux_cfg_reg pinmux_config_regs[] = {
	{ PINMUX_CFG_REG("PACR", 0xffe70000, 16, 2, GROUP(
		PA7_FN, PA7_OUT, PA7_IN, 0,
		PA6_FN, PA6_OUT, PA6_IN, 0,
		PA5_FN, PA5_OUT, PA5_IN, 0,
		PA4_FN, PA4_OUT, PA4_IN, 0,
		PA3_FN, PA3_OUT, PA3_IN, 0,
		PA2_FN, PA2_OUT, PA2_IN, 0,
		PA1_FN, PA1_OUT, PA1_IN, 0,
		PA0_FN, PA0_OUT, PA0_IN, 0 ))
	},
	{ PINMUX_CFG_REG("PBCR", 0xffe70002, 16, 2, GROUP(
		PB7_FN, PB7_OUT, PB7_IN, 0,
		PB6_FN, PB6_OUT, PB6_IN, 0,
		PB5_FN, PB5_OUT, PB5_IN, 0,
		PB4_FN, PB4_OUT, PB4_IN, 0,
		PB3_FN, PB3_OUT, PB3_IN, 0,
		PB2_FN, PB2_OUT, PB2_IN, 0,
		PB1_FN, PB1_OUT, PB1_IN, 0,
		PB0_FN, PB0_OUT, PB0_IN, 0 ))
	},
	{ PINMUX_CFG_REG("PCCR", 0xffe70004, 16, 2, GROUP(
		PC7_FN, PC7_OUT, PC7_IN, 0,
		PC6_FN, PC6_OUT, PC6_IN, 0,
		PC5_FN, PC5_OUT, PC5_IN, 0,
		PC4_FN, PC4_OUT, PC4_IN, 0,
		PC3_FN, PC3_OUT, PC3_IN, 0,
		PC2_FN, PC2_OUT, PC2_IN, 0,
		PC1_FN, PC1_OUT, PC1_IN, 0,
		PC0_FN, PC0_OUT, PC0_IN, 0 ))
	},
	{ PINMUX_CFG_REG("PDCR", 0xffe70006, 16, 2, GROUP(
		PD7_FN, PD7_OUT, PD7_IN, 0,
		PD6_FN, PD6_OUT, PD6_IN, 0,
		PD5_FN, PD5_OUT, PD5_IN, 0,
		PD4_FN, PD4_OUT, PD4_IN, 0,
		PD3_FN, PD3_OUT, PD3_IN, 0,
		PD2_FN, PD2_OUT, PD2_IN, 0,
		PD1_FN, PD1_OUT, PD1_IN, 0,
		PD0_FN, PD0_OUT, PD0_IN, 0 ))
	},
	{ PINMUX_CFG_REG_VAR("PECR", 0xffe70008, 16,
			     GROUP(-4, 2, 2, 2, 2, 2, 2),
			     GROUP(
		/* RESERVED [4] */
		PE5_FN, PE5_OUT, PE5_IN, 0,
		PE4_FN, PE4_OUT, PE4_IN, 0,
		PE3_FN, PE3_OUT, PE3_IN, 0,
		PE2_FN, PE2_OUT, PE2_IN, 0,
		PE1_FN, PE1_OUT, PE1_IN, 0,
		PE0_FN, PE0_OUT, PE0_IN, 0 ))
	},
	{ PINMUX_CFG_REG("PFCR", 0xffe7000a, 16, 2, GROUP(
		PF7_FN, PF7_OUT, PF7_IN, 0,
		PF6_FN, PF6_OUT, PF6_IN, 0,
		PF5_FN, PF5_OUT, PF5_IN, 0,
		PF4_FN, PF4_OUT, PF4_IN, 0,
		PF3_FN, PF3_OUT, PF3_IN, 0,
		PF2_FN, PF2_OUT, PF2_IN, 0,
		PF1_FN, PF1_OUT, PF1_IN, 0,
		PF0_FN, PF0_OUT, PF0_IN, 0 ))
	},
	{ PINMUX_CFG_REG("PGCR", 0xffe7000c, 16, 2, GROUP(
		PG7_FN, PG7_OUT, PG7_IN, 0,
		PG6_FN, PG6_OUT, PG6_IN, 0,
		PG5_FN, PG5_OUT, PG5_IN, 0,
		PG4_FN, PG4_OUT, PG4_IN, 0,
		PG3_FN, PG3_OUT, PG3_IN, 0,
		PG2_FN, PG2_OUT, PG2_IN, 0,
		PG1_FN, PG1_OUT, PG1_IN, 0,
		PG0_FN, PG0_OUT, PG0_IN, 0 ))
	},
	{ PINMUX_CFG_REG("PHCR", 0xffe7000e, 16, 2, GROUP(
		PH7_FN, PH7_OUT, PH7_IN, 0,
		PH6_FN, PH6_OUT, PH6_IN, 0,
		PH5_FN, PH5_OUT, PH5_IN, 0,
		PH4_FN, PH4_OUT, PH4_IN, 0,
		PH3_FN, PH3_OUT, PH3_IN, 0,
		PH2_FN, PH2_OUT, PH2_IN, 0,
		PH1_FN, PH1_OUT, PH1_IN, 0,
		PH0_FN, PH0_OUT, PH0_IN, 0 ))
	},
	{ PINMUX_CFG_REG("PJCR", 0xffe70010, 16, 2, GROUP(
		PJ7_FN, PJ7_OUT, PJ7_IN, 0,
		PJ6_FN, PJ6_OUT, PJ6_IN, 0,
		PJ5_FN, PJ5_OUT, PJ5_IN, 0,
		PJ4_FN, PJ4_OUT, PJ4_IN, 0,
		PJ3_FN, PJ3_OUT, PJ3_IN, 0,
		PJ2_FN, PJ2_OUT, PJ2_IN, 0,
		PJ1_FN, PJ1_OUT, PJ1_IN, 0,
		PJ0_FN, PJ0_OUT, PJ0_IN, 0 ))
	},
	{ PINMUX_CFG_REG("PKCR", 0xffe70012, 16, 2, GROUP(
		PK7_FN, PK7_OUT, PK7_IN, 0,
		PK6_FN, PK6_OUT, PK6_IN, 0,
		PK5_FN, PK5_OUT, PK5_IN, 0,
		PK4_FN, PK4_OUT, PK4_IN, 0,
		PK3_FN, PK3_OUT, PK3_IN, 0,
		PK2_FN, PK2_OUT, PK2_IN, 0,
		PK1_FN, PK1_OUT, PK1_IN, 0,
		PK0_FN, PK0_OUT, PK0_IN, 0 ))
	},
	{ PINMUX_CFG_REG("PLCR", 0xffe70014, 16, 2, GROUP(
		PL7_FN, PL7_OUT, PL7_IN, 0,
		PL6_FN, PL6_OUT, PL6_IN, 0,
		PL5_FN, PL5_OUT, PL5_IN, 0,
		PL4_FN, PL4_OUT, PL4_IN, 0,
		PL3_FN, PL3_OUT, PL3_IN, 0,
		PL2_FN, PL2_OUT, PL2_IN, 0,
		PL1_FN, PL1_OUT, PL1_IN, 0,
		PL0_FN, PL0_OUT, PL0_IN, 0 ))
	},
	{ PINMUX_CFG_REG_VAR("PMCR", 0xffe70016, 16,
			     GROUP(-12, 2, 2),
			     GROUP(
		/* RESERVED [12] */
		PM1_FN, PM1_OUT, PM1_IN, 0,
		PM0_FN, PM0_OUT, PM0_IN, 0 ))
	},
	{ PINMUX_CFG_REG("PNCR", 0xffe70018, 16, 2, GROUP(
		PN7_FN, PN7_OUT, PN7_IN, 0,
		PN6_FN, PN6_OUT, PN6_IN, 0,
		PN5_FN, PN5_OUT, PN5_IN, 0,
		PN4_FN, PN4_OUT, PN4_IN, 0,
		PN3_FN, PN3_OUT, PN3_IN, 0,
		PN2_FN, PN2_OUT, PN2_IN, 0,
		PN1_FN, PN1_OUT, PN1_IN, 0,
		PN0_FN, PN0_OUT, PN0_IN, 0 ))
	},
	{ PINMUX_CFG_REG_VAR("PPCR", 0xffe7001a, 16,
			     GROUP(-4, 2, 2, 2, 2, 2, 2),
			     GROUP(
		/* RESERVED [4] */
		PP5_FN, PP5_OUT, PP5_IN, 0,
		PP4_FN, PP4_OUT, PP4_IN, 0,
		PP3_FN, PP3_OUT, PP3_IN, 0,
		PP2_FN, PP2_OUT, PP2_IN, 0,
		PP1_FN, PP1_OUT, PP1_IN, 0,
		PP0_FN, PP0_OUT, PP0_IN, 0 ))
	},
	{ PINMUX_CFG_REG_VAR("PQCR", 0xffe7001c, 16,
			     GROUP(-6, 2, 2, 2, 2, 2),
			     GROUP(
		/* RESERVED [6] */
		PQ4_FN, PQ4_OUT, PQ4_IN, 0,
		PQ3_FN, PQ3_OUT, PQ3_IN, 0,
		PQ2_FN, PQ2_OUT, PQ2_IN, 0,
		PQ1_FN, PQ1_OUT, PQ1_IN, 0,
		PQ0_FN, PQ0_OUT, PQ0_IN, 0 ))
	},
	{ PINMUX_CFG_REG_VAR("PRCR", 0xffe7001e, 16,
			     GROUP(-8, 2, 2, 2, 2),
			     GROUP(
		/* RESERVED [8] */
		PR3_FN, PR3_OUT, PR3_IN, 0,
		PR2_FN, PR2_OUT, PR2_IN, 0,
		PR1_FN, PR1_OUT, PR1_IN, 0,
		PR0_FN, PR0_OUT, PR0_IN, 0 ))
	},
	{ PINMUX_CFG_REG("P1MSELR", 0xffe70080, 16, 1, GROUP(
		P1MSEL15_0, P1MSEL15_1,
		P1MSEL14_0, P1MSEL14_1,
		P1MSEL13_0, P1MSEL13_1,
		P1MSEL12_0, P1MSEL12_1,
		P1MSEL11_0, P1MSEL11_1,
		P1MSEL10_0, P1MSEL10_1,
		P1MSEL9_0, P1MSEL9_1,
		P1MSEL8_0, P1MSEL8_1,
		P1MSEL7_0, P1MSEL7_1,
		P1MSEL6_0, P1MSEL6_1,
		P1MSEL5_0, 0,
		P1MSEL4_0, P1MSEL4_1,
		P1MSEL3_0, P1MSEL3_1,
		P1MSEL2_0, P1MSEL2_1,
		P1MSEL1_0, P1MSEL1_1,
		P1MSEL0_0, P1MSEL0_1 ))
	},
	{ PINMUX_CFG_REG_VAR("P2MSELR", 0xffe70082, 16,
			     GROUP(-13, 1, 1, 1),
			     GROUP(
		/* RESERVED [13] */
		P2MSEL2_0, P2MSEL2_1,
		P2MSEL1_0, P2MSEL1_1,
		P2MSEL0_0, P2MSEL0_1 ))
	},
	{ /* sentinel */ }
};

static const struct pinmux_data_reg pinmux_data_regs[] = {
	{ PINMUX_DATA_REG("PADR", 0xffe70020, 8, GROUP(
		PA7_DATA, PA6_DATA, PA5_DATA, PA4_DATA,
		PA3_DATA, PA2_DATA, PA1_DATA, PA0_DATA ))
	},
	{ PINMUX_DATA_REG("PBDR", 0xffe70022, 8, GROUP(
		PB7_DATA, PB6_DATA, PB5_DATA, PB4_DATA,
		PB3_DATA, PB2_DATA, PB1_DATA, PB0_DATA ))
	},
	{ PINMUX_DATA_REG("PCDR", 0xffe70024, 8, GROUP(
		PC7_DATA, PC6_DATA, PC5_DATA, PC4_DATA,
		PC3_DATA, PC2_DATA, PC1_DATA, PC0_DATA ))
	},
	{ PINMUX_DATA_REG("PDDR", 0xffe70026, 8, GROUP(
		PD7_DATA, PD6_DATA, PD5_DATA, PD4_DATA,
		PD3_DATA, PD2_DATA, PD1_DATA, PD0_DATA ))
	},
	{ PINMUX_DATA_REG("PEDR", 0xffe70028, 8, GROUP(
		0, 0, PE5_DATA, PE4_DATA,
		PE3_DATA, PE2_DATA, PE1_DATA, PE0_DATA ))
	},
	{ PINMUX_DATA_REG("PFDR", 0xffe7002a, 8, GROUP(
		PF7_DATA, PF6_DATA, PF5_DATA, PF4_DATA,
		PF3_DATA, PF2_DATA, PF1_DATA, PF0_DATA ))
	},
	{ PINMUX_DATA_REG("PGDR", 0xffe7002c, 8, GROUP(
		PG7_DATA, PG6_DATA, PG5_DATA, PG4_DATA,
		PG3_DATA, PG2_DATA, PG1_DATA, PG0_DATA ))
	},
	{ PINMUX_DATA_REG("PHDR", 0xffe7002e, 8, GROUP(
		PH7_DATA, PH6_DATA, PH5_DATA, PH4_DATA,
		PH3_DATA, PH2_DATA, PH1_DATA, PH0_DATA ))
	},
	{ PINMUX_DATA_REG("PJDR", 0xffe70030, 8, GROUP(
		PJ7_DATA, PJ6_DATA, PJ5_DATA, PJ4_DATA,
		PJ3_DATA, PJ2_DATA, PJ1_DATA, PJ0_DATA ))
	},
	{ PINMUX_DATA_REG("PKDR", 0xffe70032, 8, GROUP(
		PK7_DATA, PK6_DATA, PK5_DATA, PK4_DATA,
		PK3_DATA, PK2_DATA, PK1_DATA, PK0_DATA ))
	},
	{ PINMUX_DATA_REG("PLDR", 0xffe70034, 8, GROUP(
		PL7_DATA, PL6_DATA, PL5_DATA, PL4_DATA,
		PL3_DATA, PL2_DATA, PL1_DATA, PL0_DATA ))
	},
	{ PINMUX_DATA_REG("PMDR", 0xffe70036, 8, GROUP(
		0, 0, 0, 0,
		0, 0, PM1_DATA, PM0_DATA ))
	},
	{ PINMUX_DATA_REG("PNDR", 0xffe70038, 8, GROUP(
		PN7_DATA, PN6_DATA, PN5_DATA, PN4_DATA,
		PN3_DATA, PN2_DATA, PN1_DATA, PN0_DATA ))
	},
	{ PINMUX_DATA_REG("PPDR", 0xffe7003a, 8, GROUP(
		0, 0, PP5_DATA, PP4_DATA,
		PP3_DATA, PP2_DATA, PP1_DATA, PP0_DATA ))
	},
	{ PINMUX_DATA_REG("PQDR", 0xffe7003c, 8, GROUP(
		0, 0, 0, PQ4_DATA,
		PQ3_DATA, PQ2_DATA, PQ1_DATA, PQ0_DATA ))
	},
	{ PINMUX_DATA_REG("PRDR", 0xffe7003e, 8, GROUP(
		0, 0, 0, 0,
		PR3_DATA, PR2_DATA, PR1_DATA, PR0_DATA ))
	},
	{ /* sentinel */ }
};

const struct sh_pfc_soc_info sh7785_pinmux_info = {
	.name = "sh7785_pfc",
	.input = { PINMUX_INPUT_BEGIN, PINMUX_INPUT_END },
	.output = { PINMUX_OUTPUT_BEGIN, PINMUX_OUTPUT_END },
	.function = { PINMUX_FUNCTION_BEGIN, PINMUX_FUNCTION_END },

	.pins = pinmux_pins,
	.nr_pins = ARRAY_SIZE(pinmux_pins),
	.func_gpios = pinmux_func_gpios,
	.nr_func_gpios = ARRAY_SIZE(pinmux_func_gpios),

	.cfg_regs = pinmux_config_regs,
	.data_regs = pinmux_data_regs,

	.pinmux_data = pinmux_data,
	.pinmux_data_size = ARRAY_SIZE(pinmux_data),
};
