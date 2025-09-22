// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_test.h for the primary calling header

#ifndef VERILATED_VTB_TEST___024ROOT_H_
#define VERILATED_VTB_TEST___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_test__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_test___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_test__DOT__clk;
    CData/*0:0*/ tb_test__DOT__a;
    CData/*0:0*/ tb_test__DOT__b;
    CData/*0:0*/ tb_test__DOT__out;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_test__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_test__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_test___024root(Vtb_test__Syms* symsp, const char* v__name);
    ~Vtb_test___024root();
    VL_UNCOPYABLE(Vtb_test___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
