/*__________________________________________________________________________________
|	Dextro Solu��es Tecnol�gicas
|       
|       Balne�rio Cambori�/SC
|       www.dextro-st.com.br
| __________________________________________________________________________________
|
|       This source code was developed by Dextro  and cannot be copied, in part 
|       or in whole, or used, except when legally licensed by Dextro 
|       or its distributors.
|
|       Este c�digo � propriedade da Dextro  e n�o pode ser copiado, em parte 
|       ou em todo, ou utilizado, exceto quando for legalmente licenciado pela 
|       Dextro  ou por um de seus distribuidores.
| __________________________________________________________________________________
|
|
|       Arquivo            :  RC522_target.h
| 
|       Autor              :  Marcos Aquino
|       Data cria��o       :  17/05/2019
|
|       Revis�es           :  1.0.0.0
|
|
| __________________________________________________________________________________
*/
#ifndef _RC522_TARGET_H_
#define _RC522_TARGET_H_


void RC522TARGET_ini(unsigned int clock);
void RC522TARGET_spi_write(unsigned char *pData,unsigned short int size);
void RC522TARGET_spi_read(unsigned char *pDataIn,unsigned char *pDataOut,unsigned short int size);

void spi_write_single(unsigned char data);
unsigned char spi_read_single(unsigned char data);
void RC522TARGET_cs_select(unsigned char cs);
#endif//_RC522_TARGET_H_