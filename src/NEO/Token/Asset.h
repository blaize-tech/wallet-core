// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../../BinaryCoding.h"
#include "../../Data.h"
#include "../Address.h"
#include "../Signer.h"
#include "../Transaction.h"

namespace TW::NEO::Token {

class Asset {
  protected:
    const uint8_t txType = 0xD1;
  public:
    virtual uint8_t getVersion() = 0;
    virtual Data contractAddress() = 0;
    virtual Transaction decimals(uint32_t nonce) = 0;
    virtual Transaction balanceOf(const Address &address, uint32_t nonce) = 0;
    virtual Transaction transfer(const Signer &from, const Address &to, uint64_t amount,
                                 const Signer &payer, uint64_t gasPrice, uint64_t gasLimit,
                                 uint32_t nonce) = 0;
    virtual ~Asset() {}
};
} // namespace TW::NEO
