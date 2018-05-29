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

std::string genesisTxid;
int genesisVout;
int64 genesisValue;
std::string label;
std::map<std::string, std::vector<int> > txMap;  // map of all transactoins which of or type THIS TOKEN <label>
std::map<std::string, std::vector<int64> > valueMap;  //  the value of each of the above vouts

///std::map<std::string, int> voutMap;  // vout mapped to TXiD


public:

bool isTokenTx(std::string txid);
bool isTokenOutput(std::string txid, int vout);
bool addTokenTransaction(std::string txid, int vout);
CToken (std::string txid, int vout, std::string name);

};


#endif
