// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_test__pch.h"

//============================================================
// Constructors

Vtb_test::Vtb_test(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_test__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_test::Vtb_test(const char* _vcname__)
    : Vtb_test(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_test::~Vtb_test() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_test___024root___eval_debug_assertions(Vtb_test___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_test___024root___eval_static(Vtb_test___024root* vlSelf);
void Vtb_test___024root___eval_initial(Vtb_test___024root* vlSelf);
void Vtb_test___024root___eval_settle(Vtb_test___024root* vlSelf);
void Vtb_test___024root___eval(Vtb_test___024root* vlSelf);

void Vtb_test::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_test::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_test___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_test___024root___eval_static(&(vlSymsp->TOP));
        Vtb_test___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_test___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_test___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_test::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_test::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_test::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_test___024root___eval_final(Vtb_test___024root* vlSelf);

VL_ATTR_COLD void Vtb_test::final() {
    Vtb_test___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_test::hierName() const { return vlSymsp->name(); }
const char* Vtb_test::modelName() const { return "Vtb_test"; }
unsigned Vtb_test::threads() const { return 1; }
void Vtb_test::prepareClone() const { contextp()->prepareClone(); }
void Vtb_test::atClone() const {
    contextp()->threadPoolpOnClone();
}
