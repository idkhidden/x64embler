# x64embler
x64embler is an ineffective x86-64 disassembler developed in C++. It provides an inefficient mechanism for disassembling x86-64 instructions. While it is not intended to be the most advanced or comprehensive disassembler available, x64embler serves primarily an educational purpose. Efforts to enhance and refine this project will continue as time permits.

## Work in progress  
- **Opcode Handling**: The disassembler still needs to handle a wide range of opcodes.
- **Register Mapping**: It currently manages basic register mappings but requires expansion to cover additional registers and their variations.
- **MODRM Bytes**: The handling of MODRM bytes is still under development. This includes the correct interpretation of mode, register, and r/m fields.
- **SIB Bytes**: Support for SIB (Scale-Index-Base) bytes needs to be implemented to fully decode instructions that use memory addressing with scaling and indexing.

## License
x64embler is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contributing
We welcome contributions to improve this project. 

## Showcase
![image](https://github.com/user-attachments/assets/35b15f42-3e9e-458f-b62f-04bb68d2bc48)
