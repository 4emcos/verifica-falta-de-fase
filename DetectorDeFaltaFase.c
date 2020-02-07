#include "C:\Emerson\teste.h"


void resetFuncion() 
   // Essa função reseta os parametros dos leds e do verificador de falta.
   {         
            output_bit(ledFaseUm, TRUE); // Blink
            output_bit(ledFaseDois, TRUE); // Blink
            output_bit(ledFaseTres, TRUE); // Blink
            delay_ms(1000);
            output_bit(ledFaseUm, FALSE); // Reseta estado do led da fase Um
            output_bit(ledFaseDois, FALSE); // Reseta estado do led da fase Dois
            output_bit(ledFaseTres, FALSE); // Reseta estado do led da fase Tres
            _atvRelay = 1;
   }

// Função de manutenção, o led acompanha a falta e o relé fica constantemente ativado. 
void serviceFuncion () 
   {
   output_bit(relay, TRUE);
    
    
   // ******** VERIFICADOR DA FASE UM ********* 
   if(input(faseUm)) 
   {
         output_bit(ledFaseUm, FALSE); // Liga o Led da fase um
         } else {output_bit(ledFaseUm, TRUE); }// Desliga o led da Fase Um
 
   
   // ******** VERIFICADOR DA FASE DOIS *********
   if(input(faseDois)) 
   {
         output_bit(ledFaseDois, FALSE); // Liga o Led da fase dois
         } else {output_bit(ledFaseDois, TRUE);} // delisga o led da fase dois
  
   
   
   // ******** VERIFICADOR DA FASE TRÊS *********
   if(input(faseTres)) 
   {
         output_bit(ledFaseTres, FALSE); // Liga o Led da fase tres
         }else {output_bit(ledFaseTres, TRUE);} // desliga o led da fase tres
   }
   
void main()
{
   resetFuncion();
   while (1){
         //Expressão que irá verificar se todas as fazes estão com tensão, e irá acionar o relé
         if (_atvRelay) 
               {
                  //Faz o acionamento do relé
                  output_bit(relay, TRUE); 
               } else {output_bit(relay, FALSE);}
                      
         // Verifica se o botão de serviço foi colocado em ON e irá chamar a função.             
         while (input(serviceButton)) { 
           serviceFuncion();
           
         } 
         
         // Verifica estado do botão de reset e chama a função.
         if (input(buttonReset)) 
             {
                resetFuncion();
             }
     
               //Delay para evitar blink de fases da maquina.
               delay_ms(3000);
   
               // ******** VERIFICADOR DA FASE UM ********
              if(input(faseUm) == 0 ) 
                  {
                        output_bit(ledFaseUm, TRUE); // Liga o Led
                        _atvRelay = 0;
                  }
             
               
               // ******** VERIFICADOR DA FASE DOIS *********
              if(input(faseDois) == 0) 
                  {
                        output_bit(ledFaseDois, TRUE); // Liga o Led
                        _atvRelay = 0;
                  }
               
               // ******** VERIFICADOR DA FASE TRÊS *********
              if(input(faseTres) == 0) 
                  {
                        output_bit(ledFaseTres, TRUE); // Liga o Led
                        _atvRelay = 0;
                  }
               }        
      }