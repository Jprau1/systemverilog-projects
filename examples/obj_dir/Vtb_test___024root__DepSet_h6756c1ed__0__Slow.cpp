// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_test.h for the primary calling header

#include "Vtb_test__pch.h"
#include "Vtb_test___024root.h"

VL_ATTR_COLD void Vtb_test___024root___eval_static(Vtb_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_test___024root___eval_static\n"); );
    Vtb_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_test__DOT__clk__0 
        = vlSelfRef.tb_test__DOT__clk;
}

VL_ATTR_COLD void Vtb_test___024root___eval_initial__TOP(Vtb_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_test___024root___eval_initial__TOP\n"); );
    Vtb_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_test__DOT__clk = 0U;
}

VL_ATTR_COLD void Vtb_test___024root___eval_final(Vtb_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_test___024root___eval_final\n"); );
    Vtb_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_test___024root___eval_settle(Vtb_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_test___024root___eval_settle\n"); );
    Vtb_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_test___024root___dump_triggers__act(Vtb_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_test___024root___dump_triggers__act\n"); );
    Vtb_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_test.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_test___024root___dump_triggers__nba(Vtb_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_test___024root___dump_triggers__nba\n"); );
    Vtb_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_test.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_test___024root___ctor_var_reset(Vtb_test___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_test___024root___ctor_var_reset\n"); );
    Vtb_test__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tb_test__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10107192968628391213ull);
    vlSelf->tb_test__DOT__a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3145343172239789216ull);
    vlSelf->tb_test__DOT__b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12862521194862061651ull);
    vlSelf->tb_test__DOT__out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9947075656024237149ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_test__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11008777053885063848ull);
}
