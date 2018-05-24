// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_TOKEN_H
#define BITCOIN_TOKEN_H

#include "token.h"
#include "main.h"

class CToken
{

protected:

CTransaction genesisTx;
int genesisVout;
std::string label;
std::map<std::string, CTransaction*> txMap;  // transaction mapped to TXiD
std::map<std::string, int> voutMap;  // vout mapped to TXiD


public:

bool isTokenTx(std::string txid);
bool isTokenUtxo(std::string txid, int vout);
bool addTokenTransaction(std::string txid, int vout);

};


#endif
