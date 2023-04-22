// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2021 The TerraAustralis Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CONSENSUS_AMOUNT_H
#define BITCOIN_CONSENSUS_AMOUNT_H

#include <cstdint>

/** Amount in austoshis (Can be negative) */
typedef int64_t CAmount;

/** The amount of austoshis in one TAUS. */
static constexpr CAmount CENT = 1000000;
static constexpr CAmount COIN = 100000000;

/** No amount larger than this (in austoshi) is valid.
 *
 * Note that this constant is *not* the total money supply, which in TerraAustralis
 * currently happens to be less than 84,000,000 TAUS for various reasons, but
 * rather a sanity check. As this sanity check is used by consensus-critical
 * validation code, the exact value of the MAX_MONEY constant is consensus
 * critical; in unusual circumstances like a(nother) overflow bug that allowed
 * for the creation of coins out of thin air modification could lead to a fork.
 * */
static constexpr CAmount MAX_MONEY = 84000000 * COIN;
inline bool MoneyRange(const CAmount& nValue) { return (nValue >= 0 && nValue <= MAX_MONEY); }

#endif // BITCOIN_CONSENSUS_AMOUNT_H