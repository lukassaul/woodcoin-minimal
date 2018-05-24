// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include "token.h"


bool CToken::isTokenTx(std::string txid) {
	
    std::map<std::string, CTransaction*>::iterator mi = txMap.find(txid);
        if (mi != txMap.end())
        {
            return true;
        }
    
    return false;
}

bool CToken::isTokenUtxo(std::string txid, int vout) {
    
    std::map<std::string, int>::iterator mi = voutMap.find(txid);
        if (mi != voutMap.end())
        {
		     ///const CWalletTx& prev = (*mi).second;
		     return true;
        }
    
    return false;
}



