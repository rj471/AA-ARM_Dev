# Target file name (without extension).
TARGET = PHY

#  Project Name
PROJECT = main

FIRMWARE = firmware

# define the board we are using... this helps with the hardware setup..
# BOARD = GRAVITYV2
# BOARD = INCEPTIONV1
# BOARD = INCEPTIONV1_1
BOARD = IMARK6_1
# BOARD = LAN8720_1
# BOARD = HARIOM1_0

#Handy Path defines
ROOT_PATH = ../
COMMON_PATH = $(ROOT_PATH)/common
BRD_PATH = $(ROOT_PATH)/boards
SRC_PATH = $(COMMON_PATH)/src
INC_PATH = $(COMMON_PATH)/inc
CORE_PATH = $(COMMON_PATH)/Core/CM3
UTIL_PATH = $(ROOT_PATH)/utils
DRIVER_PATH = $(ROOT_PATH)/drivers
TEST_PATH = $(ROOT_PATH)/tests
PRJ_PATH = $(ROOT_PATH)/$(TARGET)
SM_PATH = $(PRJ_PATH)/state_machines

#The C source files are listed here
#Syscalls Must be Included First
#The sequence of the inclusion startup and syscalls is critical 
# CSRCS = $(PROJECT).c
CSRCS = 
CSRCS += $(ROOT_PATH)/Common/src/syscalls.c

CSRCS += $(CORE_PATH)/core_cm3.c
CSRCS += $(CORE_PATH)/system_LPC17xx.c

CSRCS += $(SRC_PATH)/lpc17xx_gpio.c
CSRCS += $(SRC_PATH)/lpc17xx_pinsel.c
CSRCS += $(SRC_PATH)/lpc17xx_timer.c
CSRCS += $(SRC_PATH)/debug_frmwrk.c
CSRCS += $(SRC_PATH)/lpc17xx_uart.c
CSRCS += $(SRC_PATH)/lpc17xx_clkpwr.c
CSRCS += $(SRC_PATH)/lpc17xx_nvic.c
CSRCS += $(SRC_PATH)/lpc17xx_qei.c
CSRCS += $(SRC_PATH)/lpc17xx_spi.c
CSRCS += $(SRC_PATH)/lpc17xx_ssp.c
CSRCS += $(SRC_PATH)/lpc17xx_i2c.c
CSRCS += $(SRC_PATH)/lpc17xx_rtc.c
CSRCS += $(SRC_PATH)/lpc17xx_emac.c
CSRCS += $(SRC_PATH)/delay.c
CSRCS += $(SRC_PATH)/mini_cpp.c

CSRCS += $(DRIVER_PATH)/timer/timer.c
CSRCS += $(DRIVER_PATH)/UART/uart.c
CSRCS += $(DRIVER_PATH)/USB/intenable.c
CSRCS += $(DRIVER_PATH)/USB/usbhw_lpc.c
CSRCS += $(DRIVER_PATH)/USB/serial_fifo.c
CSRCS += $(DRIVER_PATH)/USB/usbinit.c
CSRCS += $(DRIVER_PATH)/USB/usbcontrol.c
CSRCS += $(DRIVER_PATH)/USB/usbstdreq.c
CSRCS += $(DRIVER_PATH)/IAP/iap_driver.c

CSRCS += $(DRIVER_PATH)/SPI/ssp_master.c

CSRCS += $(UTIL_PATH)/ring_buffer/ring.c
CSRCS += $(UTIL_PATH)/ringbuf/RingBuf.c
# CSRCS += $(UTIL_PATH)/printf/printf-stdarg.c
CSRCS += $(UTIL_PATH)/printf/ee_printf-arg.c
CSRCS += $(UTIL_PATH)/input_output/input_output.c
CSRCS += $(UTIL_PATH)/multi-steppers/multi-steppers.c
CSRCS += $(UTIL_PATH)/i2ceeprom/i2c.c
CSRCS += $(UTIL_PATH)/i2ceeprom/i2c_eeprom.c
CSRCS += $(UTIL_PATH)/usbSerial/usbSerial.c

CSRCS += $(UTIL_PATH)/modbus/modbus.c
# CSRCS += $(UTIL_PATH)/modbus_tcp/easyweb.c
# CSRCS += $(UTIL_PATH)/modbus_tcp/ethmac.c
# CSRCS += $(UTIL_PATH)/modbus_tcp/tcpip.c

CSRCS += $(PRJ_PATH)/interrupts.c
# CSRCS += $(PRJ_PATH)/state_machines/SM_serial_hariom.c

# List Assembler source files here which must be assembled in ARM-Mode..
ASRCARM =
ASRCARM += $(CORE_PATH)/startup_LPC17xx.s

#The C++ source files are listed here
CPPSRCS = 
CPPSRCS += $(PRJ_PATH)/$(PROJECT).cpp

CPPSRCS += $(PRJ_PATH)/config_data.cpp

