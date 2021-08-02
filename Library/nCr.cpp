vector<long long> fac(2,1),inv(2,1),finv(2,1) ;
 
void nCr_set(long long n){
	for(int i=2;i<=n;i++){
		fac.emplace_back(fac.at(fac.size()-1)*i%mod) ;
		inv.emplace_back(mod-inv.at(mod%i)*(mod/i)%mod) ;
		finv.emplace_back(finv.at(finv.size()-1)*inv.at(i)%mod) ;
	}
}
 
long long nCr(long long n,long long r){
	if(n<0||r<0||n<r) return 0 ;
	if(n==r||r==0) return 1 ;
	return fac.at(n)*finv.at(n-r)%mod*finv.at(r)%mod ;
}
 
long long nHr(long long n,long long r) {
	return nCr(n+r-1,n-1) ;
}
 
long long modpow(long long a,long long b){
	long long res = 1 ;
	while(b>0){
		if(b&1) res = res*a%mod ;
		b >>= 1 ;
		a = a*a%mod ;
	}
	return res ;
}