// Copyright (c) You the reader 
// Distributed under the ABC/DEF software license, see the accompanying
// fish
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
std::map<std::string, int64> valueMap;  //  the value of each of the above vouts.  the key is the txid with the vout concatenated

///std::map<std::string, int> voutMap;  // vout mapped to TXiD


public:

bool isTokenTx(std::string txid);
bool isTokenOutput(std::string txid, int vout);
void addTransaction(std::string txid, std::vector<int> vout);
void addOutput(std::string key, int64 amount);
int64 getValueOfOutput(std::string key);
CToken (std::string txid, int vout, std::string name);

};


#endif
