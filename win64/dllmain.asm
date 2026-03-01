bits 64

%include "common.inc"

;-------------------------------------------------------------------------------
; PData
;-------------------------------------------------------------------------------

section .pdata rdata align=4
    __GrimoireDllMain_pdata:
        dd GrimoireDllMain - $$
        dd GrimoireDllMain_End - $$
        dd __GrimoireDllMain_xdata - $$

;-------------------------------------------------------------------------------
; XData
;-------------------------------------------------------------------------------

section .xdata rdata align=4
    __GrimoireDllMain_xdata:
        db 1,
        db 0,
        db 0,
        db 0

;-------------------------------------------------------------------------------
; Internal Functions
;-------------------------------------------------------------------------------

section .text code align=16

; START: GrimoireDllMain -------------------------------------------------------

GRIMOIRE_INTERNAL GrimoireDllMain
    mov         rax, 1
    ret
MARKER GrimoireDllMain_End

; END: GrimoireDllMain ---------------------------------------------------------