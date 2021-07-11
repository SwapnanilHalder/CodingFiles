
ll t;
    cin>>t;

    for(ll j=1; j<=t; j++)
    {
        ll n, c;
        cin>>n>>c;

        unordered_map<ll, ll> start, end;
        vpll range;
        ll R=0;
        for(ll i=0; i<n; i++)
        {
            ll l, r;
            cin>>l>>r;
            start[l]++;
            end[r]++;
            R = max(R, r);
            range.pb({l, r});
        }

        vll cnt(R+2, 0);

        for(ll i=0; i<n; i++)
        {
            cnt[range[i].ff]++;
            cnt[range[i].ss+1]--;
        }

        for(ll i=1; i<=R; i++)
        {
            cnt[i] += cnt[i-1];
        }

        vpll CNT;
        for(ll i=1; i<=R; i++)
        {
            CNT.pb({cnt[i], i});
        }

        sort(all(CNT), greater<pll>());

        ll ans = n, cuts=0;
        for(ll i=0; i<n; i++)
        {
            if(cuts==c)
                break;
            if((CNT[i].ff - start[CNT[i].ss] - end[CNT[i].ss]) > 0)
            {
                ans += (CNT[i].ff - start[CNT[i].ss] - end[CNT[i].ss]);
                cuts++;
            }          
        }

        cout<<"Case #"<<j<<": "<<ans<<"\n";
    }