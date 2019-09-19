MB_FLAGS equ 11b
MB_MAGIC equ 0x1BADB002
MB_CHECKSUM equ -(MB_MAGIC + MB_FLAGS)

STACK_SIZE equ 16 * 1024

section .multiboot
align 4
dd MB_FLAGS
dd MB_MAGIC
dd MB_CHECKSUM

section .bss
align 16
stackBottom:
resb STACK_SIZE
stackTop:

section .text
global _start:function (_start.end - _start)
_start:
  ; Set stack pointer.
  mov esp, stackTop

  ; Open kernel.
  extern amberMain
  call amberMain

  ; Hang
  cli
.stop:
  hlt
  jmp .stop
.end: