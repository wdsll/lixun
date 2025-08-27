################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
library/%.obj: ../library/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/cl2000" -v28 -ml -mt -g --include_path="C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/include" --include_path="C:/Users/huyan/Desktop/CCS_spc/testtttttttttt/testtttttttttt/testtttttttt/Incude" --include_path="C:/Users/huyan/Desktop/CCS_spc/testtttttttttt/testtttttttttt/testtttttttt/library" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="library/$(basename $(<F)).d_raw" --obj_directory="library" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

library/%.obj: ../library/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/cl2000" -v28 -ml -mt -g --include_path="C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/include" --include_path="C:/Users/huyan/Desktop/CCS_spc/testtttttttttt/testtttttttttt/testtttttttt/Incude" --include_path="C:/Users/huyan/Desktop/CCS_spc/testtttttttttt/testtttttttttt/testtttttttt/library" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="library/$(basename $(<F)).d_raw" --obj_directory="library" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


