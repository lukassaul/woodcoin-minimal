// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include "token.h"


bool CToken::isTokenTx(std::string txid) const {
	
    ///std::map<std::string, std::vector<int> >::iterator mi = txMap.find(txid);
        if (txMap.count(txid)!=0)
        {
            return true;
        }
    return false;
}

bool CToken::isTokenOutput(std::string txid, int vout) const {

    std::string key = txid + std::to_string(vout);      
    if (valueMap.count(key)!=0) return true;   
    return false;

}

int64 CToken::getValueOfOutput(std::string key) const {

    //std::map<std::string, int64>::iterator mi = valueMap.find(key);        
        if (valueMap.count(key)!=0)
        {		     
                return valueMap.at(key);
            
        }

    return 0;
}

int CToken::getNumberOfTransactions() const {
    return valueMap.size();
}


void CToken::addTransaction(std::string txid, std::vector<int> vout) {
    if (!isTokenTx(txid)) txMap.insert(std::make_pair(txid, vout));
}

void CToken::addOutput(std::string key, int64 amount) {
     printf("ADDOUTPUT CALLED \n");
     numOutputs++;
     valueMap.insert(std::make_pair(key, amount));
}    

void CToken::setGenesisValueSet() {
    genesisValueSet = true;
}

// only set the genesis tx 
//
// we don't have the value until we scan 
//
CToken::CToken(std::string txid, int vout, std::string name) {
    //std::cout << "inside token constructor" << endl;
    label = name;
    numOutputs = 0;
    genesisTxid = txid;
    genesisVout = vout;
    genesisValueSet = false;
    // add the genesis TX to the token map
    std::vector<int> voutVec;
    voutVec.push_back(vout);
    txMap.insert(std::make_pair(txid,voutVec));
    printf("Constructing token with %s transactions", std::to_string(numOutputs).c_str());
    // concatenate the vout for the key
    // (ONLY ON RESCAN NOW)
    //valueMap.insert(std::make_pair(txid + std::to_string(vout),amount));
     
    
}
    



