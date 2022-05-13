//===============   Définition des nouveaux types / Structures =======================
//
typedef enum { True, False} bool;   // Définition du type booléen

typedef enum { FRONT, BACK, UP, DOWN, RIGHT, LEFT } T_SIDE ; // Def de enum T_SIDE comme dans le pdf

typedef enum { R, B, G, W, Y, O, LG } T_COLOR ; // Def de enum T_COLOR comme dans le pdf

/*
* Définition de la structure du Rubik's Cube comportant 2 champs:
*   -Le tableau des case de dim 3*3 et de type énuméré T_COLOR
*   -L'identifiant de la face de type énuméré T_SIDE
*/
typedef struct{T_COLOR ** face; T_SIDE * Type_face;} Rubiks;
//====================================================================================

//=============     Définition des constantes   ==================
//
const char * COLOR_STRING = "RBGWYO";
const char * SIDE_STRING = "FBUDRL";
//================================================================

//=============     Prototypes des fonctions   ===================
//
int select_color (char*);
int side_to_index(char*);

Rubiks * create_rubiks(void);
void init_rubiks(Rubiks*);

void display_rubiks(Rubiks*);

void blank_rubiks(Rubiks*);

void free_rubiks(Rubiks*);

void self_rotate(T_COLOR**, bool, bool);

void FRONT_clockwise(Rubiks*, int);
void FRONT_anticlockwise(Rubiks *, bool);

void RIGHT_clockwise(Rubiks*, bool);
void RIGHT_anticlockwise(Rubiks*, bool);

void BACK_clockwise(Rubiks*, bool);
void BACK_anticlockwise(Rubiks*, bool);

void LEFT_clockwise(Rubiks*, bool);
void LEFT_anticlockwise(Rubiks*, bool);

void UP_clockwise(Rubiks*, bool);
void UP_anticlockwise(Rubiks*, bool);

void DOWN_clockwise(Rubiks*, bool);
void DOWN_anticlockwise(Rubiks*, bool);

void scramble_rubiks(Rubiks*, int);

void horizontal_rotation(Rubiks*);
void vertical_rotation(Rubiks*);
//========================================================