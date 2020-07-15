#include "project.h"

#define LED_ON 0u
#define LED_OFF 1u

//Variables calculos interrupccion
uint16 contador_ms = 0;
uint16 max_s_contador = 10;
uint16 distancia_cm;
uint16 distancia_cambio = 15; //Cm

//Variables contador ADC
int16 ADCmilivoltios = 0;
int16 ADCcuentas = 0;

// Definición de funciones de movimiento. Dentro de estas funciones 
// programa también el color de LED que corresponde en cada caso
void robot_avanza (void); // Configura pines en modo avanzar
void robot_retrocede (void); // Configura pines en modo retroceder
void robot_derecha (void); // Configura pines en modo giro derecha
void robot_izquierda (void); // Configura pines en modo giro izquierda
void robot_parada (void); // Configura pines en modo parada
void buzzer_pitidoEncendido (void);
void buzzer_pitidoApagado (void);

CY_ISR(Counter_Interruption)
{
    //Obtenmos el tiempo que tarda en volver el tren de pulsos tras rebotar.
    contador_ms = Counter_ReadCapture();
    distancia_cm = contador_ms/58; 
    
    //Leer valor de conversión de cuentas en el Canal 0 del ADC
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    ADCcuentas = ADC_GetResult16(0);
    ADC_StopConvert();
    
    //Convertir de cuentas del ADC a milivoltios
    ADCmilivoltios = ADC_CountsTo_mVolts(0, ADCcuentas);
    
    //Limpiamos contador timer
    Counter_ClearInterrupt(Counter_INTR_MASK_CC_MATCH);
}

int main(void)
{
	CyGlobalIntEnable; // Habilita interrupciones globales
    
    // Inicializa y configura Módulos PWM Motores A y B
    PWM_1_Start();
    PWM_2_Start();
	
	// Inicializa y configura Módulo Timer y PWM Sensor Ultrasonidos
    Counter_Start();
    PWM_3_Start();   
    
    // Habilita Interrupción del Timer para medir el tiempo de Echo - Ultrasonidos
    Counter_Int_StartEx(Counter_Interruption);
    
    // Inicializa Módulo ADC Sensor IR
    ADC_Start();
    
    //Incializamos leds apagados
    Pin_Verde_Write(LED_OFF);
    Pin_Rojo_Write(LED_OFF); 
    Pin_Azul_Write(LED_OFF);
    
    // Delay para que el robot realice las primeras medidas de distancia y relfexión IR
    CyDelay(3000);
    
    for(;;) // Superbucle
    {
        if(distancia_cm <= distancia_cambio)
        {
            //Paramos 0.5 segundos y mientras pitamos. 
            buzzer_pitidoEncendido();
            robot_parada();
            CyDelay(500);
            buzzer_pitidoApagado();
            
            //Retrocedemos 0.5 segundos.
            robot_retrocede();
            CyDelay(500);
            
            //Giramos 0.5 segundos.
            robot_izquierda();
            CyDelay(500);   
        }
        if(ADCmilivoltios >= 1000)
        {
            //Retrocedemos 0.5 segundos y mientras pitamos.
            buzzer_pitidoEncendido();
            robot_retrocede();
            CyDelay(500);
            buzzer_pitidoApagado();
            
            //Giramos 0.5 segundos.
            robot_izquierda();
            CyDelay(500); 
        }
        robot_avanza();
    }
}
// Implemenración de las funciones para mover el robot
void robot_avanza (void)
{
    Pin_Verde_Write(LED_ON); //LED Verde
    Pin_Rojo_Write(LED_OFF); //Apago el pin que no se usa para no mezclar colores
    Pin_Azul_Write(LED_OFF); //Apago el pin que no se usa para no mezclar colores
    
    //Configuración Robot avanza
    Pin_MotorA_A_Write(1); //Motor A avanza
    Pin_MotorA_R_Write(0); //Motor A avanza
    Pin_MotorB_A_Write(1); //Motor B avanza
    Pin_MotorB_R_Write(0); //Motor B avanza
    
    PWM_1_WriteCompare(35);//Ajusto velocidad de giro motor A al 35 %
    PWM_2_WriteCompare(35);//Ajusto velocidad de giro motor B al 35 %
}
void robot_retrocede (void)
{
    Pin_Verde_Write(LED_OFF); //Apago el pin que no se usa para no mezclar colores
    Pin_Rojo_Write(LED_ON); //LED Rojo
    Pin_Azul_Write(LED_OFF); //Apago el pin que no se usa para no mezclar colores
    
    //Configuración Robot retrocede
    Pin_MotorA_A_Write(0); //Motor A retrocede
    Pin_MotorA_R_Write(1); //Motor A retrocede
    Pin_MotorB_A_Write(0); //Motor B retrocede
    Pin_MotorB_R_Write(1); //Motor B retrocede
    PWM_1_WriteCompare(35);//Ajusto velocidad de giro motor A al 35 %
    PWM_2_WriteCompare(35);//Ajusto velocidad de giro motor B al 35 %
}
void robot_izquierda (void)
{
    Pin_Verde_Write(LED_OFF); //Apago el pin que no se usa para no mezclar colores
    Pin_Rojo_Write(LED_ON); //LED Morado
    Pin_Azul_Write(LED_ON); //LED Morado
    
    //Configuración Girar Robot hacia la Izquierda
    Pin_MotorA_A_Write(1); //Motor A avanza
    Pin_MotorA_R_Write(0); //Motor A avanza
    Pin_MotorB_A_Write(0); //Motor B retrocede
    Pin_MotorB_R_Write(1); //Motor B retrocede
    
    PWM_1_WriteCompare(40);//Ajusto velocidad de giro motor A al 40 %
    PWM_2_WriteCompare(40);//Ajusto velocidad de giro motor B al 40 %
}
void robot_derecha (void) // Implementación de la función de giro derecha
{
    Pin_Verde_Write(LED_ON); //LED Amarillo
    Pin_Rojo_Write(LED_ON); //LED Amarillo
    Pin_Azul_Write(LED_OFF); //Apago el pin que no se usa para no mezclar colores
    
    //Configuración Girar Robot hacia la Derecha
    Pin_MotorA_A_Write(0); //Motor A retrocede
    Pin_MotorA_R_Write(1); //Motor A retrocede
    Pin_MotorB_A_Write(1); //Motor B avanza
    Pin_MotorB_R_Write(0); //Motor B avanza
    
    PWM_1_WriteCompare(40);//Ajusto velocidad de giro motor A al 40 %
    PWM_2_WriteCompare(40);//Ajusto velocidad de giro motor B al 40 %
}
void robot_parada (void)
{
    Pin_Verde_Write(LED_OFF); //Apago el pin que no se usa para no mezclar colores
    Pin_Rojo_Write(LED_OFF); //Apago el pin que no se usa para no mezclar colores
    Pin_Azul_Write(LED_ON); //LED Azul
    
    //Ruedas bloqueadas.
    Pin_MotorA_A_Write(1); //Motor A apagado
    Pin_MotorA_R_Write(1); //Motor A apagado
    Pin_MotorB_A_Write(1); //Motor B apagado
    Pin_MotorB_R_Write(1); //Motor B apagado
    
    PWM_1_WriteCompare(1);//Ajusto velocidad de giro motor A al 0 %
    PWM_2_WriteCompare(1);//Ajusto velocidad de giro motor B al 0 %
}
void buzzer_pitidoEncendido (void)
{
    Pin_Zumbador_Write(1u);
}

void buzzer_pitidoApagado (void)
{
    Pin_Zumbador_Write(0u);
}
/* [] END OF FILE */