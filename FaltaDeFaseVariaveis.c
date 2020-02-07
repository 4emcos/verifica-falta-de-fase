
//Programa : Conicaleira, verificador de falta de fase, com PIC16F628A
//Autor : Emerson costa

#include <16F628A.h>
 
//Configuracao FUSES
#FUSES NOWDT
#FUSES INTRC_IO
#FUSES NOPUT
#FUSES NOPROTECT
#FUSES NOBROWNOUT
#FUSES NOMCLR
#FUSES NOLVP
#FUSES NOCPD
 
//Define a utilização do clock interno de 4 Mhz
#use delay(clock=4000000) 
 
#define faseUm PIN_B1 //Define o pino que irá receber a fase um.
#define faseDois PIN_B2 //Define o pino que irá receber a fase dois.
#define faseTres PIN_B3 //Define o pino que irá receber a fase tres.

#define ledFaseUm PIN_A0 // Pino ao qual o led da fase um está ligdo.
#define ledFaseDois PIN_A1 // Pino ao qual o led da fase dois está ligdo.
#define ledFaseTres PIN_A2 // Pino ao qual o led da fase tres está ligdo.

#define serviceButton PIN_A6 // Pino que vi definir a função de servico, ligado ou desligdo.

#define buttonReset PIN_A7 // Pino do botão que reseta as fases ao estado original, false.

#define relay PIN_A3 //Pino ao qual o led esta ligado.

//Declaração de variavel que irá definir o estado do relé para ativo ou não, por padrão, ativo.
int _atvRelay = 1;