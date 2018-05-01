typedef long long LL;

LL pow_mod(LL a, LL b, LL p){//a的b次方求余p 
    LL ret = 1;
    while(b){
        if(b & 1) ret = (ret * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ret;
}