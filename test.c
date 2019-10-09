#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NUM 20

int descSort(const void* v1, const void* v2) {
    const double _v1 = *((const double*)v1);
    const double _v2 = *((const double*)v2);
 
    if ( _v1 < _v2 ) {
        return 1;
    } else if ( _v1 > _v2 ) {
        return -1;
    } else {
        return 0;
    }
}

int main()
{
   double Science[20] = {65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70};
   double English[20] = {44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84};
   double S_hensa[20] = {0};
   double E_hensa[20] = {0};
   double s_avg, s_dev = 0, s_sum = 0;
   double e_avg, e_dev = 0, e_sum = 0;
   int i;
   
   for(i=0; i<NUM; i++){
      s_sum += Science[i];
      e_sum += English[i];    
   }

   s_avg = s_sum / NUM;
   e_avg = e_sum / NUM;
   
   for(i=0; i<NUM; i++){
      s_dev += (Science[i] - s_avg)*(Science[i] - s_avg);
      e_dev += (English[i] - e_avg)*(English[i] - e_avg);
   }

   s_dev = sqrt(s_dev / NUM);
   e_dev = sqrt(e_dev / NUM);

   for(i=0;i<NUM;i++){
      S_hensa[i] = fabs(Science[i] - s_avg)*10.0/s_dev;
      E_hensa[i] = fabs(English[i] - e_avg)*10.0/e_dev;
   } 

   for(i=0;i<NUM;i++){
      if(Science[i] > s_avg)
         S_hensa[i] = 50 + S_hensa[i];
      else if(Science[i] == s_avg)
         S_hensa[i] = 50;
      else if(Science[i] < s_avg)
         S_hensa[i] = 50 - S_hensa[i];

      if(English[i] > e_avg)
         E_hensa[i] = 50 + E_hensa[i];
      else if(English[i] == e_avg)
         E_hensa[i] = 50;
      else if(English[i] < e_avg)
         E_hensa[i] = 50 - E_hensa[i];
   }

   qsort(Science, 20, sizeof(Science[0]), descSort);
   qsort(English, 20, sizeof(English[0]), descSort);

   printf("----------------------------理科------------------------------\n");
   printf("平均点 = %lf,標準偏差 = %lf,合計点 = %lf\n\n",s_avg,s_dev,s_sum);
   for(i=0;i<NUM;i++){
      printf("点数が%.1lfの人の偏差値は%lf\n",Science[i],S_hensa[i]);       
   }
   printf("\n");
   for(i=0;i<NUM;i++){
      printf("%d番目に高い点数：%.1lf\n",i+1,Science[i]);
   }
   printf("--------------------------------------------------------------\n");

   printf("\n\n\n===========================英語================================\n");
   printf("平均点 = %lf,標準偏差 = %lf,合計点 = %lf\n",e_avg,e_dev,e_sum);
   for(i=0;i<NUM;i++){
      printf("点数が%.1lfの人の偏差値は%lf\n",English[i],E_hensa[i]);       
   }
   printf("\n");
   for(i=0;i<NUM;i++){
      printf("%d番目に高い点数：%.1lf\n",i+1,English[i]);
   }
   printf("===============================================================\n");

   return 0;
}
