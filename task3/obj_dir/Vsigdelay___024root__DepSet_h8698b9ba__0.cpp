// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "Vsigdelay__pch.h"
#include "Vsigdelay___024root.h"

void Vsigdelay___024root___eval_act(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_act\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vsigdelay___024root___nba_sequent__TOP__0(Vsigdelay___024root* vlSelf);

void Vsigdelay___024root___eval_nba(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_nba\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vsigdelay___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vsigdelay___024root___nba_sequent__TOP__0(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___nba_sequent__TOP__0\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vdly__sigdelay__DOT____Vcellout__addrCounter__rd_addr;
    __Vdly__sigdelay__DOT____Vcellout__addrCounter__rd_addr = 0;
    CData/*7:0*/ __VdlyVal__sigdelay__DOT__RAM__DOT__ram_array__v0;
    __VdlyVal__sigdelay__DOT__RAM__DOT__ram_array__v0 = 0;
    SData/*8:0*/ __VdlyDim0__sigdelay__DOT__RAM__DOT__ram_array__v0;
    __VdlyDim0__sigdelay__DOT__RAM__DOT__ram_array__v0 = 0;
    CData/*0:0*/ __VdlySet__sigdelay__DOT__RAM__DOT__ram_array__v0;
    __VdlySet__sigdelay__DOT__RAM__DOT__ram_array__v0 = 0;
    // Body
    __Vdly__sigdelay__DOT____Vcellout__addrCounter__rd_addr 
        = vlSelfRef.sigdelay__DOT____Vcellout__addrCounter__rd_addr;
    __VdlySet__sigdelay__DOT__RAM__DOT__ram_array__v0 = 0U;
    __Vdly__sigdelay__DOT____Vcellout__addrCounter__rd_addr 
        = ((IData)(vlSelfRef.rst) ? 0U : (0xffU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.sigdelay__DOT____Vcellout__addrCounter__rd_addr))));
    if (vlSelfRef.wr) {
        __VdlyVal__sigdelay__DOT__RAM__DOT__ram_array__v0 
            = vlSelfRef.mic_signal;
        __VdlyDim0__sigdelay__DOT__RAM__DOT__ram_array__v0 
            = (0x1ffU & ((IData)(vlSelfRef.sigdelay__DOT____Vcellout__addrCounter__rd_addr) 
                         + (IData)(vlSelfRef.offset)));
        __VdlySet__sigdelay__DOT__RAM__DOT__ram_array__v0 = 1U;
    }
    if (vlSelfRef.rd) {
        vlSelfRef.delayed_signal = vlSelfRef.sigdelay__DOT__RAM__DOT__ram_array
            [vlSelfRef.sigdelay__DOT____Vcellout__addrCounter__rd_addr];
    }
    if (__VdlySet__sigdelay__DOT__RAM__DOT__ram_array__v0) {
        vlSelfRef.sigdelay__DOT__RAM__DOT__ram_array[__VdlyDim0__sigdelay__DOT__RAM__DOT__ram_array__v0] 
            = __VdlyVal__sigdelay__DOT__RAM__DOT__ram_array__v0;
    }
    vlSelfRef.sigdelay__DOT____Vcellout__addrCounter__rd_addr 
        = __Vdly__sigdelay__DOT____Vcellout__addrCounter__rd_addr;
}

void Vsigdelay___024root___eval_triggers__act(Vsigdelay___024root* vlSelf);

bool Vsigdelay___024root___eval_phase__act(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_phase__act\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsigdelay___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vsigdelay___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsigdelay___024root___eval_phase__nba(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_phase__nba\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsigdelay___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsigdelay___024root___dump_triggers__nba(Vsigdelay___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsigdelay___024root___dump_triggers__act(Vsigdelay___024root* vlSelf);
#endif  // VL_DEBUG

void Vsigdelay___024root___eval(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsigdelay___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("sigdelay.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsigdelay___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("sigdelay.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vsigdelay___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vsigdelay___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsigdelay___024root___eval_debug_assertions(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_debug_assertions\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY(((vlSelfRef.wr & 0xfeU)))) {
        Verilated::overWidthError("wr");}
    if (VL_UNLIKELY(((vlSelfRef.rd & 0xfeU)))) {
        Verilated::overWidthError("rd");}
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.offset & 0xfe00U)))) {
        Verilated::overWidthError("offset");}
}
#endif  // VL_DEBUG