CPPSRCS += $(UTIL_PATH)/delay_timer/delay_timer.cpp
CPPSRCS += $(UTIL_PATH)/state_machine/state_machine.cpp

CPPSRCS += $(UTIL_PATH)/modbus/SimpleModbusSlave_1769.cpp
# CPPSRCS += $(UTIL_PATH)/LSM6DS3/LSM6DS3.cpp
# CPPSRCS += $(UTIL_PATH)/LSM6DS3/SM_LSM6DS3.cpp
# CPPSRCS += $(UTIL_PATH)/Serial_protocol/serial_protocol.cpp
CPPSRCS += $(PRJ_PATH)/state_machines/SM_Operation.cpp

# the Extra Include Directories which may contain the various header files are listed here
INCDIRS = $(ROOT_PATH)
INCDIRS += $(CORE_PATH)/
INCDIRS += $(INC_PATH)/
INCDIRS += $(SRC_PATH)/
INCDIRS += $(BRD_PATH)
INCDIRS += $(DRIVER_PATH)/UART/
INCDIRS += $(DRIVER_PATH)/timer/
INCDIRS += $(DRIVER_PATH)/IAP/
INCDIRS += $(DRIVER_PATH)/USB/
INCDIRS += $(DRIVER_PATH)/SPI/
INCDIRS += $(PRJ_PATH)

INCDIRS += $(PRJ_PATH)/state_machines
INCDIRS += $(UTIL_PATH)
INCDIRS += $(UTIL_PATH)/ringbuf/
INCDIRS += $(UTIL_PATH)/delay_timer/
INCDIRS += $(UTIL_PATH)/printf/
INCDIRS += $(UTIL_PATH)/i2ceeprom/
INCDIRS += $(UTIL_PATH)/input_output/
INCDIRS += $(UTIL_PATH)/ring_buffer/
INCDIRS += $(UTIL_PATH)/multi-steppers/
INCDIRS += $(UTIL_PATH)/state_machine/
INCDIRS += $(UTIL_PATH)/usbSerial/
INCDIRS += $(UTIL_PATH)/modbus/
# INCDIRS += $(UTIL_PATH)/modbus_tcp/
# INCDIRS += $(UTIL_PATH)/LSM6DS3/
# INCDIRS += $(UTIL_PATH)/Serial_protocol/
INCDIRS += $(TEST_PATH)/

# Place -D or -U options for C here
CDEFS =  
CDEFS+= -DBOARD=$(BOARD) 

#Set The Compiler Optimization Level Here
OPTIMIZATION = 0

#  Compiler Options
GCFLAGS = -O$(OPTIMIZATION) -gdwarf-2 -mcpu=cortex-m3 -mthumb -mthumb-interwork -mlong-calls -ffunction-sections -fdata-sections -fpromote-loop-indices -Wall -Wextra -Wimplicit -Wcast-align -Wpointer-arith -Wredundant-decls -Wshadow -Wcast-qual -Wcast-align -Wnested-externs --std=gnu99 

#GCFLAGS = -W -Wall -fno-common -O$(OPTIMIZATION) --std=gnu99 -fgnu89-inline -mcpu=cortex-m3 -mthumb -ffunction-sections -fdata-sections -g3
GCFLAGS += $(CDEFS)
GCFLAGS += $(patsubst %,-I%,$(INCDIRS)) -I.
GCFLAGS += -Wa,-adhlns=$(subst $(suffix $<),.lst,$<) 
#GCFLAGS += -W -Wall -mcpu=cortex-m3 --std=gnu99 -fgnu89-inline -mthumb -O$(OPTIMIZATION)
#GCFLAGS += -Wcast-align -Wcast-qual -Wimplicit -Wpointer-arith -Wswitch
#GCFLAGS += -Wredundant-decls -Wreturn-type -Wshadow -Wunused
#GCFLAGS  += -W --std=gnu99 -fgnu89-inline
#GCFLAGS  += -ffunction-sections -fdata-sections
#GPFLAGS = -W -Wall -fno-common -mcpu=cortex-m3 -mthumb -O$(OPTIMIZATION)
GPFLAGS = -O$(OPTIMIZATION) -gdwarf-2 -mcpu=cortex-m3 -mthumb -mthumb-interwork -mlong-calls -ffunction-sections -fdata-sections -fpromote-loop-indices -Wall -Wextra -Wimplicit -Wcast-align -Wpointer-arith -Wredundant-decls -Wshadow -Wcast-qual -Wcast-align -Wno-write-strings -fno-rtti -fno-exceptions

