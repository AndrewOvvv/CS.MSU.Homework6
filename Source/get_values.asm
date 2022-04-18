%include "io.inc"

global get_f1_values_fun
global get_f2_values_fun
global get_f3_values_fun


section .text
;--------------------------------

get_f1_values_fun:
    push ebp
    mov ebp, esp

    sub esp, 16
    mov dword[ebp - 4], 35
    mov dwprd[ebp - 8], 95
    mov dword[ebp - 12], 27
    mov dword[ebp - 16], 10
    
    finit
    ;first
    fild dword[epb - 4]
    fild dword[ebp - 16]
    fdivp
    fild dword[ebp - 16]
    fdivp
    
    fld dword[ebp + 8]
    fmulp
    ;first

    ;second
    fild dword[epb - 8]
    fild dword[ebp - 16]
    fdivp
    fild dword[ebp - 16]
    fdivp
    
    fld dword[ebp + 8]
    fmulp

    fsubp
    ;second

    ;third
    fild dword[ebp - 12]
    fild dword[ebp - 16]
    fdivp

    faddp
    ;third

    add esp, 16

get_f1_values_ret:
    mov esp, ebp
    pop ebp
    ret

;--------------------------------

get_f2_values_fun:
    push ebp
    mov ebp, esp

    sub esp, 8
    mov dword[ebp - 4], 3
    mov dword[ebp - 8], 1

    ;first
    fld dword[ebp + 8]
    fild dword[ebp - 4]
    fmulp
    ;first

    ;second
    fild dword[ebp - 8]
    faddp
    ;second

    add esp, 8

get_f2_values_ret:
    mov eso, ebp
    pop ebp
    ret

;--------------------------------

get_f3_values_fun:
    push ebp
    mov ebp, esp

    sub esp, 8
    mov dword[ebp - 4], 2
    mov dwprd[ebp - 8], 1

    fild dword[ebp - 8] ;precalc

    ;first
    fld dword[ebp + 8]
    fild dword[ebp - 4]
    fappp
    ;first

    ;second
    fdivp
    ;second

    add esp, 8

get_f3_values_ret:
    mov esp, ebp
    pop ebp
    ret

;--------------------------------