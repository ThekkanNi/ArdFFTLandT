#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ArdFFTLandT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ArdFFTLandT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/app.c ../src/main.c ../src/Pic32MzDelay.c ../src/UartFile.c ../src/UartSource.c ../src/GuiCommunicationFile.c ../src/Adc.c ../src/Measurement.c ../src/TimerFile.c ../src/Pic32Dma.c ../../../../../../../../microchip/harmony/v2_06/framework/system/dma/src/sys_dma.c ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/UsbCommunication.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/Pic32MzDelay.o ${OBJECTDIR}/_ext/1360937237/UartFile.o ${OBJECTDIR}/_ext/1360937237/UartSource.o ${OBJECTDIR}/_ext/1360937237/GuiCommunicationFile.o ${OBJECTDIR}/_ext/1360937237/Adc.o ${OBJECTDIR}/_ext/1360937237/Measurement.o ${OBJECTDIR}/_ext/1360937237/TimerFile.o ${OBJECTDIR}/_ext/1360937237/Pic32Dma.o ${OBJECTDIR}/_ext/1684120524/sys_dma.o ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1360937237/UsbCommunication.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/Pic32MzDelay.o.d ${OBJECTDIR}/_ext/1360937237/UartFile.o.d ${OBJECTDIR}/_ext/1360937237/UartSource.o.d ${OBJECTDIR}/_ext/1360937237/GuiCommunicationFile.o.d ${OBJECTDIR}/_ext/1360937237/Adc.o.d ${OBJECTDIR}/_ext/1360937237/Measurement.o.d ${OBJECTDIR}/_ext/1360937237/TimerFile.o.d ${OBJECTDIR}/_ext/1360937237/Pic32Dma.o.d ${OBJECTDIR}/_ext/1684120524/sys_dma.o.d ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d ${OBJECTDIR}/_ext/1688732426/system_init.o.d ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d ${OBJECTDIR}/_ext/1360937237/UsbCommunication.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/Pic32MzDelay.o ${OBJECTDIR}/_ext/1360937237/UartFile.o ${OBJECTDIR}/_ext/1360937237/UartSource.o ${OBJECTDIR}/_ext/1360937237/GuiCommunicationFile.o ${OBJECTDIR}/_ext/1360937237/Adc.o ${OBJECTDIR}/_ext/1360937237/Measurement.o ${OBJECTDIR}/_ext/1360937237/TimerFile.o ${OBJECTDIR}/_ext/1360937237/Pic32Dma.o ${OBJECTDIR}/_ext/1684120524/sys_dma.o ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1360937237/UsbCommunication.o

