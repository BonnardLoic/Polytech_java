#include "stdint.h"
#include "stdio.h"

struct point {
  int32_t x;
  int32_t y;
};

/*
 * A line, embedding two points.
 */
struct line {
  struct point p1;
  struct point p2;
};

/*
 * A triangle, using pointers to 
 * its points.
 */
struct triangle {
  struct point*p1;
  struct point*p2;
  struct point*p3;
};

void point_copy(struct point* dst, struct point* src) {
  dst->x = src->x;
  dst->y = src->y;
  /*
   * Avant de sortir de cette fonction. 
   * Afficher les points src et dst.
   *   (gdb) p src
   * Cela affiche le pointeur, bien sur.
   *   (gdb) p *src
   * Super, cela affiche le point.
   * Remonter avec 
   *  (gdb) up
   * jusqu'au main(), pour verifier les valeurs.
   * Revenir ici avec
   *  (gdb) down
   */
  return;
}

void line_ctor(struct line* line,
	       struct point *p1, struct point* p2) {

  point_copy(&line->p1,p1);
  point_copy(&line->p2,p2);
}

/*
 * Voici le point d'entree de l'execution.
 * Toute execution commence toujours par ici.
 *
 * mettez un breakpoint sur main avant de faire run sous gdb
 * Utiliser la commande next pour executer la ligne courante.
 */
int32_t main(int32_t argc, char* argv[]) {

  struct point p1;
  struct point p2;
  struct point p3;
  struct line l1;
  struct line l2;
  struct triangle t;

  p1.x = 12;
  p1.y = 33;
  p2.x = -45;
  p2.y = 55;
  p3.x = 5;
  p3.y = -10;

  /*
   * Use gdb and the print command to look at the points
   * we used initialized.
   * (gdb) p p1
   */

  l1.p1.x = 300;
  l1.p1.y = -20;
  l1.p2.x = 670;
  l1.p2.y = 450;

  /*
   * Use gdb and the print command to look at the points
   * we used initialized.
   * (gdb) p l1
   * (gdb) p l1.p1
   * (gdb) p l1.p2
   */

  line_ctor(&l2, &p1, &p2);

  t.p1 = &p1;
  t.p2 = &p2;
  t.p3 = &p3;

  // Copions le point p2 dans p1.
  t.p1->x = t.p2->x;
  t.p1->y = t.p2->y;

  // restaurons le point p1.
  t.p1->x = 12;
  t.p1->y = 33;

  // nous aurions pu ausi écrire:
  p1.x = 12;
  p1.y = 33;

  // pourquoi?
  // parce t->p1 = &p1
  // donc le pointeur t->p1
  // et la variable p1
  // nomme la même region mémoire !

  p1.x = 666;
  p1.y = -666;

  printf("p1=(%d,%d)\n",p1.x,p1.y);
  printf("t->p1=(%d,%d)\n",t.p1->x,t.p1->y);
  
  return 0;
}