GPFLAGS += $(CDEFS)
GPFLAGS += $(patsubst %,-I%,$(INCDIRS)) -I.
GPFLAGS += -Wa,-adhlns=$(subst $(suffix $<),.lst,$<) 
#LDFLAGS = -Map=$(PROJECT).map -T$(LSCRIPT) --gc-sections
LDFLAGS = -mcpu=cortex-m3 -mthumb -O$(OPTIMIZATION) -Wl,-Map=$(PROJECT).map,--cref,--gc-sections -lc -lm -lgcc -lstdc++  -T$(LSCRIPT)
LDFLAGS2 = -mcpu=cortex-m3 -mthumb -O$(OPTIMIZATION) -Wl,-Map=$(PROJECT).map,--cref,--gc-sections -lc -lm -lgcc -lstdc++  -T$(LSCRIPT2)
#LDFLAGS += --gc-sections
ASFLAGS = $(LISTING) -mcpu=cortex-m3 -mthumb -x assembler-with-cpp
ASFLAGS += $(CDEFS)
ASFLAGS += $(patsubst %,-I%,$(INCDIRS)) -I.
#  Compiler/Assembler/Linker Paths
GCC = arm-none-eabi-gcc
GPP = arm-none-eabi-g++
AS = arm-none-eabi-gcc
LD = arm-none-eabi-g++
OBJCOPY = arm-none-eabi-objcopy
REMOVE = cs-rm -f
SIZE = arm-none-eabi-size


#  List of the objects files to be compiled/assembled
OBJECTS= $(ASRCARM:.s=.o) $(CSRCS:.c=.o) $(ASRCS:.s=.o) $(CPPSRCS:.cpp=.o)
LISTOBJECTS= $(ASRCARM:.s=.lst) $(CSRCS:.c=.lst) $(ASRCS:.s=.lst) $(CPPSRCS:.cpp=.lst)
LDOBJECTS= $(wildcard *.a) $(wildcard lib/*.a) $(wildcard lib/*/*.a) $(wildcard lib/*.o) $(wildcard lib/*/*.o)
# LSCRIPT = $(COMMON_PATH)/LPC17xx.ld
LSCRIPT = $(COMMON_PATH)/LPC17xx_USBBOOTLOAD.ld
# LSCRIPT = $(COMMON_PATH)/LPC17XX-OPENLPC-BARE.ld

#########################################################################

all:: $(PROJECT).hex $(PROJECT).bin 

$(PROJECT).bin: $(PROJECT).elf
	$(OBJCOPY) -O binary -j .text -j .data $(PROJECT).elf $(PROJECT).bin

$(PROJECT)_For_NXP_USB_Bootloader.bin: $(PROJECT)_For_NXP_USB_Bootloader.elf
	$(OBJCOPY) -O binary -j .text -j .data $(PROJECT)_For_NXP_USB_Bootloader.elf $(PROJECT)_For_NXP_USB_Bootloader.bin

$(PROJECT).hex: $(PROJECT).elf
	$(OBJCOPY) -R .stack -O ihex $(PROJECT).elf $(PROJECT).hex
	
$(PROJECT).elf: $(LSCRIPT) $(OBJECTS)
	$(LD) $(LDFLAGS) $(LDOBJECTS) $(OBJECTS) -o $(PROJECT).elf
	$(SIZE) $(PROJECT).elf

$(PROJECT)_For_NXP_USB_Bootloader.elf: $(LSCRIPT2) $(OBJECTS)
	$(LD) $(LDFLAGS2) $(LDOBJECTS) $(OBJECTS) -o $(PROJECT)_For_NXP_USB_Bootloader.elf

ifeq ($(FLASH_TOOL),ULINK)
# Program the device with Keil's ULINK (needs configured uVision-Workspace). 
program: $(PROJECT).hex
	@echo
	@echo "Programming with ULINK"
	C:\Keil\uv3\Uv3.exe -f ulinkflash.Uv2 -oulinkflash.txt
else
OOCD_load_image=$(PROJECT).hex
include Makefile.jtag_program

# Program the device.  
program: $(PROJECT).hex oocd_programprepare oocd_programdoit 
	@echo	
endif

stats: $(PROJECT).elf
	$(SIZE) $(PROJECT).elf

wassup:
	echo $(ASRCARM)

clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(LISTOBJECTS)
	$(REMOVE) $(PROJECT).hex
	$(REMOVE) $(PROJECT).elf
	$(REMOVE) $(PROJECT).map
	$(REMOVE) $(PROJECT).bin	

load: all
	@(echo "Load")
	@(python loadFilePy.py $(dir))		

#########################################################################
#  Default rules to compile .c and .cpp file to .o
#  and assemble .s files to .o

.c.o :
	$(GCC) $(GCFLAGS) -c $< -o $(<:.c=.o)

.cpp.o :
	$(GPP) $(GPFLAGS) -c $< -o $(<:.cpp=.o)

# .S.o :
	# $(AS) $(ASFLAGS) -c $< -o $(<:.S=.o)

.s.o :	
	$(AS) $(ASFLAGS) -c $< -o $(<:.s=.o)
#	$(AS) $(ASFLAGS) -o $(<:.S=.o) $< > $(<:.S=.lst)
#	$(AS) $(ASFLAGS) -o $(PROJECT)_crt.o $< > $(PROJECT)_crt.lst

#########################################################################
