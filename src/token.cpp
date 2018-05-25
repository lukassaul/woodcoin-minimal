// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include "token.h"


bool CToken::isTokenTx(std::string txid) {
	
    std::map<std::string, std::vector<int> >::iterator mi = txMap.find(txid);
        if (mi != txMap.end())
        {
            return true;
        }
    return false;
}

bool CToken::isTokenOutput(std::string txid, int vout) {
    
    std::map<std::string, std::vector<int>>::iterator mi = txMap.find(txid);        
        if (mi != txMap.end())
        {
		     std::vector<int> vec = txMap[txid];  //
            if (std::find(vec.begin(), vec.end(), vout) != vec.end())		     
                return true;
            
        }
    
    return false;
}

CToken::CToken(std::string txid, int vout, std::string name) {
    //std::cout << "inside token constructor" << endl;
    label = name;
    genesisTxid = txid;
    genesisVout = vout;
    // add the genesis TX to the token map
    std::vector<int> voutVec;
    voutVec.push_back(vout);
    txMap.insert(std::make_pair(txid,voutVec));
}
    //std::map<std::string,std::vector<int> > myMap;
    



