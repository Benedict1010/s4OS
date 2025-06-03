#include<stdio.h>

void main() {
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;
    printf("\nEnter the length of the page reference string: ");
    scanf("%d", &n);
    printf("\nEnter the reference string:\n");
    for(i = 0; i < n; i++) {
    	scanf("%d", &rs[i]);
    }
   
    printf("\nEnter number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++) {
    	m[i] = -1;
    }
    printf("\nReplacement process:\n");
    for(i = 0; i < n; i++) {
    	for(k = 0; k < f; k++) {
        	if(m[k] == rs[i]) {
        		break;
        	}
        }
        if(k == f) {
            m[count++] = rs[i];
            pf++;
            for(j = 0; j < f; j++) {
            	if(m[j] != -1) {
            		printf("\t%d", m[j]);
              }
              else {
              	printf("\t-");
              }
            }
            printf("\tPF No.%d", pf);
            printf("\n");
           
            if(count == f) {
            	count = 0;
            }
        }
    }
  	printf("\nThe number of page faults using FIFO are: %d\n", pf);
}
    