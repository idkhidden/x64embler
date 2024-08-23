#pragma once

#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

unordered_map<uint8_t, string> opcodeMap = {
    // data movement instructions
    {0xB8, "mov rax,"},
    {0xB9, "mov rcx,"},
    {0xBA, "mov rdx,"},
    {0xBB, "mov rbx,"},
    {0xBC, "mov rsp,"},
    {0xBD, "mov rbp,"},
    {0xBE, "mov rsi,"},
    {0xBF, "mov rdi,"},
    {0x89, "mov"},  // need to handle
    {0x8B, "mov"},  // need to handle
    {0x86, "xchg"}, // need to handle
    {0x50, "push rax"},
    {0x51, "push rcx"},
    {0x52, "push rdx"},
    {0x53, "push rbx"},
    {0x54, "push rsp"},
    {0x55, "push rbp"},
    {0x56, "push rsi"},
    {0x57, "push rdi"},
    {0x58, "pop rax"},
    {0x59, "pop rcx"},
    {0x5A, "pop rdx"},
    {0x5B, "pop rbx"},
    {0x5C, "pop rsp"},
    {0x5D, "pop rbp"},
    {0x5E, "pop rsi"},
    {0x5F, "pop rdi"},

    // arithmetic instructions
    {0x01, "add"}, // need to handle
    {0x29, "sub"}, // need to handle
    {0xF6, "mul"}, // need to handle
    {0xF7, "div"}, // need to handle
    {0x40, "inc"}, // need to handle
    {0x48, "dec"}, // need to handle

    // logical instructions
    {0x21, "and"}, // need to handle
    {0x09, "or"},  // need to handle
    {0x31, "xor"}, // need to handle
    {0xF6, "not"}, // need to handle

    // control flow instructions
    {0xE9, "jmp"}, 
    {0xE8, "call"}, 
    {0xC3, "ret"},
    {0x74, "je"},   
    {0x75, "jne"},  
    {0x7F, "jg"},   // need to handle

    // comparison instructions
    {0x3D, "cmp"}, // need to handle
    {0xA9, "test"}, // need to handle

    // string instructions
    {0xA4, "movs"}, // need to handle
    {0xA6, "cmps"}, // need to handle
    {0xAC, "scas"}, // need to handle
    {0xA4, "lods"}, // need to handle
    {0xAA, "stos"}, // need to handle

    // bit manipulation instructions
    {0xD1, "shl"}, // need to handle
    {0xD1, "shr"}, // need to handle
    {0xD3, "sal"}, // need to handle
    {0xD3, "sar"}, // need to handle
    {0xD2, "rol"}, // need to handle
    {0xD3, "ror"}, // need to handle

    // processor control instructions
    {0x90, "nop"},
    {0xF4, "hlt"},
    {0x9B, "wait"}, 
    {0xF0, "cli"},  
    {0xF8, "sti"},  

    // conversion instructions
    {0x0F, "movzx"}, // need to handle
    {0x63, "movsx"}, // need to handle

    // floating point and simd Instructions
    {0xF3, "addss"}, // need to handle
    {0xF3, "subss"}, // need to handle
    {0xF3, "mulss"}, // need to handle
    {0xF3, "divss"}, // need to handle
    {0x0F, "movaps"}, // need to handle
    {0x0F, "movdqa"},  // need to handle

    // system instructions
    {0x0F, "syscall"}
};


unordered_map<uint8_t, string> registerMap =
{
    {0xC0, "RAX"}, {0xC1, "RCX"}, {0xC2, "RDX"}, {0xC3, "RBX"},
    {0xC4, "RSP"}, {0xC5, "RBP"}, {0xC6, "RSI"}, {0xC7, "RDI"}
};