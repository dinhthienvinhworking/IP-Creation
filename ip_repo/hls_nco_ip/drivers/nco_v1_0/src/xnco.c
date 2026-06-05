// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xnco.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XNco_CfgInitialize(XNco *InstancePtr, XNco_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XNco_Start(XNco *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNco_ReadReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_AP_CTRL) & 0x80;
    XNco_WriteReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XNco_IsDone(XNco *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNco_ReadReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XNco_IsIdle(XNco *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNco_ReadReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XNco_IsReady(XNco *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNco_ReadReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XNco_EnableAutoRestart(XNco *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNco_WriteReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XNco_DisableAutoRestart(XNco *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNco_WriteReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_AP_CTRL, 0);
}

u32 XNco_Get_sine_sample(XNco *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNco_ReadReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_SINE_SAMPLE_DATA);
    return Data;
}

u32 XNco_Get_sine_sample_vld(XNco *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNco_ReadReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_SINE_SAMPLE_CTRL);
    return Data & 0x1;
}

void XNco_Set_step_size(XNco *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNco_WriteReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_STEP_SIZE_DATA, Data);
}

u32 XNco_Get_step_size(XNco *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XNco_ReadReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_STEP_SIZE_DATA);
    return Data;
}

void XNco_InterruptGlobalEnable(XNco *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNco_WriteReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_GIE, 1);
}

void XNco_InterruptGlobalDisable(XNco *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNco_WriteReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_GIE, 0);
}

void XNco_InterruptEnable(XNco *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XNco_ReadReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_IER);
    XNco_WriteReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_IER, Register | Mask);
}

void XNco_InterruptDisable(XNco *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XNco_ReadReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_IER);
    XNco_WriteReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_IER, Register & (~Mask));
}

void XNco_InterruptClear(XNco *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XNco_WriteReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_ISR, Mask);
}

u32 XNco_InterruptGetEnabled(XNco *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XNco_ReadReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_IER);
}

u32 XNco_InterruptGetStatus(XNco *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XNco_ReadReg(InstancePtr->Control_BaseAddress, XNCO_CONTROL_ADDR_ISR);
}

