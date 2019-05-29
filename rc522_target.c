/*__________________________________________________________________________________
|	Dextro Soluções Tecnológicas
|       
|       Balneário Camboriú/SC
|       www.dextro-st.com.br
| __________________________________________________________________________________
|
|       This source code was developed by Dextro  and cannot be copied, in part 
|       or in whole, or used, except when legally licensed by Dextro 
|       or its distributors.
|
|       Este código é propriedade da Dextro  e não pode ser copiado, em parte 
|       ou em todo, ou utilizado, exceto quando for legalmente licenciado pela 
|       Dextro  ou por um de seus distribuidores.
| __________________________________________________________________________________
|
|
|       Arquivo            :  rc522_target.c
| 
|       Autor              :  Marcos Aquino
|       Data criação       :  17/05/2019
|
|       Revisões           :  1.0.0.0
|
|
| __________________________________________________________________________________
*/

#include <nxp/iolpc1768.h>
#include <stdio.h>
#include <stdlib.h>
#include "rc522.h"
#include "rc522_target.h"


#define SPI_DOUT_PIN                    (0x01)<<28
#define SPI_DIN_PIN                     (0x01)<<27
#define SPI_CLK_PIN                     (0x01)<<15

#define SPI_CS_01_PIN                   (0x01)<<16
#define SPI_CS_02_PIN                   (0x01)<<17
#define SPI_CS_03_PIN                   (0x01)<<18
#define SPI_CS_04_PIN                   (0x01)<<16

#define SPI_DOUT_DIR                    FIO0DIR                             
#define SPI_DOUT_SET                    FIO0SET
#define SPI_DOUT_CLR                    FIO0CLR

#define SPI_DIN_DATA                    FIO0PIN

#define SPI_CLK_DIR                     FIO1DIR
#define SPI_CLK_SET                     FIO1SET
#define SPI_CLK_CLR                     FIO1CLR

#define SPI_CS_01_DIR                   FIO1DIR
#define SPI_CS_01_SET                   FIO1SET
#define SPI_CS_01_CLR                   FIO1CLR        

#define SPI_CS_02_DIR                   FIO1DIR        
#define SPI_CS_02_SET                   FIO1SET
#define SPI_CS_02_CLR                   FIO1CLR

#define SPI_CS_03_DIR                   FIO0DIR
#define SPI_CS_03_SET                   FIO0SET
#define SPI_CS_03_CLR                   FIO0CLR

#define SPI_CS_04_DIR                   FIO0DIR
#define SPI_CS_04_SET                   FIO0SET
#define SPI_CS_04_CLR                   FIO0CLR

#define INIT_PINS()             SPI_DOUT_DIR  |= SPI_DOUT_PIN;\
                                SPI_CLK_DIR   |= SPI_CLK_PIN;\
                                SPI_CS_01_DIR |= SPI_CS_01_PIN;\
                                SPI_CS_02_DIR |= SPI_CS_02_PIN;\
                                SPI_CS_03_DIR |= SPI_CS_03_PIN;\
                                SPI_CS_04_DIR |= SPI_CS_04_PIN;\
                                SPI_CS_01_SET |= SPI_CS_01_PIN;\
                                SPI_CS_02_SET |= SPI_CS_02_PIN;\
                                SPI_CS_03_SET |= SPI_CS_03_PIN;\
                                SPI_CS_04_SET |= SPI_CS_04_PIN;
                                
#define SET_SPI_DOUT(X)         X?(SPI_DOUT_SET|=SPI_DOUT_PIN):(SPI_DOUT_CLR|=SPI_DOUT_PIN)
#define GET_SPI_DIN()           (SPI_DIN_DATA&SPI_DIN_PIN)?1:0
                                
#define SET_SPI_CLK(X)          X?(SPI_CLK_SET|=SPI_CLK_PIN):(SPI_CLK_CLR|=SPI_CLK_PIN)
                                
#define SET_CS_01(X)            X?(SPI_CS_01_SET|=SPI_CS_01_PIN):(SPI_CS_01_CLR|=SPI_CS_01_PIN)
#define SET_CS_02(X)            X?(SPI_CS_02_SET|=SPI_CS_02_PIN):(SPI_CS_02_CLR|=SPI_CS_02_PIN)
#define SET_CS_03(X)            X?(SPI_CS_03_SET|=SPI_CS_03_PIN):(SPI_CS_03_CLR|=SPI_CS_03_PIN)
#define SET_CS_04(X)            X?(SPI_CS_04_SET|=SPI_CS_04_PIN):(SPI_CS_04_CLR|=SPI_CS_04_PIN)

#define TINY_DELAY()            {for(unsigned char i=10;i;i--);}        
#define LOOP_DELAY()            {for(unsigned char i=200;i;i--);}
                                
static unsigned char card_lane=0;
                                
void RC522TARGET_ini(unsigned int clock){
  
  INIT_PINS();
}

void spi_write_single(unsigned char data){
  
  for(unsigned char i=0;i<8;i++){
    
    SET_SPI_DOUT(data&0x80);
    TINY_DELAY();
    
    SET_SPI_CLK(1);
    LOOP_DELAY();
    
    data<<=1;
    
    SET_SPI_CLK(0);    
    LOOP_DELAY();
  }
}

void RC522TARGET_spi_write(unsigned char *pData,unsigned short int size){
  
  for(unsigned short int i=0;i<size;i++)
    spi_write_single(*pData++);  
}

unsigned char spi_read_single(unsigned char data){
  unsigned char res=0;
  
  for(unsigned char i=0;i<8;i++){
    
    SET_SPI_DOUT(data&0x80);
    TINY_DELAY();
    
    SET_SPI_CLK(1);    
    LOOP_DELAY();
    
    data<<=1;
    
    if(GET_SPI_DIN()) 
      res|= 0x80>>i;
    
    SET_SPI_CLK(0);    
    LOOP_DELAY();
  }    
  
  return res;
}

void RC522TARGET_spi_read(unsigned char *pDataIn,unsigned char *pDataOut,unsigned short int size){
    
  for(unsigned short int i=0;i<size;i++)
    (*pDataIn++) = spi_read_single(*pDataOut++);

}

void RC522TARGET_spi_cs_0(unsigned char state){
 
  // Através do atributo global verifica qual CS
  // será utilizado
  switch(card_lane){
  case 0: SET_CS_01(state); break;
  case 1: SET_CS_02(state); break;
  case 2: SET_CS_03(state); break;
  case 3: SET_CS_04(state); break;  
  }
}

void RC522TARGET_cs_select(unsigned char cs){
  
  card_lane = cs;
}