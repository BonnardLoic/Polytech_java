#include "stdint.h"
#include "stdio.h"


int32_t main(int32_t argc, char* argv[]) {
  
  // mettez un breakpoint sur main avant de faire run sous gdb
  // Utiliser la commande next pour executer la ligne courante.

  int32_t v1 = 5;
  int32_t v2 = 10;

  printf(" v1=%d at %p \n",v1,&v1);
  printf(" v2=%d at %p \n",v2,&v2);

  printf("\n");
  int32_t* vpt;

  vpt = &v1;
  printf(" vpt=%p *vpt=%d \n",vpt,*vpt);

  vpt = &v2;
  printf(" vpt=%p *vpt=%d \n",vpt,*vpt);

  printf("\n");
  int32_t** vptpt;
  vptpt= &vpt;
  
  printf("Setting: *vptpt = &v1\n");
  *vptpt = &v1;
  printf("  vpt=%p *vpt=%d \n",vpt,*vpt);
  **vptpt = 55;
  printf("  v1=%d at %p \n",v1,&v1);
    
  printf("\n");
  printf("Setting: *vptpt = &v2\n");
  *vptpt = &v2;
  printf("  vpt=%p *vpt=%d \n",vpt,*vpt);
  **vptpt = 1010;
  printf("  v2=%d at %p \n",v2,&v2);

  return 0;
}
