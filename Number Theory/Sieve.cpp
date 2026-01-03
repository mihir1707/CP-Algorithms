const int N=1e6;
vector<bool> isPrime(N+1,true);
void Sieve(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=N;++i) if(isPrime[i]) for(int j=i*i;j<=N;j+=i) isPrime[j]=false;
}