#  Copyright (c) Microsoft Corporation. All rights reserved.
#  Licensed under the MIT License.

cmake_minimum_required(VERSION 3.10)

project(AvnetAzureIoT C)

azsphere_configure_tools(TOOLS_REVISION "20.10")
azsphere_configure_api(TARGET_API_SET "7") 
 
add_executable(${PROJECT_NAME} 
                main.c 
                arducam_driver/ArduCAM.c 
                arducam_driver/ll.c 
                arducam_driver/ov2640_regs.c 
                delay.c)
target_include_directories(${PROJECT_NAME} PUBLIC ${AZURE_SPHERE_API_SET_DIR}/usr/include/azureiot ${AZURE_SPHERE_API_SET_DIR}/usr/include/azure_prov_client)

# Set the defines for the build
target_compile_definitions(${PROJECT_NAME} PUBLIC AZURE_IOT_HUB_CONFIGURED)
target_compile_definitions(${PROJECT_NAME} PUBLIC AzureSphere_CA7)
target_compile_definitions(${PROJECT_NAME} PUBLIC CFG_MODE_JPEG)

target_link_libraries(${PROJECT_NAME} azureiot applibs pthread gcc_s c curl)

azsphere_target_hardware_definition(${PROJECT_NAME} TARGET_DIRECTORY "Hardware/avnet_mt3620_sk_rev2" TARGET_DEFINITION "sample_hardware.json")

#find_program(POWERSHELL powershell.exe)

#if (POWERSHELL)
#    # Run validate_manifest script during build
#    add_custom_target(ValidateManifest ALL
#        COMMAND ${POWERSHELL} -ExecutionPolicy Bypass -NoProfile -NonInteractive -File ${CMAKE_SOURCE_DIR}/script/validate_manifest.ps1
#        DEPENDS ${CMAKE_SOURCE_DIR}/app_manifest.json)
#else()
#    # Warn users without PowerShell to update their manifest
#    add_custom_target(ValidateManifest ALL
#       COMMAND echo "Please ensure that you have updated app_manifest.json as described in IoTCentral.md or IoTHub.md, as appropriate."
#       DEPENDS ${CMAKE_SOURCE_DIR}/app_manifest.json)
#endif()
       
# add_dependencies(ValidateManifest ${PROJECT_NAME})

azsphere_target_add_image_package(${PROJECT_NAME})
#azsphere_target_add_image_package(${PROJECT_NAME} RESOURCE_FILES "certs/Microsoft RSA TLS CA 01.crt")
