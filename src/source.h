#ifndef SOURCE_H_
#define SOURCE_H_
#include <string.h>
#include <stdio.h>
#include "Don.h"
void Afficher_type_sang(GtkTreeView *treeview);
Don verifier02(char code_de_don[]);
int verifier_existant_don(char code[]);
Don chercher01(char *filename, char *code_de_don);
int trouvertype(char code_de_don[]);
int trouverregion(char code_de_don[]);
int trouverannee(char code_de_don[]);
int trouvermois(char code_de_don[]);
int trouverjour(char code_de_don[]);
#endif 
