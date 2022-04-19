global get_f1_values_fun
global get_f2_values_fun
global get_f3_values_fun


section .text
;--------------------------------

get_f1_values_fun: ;вычисление значения функции 0.35*x^2 - 0.95 * x + 2.7
    push ebp
    mov ebp, esp

    sub esp, 16
    mov dword[ebp - 4], 35
    mov dword[ebp - 8], 95
    mov dword[ebp - 12], 27
    mov dword[ebp - 16], 10
    
    finit
    ;first
    fild dword[ebp - 4] ;push 35
    fild dword[ebp - 16] ;push 10
    fdivp ;div 35/10
    fild dword[ebp - 16] ;push 10 
    fdivp ;div 3.5/10
    
    fld qword[ebp + 8] ;push X
    fmulp ;mul 0.35 * x
    fld qword[ebp + 8] ;push X
    fmulp ;mul 0.35 * x * x
    ;first

    ;second
    fild dword[ebp - 8] ;push 95
    fild dword[ebp - 16] ;push 10
    fdivp ;div 95/10
    fild dword[ebp - 16] ;push 10
    fdivp ;div 9.5/10
    
    fld qword[ebp + 8] ;push X
    fmulp ;mul 0.95 * x

    fsubp ;sub 0.95
    ;second

    ;third
    fild dword[ebp - 12] ;push 27
    fild dword[ebp - 16] ;push 10
    fdivp ;div 27/10

    faddp ;add 2.7
    ;third

    add esp, 16

get_f1_values_ret:
    mov esp, ebp
    pop ebp
    ret

;--------------------------------

get_f2_values_fun: ;вычисляет фукцию 3x + 1
    push ebp
    mov ebp, esp

    sub esp, 8
    mov dword[ebp - 4], 3
    mov dword[ebp - 8], 1

    ;first
    fld qword[ebp + 8] ;push X
    fild dword[ebp - 4] ;push 3
    fmulp ;mul 3 * x
    ;first

    ;second
    fild dword[ebp - 8] ;push 1
    faddp ;add 1
    ;second

    add esp, 8

get_f2_values_ret:
    mov esp, ebp
    pop ebp
    ret

;--------------------------------

get_f3_values_fun: ;вычисляет функию 1 / (x + 2)
    push ebp
    mov ebp, esp

    sub esp, 8
    mov dword[ebp - 4], 2
    mov dword[ebp - 8], 1

    fild dword[ebp - 8] ;push 1

    ;first
    fld qword[ebp + 8] ;push x
    fild dword[ebp - 4] ;push 2
    faddp ;add 2
    ;first

    ;second
    fdivp ;div 1 / (x + 2)
    ;second

    add esp, 8

get_f3_values_ret:
    mov esp, ebp
    pop ebp
    ret

;--------------------------------