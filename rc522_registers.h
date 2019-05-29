#ifndef _RC522REGISTERS_H_
#define _RC522REGISTERS_H_

#define Page0_Reserved_1 	                0x00
#define CommandReg			        0x01
#define ComIEnReg			        0x02
#define DivIEnReg			        0x03
#define ComIrqReg			        0x04
#define DivIrqReg			        0x05
#define ErrorReg			        0x06
#define Status1Reg			        0x07
#define Status2Reg			        0x08
#define FIFODataReg			        0x09
#define FIFOLevelReg		                0x0A
#define WaterLevelReg		                0x0B
#define ControlReg			        0x0C
#define BitFramingReg		                0x0D
#define CollReg				        0x0E
#define Page0_Reserved_2	                0x0F

//Page 1 ==> Command
#define Page1_Reserved_1	                0x10
#define ModeReg				        0x11
#define TxModeReg			        0x12
#define RxModeReg			        0x13
#define TxControlReg		                0x14
#define TxASKReg			        0x15
#define TxSelReg			        0x16
#define RxSelReg			        0x17
#define RxThresholdReg		                0x18
#define	DemodReg			        0x19
#define Page1_Reserved_2	                0x1A
#define Page1_Reserved_3	                0x1B
#define MfTxReg				        0x1C
#define MfRxReg				        0x1D
#define Page1_Reserved_4	                0x1E
#define SerialSpeedReg		                0x1F

//Page 2 ==> CFG
#define Page2_Reserved_1	                0x20
#define CRCResultReg_1		                0x21
#define CRCResultReg_2		                0x22
#define Page2_Reserved_2	                0x23
#define ModWidthReg			        0x24
#define Page2_Reserved_3	                0x25
#define RFCfgReg			        0x26
#define GsNReg				        0x27
#define CWGsPReg			        0x28
#define ModGsPReg			        0x29
#define TModeReg			        0x2A
#define TPrescalerReg		                0x2B
#define TReloadReg_1		                0x2C
#define TReloadReg_2		                0x2D
#define TCounterValReg_1	                0x2E
#define TCounterValReg_2 	                0x2F

//Page 3 ==> TestRegister
#define Page3_Reserved_1 	                0x30
#define TestSel1Reg			        0x31
#define TestSel2Reg			        0x32
#define TestPinEnReg		                0x33
#define TestPinValueReg		                0x34
#define TestBusReg			        0x35
#define AutoTestReg			        0x36
#define VersionReg			        0x37
#define AnalogTestReg		                0x38
#define TestDAC1Reg			        0x39
#define TestDAC2Reg			        0x3A
#define TestADCReg			        0x3B
#define Page3_Reserved_2 	                0x3C
#define Page3_Reserved_3	                0x3D
#define Page3_Reserved_4	                0x3E
#define Page3_Reserved_5	                0x3F

//Card types
#define Mifare_UltraLight 	                0x4400
#define Mifare_One_S50		                0x0400
#define Mifare_One_S70		                0x0200
#define Mifare_Pro_X		                0x0800
#define Mifare_DESFire		                0x4403

// Mifare_One card command word
#define PICC_REQIDL                             0x26               // find the antenna area does not enter hibernation
#define PICC_REQALL                             0x52               // find all the cards antenna area
#define PICC_ANTICOLL                           0x93               // anti-collision
#define PICC_SElECTTAG                          0x93               // election card
#define PICC_AUTHENT1A                          0x60               // authentication key A
#define PICC_AUTHENT1B                          0x61               // authentication key B
#define PICC_READ                               0x30               // Read Block
#define PICC_WRITE                              0xA0               // write block
#define PICC_DECREMENT                          0xC0               // debit
#define PICC_INCREMENT                          0xC1               // recharge
#define PICC_RESTORE                            0xC2               // transfer block data to the buffer
#define PICC_TRANSFER                           0xB0               // save the data in the buffer
#define PICC_HALT                               0x50               // Sleep

//MF522 command word
#define PCD_IDLE                                0x00               //NO action; cancel the current command
#define PCD_AUTHENT                             0x0E               // authentication key
#define PCD_RECEIVE                             0x08               // receive data
#define PCD_TRANSMIT                            0x04               // Transmit Data
#define PCD_TRANSCEIVE                          0x0C               // Send and receive data
#define PCD_RESETPHASE                          0x0F               // Reset
#define PCD_CALCCRC                             0x03               // CRC calculation

