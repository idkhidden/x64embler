/*
* x64embler
* https://github.com/idkhidden/
*/

#include "./isa.h"

// to do -> handle alot of opcodes, registers, modrm and sib bytes

void disassemble(const vector<uint8_t>& bytes)
{
    size_t offset = 0;
    while (offset < bytes.size())
    {
        if (bytes[offset] >= 0x40 && bytes[offset] <= 0x4F) // ignoring the prefix
        {
            offset++;
            continue;
        }

        if (bytes[offset] == 0x00) //ignoring 0x00
        {
            offset++;
            continue;
        }

        uint8_t opcode = bytes[offset];

        if (opcodeMap.find(opcode) != opcodeMap.end())
        {

            if (opcode >= 0xB8 && opcode <= 0xBF) // handling mov 
            {
                cout << opcodeMap[opcode];

                uint64_t immediate = 0;
                for (int i = 0; i < 8; ++i)
                {
                    immediate |= static_cast<uint64_t>(bytes[offset + 1 + i]) << (i * 8);
                }
                cout << " 0x" << hex << setw(16) << setfill('0') << immediate;
                offset += 9;
            }
            else if (opcode >= 0x50 && opcode <= 0x57) // handling push 
            {
                cout << opcodeMap[opcode];
                offset += 1;
            }
            else if (opcode >= 0x58 && opcode <= 0x5F) // handling pop 
            {

                cout << opcodeMap[opcode];
                offset += 1;
            }


            else if (opcode == 0xE9) // handling jmp
            {
                cout << opcodeMap[opcode];
                int32_t offsetValue = 0;
                for (int i = 0; i < 4; ++i)
                {
                    offsetValue |= static_cast<int32_t>(bytes[offset + 1 + i]) << (i * 8);
                }
                cout << " 0x" << hex << setw(8) << setfill('0') << offsetValue;
                offset += 5;
            }
            else if (opcode == 0x74 || opcode == 0x75) // handling je/jne
            {
                cout << opcodeMap[opcode];

                int8_t offsetValue = static_cast<int8_t>(bytes[offset + 1]);
                cout << " 0x" << hex << setw(2) << setfill('0') << static_cast<int>(offsetValue);
                offset += 2;
            }
            else if (opcode == 0xE8) // handling call with displacement 
            {
                int32_t displacement = 0;

                for (int i = 0; i < 4; ++i)
                {
                    displacement |= static_cast<int32_t>(bytes[offset + 1 + i]) << (i * 8);
                }

                int32_t address = offset + 5 + displacement;

                cout << "call " << "0x" << hex << address;

                offset += 5;
            }
          
           else if (opcode == 0x90) //handling nop 
            {
                cout << opcodeMap[opcode];
                offset += 1;
            }
            else if (opcode == 0xF4) //handling hlt 
            {
                cout << opcodeMap[opcode];
                offset += 1;
            }
            else if (opcode == 0x9B) //handling wait 
            {
                cout << opcodeMap[opcode];
                offset += 1;
            }
            else if (opcode == 0xF0) //handling cli 
            {
                cout << opcodeMap[opcode];
                offset += 1;
            }
            else if (opcode == 0xF8) //handling sti 
            {
                cout << opcodeMap[opcode];
                offset += 1;
            }
            else if (opcode == 0xC3) //handling ret 
            {
                cout << opcodeMap[opcode];
                offset += 1;
            }
            else if (opcode == 0x0F) // handling syscall
            {
                cout << opcodeMap[opcode];
                uint8_t nextByte = bytes[offset + 1];
                if (nextByte == 0x05)
                {
                    offset += 2;
                }
                else
                {
                    offset++;
                }
            }
            else
            {
                offset++;
            }
        }
        else
        {
            cout << "[unknown]";
            offset++;
        }
        cout << endl;
    }
}

int main() 
{
    string binpath;
    cout << "[ x64embler ] Enter bin name -> ";
    cin >> binpath;

    ifstream bin(binpath, ios::binary);

    if (!bin)
    {
        cout << "[ Error ] Couldnt open bin :(\n";
        return 1;
    }

    vector<uint8_t> binary((istreambuf_iterator<char>(bin)), istreambuf_iterator<char>());


    disassemble(binary);

    while (1);
    
}
