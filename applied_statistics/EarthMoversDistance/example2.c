/* example2.c */

#include <stdio.h>
#include <math.h>

#include "emd.h"


float dist(feature_t *F1, feature_t *F2) { return fabs(*F1 - *F2); }

main()
{
  feature_t   f1[5] = { 0, 1, 2, 3, 4 };
  float       w1[5] = { 0.4, 0.2, 0.2, 0.1, 0.1 }, // must sum to 1.0
              w2[5] = { 0.5, 0.1, 0.1, 0.1, 0.2 }; // must sum to 1.0
  signature_t   s1 = { 5, f1, w1},
	              s2 = { 5, f1, w2};
  
  float       e;
  flow_t      flow[100];
  int         i, flowSize;

  e = emd(&s1, &s2, dist, flow, &flowSize);

  printf("emd = %f\n", e);

  printf("\nflow: (flowSize: %d)\n", flowSize);
  printf("from\tto\tamount\n");
  for (i=0; i < flowSize; i++)
    if (flow[i].amount > 0)
      printf("%d\t%d\t%f\n", flow[i].from, flow[i].to, flow[i].amount);

  return 0;
}
