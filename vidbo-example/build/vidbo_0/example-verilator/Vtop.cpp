// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("src/vidbo_0/example/top.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("src/vidbo_0/example/top.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_led = (0xffffU & (((IData)(1U) << (IData)(vlTOPp->top__DOT__ones)) 
                                - (IData)(1U)));
}

VL_INLINE_OPT void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__ones = (1U & (IData)(vlTOPp->i_sw));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 1U))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 2U))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 3U))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 4U))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 5U))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 6U))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 7U))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 8U))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 9U))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 0xaU))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 0xbU))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 0xcU))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 0xdU))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 0xeU))));
    vlTOPp->top__DOT__ones = (0xfU & ((IData)(vlTOPp->top__DOT__ones) 
                                      + (1U & ((IData)(vlTOPp->i_sw) 
                                               >> 0xfU))));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_settle__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
}
#endif  // VL_DEBUG
