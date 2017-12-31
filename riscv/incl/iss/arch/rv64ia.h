////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017, MINRES Technologies GmbH
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
// 
// Created on: Sat Dec 30 12:50:15 CET 2017
//             *      rv64ia.h Author: <CoreDSL Generator>
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _RV64IA_H_
#define _RV64IA_H_

#include <iss/arch_if.h>
#include <iss/vm_if.h>
#include <iss/arch/traits.h>

namespace iss {
namespace arch {

struct rv64ia;

template<>
struct traits<rv64ia> {

    enum constants {XLEN=64,XLEN2=128,XLEN_BIT_MASK=63,PCLEN=64,fence=0,fencei=1,fencevmal=2,fencevmau=3,MISA_VAL=2147746049,PGSIZE=4096,PGMASK=4095};

    enum reg_e {
        X0,
        X1,
        X2,
        X3,
        X4,
        X5,
        X6,
        X7,
        X8,
        X9,
        X10,
        X11,
        X12,
        X13,
        X14,
        X15,
        X16,
        X17,
        X18,
        X19,
        X20,
        X21,
        X22,
        X23,
        X24,
        X25,
        X26,
        X27,
        X28,
        X29,
        X30,
        X31,
        PC,
        NUM_REGS,
        NEXT_PC=NUM_REGS,
        TRAP_STATE,
        PENDING_TRAP,
        MACHINE_STATE,
        ICOUNT
    };

    using reg_t = uint64_t;

    using addr_t = uint64_t;

    using code_word_t = uint64_t; //TODO: check removal

    using virt_addr_t = iss::typed_addr_t<iss::address_type::VIRTUAL>;

    using phys_addr_t = iss::typed_addr_t<iss::address_type::PHYSICAL>;

    constexpr static unsigned reg_bit_width(unsigned r) {
        const uint32_t RV64IA_reg_size[] = {64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,32,32,32,64};
        return RV64IA_reg_size[r];
    }

    constexpr static unsigned reg_byte_offset(unsigned r) {
        const uint32_t RV64IA_reg_byte_offset[] = {0,8,16,24,32,40,48,56,64,72,80,88,96,104,112,120,128,136,144,152,160,168,176,184,192,200,208,216,224,232,240,248,256,264,272,276,280,288,296};
        return RV64IA_reg_byte_offset[r];
    }

    static const uint64_t addr_mask = (reg_t(1) << (XLEN - 1)) | ((reg_t(1) << (XLEN - 1)) - 1);

    enum sreg_flag_e {FLAGS};

    enum mem_type_e {MEM,CSR,FENCE,RES};

};

struct rv64ia: public arch_if {

    using virt_addr_t = typename traits<rv64ia>::virt_addr_t;
    using phys_addr_t = typename traits<rv64ia>::phys_addr_t;
    using reg_t =  typename traits<rv64ia>::reg_t;
    using addr_t = typename traits<rv64ia>::addr_t;

    rv64ia();
    ~rv64ia();

    void reset(uint64_t address=0) override;

    uint8_t* get_regs_base_ptr() override;
    /// deprecated
    void get_reg(short idx, std::vector<uint8_t>& value) override {}
    void set_reg(short idx, const std::vector<uint8_t>& value) override {}
    /// deprecated
    bool get_flag(int flag) override {return false;}
    void set_flag(int, bool value) override {};
    /// deprecated
    void update_flags(operations op, uint64_t opr1, uint64_t opr2) override {};

    uint64_t get_icount() { return reg.icount;}

    inline phys_addr_t v2p(const iss::addr_t& addr){
        if(addr.space != traits<rv64ia>::MEM ||
                addr.type == iss::address_type::PHYSICAL ||
                addr_mode[static_cast<uint16_t>(addr.access)&0x3]==address_type::PHYSICAL){
            return phys_addr_t(addr.access, addr.space, addr.val&traits<rv64ia>::addr_mask);
        } else
            return virt2phys(addr);
    }

    virtual phys_addr_t virt2phys(const iss::addr_t& addr);

    virtual iss::sync_type needed_sync() const { return iss::NO_SYNC; }

protected:
    struct RV64IA_regs {
        uint64_t X0 = 0;
        uint64_t X1 = 0;
        uint64_t X2 = 0;
        uint64_t X3 = 0;
        uint64_t X4 = 0;
        uint64_t X5 = 0;
        uint64_t X6 = 0;
        uint64_t X7 = 0;
        uint64_t X8 = 0;
        uint64_t X9 = 0;
        uint64_t X10 = 0;
        uint64_t X11 = 0;
        uint64_t X12 = 0;
        uint64_t X13 = 0;
        uint64_t X14 = 0;
        uint64_t X15 = 0;
        uint64_t X16 = 0;
        uint64_t X17 = 0;
        uint64_t X18 = 0;
        uint64_t X19 = 0;
        uint64_t X20 = 0;
        uint64_t X21 = 0;
        uint64_t X22 = 0;
        uint64_t X23 = 0;
        uint64_t X24 = 0;
        uint64_t X25 = 0;
        uint64_t X26 = 0;
        uint64_t X27 = 0;
        uint64_t X28 = 0;
        uint64_t X29 = 0;
        uint64_t X30 = 0;
        uint64_t X31 = 0;
        uint64_t PC = 0;
        uint64_t NEXT_PC = 0;
        uint32_t trap_state = 0, pending_trap = 0, machine_state = 0;
        uint64_t icount = 0;
    } reg;

    address_type addr_mode[4];

    uint64_t cycles = 0;
    
};

}
}            
#endif /* _RV64IA_H_ */
