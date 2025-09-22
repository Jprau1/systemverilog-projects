// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_test.h for the primary calling header

#include "Vtb_test__pch.h"
#include "Vtb_test__Syms.h"
#include "Vtb_test___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_test___024root___eval_initial__TOP__Vtiming__1(Vtb_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_test___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0xaULL, 
                                             nullptr, 
                                             "tb_test.sv", 
                                             8);
        vlSelfRef.tb_test__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_test__DOT__clk)));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_test___024root___dump_triggers__act(Vtb_test___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_test___024root___eval_triggers__act(Vtb_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_test___024root___eval_triggers__act\n"); );
    Vtb_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.tb_test__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_test__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb_test__DOT__clk__0 
        = vlSelfRef.tb_test__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_test___024root___dump_triggers__act(vlSelf);
    }
#endif
}
