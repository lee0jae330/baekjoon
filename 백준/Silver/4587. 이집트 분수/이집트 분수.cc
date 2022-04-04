#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

void
fastio ()
{
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
}


vector < long long >v;


int
main (void)
{
  fastio();

 while (1)
    {
      v.clear ();
      int M, N;
      cin >> M >> N;
      if (!N && !M)
	break;

      while (1)
	{

	  long long mod, GCD ,lcm;
	  long long tmpM, tmpS;
	  long long flag,num;
	  mod= N/M;
	  if(mod*M!=N)
	    mod++;

	  while(1){
	        GCD = gcd (N, mod);
	        lcm = GCD * (N / GCD) * (mod / GCD);
	        tmpM = M * (lcm / N);
	        tmpS = 1 * (lcm / mod);
	        num = tmpM-tmpS;
	 
	        flag= lcm / gcd(lcm, num);
	        num=num/gcd(lcm, num);
	   
	        if(flag <1000000){
	            v.push_back(mod);
	            break;
	        }
	        else{
	            mod++;
	        }
	      
	  }
        M=num;
        N=flag;

	  if (M==1){
	      
        for(int i=0;i<v.size();i++)
            cout <<v[i]<<' ';
	    cout <<N<<'\n';
        break;
	  }
	}
    }
  return 0;
}
