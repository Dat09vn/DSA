#include <bits/stdc++.h>
using namespace std;
long n,W;
struct Dta
{
	long w,val;
};
Dta a[100];
bool cmp (Dta a, Dta b )
{
	return (float)a.val/a.w > (float)b.val/b.w;
}
long Try(int i, long  w , long val)
{
    cout<<"i:"<<i<<"w:"<<w<<"val:"<<val<<endl;
    if(w > W)
        return 0;
    if(i == n && w<=W)
    {
       // if(w <= W)
        return val;
       // else return 0;
    }
        int l = Try(i + 1 ,w + a[i].w, val + a[i].val);
        int r = Try(i + 1, w , val);
        return max(l ,r);
    }
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>W;
	for (int i=0 ; i<n ; i++)
        cin>>a[i].w>>a[i].val;
	sort(a,a+n,cmp);
	cout<<Try(0,0,0);
    return 0;
}