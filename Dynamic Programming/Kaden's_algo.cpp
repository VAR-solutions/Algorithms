struct gg{
  ll start;
  ll end;
  ll maxi;
};

gg kadens(ll dp[], ll n){
  gg ans;
  ans.start = 0;
  ans.end = 0;
  ans.maxi = 0;
  ll best = 0;
  ll ok = 1;
  for(ll i=0;i<n;i++){
    best += dp[i];
    if(best<0){
      best = 0;
      ok = 1;
    }else{
      if(ans.maxi<best&&ok){
        ans.start = i;
        ans.end  = i;
        ans.maxi = max(ans.maxi,best);
        ok = 0;
      }else if(ans.maxi<best){
        ans.maxi = max(ans.maxi,best);
        ans.end = i;
      }
    }
  }
  return ans;
}