//command set
#define Idle_CMD 				0x00
#define Mem_CMD					0x01
#define GenerateRandomId_CMD	                0x02
#define CalcCRC_CMD				0x03
#define Transmit_CMD			        0x04
#define NoCmdChange_CMD			        0x07
#define Receive_CMD				0x08
#define Transceive_CMD			        0x0C
#define Reserved_CMD			        0x0D
#define MFAuthent_CMD			        0x0E
#define SoftReset_CMD			        0x0F

typedef struct{
  unsigned char command:4;
  unsigned char power_down:1;
  unsigned char rcv_off:1;
  unsigned char x:2;
}sCommandReg;

typedef struct{
  unsigned char timer_ien:1;
  unsigned char err_ien:1;
  unsigned char lo_alert_ien:1;
  unsigned char hi_alert_ien:1;
  unsigned char idle_ien:1;
  unsigned char rx_ien:1;
  unsigned char tx_ien:1;
  unsigned char irq_inv:1;
}sComIEnReg;

typedef struct{
  unsigned char reserved:1;
  unsigned char crc_ien:1;
  unsigned char reserved2:1;
  unsigned char m_fin_actl_en:1;
  unsigned char reserved3:2;
  unsigned char irq_push_pull:1;
}sDivIEnReg;

typedef struct{
  unsigned char timer_irq:1;
  unsigned char err_irq:1;
  unsigned char lo_alert_irq:1;
  unsigned char hi_alert_irq:1;
  unsigned char idle_irq:1;
  unsigned char rx_irq:1;
  unsigned char tx:1;
  unsigned char set1:1;
}sComIrqReg;

typedef struct{
  unsigned char reserved:1;
  unsigned char crc_irq:1;
  unsigned char reserved2:1;
  unsigned char m_fin_act_irq:1;
  unsigned char reserved3:2;
  unsigned char set2:1;  
}sDivIrqReg;

typedef struct{
  unsigned char protocol_err:1;
  unsigned char parity_err:1;
  unsigned char crc_err:1;
  unsigned char coll_err:1;
  unsigned char buffer_ovfl:1;
  unsigned char reserved:1;
  unsigned char temp_err:1;
  unsigned char wr_err:1;  
}sErrorReg;

typedef struct{
  unsigned char lo_alert:1;
  unsigned char hi_alert:1;
  unsigned char reserved:1;
  unsigned char t_running:1;
  unsigned char irq:1;
  unsigned char crc_ready:1;
  unsigned char crc_ok:1;
  unsigned char reserved1:1;  
}sStatus1Reg;

typedef struct{
  unsigned char ModelState:3;
  unsigned char mifare_crypto:1;
  unsigned char reserved2:2;
  unsigned char i2c_force_hs:1;
  unsigned char temp_sense_clear:1;  
}sStatus2Reg;

typedef struct{
  unsigned char fifo_level:7;
  unsigned char flush_buffer:1;    
}sFifoLevelReg;

typedef struct{
  unsigned char water_level:6;
  unsigned char reserved:2;  
}sWaterLevelReg;

typedef struct{
  unsigned char rx_last_bits:3;
  unsigned char reserved:3;
  unsigned char t_start_now:1;
  unsigned char t_stop_now:1;  
}sControlReg;

typedef struct{
  unsigned char tx_last_bits:3;
  unsigned char reserved:1;
  unsigned char tx_align:3;
  unsigned char start_send:1;    
}sBitFramingReg;

typedef struct{
  unsigned char coll_pos:5;
  unsigned char coll_pos_not_valid:1;
  unsigned char reserved:1;
  unsigned char values_after_coll:1;
}sCollReg;

typedef struct{
  unsigned char crc_preset:2;
  unsigned char reserved:1;
  unsigned char pol_m_fin:1;
  unsigned char reserved2:1;
  unsigned char tx_wait_rf:1;
  unsigned char reserved1:1;
  unsigned char msb_first:1;
}sModeReg;

typedef struct{
  unsigned char reserved:3;
  unsigned char inv_mod:1;
  unsigned char tx_speed:3;
  unsigned char tx_cr_en:1;    
}sTxModeReg;

typedef struct{
  unsigned char reserved:2;
  unsigned char tx_multiple:1;
  unsigned char rx_no_err:1;
  unsigned char rx_speed:3;
  unsigned char rx_crc_en:1;  
}sRxModeReg;


#endif//_RC522REGISTERS_H_