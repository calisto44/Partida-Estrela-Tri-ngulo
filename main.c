#define F_CPU   16000000
#include <util/delay.h>
#include <avr/io.h>

int main(void) 
{
    // Configuração de entradas e saídas
    // Entradas
    DDRB &= ~((1<<2)|(1<<1));   // S1 e S2 
    PORTB |=((1<<2)|(1<<1));    // Pull-up em S1 e S2

    // Saídas
    DDRB |= ((1<<3)|(1<<4)|(1<<5)); // K1, K2, K3
    PORTB &= ~((1<<3)|(1<<4)|(1<<5)); // Desliga K1, K2, K3

    while (1)
    {
        //  S1 pressionado
        if ( !(PINB &(1<<2)) ) // S1
        {
            PORTB |= (1<<5);  // Liga K1
            PORTB |= (1<<4);  // Liga K2 

            _delay_ms(5000); 

            PORTB &= ~(1<<4); // Desliga K2 
            PORTB |= (1<<3);  // Liga K3 
        }
        // S2 pressionado
        else if (!(PINB &(1<<1))) // S2
        {
            PORTB &= ~(1<<3); // Desliga K3
            PORTB &= ~(1<<4); // Desliga K2
            PORTB &= ~(1<<5); // Desliga K1
        }
    }
}

