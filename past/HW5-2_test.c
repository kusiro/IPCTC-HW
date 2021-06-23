#include <stdio.h>
#include <stdlib.h>


int main()
{
    int t;
    scanf("%d",&t);

    while( t-- ){
        int n, m, k;
        scanf("%d %d %d",&n,&m,&k);
        long long int nums[5050];

        for(int i = 1; i <= n; i++){
            scanf("%lld",&nums[i]);
        }

        if( m == 1 ){
            long long int ans = nums[1] > nums[n] ? nums[1] : nums[n];
            printf("%lld\n",ans);
        }

        else if( k > m - 1 && m > 1){
            long long int ans = nums[1];
            for(int edge_l = 0 ; edge_l <= k ; edge_l++ ){
                int r_edge = k - edge_l;
                long long int l = nums[edge_l + 1];
                long long int r = nums[n-r_edge];

                long long int this_time_max = l > r ? l : r;
                if( this_time_max > ans )
                    ans = this_time_max;
            }
            printf("%lld\n",ans);
        }

        else{
          long long int ans = 0;
          for (int c_edge_l = 0; c_edge_l <= k; c_edge_l++)
          {
            int c_edge_r = k - c_edge_l;
            long long int cur_min = 0xfffffff;

            for (int uc_people_l = 0; uc_people_l <= m - k - 1; uc_people_l++)
            {
              int uc_people_r = m - k - 1 - uc_people_l;

              long long int this_time_min = nums[1 + c_edge_l + uc_people_l] > nums[n - c_edge_r - uc_people_r] ? nums[1 + c_edge_l + uc_people_l] : nums[n - c_edge_r - uc_people_r];
              if (this_time_min < cur_min)
              {
                cur_min = this_time_min;
              }
            }
            if (cur_min > ans)
              ans = cur_min;
            }
            printf("%lld\n",ans);
        }
            
    }
    return 0;
}
