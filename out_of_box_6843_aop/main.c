/* Standard Include Files. */
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

/* BIOS/XDC Include Files. */
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* mmWave SDK Include Files: */
#include <ti/common/sys_common.h>
#include <ti/drivers/gpio/gpio.h>
#include <ti/drivers/uart/UART.h>

#include <ti/drivers/pinmux/pinmux.h>

/* Demo Include Files */
#include <ti/demo/xwr64xx/mmw/mmw.h>


UART_Handle uart;
UART_Params uartParams;

void MmwDemo_initTask(UArg arg0, UArg arg1);
void _MmwDemo_debugAssert(int32_t expression, const char *file, int32_t line);
void MmwDemo_sleep(void);
void Led_Toggle(uint32_t SOC_XWR14XX_GPIO_X, uint32_t ms_time);
void GPIO_pin_init(void);
void UART_pin_init(void);




void UART_printf(const char *format, ...)
{
    char buffer[100];

    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);

    // Send the formatted string over UART
    size_t len = strlen(buffer);
    UART_write(uart, (uint8_t*)buffer, len);
}

void MmwDemo_initTask(UArg arg0, UArg arg1)
{
    /* Initialize the GPIO */
    GPIO_init();
    GPIO_pin_init();

    /* Initialize the UART */
    UART_init();
    UART_pin_init();


    //uint8_t a = 0x66;


    while(1)
    {
        Led_Toggle(SOC_XWR68XX_GPIO_2, 200);
        UART_printf("HelloWorld!\n");
    }
}


int main (void)
{
    Task_Params     taskParams;

    Task_Params_init(&taskParams);
    taskParams.stackSize = 4*1024;
    Task_create(MmwDemo_initTask, &taskParams, NULL);

    /* Start BIOS */
    BIOS_start();
    return 0;
}

/**************************************************************************/

void Led_Toggle(uint32_t SOC_XWR14XX_GPIO_X, uint32_t ms_time)
{
    GPIO_write (SOC_XWR14XX_GPIO_X, 1U);        //LED on
    Task_sleep(ms_time);

    GPIO_write (SOC_XWR14XX_GPIO_X, 0U);        //LED off
    Task_sleep(ms_time);

    return;
}

void GPIO_pin_init(void)
{
    // GPIO Output: Configure pin K13 as GPIO_2 output
    Pinmux_Set_OverrideCtrl(SOC_XWR68XX_PINK13_PADAZ, PINMUX_OUTEN_RETAIN_HW_CTRL, PINMUX_INPEN_RETAIN_HW_CTRL);
    Pinmux_Set_FuncSel(SOC_XWR68XX_PINK13_PADAZ, SOC_XWR68XX_PINK13_PADAZ_GPIO_2);

    // Setup the DS3 LED on the EVM connected to GPIO_2
    GPIO_setConfig (SOC_XWR68XX_GPIO_2, GPIO_CFG_OUTPUT);
}

void UART_pin_init(void)
{
    // UART Pin
    Pinmux_Set_OverrideCtrl(SOC_XWR68XX_PINN5_PADBE, PINMUX_OUTEN_RETAIN_HW_CTRL, PINMUX_INPEN_RETAIN_HW_CTRL);
    Pinmux_Set_FuncSel(SOC_XWR68XX_PINN5_PADBE, SOC_XWR68XX_PINN5_PADBE_MSS_UARTA_TX);
    Pinmux_Set_OverrideCtrl(SOC_XWR68XX_PINN4_PADBD, PINMUX_OUTEN_RETAIN_HW_CTRL, PINMUX_INPEN_RETAIN_HW_CTRL);
    Pinmux_Set_FuncSel(SOC_XWR68XX_PINN4_PADBD, SOC_XWR68XX_PINN4_PADBD_MSS_UARTA_RX);

    /* Setup the default UART Parameters */
    UART_Params_init(&uartParams);
    uartParams.isPinMuxDone   = 1;

    /* Open the UART Instance */
    uart = UART_open(0, &uartParams);

    /* Setup the default UART Parameters */
    UART_Params_init(&uartParams);
    uartParams.writeDataMode  = UART_DATA_BINARY;
    uartParams.readDataMode   = UART_DATA_BINARY;
    uartParams.baudRate       = 115200;
}

void MmwDemo_sleep(void)
{
    /* issue WFI (Wait For Interrupt) instruction */
    asm(" WFI ");
}
