#define long long ll

bool is_possible(vector<int> &C, int mid_t, int A) {
    ll count=0, temp=0;
    for(int i=0; i<C.size(); i++) {
        if(temp + C[i] > mid_t) {
            temp = 0;
            count++;
        }
        else {
            temp += C[i];
        }
    }
    return(count <= A);
}

int Solution::paint(int A, int B, vector<int> &C) {
    ll sum = accumulate(C.begin(), C.end(), 0);
    ll min_t = sum/A;
    
    ll max_t = sum;
    ll mid_t = -1;
    while(max_t >= min_t) {
        mid_t = min_t + (max_t-min_t)/2;
        if(is_possible(C, mid_t, A)) {
            max_t = mid_t-1;
        }
        else {
            min_t = mid_t+1;
        }
    }
    mid_t %= 10000003;
    mid_t = mid_t % mod * 
    mid_t %= 10000003;
    return mid_t;
}
