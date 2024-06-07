#include "conversores.h"
#include "MKL25Z4.h"


ADC_Init(){
    SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
    ADC0->CFG1 = ADC_CFG1_MODE(3) | ADC_CFG1_ADICLK(1) | ADC_CFG1_ADIV(0);
    ADC0->SC3 = ADC_SC3_AVGE_MASK | ADC_SC3_AVGS(3);
    while (ADC0->SC3 & ADC_SC3_CAL_MASK){
    }
}
int ADC_Convertion(int channel){
    ADC0->SC1[0] = ADC_SC1_ADCH(channel);
    while (!(ADC0->SC1[0] & ADC_SC1_COCO_MASK)){
        float convertido = (((float)(ADC0->R[0]) * 3.3) / (65536 - 1)); //ADC0->R[0] es el valor convertido,
    }                                                                   //la cuenta es como un map a 3.3
}


void DAC_Init(){
    DAC0->C0 = DAC_C0_DACEN_MASK | DAC_C0_DACRFS_MASK;
}
void DAC_Convertion(int valor){
    DAC0->DAT[0].DATH = DAC_DATH_DATA1(valor >> 8);
    DAC0->DAT[0].DATL = DAC_DATL_DATA0(valor & 0xFF);
}