################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.oer4f: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ti-cgt-arm_16.9.6.LTS/bin/armcl" -mv7R4 --code_state=16 --float_support=VFPv3D16 -me -O3 --include_path="C:/Users/PETABREW001/workspace_v12/out_of_box_6843_aop" --include_path="C:/ti/mmwave_sdk_03_06_00_00-LTS/packages" --include_path="C:/ti/ti-cgt-arm_16.9.6.LTS/include" --define=SOC_XWR68XX --define=SUBSYS_MSS --define=DOWNLOAD_FROM_CCS --define=MMWAVE_L3RAM_NUM_BANK=6 --define=MMWAVE_SHMEM_TCMA_NUM_BANK=0 --define=MMWAVE_SHMEM_TCMB_NUM_BANK=0 --define=MMWAVE_SHMEM_BANK_SIZE=0x20000 --define=DebugP_ASSERT_ENABLED --define=_LITTLE_ENDIAN --define=DebugP_LOG_ENABLED --define=XWR68XX_AOP_ANTENNA_PATTERN --define=USE_2D_AOA_DPU --define=AOP --define=APP_RESOURCE_FILE='<'ti/demo/xwr64xx/mmw/mmw_res.h'>' -g --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --enum_type=int --abi=eabi --obj_extension=.oer4f --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1188615185:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-1188615185-inproc

build-1188615185-inproc: ../mmw.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_50_08_24_core/xs" --xdcpath="C:/ti/bios_6_73_01_01/packages;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.R4Ft -p ti.platforms.cortexR:IWR68XX:false:200 -r release -c "C:/ti/ti-cgt-arm_16.9.6.LTS" --compileOptions "--enum_type=int " "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-1188615185 ../mmw.cfg
configPkg/compiler.opt: build-1188615185
configPkg/: build-1188615185


