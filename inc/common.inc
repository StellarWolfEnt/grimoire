%ifndef GRIMOIRE_COMMON_INC
%define GRIMOIRE_COMMON_INC

%macro GRIMOIRE_PUBLIC 1
    align 16
    global %1
    %1:
%endmacro

%macro GRIMOIRE_INTERNAL 1
    align 16
    global %1
    %1:
%endmacro

%macro GRIMOIRE_PRIVATE 1
    align 16
    %1:
%endmacro

%macro MARKER 1
    %1:
%endmacro

%endif ;GRIMOIRE_COMMON_INC