# Source Files
SOURCEFILES=../src/app.c ../src/main.c ../src/Pic32MzDelay.c ../src/UartFile.c ../src/UartSource.c ../src/GuiCommunicationFile.c ../src/Adc.c ../src/Measurement.c ../src/TimerFile.c ../src/Pic32Dma.c ../../../../../../../../microchip/harmony/v2_06/framework/system/dma/src/sys_dma.c ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/UsbCommunication.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/ArdFFTLandT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ1024EFE064
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  .generated_files/flags/default/f25530bf75aecc1268eae426e2ede0e7a997d .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.ok ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d"  -o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d" "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  .generated_files/flags/default/ec84d57533b4bc349e867a44ed16517539d4290e .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.ok ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.err 
	${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d"  -o ${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_cache_pic32mz.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d",--gdwarf-2 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.d" "${OBJECTDIR}/_ext/340578644/sys_devcon_cache_pic32mz.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/c2fd542a3a28771fcae7f68af86cc07057cb8d87 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/37c8dcd0a24f18623d8dcb31e214df06d331b6bd .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/Pic32MzDelay.o: ../src/Pic32MzDelay.c  .generated_files/flags/default/901fb27aba0deb9d6ef450bb063b12ec1f316ffd .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Pic32MzDelay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Pic32MzDelay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Pic32MzDelay.o.d" -o ${OBJECTDIR}/_ext/1360937237/Pic32MzDelay.o ../src/Pic32MzDelay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/UartFile.o: ../src/UartFile.c  .generated_files/flags/default/dacacbb39916b434147f5fff8721e62385868cbe .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/UartFile.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/UartFile.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/UartFile.o.d" -o ${OBJECTDIR}/_ext/1360937237/UartFile.o ../src/UartFile.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/UartSource.o: ../src/UartSource.c  .generated_files/flags/default/1d2206d10dd1d8cbe572eb07fcac45a88e1270db .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/UartSource.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/UartSource.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/UartSource.o.d" -o ${OBJECTDIR}/_ext/1360937237/UartSource.o ../src/UartSource.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/GuiCommunicationFile.o: ../src/GuiCommunicationFile.c  .generated_files/flags/default/fcebfd878a79cf429eb2186f92b4c4013f24cddc .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GuiCommunicationFile.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GuiCommunicationFile.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/GuiCommunicationFile.o.d" -o ${OBJECTDIR}/_ext/1360937237/GuiCommunicationFile.o ../src/GuiCommunicationFile.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/Adc.o: ../src/Adc.c  .generated_files/flags/default/e3b43b50f43fca4ed9a6834d4ae6153ae62153fa .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Adc.o.d" -o ${OBJECTDIR}/_ext/1360937237/Adc.o ../src/Adc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/Measurement.o: ../src/Measurement.c  .generated_files/flags/default/139384b8fc988fcc557db943a2bdfce1a0d626d6 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Measurement.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Measurement.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Measurement.o.d" -o ${OBJECTDIR}/_ext/1360937237/Measurement.o ../src/Measurement.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/TimerFile.o: ../src/TimerFile.c  .generated_files/flags/default/b7ed488657c9d39f352b55d41277d1abd17bed1b .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TimerFile.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TimerFile.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/TimerFile.o.d" -o ${OBJECTDIR}/_ext/1360937237/TimerFile.o ../src/TimerFile.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/Pic32Dma.o: ../src/Pic32Dma.c  .generated_files/flags/default/97d225f63bd81acdac61e448566018a4bdca7e0e .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Pic32Dma.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Pic32Dma.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Pic32Dma.o.d" -o ${OBJECTDIR}/_ext/1360937237/Pic32Dma.o ../src/Pic32Dma.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1684120524/sys_dma.o: ../../../../../../../../microchip/harmony/v2_06/framework/system/dma/src/sys_dma.c  .generated_files/flags/default/87381b7ca02e7c67b4d52533475d5a8b9e6c5ca2 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1684120524" 
	@${RM} ${OBJECTDIR}/_ext/1684120524/sys_dma.o.d 
	@${RM} ${OBJECTDIR}/_ext/1684120524/sys_dma.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1684120524/sys_dma.o.d" -o ${OBJECTDIR}/_ext/1684120524/sys_dma.o ../../../../../../../../microchip/harmony/v2_06/framework/system/dma/src/sys_dma.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o: ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c  .generated_files/flags/default/2a5f4174a0750a53a1b4d2c6665fa5666cf71cc .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1872847683" 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c  .generated_files/flags/default/b157fd26774cc3cc6818c904af45e713d1a05a4b .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  .generated_files/flags/default/255d2266c2aaa093a558795a8696fab29a106ce9 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c  .generated_files/flags/default/f57c856148ed930146e2eaf97ab6f1555a4cb41f .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  .generated_files/flags/default/6f06b6e6b4e6970352644ec203662266a42925b3 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  .generated_files/flags/default/6f3b9e618baff17f6af1a4f5cfc51ea512c1c057 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  .generated_files/flags/default/1e1ccaf56a674ccdf905dcc48eda21a569bdb1be .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  .generated_files/flags/default/9bfdaf6c0238a7e461f731f824ed1b233704968f .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  .generated_files/flags/default/641e74305e86308d2a496c4610f00899bd01a329 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/UsbCommunication.o: ../src/UsbCommunication.c  .generated_files/flags/default/96eb5f5c94508bfac7ca8ea81b9e1ad643ce21ab .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/UsbCommunication.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/UsbCommunication.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/UsbCommunication.o.d" -o ${OBJECTDIR}/_ext/1360937237/UsbCommunication.o ../src/UsbCommunication.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
else
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/ccacb4b9a9d28dcaa81a1d1c920472bf72c2bab3 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/e9cc5c787db5a7fd15c98bf0162450b6e8e06f8f .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/Pic32MzDelay.o: ../src/Pic32MzDelay.c  .generated_files/flags/default/d97fc9ec9fbd5461683ea8c32feb54e7bfbab283 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Pic32MzDelay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Pic32MzDelay.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Pic32MzDelay.o.d" -o ${OBJECTDIR}/_ext/1360937237/Pic32MzDelay.o ../src/Pic32MzDelay.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/UartFile.o: ../src/UartFile.c  .generated_files/flags/default/d70d529fee0d6d7c1626fb41b10bcaf8b17f4068 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/UartFile.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/UartFile.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/UartFile.o.d" -o ${OBJECTDIR}/_ext/1360937237/UartFile.o ../src/UartFile.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/UartSource.o: ../src/UartSource.c  .generated_files/flags/default/f9e356f0881885b1210d2a94dfc2e4a624119b6e .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/UartSource.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/UartSource.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/UartSource.o.d" -o ${OBJECTDIR}/_ext/1360937237/UartSource.o ../src/UartSource.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/GuiCommunicationFile.o: ../src/GuiCommunicationFile.c  .generated_files/flags/default/cf01bde6f5fa5601b6d8cd7537eb853dde25e9f5 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GuiCommunicationFile.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/GuiCommunicationFile.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/GuiCommunicationFile.o.d" -o ${OBJECTDIR}/_ext/1360937237/GuiCommunicationFile.o ../src/GuiCommunicationFile.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/Adc.o: ../src/Adc.c  .generated_files/flags/default/dbee06fa2f5e720e9e87bac16bc04219b9cdad92 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Adc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Adc.o.d" -o ${OBJECTDIR}/_ext/1360937237/Adc.o ../src/Adc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/Measurement.o: ../src/Measurement.c  .generated_files/flags/default/c137507336c44938741b0216c067fee598f4b1f1 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Measurement.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Measurement.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Measurement.o.d" -o ${OBJECTDIR}/_ext/1360937237/Measurement.o ../src/Measurement.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/TimerFile.o: ../src/TimerFile.c  .generated_files/flags/default/149c281d2f565150c1f67e746efadb5c57684a79 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TimerFile.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TimerFile.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/TimerFile.o.d" -o ${OBJECTDIR}/_ext/1360937237/TimerFile.o ../src/TimerFile.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/Pic32Dma.o: ../src/Pic32Dma.c  .generated_files/flags/default/ffcd821bfcdb3dc00f2a685efe346c1848ea9c0c .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Pic32Dma.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Pic32Dma.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/Pic32Dma.o.d" -o ${OBJECTDIR}/_ext/1360937237/Pic32Dma.o ../src/Pic32Dma.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1684120524/sys_dma.o: ../../../../../../../../microchip/harmony/v2_06/framework/system/dma/src/sys_dma.c  .generated_files/flags/default/f763960b44304a221a1d10414234b209b18e3399 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1684120524" 
	@${RM} ${OBJECTDIR}/_ext/1684120524/sys_dma.o.d 
	@${RM} ${OBJECTDIR}/_ext/1684120524/sys_dma.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1684120524/sys_dma.o.d" -o ${OBJECTDIR}/_ext/1684120524/sys_dma.o ../../../../../../../../microchip/harmony/v2_06/framework/system/dma/src/sys_dma.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o: ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c  .generated_files/flags/default/875328d16fcc4507ffc33f9bf3784c98f137260b .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1872847683" 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c  .generated_files/flags/default/6429a3606faae6c406941cb2277791d97aa69257 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mz.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  .generated_files/flags/default/f32b7a84dda5c3e1d3c9da5c854b2dfb0faad41e .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c  .generated_files/flags/default/4093e96f61cf561e2b03f5db1f0408b63283694d .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mz.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mz.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  .generated_files/flags/default/230ccb452e3f4ff308b9889b9ee89cd30ac832ba .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  .generated_files/flags/default/dd4f0fa46e3a01f4f94bf6ced49204a0660b9408 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  .generated_files/flags/default/36c5896ac601f6f51f6a65a34527e37022c910af .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  .generated_files/flags/default/6b8d7078f86e570c34aacbb285bb276b4b50dda2 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  .generated_files/flags/default/786b99ef5a52c5e8c47a295a06a8ff78e2fdbc3d .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/1360937237/UsbCommunication.o: ../src/UsbCommunication.c  .generated_files/flags/default/1f55907f9197077cc36e12897caba0ba29085941 .generated_files/flags/default/5a43ce0a1a49bfdd311d19ad35e513e395645c1e
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/UsbCommunication.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/UsbCommunication.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../src/system_config/default/framework" -I"../../../../../../../../microchip/harmony/v2_06/framework" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/UsbCommunication.o.d" -o ${OBJECTDIR}/_ext/1360937237/UsbCommunication.o ../src/UsbCommunication.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ArdFFTLandT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../../../microchip/harmony/v2_06/bin/framework/peripheral/PIC32MZ1024EFE064_peripherals.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ArdFFTLandT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\..\..\microchip\harmony\v2_06\bin\framework\peripheral\PIC32MZ1024EFE064_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/ArdFFTLandT.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../../../microchip/harmony/v2_06/bin/framework/peripheral/PIC32MZ1024EFE064_peripherals.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/ArdFFTLandT.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\..\..\microchip\harmony\v2_06\bin\framework\peripheral\PIC32MZ1024EFE064_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/ArdFFTLandT.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
