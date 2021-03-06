# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\carles\Google Drive\Universidad\28. SIT\Miniproyecto\MiniProyecto\MiniProyecto.cydsn\MiniProyecto.cyprj
# Date: Tue, 05 May 2020 14:35:54 GMT
#set_units -time ns
create_clock -name {Clock_2(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {ADC_intClock(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_6}]]
create_clock -name {Clock(FFB)} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ff_div_8}] [get_pins {ClockBlock/ff_div_9}]]
create_clock -name {Clock_1(FFB)} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ff_div_10}]]
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyWCO} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/wco}]]
create_clock -name {CyLFClk} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyECO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/eco}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/hfclk}] -edges {1 49 97} [list]
create_generated_clock -name {ADC_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 49 97} [list]
create_generated_clock -name {Clock} -source [get_pins {ClockBlock/hfclk}] -edges {1 481 961} [list]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 481 961} [list]


# Component constraints for C:\Users\carles\Google Drive\Universidad\28. SIT\Miniproyecto\MiniProyecto\MiniProyecto.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\carles\Google Drive\Universidad\28. SIT\Miniproyecto\MiniProyecto\MiniProyecto.cydsn\MiniProyecto.cyprj
# Date: Tue, 05 May 2020 14:35:50 GMT
